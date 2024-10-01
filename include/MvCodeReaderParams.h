
#ifndef _MV_CODEREADER_PARAMS_H_
#define _MV_CODEREADER_PARAMS_H_

#include "MvCodeReaderPixelType.h"

#ifndef __cplusplus
typedef char    bool;
#define true    1
#define false   0
#endif

// �豸���Ͷ���
#define MV_CODEREADER_UNKNOW_DEVICE        0x00000000           // δ֪�豸����
#define MV_CODEREADER_GIGE_DEVICE          0x00000001           // GigE�豸
#define MV_CODEREADER_1394_DEVICE          0x00000002           // 1394-a/b �豸
#define MV_CODEREADER_USB_DEVICE           0x00000004           // USB3.0 �豸
#define MV_CODEREADER_CAMERALINK_DEVICE    0x00000008           // CameraLink�豸

// GigE�豸��Ϣ
typedef struct _MV_CODEREADER_GIGE_DEVICE_INFO_
{
    unsigned int        nIpCfgOption;                           // �豸֧�ֵ�IP����
    unsigned int        nIpCfgCurrent;                          // �豸��ǰIP����
    unsigned int        nCurrentIp;                             // �豸��ǰIP
    unsigned int        nCurrentSubNetMask;                     // �豸��ǰ��������
    unsigned int        nDefultGateWay;                         // �豸Ĭ������
    unsigned char       chManufacturerName[32];                 // �豸����
    unsigned char       chModelName[32];                        // �豸�ͺ�
    unsigned char       chDeviceVersion[32];                    // �豸�汾
    unsigned char       chManufacturerSpecificInfo[48];         // �豸����������Ϣ
    unsigned char       chSerialNumber[16];                     // �豸���к�
    unsigned char       chUserDefinedName[16];                  // �豸�û��Զ�������

    unsigned int        nNetExport;                             // ��������IP��ַ
    unsigned int        nCurUserIP;                             // ��ǰռ���豸���û�IP

    unsigned int        nReserved[3];                           // �����ֽ�

}MV_CODEREADER_GIGE_DEVICE_INFO;

#define INFO_MAX_BUFFER_SIZE 64                                 // �����Ϣ����

// U3V�豸��Ϣ
typedef struct _MV_CODEREADER_USB3_DEVICE_INFO_
{
    unsigned char           CrtlInEndPoint;                             // ��������˵�
    unsigned char           CrtlOutEndPoint;                            // ��������˵�
    unsigned char           StreamEndPoint;                             // ���˵�
    unsigned char           EventEndPoint;                              // �¼��˵�
    unsigned short          idVendor;                                   // ��Ӧ��ID��
    unsigned short          idProduct;                                  // ��ƷID��
    unsigned int            nDeviceNumber;                              // �豸���к�
    unsigned char           chDeviceGUID[INFO_MAX_BUFFER_SIZE];         // �豸GUID��
    unsigned char           chVendorName[INFO_MAX_BUFFER_SIZE];         // ��Ӧ������
    unsigned char           chModelName[INFO_MAX_BUFFER_SIZE];          // �豸�ͺ�
    unsigned char           chFamilyName[INFO_MAX_BUFFER_SIZE];         // �豸��������
    unsigned char           chDeviceVersion[INFO_MAX_BUFFER_SIZE];      // �豸�汾
    unsigned char           chManufacturerName[INFO_MAX_BUFFER_SIZE];   // �豸����
    unsigned char           chSerialNumber[INFO_MAX_BUFFER_SIZE];       // �豸���к�
    unsigned char           chUserDefinedName[INFO_MAX_BUFFER_SIZE];    // �豸�û��Զ�������
    unsigned int            nbcdUSB;                                    // �豸֧�ֵ�USBЭ��
    unsigned int            nReserved[3];                               // �����ֽ�
}MV_CODEREADER_USB3_DEVICE_INFO;

// �豸��Ϣ
typedef struct _MV_CODEREADER_DEVICE_INFO_
{
    unsigned short      nMajorVer;                  // �豸���汾��
    unsigned short      nMinorVer;                  // �豸�ΰ汾��
    unsigned int        nMacAddrHigh;               // �豸MAC��ַ��λ
    unsigned int        nMacAddrLow;                // �豸MAC��ַ��λ

    unsigned int        nTLayerType;                // �豸�����Э������

    // �Ƿ�Ϊָ��ϵ���ͺ����
    // true -ָ��ϵ���ͺ���� false- ��ָ��ϵ���ͺ����
    bool                bSelectDevice;              // ch:ѡ���豸 |en:Choose device

    unsigned int        nReserved[3];               // �����ֽ�

    union
    {
        MV_CODEREADER_GIGE_DEVICE_INFO stGigEInfo;  // GigE�豸��Ϣ
        MV_CODEREADER_USB3_DEVICE_INFO stUsb3VInfo; // U3V�豸��Ϣ
        // more ...
    }SpecialInfo;

}MV_CODEREADER_DEVICE_INFO;

// ���֧�ֵ��豸����
#define MV_CODEREADER_MAX_DEVICE_NUM      512

// �豸��Ϣ�б�
typedef struct _MV_CODEREADER_DEVICE_INFO_LIST_
{
    unsigned int            nDeviceNum;                                             // �����豸����
    MV_CODEREADER_DEVICE_INFO*      pDeviceInfo[MV_CODEREADER_MAX_DEVICE_NUM];      // �豸��Ϣ(֧�����256���豸)

}MV_CODEREADER_DEVICE_INFO_LIST;

