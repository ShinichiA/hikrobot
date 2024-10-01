#define MAX_BCR_LEN  512

#include "MvCodeReaderParams.h"
#include "MvCodeReaderErrorDefine.h"
#include "MvCodeReaderCtrl.h"
#include "include.h"

#include <ctype.h>

using namespace std;

static MV_CODEREADER_DEVICE_INFO_LIST stDeviceList;

class Scanner {
public:
    int nRet = MV_CODEREADER_OK;
    int LEN_OF_MESSAGE = 1000;
    MV_CODEREADER_DEVICE_INFO *devInfo;
    void *handle = NULL;
    string ip;
    string mac;
    char *message = new char[LEN_OF_MESSAGE];
    LogConsole _LOGGER = LogConsole(ip);
    char strChar[MAX_BCR_LEN] = {0};
    MV_CODEREADER_IMAGE_OUT_INFO_EX2 stImageInfo = {0};
    FILE *pFile;
    unsigned char *pData = NULL;


public:
    Scanner();

    Scanner(MV_CODEREADER_DEVICE_INFO *mDevInfo);

    static bool EnumDevice(MV_CODEREADER_DEVICE_INFO_LIST &stDeviceList);

    bool OpenDevice();

    bool GetFrame();

    bool GetBarcodeFromFrame(vector<string> &readerBarcode, vector<int> &typeBarcode);

    bool StartGrab();

    bool StopGrab();

    bool CloseDevice();

    bool DestroyHandle();

    bool SetTriggerMode(int mode);

    bool SetTriggerSource(int mode);

    int TriggerSoftware();

    bool SetTriggerSoft();

    bool SetUpTrigger();

    bool GetEnumTrigger();

    void __stdcall ImageCallBack(unsigned char *pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2 *pFrameInfo, void *pUser);

    bool RegisterCallBack(
            void (*cbOutput)(unsigned char *pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2 *pstFrameInfo, void *pUser));

    void GetDeviceIpAndMac(MV_CODEREADER_DEVICE_INFO *stDeviceList);

    static int GB2312ToUTF8(char *szSrc, size_t iSrcLen, char *szDst, size_t iDstLen);

    static int FindDeviceInDeviceList(string ip, MV_CODEREADER_DEVICE_INFO_LIST *stDeviceList);

    void SaveImage(string path);

    string decToHex(int number);

    int getIntValue(const char* key);

    void saveImageV2(int dataLength,  MvCodeReaderGvspPixelType pixelType, unsigned char *data);
};
