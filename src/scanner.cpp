#include "scanner.h"

Scanner::Scanner() {
}

Scanner::Scanner(MV_CODEREADER_DEVICE_INFO *mDevInfo) {
    devInfo = mDevInfo;
    GetDeviceIpAndMac(mDevInfo);
    _LOGGER = LogConsole(ip);
}

// get no of device in same network
bool Scanner::EnumDevice(MV_CODEREADER_DEVICE_INFO_LIST &_stDeviceList) {
    int LEN_OF_MESSAGE = 200;
    LogConsole *logEnumDevice = new LogConsole("logEnumDevice");
    char *message = new char[LEN_OF_MESSAGE];
    int nRet = MV_CODEREADER_OK;
    memset(&_stDeviceList, 0, sizeof(MV_CODEREADER_DEVICE_INFO_LIST));
    nRet = MV_CODEREADER_EnumDevices(&_stDeviceList, MV_CODEREADER_GIGE_DEVICE);
    if (MV_CODEREADER_OK != nRet) {
        memset(message, 0, LEN_OF_MESSAGE);
        sprintf(message, "Enum Devices fail! nRet [%#x]", nRet);
        logEnumDevice->info(message);
        delete logEnumDevice;
        delete[] message;
        return false;
    }

    if (_stDeviceList.nDeviceNum <= 0) {
        logEnumDevice->warn("Find No Devices!");
        delete logEnumDevice;
        delete[] message;
        return false;
    }
    memset(message, 0, LEN_OF_MESSAGE);
    sprintf(message, "Find %d Devices", _stDeviceList.nDeviceNum);
    logEnumDevice->info(message);
    delete logEnumDevice;
    delete[] message;
    return true;
}

bool Scanner::OpenDevice() {
    nRet = MV_CODEREADER_CreateHandle(&handle, devInfo);
//    nRet = MV_CODEREADER_CreateHandleBySerialNumber(&handle, "PutSerialNumberHere");
    if (MV_CODEREADER_OK != nRet) {
        _LOGGER.error("Create Handle fail!");
        return false;
    }

    // Open device
    nRet = MV_CODEREADER_OpenDevice(handle);
    if (MV_CODEREADER_OK != nRet) {
        _LOGGER.error("Open Device fail!");
        return false;
    }
    _LOGGER.info("Open Device succeed!");
    return true;
}

int Scanner::GB2312ToUTF8(char *szSrc, size_t iSrcLen, char *szDst, size_t iDstLen) {
    iconv_t cd = iconv_open("utf-8//IGNORE", "gb2312//IGNORE");
    if (0 == cd) {
        return -2;
    }

    memset(szDst, 0, iDstLen);
    char **src = &szSrc;
    char **dst = &szDst;
    if (-1 == (int) iconv(cd, src, &iSrcLen, dst, &iDstLen)) {
        return -1;
    }

    iconv_close(cd);
    return 0;
}

bool Scanner::RegisterCallBack(
        void (*cbOutput)(unsigned char *pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2 *pstFrameInfo, void *pUser)) {
    nRet = MV_CODEREADER_RegisterImageCallBackEx2(handle, cbOutput, &mac);
    if (nRet != MV_CODEREADER_OK) {
        return false;
    }
    return true;
}

// to do
bool Scanner::GetFrame() {
    memset(&stImageInfo, 0, sizeof(MV_CODEREADER_IMAGE_OUT_INFO_EX2));
    pData = NULL;
    nRet = MV_CODEREADER_GetOneFrameTimeoutEx2(handle, &pData, &stImageInfo, 1000);
    if (nRet != MV_CODEREADER_OK) {
        // memset(message, 0, LEN_OF_MESSAGE);
        // sprintf(message, "No data[0x%x]", nRet);
        // _LOGGER.error(message);
        return false;
    }
    memset(message, 0, LEN_OF_MESSAGE);
    sprintf(message, "Get One Frame Width[%d], Height[%d], nTriggerIndex[%d]\n", stImageInfo.nWidth,
            stImageInfo.nHeight, stImageInfo.nTriggerIndex);
    _LOGGER.info(message);
    return true;
}

int Scanner::TriggerSoftware() {
    return MV_CODEREADER_SetCommandValue(handle, "TriggerSoftware");
}