// ���֡��Ϣ
typedef struct _MV_CODEREADER_FRAME_OUT_INFO_
{
    unsigned short      nWidth;                             // ͼ���
    unsigned short      nHeight;                            // ͼ���

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)�ֶ�
    enum MvCodeReaderGvspPixelType     enPixelType;         // ���ظ�ʽ

    unsigned int        nFrameNum;                          // ֡��
    unsigned int        nDevTimeStampHigh;                  // ʱ�����32λ
    unsigned int        nDevTimeStampLow;                   // ʱ�����32λ
    unsigned int        nReserved0;                         // ������8�ֽڶ���
    int64_t             nHostTimeStamp;                     // �������ɵ�ʱ���

    unsigned int        nFrameLen;                          // ͼ�񳤶�

    unsigned int        nLostPacket;                        // ��֡������
    unsigned int        nReserved[2];                       // �����ֽ�
}MV_CODEREADER_FRAME_OUT_INFO;

// ch:Chunk���� | en:The content of ChunkData
typedef struct _MV_CODEREADER_CHUNK_DATA_CONTENT_
{
    unsigned char*  pChunkData;
    unsigned int    nChunkID;
    unsigned int    nChunkLen;

    unsigned int    nReserved[8];       // ����

}MV_CODEREADER_CHUNK_DATA_CONTENT;

// ���֡��Ϣ
typedef struct _MV_CODEREADER_FRAME_OUT_INFO_EX_
{
    unsigned short      nWidth;                             // ͼ���
    unsigned short      nHeight;                            // ͼ���

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)�ֶ�
    enum MvCodeReaderGvspPixelType     enPixelType;         // ���ظ�ʽ

    unsigned int        nFrameNum;                          // ֡��
    unsigned int        nDevTimeStampHigh;                  // ʱ�����32λ
    unsigned int        nDevTimeStampLow;                   // ʱ�����32λ
    unsigned int        nReserved0;                         // ������8�ֽڶ���
    int64_t             nHostTimeStamp;                     // �������ɵ�ʱ���

    unsigned int        nFrameLen;                          // ͼ�񳤶�

    // chunk����ˮӡ��Ϣ
    // �豸ˮӡʱ��
    unsigned int        nSecondCount;                       // ����
    unsigned int        nCycleCount;                        // ѭ������
    unsigned int        nCycleOffset;                       // ѭ������ƫ����

    float               fGain;                              // ����
    float               fExposureTime;                      // �ع�ʱ��
    unsigned int        nAverageBrightness;                 // ƽ������

    // ��ƽ�����
    unsigned int        nRed;                               // ��ɫ����
    unsigned int        nGreen;                             // ��ɫ����
    unsigned int        nBlue;                              // ��ɫ����

    unsigned int        nFrameCounter;                      // ͼ����������
    unsigned int        nTriggerIndex;                      // ��������

    // Line ����/���
    unsigned int        nInput;                             // ����
    unsigned int        nOutput;                            // ���

    // ROI����
    unsigned short      nOffsetX;                           // ROI X��ƫ��
    unsigned short      nOffsetY;                           // ROI Y��ƫ��
    unsigned short      nChunkWidth;                        // Chunk����
    unsigned short      nChunkHeight;                       // Chunk�߶�

    unsigned int        nLostPacket;                        // ��֡������

    unsigned int        nUnparsedChunkNum;                  //δ������Chunkdata����
    union
    {
        MV_CODEREADER_CHUNK_DATA_CONTENT* pUnparsedChunkContent;
        int64_t nAligning;
    }UnparsedChunkList;

    unsigned int        nReserved[36];                      // �����ֽ�
}MV_CODEREADER_FRAME_OUT_INFO_EX;

// ͼ����ʾ��Ϣ
typedef struct _MV_CODEREADER_DISPLAY_FRAME_INFO_
{
    void*                    hWnd;                          // ��ʾ���ھ��
    unsigned char*           pData;                         // Դͼ������
    unsigned int             nDataLen;                      // Դͼ�����ݳ���
    unsigned short           nWidth;                        // Դͼ���
    unsigned short           nHeight;                       // Դͼ���
    enum MvCodeReaderGvspPixelType     enPixelType;         // Դͼ�����ظ�ʽ
    unsigned int             nRes[4];                       // �����ֽ�

}MV_CODEREADER_DISPLAY_FRAME_INFO;

// ����ͼƬ��ʽ
enum    MV_CODEREADER_IAMGE_TYPE
{
    MV_CODEREADER_Image_Undefined       = 0,
    MV_CODEREADER_Image_Mono8           = 1,
    MV_CODEREADER_Image_Jpeg            = 2,
    MV_CODEREADER_Image_Bmp             = 3,
    MV_CODEREADER_Image_RGB24           = 4,
    MV_CODEREADER_Image_Png             = 5,      // Pngͼ��(�ݲ�֧��)
    MV_CODEREADER_Image_Tif             = 6,      // Tifͼ��(�ݲ�֧��)
};

// ����ͼƬ����
typedef struct _MV_CODEREADER_SAVE_IMAGE_PARAM_T_
{
    unsigned char*        pData;                            // �������ݻ���
    unsigned int          nDataLen;                         // �������ݴ�С

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)���ֶ�
    enum MvCodeReaderGvspPixelType       enPixelType;       // �������ݵ����ظ�ʽ
    unsigned short        nWidth;                           // ͼ���
    unsigned short        nHeight;                          // ͼ���

    unsigned char*        pImageBuffer;                     // ���ͼƬ����
    unsigned int          nImageLen;                        // ���ͼƬ��С
    unsigned int          nBufferSize;                      // �ṩ�������������С
    enum MV_CODEREADER_IAMGE_TYPE    enImageType;      // ���ͼƬ��ʽ

}MV_CODEREADER_SAVE_IMAGE_PARAM;

// ͼƬ�������
typedef struct _MV_CODEREADER_SAVE_IMAGE_PARAM_T_EX_
{
    unsigned char*      pData;                              // �������ݻ���
    unsigned int        nDataLen;                           // �������ݴ�С

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)���ֶ�
    enum MvCodeReaderGvspPixelType     enPixelType;         // �������ݵ����ظ�ʽ
    unsigned short      nWidth;                             // ͼ���
    unsigned short      nHeight;                            // ͼ���

    unsigned char*      pImageBuffer;                       // ���ͼƬ����
    unsigned int        nImageLen;                          // ���ͼƬ��С
    unsigned int        nBufferSize;                        // �ṩ�������������С
    enum MV_CODEREADER_IAMGE_TYPE  enImageType;             // ���ͼƬ��ʽ
    unsigned int        nJpgQuality;                        // ��������, (50-99]

    // ��ʽתΪRGB24�Ĳ�ֵ����  0-����� 1-˫���� 2-Hamilton �������������ֵ��Ĭ��Ϊ����ڣ�
    unsigned int        iMethodValue;                       // ��ֵ��ʽ
    unsigned int        nReserved[3];                       // �����ֽ�

}MV_CODEREADER_SAVE_IMAGE_PARAM_EX;

// ����ģʽ
typedef enum _MV_CODEREADER_TRIGGER_MODE_
{
    MV_CODEREADER_TRIGGER_MODE_OFF         = 0,            // �����ر�
    MV_CODEREADER_TRIGGER_MODE_ON          = 1,            // ������

}MV_CODEREADER_TRIGGER_MODE;

// ����Դ
typedef enum _MV_CODEREADER_TRIGGER_SOURCE_
{
    MV_CODEREADER_TRIGGER_SOURCE_LINE0             = 0,     // Line0
    MV_CODEREADER_TRIGGER_SOURCE_LINE1             = 1,     // Line1
    MV_CODEREADER_TRIGGER_SOURCE_LINE2             = 2,     // Line2
    MV_CODEREADER_TRIGGER_SOURCE_LINE3             = 3,     // Line3
    MV_CODEREADER_TRIGGER_SOURCE_COUNTER0          = 4,     // Line4

    MV_CODEREADER_TRIGGER_SOURCE_SOFTWARE          = 7,     // ������
    MV_CODEREADER_TRIGGER_SOURCE_FrequencyConverter= 8,     // ��Ƶ������

}MV_CODEREADER_TRIGGER_SOURCE;

// GigEVision IP���÷�ʽ
#define MV_CODEREADER_IP_CFG_STATIC        0x05000000       // ��̬IP
#define MV_CODEREADER_IP_CFG_DHCP          0x06000000       // DHCP
#define MV_CODEREADER_IP_CFG_LLA           0x04000000       // LLA

// ��������
typedef enum _MV_CODEREADER_CODE_TYPE_
{
    MV_CODEREADER_CODE_NONE         = 0,                    // �޿�ʶ������

    // ��ά��
    MV_CODEREADER_TDCR_DM           = 1,                    // DM��
    MV_CODEREADER_TDCR_QR           = 2,                    // QR��

    // һά��
    MV_CODEREADER_BCR_EAN8          = 8,                    // EAN8��
    MV_CODEREADER_BCR_UPCE          = 9,                    // UPCE��
    MV_CODEREADER_BCR_UPCA          = 12,                   // UPCA��
    MV_CODEREADER_BCR_EAN13         = 13,                   // EAN13��
    MV_CODEREADER_BCR_ISBN13        = 14,                   // ISBN13��
    MV_CODEREADER_BCR_CODABAR       = 20,                   // ��°���
    MV_CODEREADER_BCR_ITF25         = 25,                   // ����25��
    MV_CODEREADER_BCR_CODE39        = 39,                   // Code 39
    MV_CODEREADER_BCR_CODE93        = 93,                   // Code 93
    MV_CODEREADER_BCR_CODE128       = 128,                  // Code 128

    MV_CODEREADER_TDCR_PDF417       = 131,                  // PDF417��

    MV_CODEREADER_BCR_MATRIX25      = 26,                   // MATRIX25��
    MV_CODEREADER_BCR_MSI           = 30,                   // MSI��
    MV_CODEREADER_BCR_CODE11        = 31,                   // code11
    MV_CODEREADER_BCR_INDUSTRIAL25  = 32,                   // industrial25
    MV_CODEREADER_BCR_CHINAPOST     = 33,                   // �й�������
    MV_CODEREADER_BCR_ITF14         = 27,                   // ����14��

    MV_CODEREADER_TDCR_ECC140       = 133,                  // ECC140����

}MV_CODEREADER_CODE_TYPE;

// ������͸���(������ö������)
#define MV_CODEREADER_MAX_XML_SYMBOLIC_NUM          64

// �쳣��Ϣ����
#define MV_CODEREADER_EXCEPTION_DEV_DISCONNECT      0x00008001      // �豸�Ͽ�����
#define MV_CODEREADER_EXCEPTION_VERSION_CHECK       0x00008002      // SDK�������汾��ƥ��


// �豸�ķ���ģʽ
// ��ռȨ�ޣ�����APPֻ������CCP�Ĵ���
#define MV_CODEREADER_ACCESS_Exclusive                                         1
// ���Դ�5ģʽ����ռȨ�ޣ�Ȼ���Զ�ռȨ�޴�
#define MV_CODEREADER_ACCESS_ExclusiveWithSwitch                               2
// ����Ȩ�ޣ�����APP���������мĴ���
#define MV_CODEREADER_ACCESS_Control                                           3
// ���Դ�5��ģʽ����ռȨ�ޣ�Ȼ���Կ���Ȩ�޴�
#define MV_CODEREADER_ACCESS_ControlWithSwitch                                 4
// �Կɱ���ռ�Ŀ���Ȩ�޴�
#define MV_CODEREADER_ACCESS_ControlSwitchEnable                               5
// ���Դ�5��ģʽ����ռȨ�ޣ�Ȼ���Կɱ���ռ�Ŀ���Ȩ�޴�
#define MV_CODEREADER_ACCESS_ControlSwitchEnableWithKey                        6
// ��ģʽ���豸�������ڿ���Ȩ����
#define MV_CODEREADER_ACCESS_Monitor                                           7

// �ڵ����ģʽ
enum MV_CODEREADER_XML_AccessMode
{
    MV_CODEREADER_AM_NI,                                // �ڵ�δʵ��
    MV_CODEREADER_AM_NA,                                // �ڵ㲻�ɴ�
    MV_CODEREADER_AM_WO,                                // �ڵ�ֻд
    MV_CODEREADER_AM_RO,                                // �ڵ�ֻ��
    MV_CODEREADER_AM_RW,                                // �ڵ�ɶ���д
    MV_CODEREADER_AM_Undefined,                         // �ڵ�δ����
    MV_CODEREADER_AM_CycleDetect,                       // �ڵ������ڼ��
};

// Event�¼��ص���Ϣ 
#define MV_CODEREADER_MAX_EVENT_NAME_SIZE     128       // ���Event�¼�������󳤶�

typedef struct _MV_CODEREADER_EVENT_OUT_INFO_
{
    char            EventName[MV_CODEREADER_MAX_EVENT_NAME_SIZE];     // Event����

    unsigned short  nEventID;                           // Event��
    unsigned short  nStreamChannel;                     // ��ͨ�����

    unsigned int    nBlockIdHigh;                       // ֡�Ÿ�λ
    unsigned int    nBlockIdLow;                        // ֡�ŵ�λ

    unsigned int    nTimestampHigh;                     // ʱ�����λ
    unsigned int    nTimestampLow;                      // ʱ�����λ

    void *          pEventData;                         // Event����
    unsigned int    nEventDataSize;                     // Event���ݳ���

    unsigned int    nReserved[16];                      // Ԥ��
}MV_CODEREADER_EVENT_OUT_INFO;

// �ļ���ȡ
typedef struct _MV_CODEREADER_FILE_ACCESS_T
{
    const char * pUserFileName;                         // �û��ļ���
    const char * pDevFileName;                          // �豸�ļ���

    unsigned int    nReserved[32];                      // Ԥ���ֽ�
}MV_CODEREADER_FILE_ACCESS;

// �ļ���ȡ����
typedef struct _MV_CODEREADER_FILE_ACCESS_PROGRESS_T
{
    int64_t nCompleted;                                 // ����ɵĳ���
    int64_t nTotal;                                     // �ܳ���

    unsigned int    nReserved[8];                       // Ԥ���ֽ�
}MV_CODEREADER_FILE_ACCESS_PROGRESS;

// Enum����ֵ
typedef struct _MV_CODEREADER_ENUMVALUE_T
{
    unsigned int    nCurValue;                                          // ��ǰֵ
    unsigned int    nSupportedNum;                                      // ��Ч���ݸ���
    unsigned int    nSupportValue[MV_CODEREADER_MAX_XML_SYMBOLIC_NUM];  // ֧�ֵ�ö������

    unsigned int    nReserved[4];                                       // �����ֽ�
}MV_CODEREADER_ENUMVALUE;

// Int����ֵ
typedef struct _MV_CODEREADER_INTVALUE_T
{
    unsigned int    nCurValue;                          // ��ǰֵ
    unsigned int    nMax;                               // ���ֵ
    unsigned int    nMin;                               // ��Сֵ
    unsigned int    nInc;                               // ����ֵ

    unsigned int    nReserved[4];                       // �����ֽ�
}MV_CODEREADER_INTVALUE;

// Int����ֵ
typedef struct _MV_CODEREADER_INTVALUE_EX_T
{
    int64_t    nCurValue;                               // ��ǰֵ
    int64_t    nMax;                                    // ���ֵ
    int64_t    nMin;                                    // ��Сֵ
    int64_t    nInc;                                    // ����ֵ

    unsigned int    nReserved[16];                      // �����ֽ�
}MV_CODEREADER_INTVALUE_EX;

// Float����ֵ
typedef struct _MV_CODEREADER_FLOATVALUE_T
{
    float           fCurValue;                          // ��ǰֵ
    float           fMax;                               // ���ֵ
    float           fMin;                               // ��Сֵ

    unsigned int    nReserved[4];                       // �����ֽ�
}MV_CODEREADER_FLOATVALUE;

// String����ֵ
typedef struct _MV_CODEREADER_STRINGVALUE_T
{
    char            chCurValue[256];                    // ��ǰֵ

    int64_t         nMaxLength;                         // ��󳤶�
    unsigned int    nReserved[2];                       // �����ֽ�
}MV_CODEREADER_STRINGVALUE;

// ������볤��
#define MV_CODEREADER_MAX_BCR_CODE_LEN 256

// ������볤����չ
#define MV_CODEREADER_MAX_BCR_CODE_LEN_EX 4096

// Int������
typedef struct _MV_CODEREADER_POINT_I_
{
    int x;                                              // x����
    int y;                                              // y����
}MV_CODEREADER_POINT_I;

// Float������
typedef struct _MV_CODEREADER_POINT_F_
{
    float x;                                            // x����
    float y;                                            // y����
}MV_CODEREADER_POINT_F;