void Scanner::SaveImage(string path) {
    pFile = fopen(path.c_str(), "w");
    fwrite(pData, stImageInfo.nFrameLen, 1, pFile);
    fclose(pFile);
}

bool Scanner::GetBarcodeFromFrame(vector<string> &readerBarcode, vector<int> &typeBarcode) {
    string barcode;
    MV_CODEREADER_RESULT_BCR_EX *stBcrResult = (MV_CODEREADER_RESULT_BCR_EX *) stImageInfo.pstCodeListEx;
    if (stBcrResult->nCodeNum == 0) {
        return false;
    }
    for (int i = 0; i < stBcrResult->nCodeNum; i++) {
        memset(strChar, 0, MAX_BCR_LEN);
        nRet = GB2312ToUTF8(stBcrResult->stBcrInfoEx[i].chCode, strlen(stBcrResult->stBcrInfoEx[i].chCode), strChar,
                            MAX_BCR_LEN);
        int bType = stBcrResult->stBcrInfoEx[i].nBarType;
        if (nRet == MV_CODEREADER_OK) {
            memset(message, 0, LEN_OF_MESSAGE);
            sprintf(message, "CodeNum[%d] Code[%s]", i, strChar);
            _LOGGER.info(message);
            barcode = strChar;
            readerBarcode.push_back(barcode);
            typeBarcode.push_back(bType);
        } else {
            memset(message, 0, LEN_OF_MESSAGE);
            sprintf(message, "Error GetBarcodeFromFrame");
            _LOGGER.info(message);
        }
    }
    memset(message, 0, LEN_OF_MESSAGE);

    return true;
}

bool Scanner::StartGrab() {
    nRet = MV_CODEREADER_StartGrabbing(handle);
    if (MV_CODEREADER_OK != nRet) {
        _LOGGER.error("Start Grabbing fail!");
        return false;
    }

    _LOGGER.info("Start Grabbing succeed!");
    return true;
}

bool Scanner::StopGrab() {
    nRet = MV_CODEREADER_StopGrabbing(handle);
    if (MV_CODEREADER_OK != nRet) {
        _LOGGER.error("Stop Grabbing fail!");
        return false;
    }

    _LOGGER.info("Stop Grabbing succeed!");
    return true;
}

bool Scanner::CloseDevice() {
    nRet = MV_CODEREADER_CloseDevice(handle);
    if (MV_CODEREADER_OK != nRet) {
        memset(message, 0, LEN_OF_MESSAGE);
        sprintf(message, "MV_CODEREADER_CloseDevice fail! nRet [%#x]", nRet);
        _LOGGER.error(message);
        return false;
    }
    _LOGGER.info("CloseDevice succeed!");
    return true;
}

bool Scanner::DestroyHandle() {
    nRet = MV_CODEREADER_DestroyHandle(handle);
    if (MV_CODEREADER_OK != nRet) {
        memset(message, 0, LEN_OF_MESSAGE);
        sprintf(message, "MV_CODEREADER_DestroyHandle fail! nRet [%#x]", nRet);
        _LOGGER.error(message);
        return false;
    }
    _LOGGER.info("DestroyHandle succeed!");
    return true;
}

bool Scanner::SetUpTrigger() {
    if (!SetTriggerMode(MV_CODEREADER_TRIGGER_MODE_OFF)) {
        return false;
    }
    if (!SetTriggerMode(MV_CODEREADER_TRIGGER_MODE_ON)) {
        return false;
    }
    if (!SetTriggerSource(MV_CODEREADER_TRIGGER_SOURCE_LINE0)) {
        return false;
    }
    return true;
}

bool Scanner::SetTriggerMode(int mode) {
    if (MV_CODEREADER_OK != MV_CODEREADER_SetEnumValue(handle, "TriggerMode", mode)) {
        _LOGGER.error("Set Trigger Mode fail!");
        return false;
    }
    _LOGGER.info("Set Trigger Mode succeed!");
    return true;
}

bool Scanner::GetEnumTrigger() {
    MV_CODEREADER_ENUMVALUE *value = new MV_CODEREADER_ENUMVALUE();
    nRet = MV_CODEREADER_GetEnumValue(handle, "TriggerMode", value);
    delete value;
    if (MV_CODEREADER_OK != nRet) {
        _LOGGER.error("Get Trigger Mode fail!");
        return false;
    }
    return true;
}