// ������Ϣ
typedef struct _MV_CODEREADER_BCR_INFO_
{
    unsigned int                nID;                                        // ����ID
    char                        chCode[MV_CODEREADER_MAX_BCR_CODE_LEN];     // �ַ�
    unsigned int                nLen;                                       // �ַ�����
    unsigned int                nBarType;                                   // ��������

    MV_CODEREADER_POINT_I       pt[4];                                      // ����λ��

    int                         nAngle;                                     // ����Ƕ�(10��)��0~3600��
    unsigned int                nMainPackageId;                             // ����ID
    unsigned int                nSubPackageId;                              // �ΰ�ID
    unsigned short              sAppearCount;                               // ���뱻ʶ��Ĵ���
    unsigned short              sPPM;                                       // PPM(10��)
    unsigned short              sAlgoCost;                                  // �㷨��ʱ
    unsigned short              sSharpness;                                 // ͼ��������(10��)
} MV_CODEREADER_BCR_INFO;

// ����������������5��[0,4], Խ�ߵ�����Խ��; 1Dָһά�룬2Dָ��ά�룩
typedef struct _MV_CODEREADER_CODE_INFO_
{
    // �ȼ�
    int             nOverQuality;             // �����������֣�1D/2D���ã�
    int             nDeCode;                  // �������֣�1D/2D���ã�
    int             nSCGrade;                 // Symbol Contrast�Աȶ��������֣�1D/2D���ã�
    int             nModGrade;                // modulationģ����������֣�1D/2D���ã�

    // 2D�ȼ�
    int             nFPDGrade;                // fixed_pattern_damage����
    int             nANGrade;                 // axial_nonuniformity������������� 
    int             nGNGrade;                 // grid_nonuniformity����grid��������������
    int             nUECGrade;                // unused_error_correctionδʹ�þ�����������
    int             nPGHGrade;                // Print Growth Horizontal ��ӡ����(ˮƽ)����
    int             nPGVGrade;                // Print Growth Veritical ��ӡ����(��ֱ)����

    // ����
    float           fSCScore;                 // Symbol Contrast�Աȶ�����������1D/2D���ã�
    float           fModScore;                // modulationģ������Է�����1D/2D���ã�

    // 2D����
    float           fFPDScore;                // fixed_pattern_damage����
    float           fAnScore;                 // axial_nonuniformity��������Է��� 
    float           fGNScore;                 // grid_nonuniformity����grid��������������
    float           fUECScore;                // unused_error_correctionδʹ�þ������ܷ���

    float           fPGHScore;                // Print Growth Horizontal ��ӡ����(ˮƽ)����
    float           fPGVScore;                // Print Growth Veritical ��ӡ����(��ֱ)����

    int             nRMGrade;                 // reflectance margin��������������
    float           fRMScore;                 // reflectance margin��������������

    // 1D�ȼ�
    int             n1DEdgeGrade;               // edge determination     ��Եȷ���������ȼ�
    int             n1DMinRGrade;               // minimum reflectance    ��С�����������ȼ�
    int             n1DMinEGrade;               // minimum edge contrast  ��С��Ե�Աȶ������ȼ�
    int             n1DDcdGrade;                // decodability           �������������ȼ� 
    int             n1DDefGrade;                // defects                ȱ�������ȼ�
    int             n1DQZGrade;                 // quiet zone             ���������ȼ�

    // 1D����
    float           f1DEdgeScore;               // edge determination     ��Եȷ���ȷ���
    float           f1DMinRScore;               // minimum reflectance    ��С�����ʷ���
    float           f1DMinEScore;               // minimum edge contrast  ��С��Ե�Աȶȷ���
    float           f1DDcdScore;                // decodability           �������Է��� 
    float           f1DDefScore;                // defects                ȱ�ݷ���
    float           f1DQZScore;                 // quiet zone             ��������

    int    nReserved[18];

} MV_CODEREADER_CODE_INFO;

// ��������Ϣ��BCR��Ϣ
typedef struct _MV_CODEREADER_BCR_INFO_EX_
{
    unsigned int                nID;                                        // ����ID
    char                        chCode[MV_CODEREADER_MAX_BCR_CODE_LEN];     // �ַ�
    unsigned int                nLen;                                       // �ַ�����
    unsigned int                nBarType;                                   // ��������

    MV_CODEREADER_POINT_I       pt[4];                                      // ����λ��
    MV_CODEREADER_CODE_INFO     stCodeQuality;                              // ������������

    int                         nAngle;                                     // ����Ƕ�(10��)��0~3600��
    unsigned int                nMainPackageId;                             // ����ID
    unsigned int                nSubPackageId;                              // �ΰ�ID
    unsigned short              sAppearCount;                               // ���뱻ʶ��Ĵ���
    unsigned short              sPPM;                                       // PPM(10��)
    unsigned short              sAlgoCost;                                  // �㷨��ʱ
    unsigned short              sSharpness;                                 // ������
    bool                        bIsGetQuality;                              // �Ƿ�֧�ֶ�ά����������
    unsigned int                nIDRScore;                                  // ��������

    unsigned int                n1DIsGetQuality;                            // �Ƿ�֧��һά����������(0-��֧�� 1-֧��)

    unsigned int                nReserved[29];

} MV_CODEREADER_BCR_INFO_EX;


// ��������Ϣ�������ַ���չ��BCR��Ϣ
typedef struct _MV_CODEREADER_BCR_INFO_EX_2_
{
    unsigned int                nID;                                        // ����ID
    char                        chCode[MV_CODEREADER_MAX_BCR_CODE_LEN_EX];  // �ַ���ʶ�𳤶���չ��4096
    unsigned int                nLen;                                       // �ַ�ʵ����ʵ����
    unsigned int                nBarType;                                   // ��������

    MV_CODEREADER_POINT_I       pt[4];                                      // ����λ��
    MV_CODEREADER_CODE_INFO     stCodeQuality;                              // ������������

    // һά�룺��ͼ��x����Ϊ��׼��˳ʱ��0-3600�ȣ���ά�룺��ͼ��x����Ϊ��׼����ʱ��0-3600��
    int                         nAngle;                                     // ����Ƕ�(10��)��0~3600��
    unsigned int                nMainPackageId;                             // ����ID
    unsigned int                nSubPackageId;                              // �ΰ�ID
    unsigned short              sAppearCount;                               // ���뱻ʶ��Ĵ���
    unsigned short              sPPM;                                       // PPM(10��)
    unsigned short              sAlgoCost;                                  // �㷨��ʱ
    unsigned short              sSharpness;                                 // ������
    bool                        bIsGetQuality;                              // �Ƿ�֧�ֶ�ά����������
    unsigned int                nIDRScore;                                  // ��������

    unsigned int                n1DIsGetQuality;                            // �Ƿ�֧��һά����������(0-��֧�� 1-֧��)

    int                         nReserved[64];

} MV_CODEREADER_BCR_INFO_EX2;

// һ���������������
#define MAX_CODEREADER_BCR_COUNT    200

// һ���������������
#define MAX_CODEREADER_BCR_COUNT_EX    300

// ������Ϣ�б�
typedef struct _MV_CODEREADER_RESULT_BCR_
{
    unsigned int            nCodeNum;                                   // ��������
    MV_CODEREADER_BCR_INFO  stBcrInfo[MAX_CODEREADER_BCR_COUNT];        // ������Ϣ
    unsigned int            nReserved[4];                               // �����ֽ�
}MV_CODEREADER_RESULT_BCR;

// ������Ϣ�����������б�
typedef struct _MV_CODEREADER_RESULT_BCR_EX_
{
    unsigned int                        nCodeNum;                                   // ��������
    MV_CODEREADER_BCR_INFO_EX           stBcrInfoEx[MAX_CODEREADER_BCR_COUNT];      // ������Ϣ
    unsigned int                        nReserved[4];                               // �����ֽ�
}MV_CODEREADER_RESULT_BCR_EX;

// ������Ϣ�ַ���չ�����������б�
typedef struct _MV_CODEREADER_RESULT_BCR_EX_2_
{
    unsigned int                        nCodeNum;                                   // ������������չ��
    MV_CODEREADER_BCR_INFO_EX2          stBcrInfoEx2[MAX_CODEREADER_BCR_COUNT_EX];  // ������Ϣ�������ַ���չ��
    unsigned int                        nReserved[8];                               // �����ֽ�
}MV_CODEREADER_RESULT_BCR_EX2;

// ������ݻ���
#define MV_CODEREADER_MAX_RESULT_SIZE       (1024*64)

// ���֡��Ϣ
typedef struct _MV_CODEREADER_IMAGE_OUT_INFO_
{
    unsigned short      nWidth;                                     // ͼ���
    unsigned short      nHeight;                                    // ͼ���

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)�ֶ�
    MvCodeReaderGvspPixelType   enPixelType;                        // ���ػ�ͼƬ��ʽ

    unsigned int        nTriggerIndex;                              // �������
    unsigned int        nFrameNum;                                  // ֡��
    unsigned int        nFrameLen;                                  // ��ǰ֡���ݴ�С
    unsigned int        nTimeStampHigh;                             // ʱ�����32λ
    unsigned int        nTimeStampLow;                              // ʱ�����32λ

    unsigned int        nResultType;                                // �����Ϣ����

    unsigned char       chResult[MV_CODEREADER_MAX_RESULT_SIZE];    // ������Ϣ���Ͷ�Ӧ��ͬ�ṹ��
    bool                bIsGetCode;                                 // �Ƿ��������

    unsigned char*      pImageWaybill;                              // �浥ͼ��
    unsigned int        nImageWaybillLen;                           // �浥���ݴ�С
    enum MV_CODEREADER_IAMGE_TYPE     enWaybillImageType;           // �浥ͼ������

    unsigned int        bFlaseTrigger;                              // �Ƿ��󴥷�
    unsigned int        nFocusScore;                                // �۽��÷�

    unsigned int        nChannelID;                                 // ��ӦStreamͨ�����
    unsigned int        nImageCost;                                 // ֡ͼ��������ڲ��Ĵ�����ʱ

    unsigned int        nReserved[6];                               // �����ֽ�
}MV_CODEREADER_IMAGE_OUT_INFO;


typedef struct _MV_CODEREADER_WAYBILL_INFO_
{
    // �浥������Ϣ
    float fCenterX;                 // ���ĵ�������
    float fCenterY;                 // ���ĵ�������
    float fWidth;                   // ���ο��ȣ�����Ϊ������
    float fHeight;                  // ���θ߶ȣ��߶�Ϊ�̰���
    float fAngle;                   // ���νǶ�
    float fConfidence;              // ���Ŷ�

    // �浥ͼƬ
    unsigned char*  pImageWaybill;
    unsigned int    nImageLen;

    unsigned int    nReserved[12];
}MV_CODEREADER_WAYBILL_INFO;

#define MAX_CODEREADER_WAYBILL_COUNT        50

// �浥��Ϣ�б�
typedef struct _MV_CODEREADER_WAYBILL_LIST_
{
    unsigned int                    nWaybillNum;                                    // �浥����
    enum MV_CODEREADER_IAMGE_TYPE   enWaybillImageType;                             // �浥ͼ�����ͣ���ѡ��bmp��raw��jpg���

    MV_CODEREADER_WAYBILL_INFO      stWaybillInfo[MAX_CODEREADER_WAYBILL_COUNT];    // �浥��Ϣ
    unsigned int                    nReserved[4];                                   // �����ֽ�
}MV_CODEREADER_WAYBILL_LIST;