bool Scanner::SetTriggerSource(int mode) {
    if (MV_CODEREADER_OK != MV_CODEREADER_SetEnumValue(handle, "TriggerSource", mode)) {
        _LOGGER.error("Set Trigger Source fail!");
        return false;
    }
    _LOGGER.info("Set Trigger Source succeed!");
    return true;
}

bool Scanner::SetTriggerSoft() {
    if (MV_CODEREADER_OK != MV_CODEREADER_SetCommandValue(handle, "TriggerSoftware")) {
        _LOGGER.error("Set Trigger Soft fail!");
        return false;
    }
    _LOGGER.info("Set Trigger Soft succeed!");
    return true;
}

void Scanner::GetDeviceIpAndMac(MV_CODEREADER_DEVICE_INFO *DevInfo) {
    // get IP
    int nIp1 = ((DevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
    int nIp2 = ((DevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
    int nIp3 = ((DevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
    int nIp4 = (DevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);
    ip = to_string(nIp1) + "." + to_string(nIp2) + "." + to_string(nIp3) + "." + to_string(nIp4);

    // get mac
    mac = "";
    string macAddHigh = decToHex(DevInfo->nMacAddrHigh);
    string macLow = decToHex(DevInfo->nMacAddrLow);
    mac = mac + macAddHigh[0] + macAddHigh[1] + ":" + macAddHigh[2] + macAddHigh[3] + ":" + macLow[0] + macLow[1] +
          +":" + macLow[2] + macLow[3] + ":" + macLow[4] + macLow[5] + +":" + macLow[6] + macLow[7];
    for (int i = 0; i < mac.length(); i++) {
        mac[i] = tolower(mac[i]);
    }
}

string Scanner::decToHex(int p_intValue) {
    std::stringstream ss;
    ss << std::hex << p_intValue; // int decimal_value
    std::string res(ss.str());
    return res;
}

int Scanner::FindDeviceInDeviceList(string inputIp, MV_CODEREADER_DEVICE_INFO_LIST *stDeviceList) {
    LogConsole *logFindDevice = new LogConsole("logFindDevice");
    string deviceIp;
    for (unsigned int i = 0; i < stDeviceList->nDeviceNum; i++) {
        deviceIp = "";
        MV_CODEREADER_DEVICE_INFO *pDeviceInfo = stDeviceList->pDeviceInfo[i];
        int nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
        int nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
        int nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
        int nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);
        deviceIp = to_string(nIp1) + "." + to_string(nIp2) + "." + to_string(nIp3) + "." + to_string(nIp4);
        if (deviceIp.compare(inputIp) == 0) {
            logFindDevice->info("Found Device: " + inputIp);
            delete logFindDevice;
            return i;
        }
        continue;
    }
    logFindDevice->warn("Not Found Device: " + inputIp);
    delete logFindDevice;
    return -1;
}

void Scanner::ImageCallBack(unsigned char *pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2 *pFrameInfo, void *pUser) {

}

int Scanner::getIntValue(const char *key) {
    try {
        MV_CODEREADER_INTVALUE_EX curValue = MV_CODEREADER_INTVALUE_EX();
        MV_CODEREADER_GetIntValue(handle, key, &curValue);
        return curValue.nCurValue;
    } catch (exception e) {
        _LOGGER.error(e.what());
        return -1;
    }
}

void Scanner::saveImageV2(int dataLength, MvCodeReaderGvspPixelType pixelType, unsigned char *data) {
    MV_CODEREADER_SAVE_IMAGE_PARAM_EX imageParam = MV_CODEREADER_SAVE_IMAGE_PARAM_EX();
    imageParam.pData = data;
    imageParam.nDataLen = dataLength;
    imageParam.enPixelType = pixelType;
    imageParam.nWidth = 5440;
    imageParam.nHeight = 3648;
    imageParam.nBufferSize = 5440 * 3648 * 3 + 2048;
    imageParam.enImageType = MV_CODEREADER_Image_Jpeg;
    imageParam.nJpgQuality = 50;
    MV_CODEREADER_SaveImage(handle, &imageParam);
}