typedef struct _MV_CODEREADER_IMAGE_OUT_INFO_EX_
{
    unsigned short              nWidth;                     // ͼ���
    unsigned short              nHeight;                    // ͼ���

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)�ֶ�
    MvCodeReaderGvspPixelType   enPixelType;                // ���ػ�ͼƬ��ʽ

    unsigned int                nTriggerIndex;              // �������
    unsigned int                nFrameNum;                  // ֡��
    unsigned int                nFrameLen;                  // ��ǰ֡���ݴ�С
    unsigned int                nTimeStampHigh;             // ʱ�����32λ
    unsigned int                nTimeStampLow;              // ʱ�����32λ

    unsigned int                bFlaseTrigger;              // �Ƿ��󴥷�
    unsigned int                nFocusScore;                // �۽��÷�

    bool                        bIsGetCode;                 // �Ƿ��������
    MV_CODEREADER_RESULT_BCR*   pstCodeList;

    MV_CODEREADER_WAYBILL_LIST* pstWaybillList;             // �浥��Ϣ

    unsigned int                nEventID;                   // �¼�ID

    unsigned int                nChannelID;                 // ��ӦStreamͨ�����

    unsigned int                nImageCost;                 // ֡ͼ��������ڲ��Ĵ�����ʱ

    unsigned int                nReserved[6];               // �����ֽ�
}MV_CODEREADER_IMAGE_OUT_INFO_EX;

typedef struct _MV_CODEREADER_IMAGE_OUT_INFO_EX_2_
{
    unsigned short                  nWidth;                     // ͼ���
    unsigned short                  nHeight;                    // ͼ���

	// ���ظ�ʽ���ע��ƽ̨32λϵͳ�� ��ǿת��ȡ������� ��(unsigned int)�ֶ�
    MvCodeReaderGvspPixelType       enPixelType;                // ���ػ�ͼƬ��ʽ

    unsigned int                    nTriggerIndex;              // �������
    unsigned int                    nFrameNum;                  // ֡��
    unsigned int                    nFrameLen;                  // ��ǰ֡���ݴ�С
    unsigned int                    nTimeStampHigh;             // ʱ�����32λ
    unsigned int                    nTimeStampLow;              // ʱ�����32λ

    unsigned int                    bFlaseTrigger;              // �Ƿ��󴥷�
    unsigned int                    nFocusScore;                // �۽��÷�

    bool                            bIsGetCode;                 // �Ƿ��������
    MV_CODEREADER_RESULT_BCR_EX*    pstCodeListEx;

    MV_CODEREADER_WAYBILL_LIST*     pstWaybillList;             // �浥��Ϣ

    unsigned int                    nEventID;                   // �¼�ID
    unsigned int                    nChannelID;                 // ��ӦStreamͨ�����
    unsigned int                    nImageCost;                 // ֡ͼ��������ڲ��Ĵ�����ʱ

    union
    {
        MV_CODEREADER_RESULT_BCR_EX2*   pstCodeListEx2;     // ������Ϣ�������ַ�������չ�������Ը���չ�����ַ���������Ϣ��������
        int64_t nAligning;
    }UnparsedBcrList;

    unsigned int                    nReserved[28];               // �����ֽ�
}MV_CODEREADER_IMAGE_OUT_INFO_EX2;


// �����Ϣ����
enum MvCodeReaderType
{
    CodeReader_ResType_NULL       = 0,    // û�н�����
    CodeReader_ResType_BCR        = 1,    // �����ϢΪBCR(��Ӧ�ṹ�� MV_CODEREADER_RESULT_BCR)
};

// ���Э������
#define CommuPtlSmartSDK 1          // SamrtSDKЭ��
#define CommuPtlTcpIP    2          // TCPIPЭ��
#define CommuPtlSerial   3          // SerialЭ��

/************************************************************************/
/* ��ͼ�������ڲ���Ĭ��ֵ�����Բ�����                                   */
/************************************************************************/
#define KEY_WAYBILL_ABILITY                     "WAYBILL_Ability"                   // �㷨�����������浥��ȡ[0x1]��ͼ����ǿ[0x2]������ȡ[0x4]��Box����ģ��[0x8]���浥��ȡģ��[0x10]��ģ�������[0x3F]
#define KEY_WAYBILL_MAX_WIDTH                   "WAYBILL_Max_Width"                 // �㷨�����ȣ�Ĭ��5472����Χ[0,65535]
#define KEY_WAYBILL_MAX_HEIGHT                  "WAYBILL_Max_Height"                // �㷨���߶ȣ�Ĭ��3648����Χ[0,65535]
#define KEY_WAYBILL_OUTPUTIMAGETYPE             "WAYBILL_OutputImageType"           // �浥��ͼ�����ͼƬ��ʽ��Ĭ��Jpg����Χ[1,3],1ΪMono8��2ΪJpg��3ΪBmp
#define KEY_WAYBILL_JPGQUALITY                  "WAYBILL_JpgQuality"                // jpg����������Ĭ��80����Χ[1,100]
#define KEY_WAYBILL_ENHANCEENABLE               "WAYBILL_EnhanceEnable"             // ͼ����ǿʹ�ܣ�Ĭ��0����Χ[0,1]

#define KEY_WAYBILL_MINWIDTH                    "WAYBILL_MinWidth"                  // waybill��С��, ���ǳ���, ���Ƕ̱ߣ�Ĭ��100����Χ[15,2592]
#define KEY_WAYBILL_MINHEIGHT                   "WAYBILL_MinHeight"                 // waybill��С�ߣ�Ĭ��100����Χ[10,2048]
#define KEY_WAYBILL_MAXWIDTH                    "WAYBILL_MaxWidth"                  // waybill����, ���ǳ���, ���Ƕ̱ߣ�Ĭ��3072����Сֵ15
#define KEY_WAYBILL_MAXHEIGHT                   "WAYBILL_MaxHeight"                 // waybill���ߣ�Ĭ��2048����Сֵ10
#define KEY_WAYBILL_MORPHTIMES                  "WAYBILL_MorphTimes"                // ���ʹ�����Ĭ��0����Χ[0,10]
#define KEY_WAYBILL_GRAYLOW                     "WAYBILL_GrayLow"                   // �浥��������ַ��Ҷ���Сֵ��Ĭ��0����Χ[0,255]
#define KEY_WAYBILL_GRAYMID                     "WAYBILL_GrayMid"                   // �浥�ϻҶ��м�ֵ��������������ͱ�����Ĭ��70����Χ[0,255]
#define KEY_WAYBILL_GRAYHIGH                    "WAYBILL_GrayHigh"                  // �浥�ϱ����Ҷ����ֵ��Ĭ��130����Χ[0,255]
#define KEY_WAYBILL_BINARYADAPTIVE              "WAYBILL_BinaryAdaptive"            // ����Ӧ��ֵ����Ĭ��1����Χ[0,1]
#define KEY_WAYBILL_BOUNDARYROW                 "WAYBILL_BoundaryRow"               // �浥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000]
#define KEY_WAYBILL_BOUNDARYCOL                 "WAYBILL_BoundaryCol"               // �浥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000]
#define KEY_WAYBILL_MAXBILLBARHEIGTHRATIO       "WAYBILL_MaxBillBarHightRatio"      // ����浥������߶ȱ�����Ĭ��20����Χ[1,100]
#define KEY_WAYBILL_MAXBILLBARWIDTHRATIO        "WAYBILL_MaxBillBarWidthRatio"      // ����浥��������ȱ�����Ĭ��5����Χ[1,100]
#define KEY_WAYBILL_MINBILLBARHEIGTHRATIO       "WAYBILL_MinBillBarHightRatio"      // ��С�浥������߶ȱ�����Ĭ��5����Χ[1,100]
#define KEY_WAYBILL_MINBILLBARWIDTHRATIO        "WAYBILL_MinBillBarWidthRatio"      // ��С�浥��������ȱ�����Ĭ��2����Χ[1,100]
#define KEY_WAYBILL_ENHANCEMETHOD               "WAYBILL_EnhanceMethod"             // ��ǿ��������Сֵ/Ĭ��ֵ/��������ǿ[0x1]����������[0x2]��ֱ��ͼ����[0x3]��ֱ��ͼ���⻯[0x4]������У��/���ֵ[0x5]
#define KEY_WAYBILL_ENHANCECLIPRATIOLOW         "WAYBILL_ClipRatioLow"              // ��ǿ�������ֵ������Ĭ��1����Χ[0,100]
#define KEY_WAYBILL_ENHANCECLIPRATIOHIGH        "WAYBILL_ClipRatioHigh"             // ��ǿ�������ֵ������Ĭ��99����Χ[0,100]
#define KEY_WAYBILL_ENHANCECONTRASTFACTOR       "WAYBILL_ContrastFactor"            // �Աȶ�ϵ����Ĭ��100����Χ[1,10000]
#define KEY_WAYBILL_ENHANCESHARPENFACTOR        "WAYBILL_SharpenFactor"             // ��ϵ����Ĭ��0����Χ[0,10000]
#define KEY_WAYBILL_SHARPENKERNELSIZE           "WAYBILL_KernelSize"                // ���˲��˴�С��Ĭ��3����Χ[3,15]
#define KEY_WAYBILL_CODEBOUNDARYROW             "WAYBILL_CodeBoundaryRow"           // �뵥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000]
#define KEY_WAYBILL_CODEBOUNDARYCOL             "WAYBILL_CodeBoundaryCol"           // �뵥��ͼ�з������ߣ�Ĭ��0����Χ[0,2000]


/************************************************************************/
/* ������ظ߼�����                                                      */
/************************************************************************/
// �������֧�ֵ��豸����
#define MV_CODEREADER_MAX_UPGARDEDEVICE_NUM     100

// �豸����״̬
enum MV_CODEREADER_PROGRAM_STATE
{
    MV_CODEREADER_PROGRAM_UNKNOWN,                      // δ֪״̬
    MV_CODEREADER_PROGRAM_RUNNING,                      // �豸��������
    MV_CODEREADER_PROGRAM_STOP                          // �豸ֹͣ����
};

// �豸��ǰ����״̬
typedef enum _MV_CODEREADER_DEVICE_CONNECT_STATUS_
{
    MV_CODEREADER_DEVICE_STATUS_FREE          = 1,      // ����״̬
    MV_CODEREADER_DEVICE_STATUS_BASE          = 2,      // ����������״̬

}MV_CODEREADER_DEVICE_CONNECT_STATUS;

//����/��������ģʽ
typedef enum _MV_CODEREADER_FIELD_CORRECT_MODE_
{
    MV_CODEREADER_DARK_FILED_CORRECT         = 0,       // ����У��
    MV_CODEREADER_BRIGHT_FILED_CORRECT       = 1,       // ����У��
    MV_CODEREADER_INVAILED_FILED_CORRECT     = 2,       // ��ЧУ��

}MV_CODEREADER_FIELD_CORRECT_MODE;

#endif /* _MV_CODEREADER_PARAMS_H_ */
