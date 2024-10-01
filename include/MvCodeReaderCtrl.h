
#ifndef _MV_CODEREADER_CTRL_H_
#define _MV_CODEREADER_CTRL_H_

#include "MvCodeReaderErrorDefine.h"
#include "MvCodeReaderParams.h"

/**
*  @brief  ��̬�⵼�뵼������
*  @brief  Import and export definition of the dynamic library 
*/
#ifndef MV_CODEREADERCTRL_API

    #if (defined (_WIN32) || defined(WIN64))
        #if defined(MV_CODEREADERCTRL_EXPORTS)
            #define MV_CODEREADERCTRL_API __declspec(dllexport)
        #else
            #define MV_CODEREADERCTRL_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif

        #ifndef MV_CODEREADERCTRL_API
            #define  MV_CODEREADERCTRL_API
        #endif
    #endif

#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifdef __cplusplus
extern "C" {
#endif 

/************************************************************************/
/* ����Ļ���ָ��Ͳ���                                                 */
/* Camera basic instructions and operations                             */
/************************************************************************/
/************************************************************************
 *  @fn     MV_CODEREADER_GetSDKVersion()
 *  @brief  ��ȡSDK�汾��
 *  @param  
 *  @return ʼ�շ���4�ֽڰ汾�� |��    |��    |����  |  ����|
                                    8bits  8bits  8bits  8bits 
 
 *  @fn     MV_CODEREADER_GetSDKVersion()
 *  @brief  Get SDK Version
 *  @param  
 *  @return Always return 4 Bytes of version number |Main    |Sub    |Rev  |  Test|
                                                     8bits  8bits  8bits  8bits 
 ************************************************************************/
MV_CODEREADERCTRL_API unsigned int __stdcall MV_CODEREADER_GetSDKVersion();

/************************************************************************
 *  @fn     MV_CODEREADER_EnumDevices()
 *  @brief  ö���豸 
 *  @param  nTLayerType            [IN]           ö�ٴ����
 *  @param  pstDevList             [IN][OUT]      �豸�б�
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_EnumDevices()
 *  @brief  Enumerate Device(support virtual camera)
 *  @param  nTLayerType            [IN]           Enumerate TLs
 *  @param  pstDevList             [IN][OUT]      Device List
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code 
 ************************************************************************/
#ifndef __cplusplus
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_EnumDevices(IN OUT MV_CODEREADER_DEVICE_INFO_LIST* pstDevList, IN unsigned int nTLayerType);
#else
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_EnumDevices(IN OUT MV_CODEREADER_DEVICE_INFO_LIST* pstDevList, IN unsigned int nTLayerType = MV_CODEREADER_GIGE_DEVICE);
#endif

/************************************************************************
 *  @fn     MV_CODEREADER_EnumCodeReader()
 *  @brief  ö��ָ��ϵ���豸 
 *  @param  pstDevList             [IN][OUT]          �豸�б�
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_EnumCodeReader()
 *  @brief  Enumerate Specified Series Device
 *  @param  pstDevList             [IN][OUT]          Device List
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code 
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_EnumCodeReader(IN OUT MV_CODEREADER_DEVICE_INFO_LIST* pstDevList);

/************************************************************************
 *  @fn     MV_CODEREADER_IsDeviceAccessible()
 *  @brief  �豸�Ƿ�ɴ�
 *  @param  pstDevInfo             [IN]           �豸��Ϣ�ṹ��
 *  @param  nAccessMode            [IN]           ����Ȩ��
 *  @return �ɴ����true�����ɴ����false 
 
 *  @fn     MV_CODEREADER_IsDeviceAccessible()
 *  @brief  Is the device accessible
 *  @param  pstDevInfo             [IN]           Device Information Structure
 *  @param  nAccessMode            [IN]           Access Right
 *  @return Access, return true. Not access, return false
 ************************************************************************/
MV_CODEREADERCTRL_API bool __stdcall MV_CODEREADER_IsDeviceAccessible(IN MV_CODEREADER_DEVICE_INFO* pstDevInfo, IN unsigned int nAccessMode);

/************************************************************************
 *  @fn     MV_CODEREADER_CreateHandle()
 *  @brief  �����豸���
 *  @param  handle                 [IN][OUT]      �����ַ
 *  @param  pstDevInfo             [IN]           �豸��Ϣ�ṹ��
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_CreateHandle()
 *  @brief  Create Device Handle
 *  @param  handle                 [IN][OUT]      Handle Address
 *  @param  pstDevInfo             [IN]           Device Information Structure
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_CreateHandle(IN OUT void ** handle, IN const MV_CODEREADER_DEVICE_INFO* pstDevInfo);

/************************************************************************
 *  @fn     MV_CODEREADER_CreateHandleBySerialNumber()
 *  @brief  �����豸���
 *  @param  handle                 [IN][OUT]      �����ַ
 *  @param  chSerialNumber         [IN]           �豸���к�
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_CreateHandleBySerialNumber()
 *  @brief  Create Device Handle
 *  @param  handle                 [IN][OUT]      Handle Address
 *  @param  chSerialNumber         [IN]           Device SerialNumber
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_CreateHandleBySerialNumber(IN OUT void ** handle, IN const char* chSerialNumber);

/************************************************************************
 *  @fn     MV_CODEREADER_DestroyHandle()
 *  @brief  �����豸���
 *  @param  handle                 [IN]          ���
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_DestroyHandle()
 *  @brief  Destroy Device Handle
 *  @param  handle                 [IN]          Handle
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_DestroyHandle(IN void * handle);

/************************************************************************
 *  @fn     MV_CODEREADER_OpenDevice()
 *  @brief  ���豸 
 *  @param  handle                 [IN]          ���
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_OpenDevice()
 *  @brief  Open Device
 *  @param  handle                 [IN]          Handle
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_OpenDevice(IN void* handle);

/***********************************************************************
 *  @fn         MV_CODEREADER_CloseDevice()
 *  @brief      �ر���� 
 *  @param       handle                 [IN]          ���
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_CloseDevice()
 *  @brief      Close Device
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_CloseDevice(IN void* handle);

/***********************************************************************
 *  @fn         MV_CODEREADER_RegisterImageCallBack()
 *  @brief      ע��ͼ�����ݻص� 
 *  @param       handle                 [IN]          ���
 *  @param       cbOutput               [IN][OUT]     �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_RegisterImageCallBack()
 *  @brief      register image data callback 
                The virtual camera RAW mode does not support.
 *  @param       handle                 [IN]          Handle
 *  @param       cbOutput               [IN][OUT]     Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_RegisterImageCallBack(IN void* handle, 
                                                         void(__stdcall* cbOutput)(unsigned char * pData, MV_CODEREADER_IMAGE_OUT_INFO* pstFrameInfo, void* pUser),
                                                         void* pUser);

/***********************************************************************
 *  @fn         MV_CODEREADER_RegisterImageCallBackEx()
 *  @brief      ע��ͼ�����ݻص�
 *  @param       handle                 [IN]          ���
 *  @param       cbOutput               [IN]          �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_RegisterImageCallBackEx()
 *  @brief      register image data callback 
                The virtual camera RAW mode does not support.
 *  @param       handle                 [IN]          Handle
 *  @param       cbOutput               [IN]          Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_RegisterImageCallBackEx(IN void* handle, 
                                                                        void(__stdcall* cbOutput)(unsigned char * pData, MV_CODEREADER_IMAGE_OUT_INFO_EX* pstFrameInfo, void* pUser),
                                                                        void* pUser);

/***********************************************************************
 *  @fn         MV_CODEREADER_RegisterImageCallBackEx2()
 *  @brief      ע��ͼ������(���ݰ�����ά����������)�ص� 
 *  @remark     �ýӿ�֧��ID5000ϵ�ж�������ȡ��ά��������Ϣ�������޶�ά���������ܵ����������������ά��������ϢΪ0
 *  @param       handle                 [IN]          ���
 *  @param       cbOutput               [IN][OUT]     �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_RegisterImageCallBackEx2()
 *  @brief      register image data(Include QR quality info) callback
 *  @param       handle                 [IN]          Handle
 *  @param       cbOutput               [IN][OUT]     Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_RegisterImageCallBackEx2(IN void* handle, 
                                                                        void(__stdcall* cbOutput)(unsigned char * pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstFrameInfo, void* pUser),
                                                                        void* pUser);

/***********************************************************************
 *  @fn         MV_CODEREADER_MSC_RegisterImageCallBack()
 *  @brief      ע��ָ��һ·��ͨ��ͼ������(���ݰ�����ά����������)�ص� 
 *  @remark     �ýӿ�������ע��ͼ��ص��ӿڴ��ڻ����ϵ�����ȡͼ����ؽӿڴ��ڻ����ϵ
 *  @remark     �ýӿ�֧��IDXϵ�����ܶ�������·ͨ��ͬʱ��ѯָ����ͬ��ͨ���ţ�0/1�����ָ��ͨ��ͼ����Ϣ��ԭ��ͨ���̼���ͨ���Ų���Ĭ��Ϊ0
 *  @remark     �ýӿ�֧��ID5000ϵ�����ܶ�������ȡ��ά��������Ϣ�������޶�ά���������ܵ����������������ά��������ϢΪ0
 *  @remark     �ýӿ���ֹͣ/ȡ��ע��ָ��·��ͨ���ص�ʱ����cbOutput������ΪNULL���ɡ�
 *  @param       handle                 [IN]          ���
 *  @param       nChannelID             [IN]          ��ͨ���ţ���ͨ���̼�ͨ����Ϊ0, ��ͨ���̼�ͨ����Ϊ0/1(���ݶ�ͨ��sensor����)��
 *  @param       cbOutput               [IN]          �ص�����ָ��
 *  @param       pUser                  [IN]          �û��Զ������
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_MSC_RegisterImageCallBack()
 *  @brief      register image data(Include QR quality info) callback 
 *  @param       handle                 [IN]          Handle
 *  @param       nChannelID             [IN]          Stream Channel ID(one sensor is 0, Multichannel is 0/1(follow sensor num))
 *  @param       cbOutput               [IN]          Callback function pointer
 *  @param       pUser                  [IN]          User defined variable
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_MSC_RegisterImageCallBack(IN void* handle, unsigned int nChannelID, 
                                                                        void(__stdcall* cbOutput)(unsigned char * pData, MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstFrameInfo, void* pUser),
                                                                        void* pUser);

/***********************************************************************
 *  @fn         MV_CODEREADER_StartGrabbing()
 *  @brief      ��ʼȡ�� 
 *  @param       handle                 [IN]          ���
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_StartGrabbing()
 *  @brief      Start Grabbing 
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_StartGrabbing(IN void* handle);

/***********************************************************************
 *  @fn         MV_CODEREADER_StopGrabbing()
 *  @brief      ֹͣȡ�� 
 *  @param       handle                 [IN]          ���
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_StopGrabbing()
 *  @brief      Stop Grabbing 
 *  @param      handle                 [IN]          Handle
 *  @return     Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_StopGrabbing(IN void* handle);

/***********************************************************************
 *  @fn         MV_CODEREADER_GetOneFrameTimeout()
 *  @brief      ���ó�ʱ���ƻ�ȡһ֡ͼƬ��SDK�ڲ��ȴ�ֱ��������ʱ���� 
 *  @param       handle                 [IN]          ���
 *  @param       pData                  [OUT]         ͼ�����ݽ���ָ��
 *  @param       pstFrameInfo           [OUT]         ͼ����Ϣ�ṹ��
 *  @param       nMsec                  [IN]          �ȴ���ʱʱ��, �Ժ���Ϊ��λ
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_GetOneFrameTimeout()
 *  @brief      Timeout mechanism is used to get image, and the SDK waits inside until the data is returned 
 *  @param       handle                 [IN]          Handle
 *  @param       pData                  [OUT]         Recevied image data pointer
 *  @param       pstFrameInfo           [OUT]         Image information structure
 *  @param       nMsec                  [IN]          Waiting timeout, speed in milliseconds
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetOneFrameTimeout(IN void* handle, IN OUT unsigned char ** pData, IN OUT MV_CODEREADER_IMAGE_OUT_INFO* pstFrameInfo, IN unsigned int nMsec);

/***********************************************************************
 *  @fn         MV_CODEREADER_GetOneFrameTimeoutEx()
 *  @brief      ���ó�ʱ���ƻ�ȡһ֡ͼƬ��SDK�ڲ��ȴ�ֱ��������ʱ����
 *  @param       handle                 [IN]          ���
 *  @param       pData                  [OUT]         ͼ�����ݽ���ָ��
 *  @param       pstFrameInfo           [OUT]         ͼ����Ϣ�ṹ��
 *  @param       nMsec                  [IN]          �ȴ���ʱʱ��, �Ժ���Ϊ��λ
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_GetOneFrameTimeoutEx()
 *  @brief      Timeout mechanism is used to get image, and the SDK waits inside until the data is returned 
 *  @param       handle                 [IN]          Handle
 *  @param       pData                  [OUT]         Recevied image data pointer
 *  @param       pstFrameInfo           [OUT]         Image information structure
 *  @param       nMsec                  [IN]          Waiting timeout, speed in milliseconds
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetOneFrameTimeoutEx(IN void* handle, IN OUT unsigned char ** pData, IN OUT MV_CODEREADER_IMAGE_OUT_INFO_EX* pstFrameInfo, IN unsigned int nMsec);

/***********************************************************************
 *  @fn         MV_CODEREADER_GetOneFrameTimeoutEx2()
 *  @brief      ���ó�ʱ���ƻ�ȡһ֡ͼƬ��SDK�ڲ��ȴ�ֱ��������ʱ����
 *  @remark     �ýӿ�֧��ID5000ϵ�ж�������ȡ��ά��������Ϣ�������޶�ά���������ܵ����������������ά��������ϢΪ0
 *  @param       handle                 [IN]          ���
 *  @param       pData                  [OUT]         ͼ�����ݽ���ָ��
 *  @param       pstFrameInfoEx         [OUT]         ͼ����Ϣ�ṹ��(������ά��������Ϣ)
 *  @param       nMsec                  [IN]          �ȴ���ʱʱ��, �Ժ���Ϊ��λ
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_GetOneFrameTimeoutEx2()
 *  @brief      Timeout mechanism is used to get image, and the SDK waits inside until the data is returned 
 *  @param       handle                 [IN]          Handle
 *  @param       pData                  [OUT]         Recevied image data(Include QR quality info) pointer
 *  @param       pstFrameInfoEx         [OUT]         Image information structure
 *  @param       nMsec                  [IN]          Waiting timeout, speed in milliseconds
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetOneFrameTimeoutEx2(IN void* handle, IN OUT unsigned char ** pData, IN OUT MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstFrameInfo, IN unsigned int nMsec);

/***********************************************************************
 *  @fn         MV_CODEREADER_MSC_GetOneFrameTimeout()
 *  @brief      ���ó�ʱ���ƻ�ȡһ·��ͨ��һ֡ͼƬ��SDK�ڲ��ȴ�ֱ��������ʱ����
 *  @remark     �ýӿ�֧��IDXϵ�����ܶ�������·ͨ��ͬʱ��ѯָ����ͬ��ͨ���ţ�0/1�����ָ��ͨ��ͼ����Ϣ��ԭ��ͨ���̼���ͨ���Ų���Ĭ��Ϊ0
 *  @remark     �ýӿ�֧��ID5000ϵ�����ܶ�������ȡ��ά��������Ϣ�������޶�ά���������ܵ����������������ά��������ϢΪ0
 *  @param       handle                 [IN]          ���
 *  @param       pData                  [OUT]         ͼ�����ݽ���ָ��
 *  @param       pstFrameInfo           [OUT]         ͼ����Ϣ�ṹ��(������ά��������Ϣ)
 *  @param       nChannelID             [IN]          ��ͨ��ID����ͨ���̼�ͨ����Ϊ0, ��ͨ���̼�ͨ����Ϊ0/1(���ݶ�ͨ��sensor����)��
 *  @param       nMsec                  [IN]          �ȴ���ʱʱ��, �Ժ���Ϊ��λ
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش�����
 
 *  @fn         MV_CODEREADER_MSC_GetOneFrameTimeout()
 *  @brief      Timeout mechanism is used to get image, and the SDK waits inside until the data is returned 
 *  @param       handle                 [IN]          Handle
 *  @param       pData                  [OUT]         Recevied image data pointer
 *  @param       pstFrameInfo           [OUT]         Image information structure(Include QR code quality Info)
 *  @param       nChannelID             [IN]          Stream Channel ID(one sensor is 0, Multichannel is 0/1(follow sensor num))
 *  @param       nMsec                  [IN]          Waiting timeout, speed in milliseconds
 *  @return      Success, return MV_CODEREADER_OK. Failure, return error code
 ***********************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_MSC_GetOneFrameTimeout(IN void* handle, IN OUT unsigned char **pData,
                                                                           IN OUT MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstFrameInfo,
                                                                           IN unsigned int nChannelID, unsigned int nMsec);

/************************************************************************
 *  @fn     MV_CODEREADER_GetDeviceInfo()
 *  @brief  ��ȡ�豸��Ϣ
 *  @param  void* handle                     [IN]        ������
 *  @param  pstDevInfo                       [IN][OUT]   ���ظ��������й�����豸��Ϣ�ṹ��ָ��
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_GetDeviceInfo()
 *  @brief  Get device information 
 *  @param  void* handle                     [IN]        Handle
 *  @param  pstDevInfo                       [IN][OUT]   Structure pointer of device information
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetDeviceInfo(IN void * handle, IN OUT MV_CODEREADER_DEVICE_INFO* pstDevInfo);

/************************************************************************/
/* ���úͻ�ȡ������������ܽӿ�                                         */
/* General interface for getting and setting camera parameters          */
/************************************************************************/
/************************************************************************
 *  @fn     MV_CODEREADER_GetIntValue()
 *  @brief  ��ȡInteger����ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ�����ȡ�����Ϣ��Ϊ"Width"
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_GetIntValue()
 *  @brief  Get Integer value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value, for example, using "Width" to get width
 *  @param  MVCC_INTVALUE* pstValue     [IN][OUT]   Structure pointer of camera features
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetIntValue(IN void* handle,IN const char* strKey,IN OUT MV_CODEREADER_INTVALUE_EX *pIntValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetIntValue()
 *  @brief  ����Integer������ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ�����ȡ�����Ϣ��Ϊ"Width"
 *          const unsigned int nValue   [IN]        ��Ҫ���õ����������ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetIntValue()
 *  @brief  Set Integer value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value, for example, using "Width" to set width
 *          const unsigned int nValue   [IN]        Feature value to set
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetIntValue(IN void* handle,IN const char* strKey,IN int64_t nValue);

/************************************************************************
 *  @fn     MV_CODEREADER_GetEnumValue()
 *  @brief  ��ȡEnum����ֵ
 *  @param  void* handle                   [IN]        ������
 *  @param  char* strKey                   [IN]        ���Լ�ֵ�����ȡ���ظ�ʽ��Ϣ��Ϊ"PixelFormat"
 *  @param  MVCC_ENUMVALUE* pEnumValue     [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_GetEnumValue()
 *  @brief  Get Enum value
 *  @param  void* handle                   [IN]        Handle
 *  @param  char* strKey                   [IN]        Key value, for example, using "PixelFormat" to get pixel format
 *  @param  MVCC_ENUMVALUE* pEnumValue     [IN][OUT]   Structure pointer of camera features
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetEnumValue(IN void* handle,IN const char* strKey, IN OUT MV_CODEREADER_ENUMVALUE *pEnumValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetEnumValue()
 *  @brief  ����Enum������ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ�����ȡ���ظ�ʽ��Ϣ��Ϊ"PixelFormat"
 *          const unsigned int nValue   [IN]        ��Ҫ���õ����������ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetEnumValue()
 *  @brief  Set Enum value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value, for example, using "PixelFormat" to set pixel format
 *          const unsigned int nValue   [IN]        Feature value to set
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetEnumValue(IN void* handle,IN const char* strKey,IN unsigned int nValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetEnumValueByString()
 *  @brief  ����Enum������ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ�����ȡ���ظ�ʽ��Ϣ��Ϊ"PixelFormat"
 *          char* sValue                [IN]        ��Ҫ���õ�����������ַ���
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetEnumValueByString()
 *  @brief  Set Enum value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value, for example, using "PixelFormat" to set pixel format
 *          char* sValue                [IN]        Feature String to set
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetEnumValueByString(IN void* handle,IN const char* strKey,IN const char* sValue);

/************************************************************************
 *  @fn     MV_CODEREADER_GetFloatValue()
 *  @brief  ��ȡFloat����ֵ
 *  @param  void* handle                     [IN]        ������
 *  @param  char* strKey                     [IN]        ���Լ�ֵ
 *  @param  MVCC_FLOATVALUE *pFloatValue     [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_GetFloatValue()
 *  @brief  Get Float value
 *  @param  void* handle                     [IN]        Handle
 *  @param  char* strKey                     [IN]        Key value
 *  @param  MVCC_FLOATVALUE *pFloatValue     [IN][OUT]   Structure pointer of camera features
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetFloatValue(IN void* handle,IN const char* strKey, IN OUT MV_CODEREADER_FLOATVALUE *pFloatValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetFloatValue()
 *  @brief  ����Enum������ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ
 *          float fValue                [IN]        ��Ҫ���õ����������ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetFloatValue()
 *  @brief  Set Enum value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value
 *          float fValue                [IN]        Feature value to set
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetFloatValue(IN void* handle,IN const char* strKey,IN float fValue);
    
/************************************************************************
 *  @fn     MV_CODEREADER_GetBoolValue()
 *  @brief  ��ȡBoolean����ֵ
 *  @param  void* handle                     [IN]        ������
 *  @param  char* strKey                     [IN]        ���Լ�ֵ
 *  @param  bool *pBoolValue                 [IN][OUT]   ���ظ��������й��������ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_GetBoolValue()
 *  @brief  Get Boolean value
 *  @param  void* handle                     [IN]        Handle
 *  @param  char* strKey                     [IN]        Key value
 *  @param  bool *pBoolValue                 [IN][OUT]   Structure pointer of camera features
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetBoolValue(IN void* handle,IN const char* strKey,IN OUT bool *pBoolValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetBoolValue()
 *  @brief  ����Boolean������ֵ
 *  @param  void* handle                [IN]        ������
 *  @param  char* strKey                [IN]        ���Լ�ֵ
 *          bool bValue                 [IN]        ��Ҫ���õ����������ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetBoolValue()
 *  @brief  Set Boolean value
 *  @param  void* handle                [IN]        Handle
 *  @param  char* strKey                [IN]        Key value
 *          bool bValue                 [IN]        Feature value to set
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetBoolValue(IN void* handle,IN const char* strKey,IN bool bValue);

/************************************************************************
 *  @fn     MV_CODEREADER_GetStringValue()
 *  @brief  ��ȡString����ֵ
 *  @param  void* handle                       [IN]        ������
 *  @param  char* strKey                       [IN]        ���Լ�ֵ
 *  @param  MVCC_STRINGVALUE *pStringValue     [IN][OUT]   ���ظ��������й�������Խṹ��ָ��
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_GetStringValue()
 *  @brief  Get String value
 *  @param  void* handle                       [IN]        Handle
 *  @param  char* strKey                       [IN]        Key value
 *  @param  MVCC_STRINGVALUE *pStringValue     [IN][OUT]   Structure pointer of camera features
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetStringValue(IN void* handle,IN const char* strKey, IN OUT MV_CODEREADER_STRINGVALUE *pStringValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetStringValue()
 *  @brief  ����String������ֵ
 *  @param  void* handle                  [IN]        ������
 *  @param  char* strKey                  [IN]        ���Լ�ֵ
 *          char * sValue                 [IN]        ��Ҫ���õ����������ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetStringValue()
 *  @brief  Set String value
 *  @param  void* handle                  [IN]        Handle
 *  @param  char* strKey                  [IN]        Key value
 *          char * sValue                 [IN]        Feature value to set
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetStringValue(IN void* handle,IN const char* strKey,IN const char * sValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SetCommandValue()
 *  @brief  ����Command������ֵ
 *  @param  void* handle                  [IN]        ������
 *  @param  char* strKey                  [IN]        ���Լ�ֵ
 *  @return �ɹ�,����MV_CODEREADER_OK,ʧ��,���ش�����
 
 *  @fn     MV_CODEREADER_SetCommandValue()
 *  @brief  Set Command value
 *  @param  void* handle                  [IN]        Handle
 *  @param  char* strKey                  [IN]        Key value
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetCommandValue(IN void* handle,IN const char* strKey);

/************************************************************************
 *  @fn     MV_CODEREADER_GetOptimalPacketSize()
 *  @brief  ��ȡ��ѵ�packet size���ýӿ�Ŀǰֻ֧��GigE���
 *  @param  void* handle                  [IN]        ������
 *  @return ���packetsize
 
 *  @fn     MV_CODEREADER_GetOptimalPacketSize()
 *  @brief  Get the optimal Packet Size, Only support GigE Camera
 *  @param  void* handle                  [IN]        Camera handle
 *  @return Optimal packetsize
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetOptimalPacketSize(IN void* handle);

/************************************************************************
 *  @fn     MV_CODEREADER_ReadMemory()
 *  @brief  ���ڴ�
 *  @param  handle���豸���
 *  @param  pBuffer����Ϊ����ֵʹ�ã�����������ڴ�ֵ���ڴ�ֵ�ǰ��մ��ģʽ�洢�ģ�
 *  @param  nAddress������ȡ���ڴ��ַ���õ�ַ���Դ��豸��Camera.xml�ļ��л�ȡ������xxx_RegAddr��xml�ڵ�ֵ
                  ���豸��Camera.xml�ļ������豸��֮���Զ�������Ӧ�ó���ĵ�ǰĿ¼�У�
 *  @param  nLength������ȡ���ڴ泤��
 *  @return �����ش�����
 
 *  @fn     MV_CODEREADER_ReadMemory()
 *  @brief  Read Memory
 *  @param  handle: Device Handle
 *  @param  pBuffer: Used as a return value, save the read-in memory value ( Memory value is stored in accordance with the big end model)
 *  @param  nAddress: Memory address to be read, which can be obtained from the Camera.xml file of the device, the form xml node value of xxx_RegAddr
                     (Camera.xml file of device is automatically generated in the application's current directory after the device is opened)
 *  @param  nLength: Length of the memory to be read
 *  @return Refer to the return error code
*************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_ReadMemory(IN void* handle , IN OUT void *pBuffer, IN int64_t nAddress, IN int64_t nLength);

/************************************************************************
 *  @fn     MV_CODEREADER_WriteMemory()
 *  @brief  д�ڴ�
 *  @param  handle���豸���
 *  @param  pBuffer����д����ڴ�ֵ��ע���ڴ�ֵҪ���մ��ģʽ�洢��
 *  @param  nAddress����д����ڴ��ַ���õ�ַ���Դ��豸��Camera.xml�ļ��л�ȡ������xxx_RegAddr��xml�ڵ�ֵ
                  ���豸��Camera.xml�ļ������豸��֮���Զ�������Ӧ�ó���ĵ�ǰĿ¼�У�
 *  @param  nLength����д����ڴ泤��
 *  @return �����ش�����
 
 *  @fn     MV_CODEREADER_WriteMemory()
 *  @brief  Write Memory
 *  @param  handle: Device Handle
 *  @param  pBuffer: Memory value to be written ( Note the memory value to be stored in accordance with the big end model)
 *  @param  nAddress: Memory address to be written, which can be obtained from the Camera.xml file of the device, the form xml node value of xxx_RegAddr
                     (Camera.xml file of device is automatically generated in the application's current directory after the device is opened)
 *  @param  nLength: Length of the memory to be written
 *  @return Refer to the return error code
************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_WriteMemory(IN void* handle , IN const void *pBuffer, IN int64_t nAddress, IN int64_t nLength);

// ע���쳣��Ϣ�ص����ڴ��豸֮�����
// Register exception message callback, call after open device
/************************************************************************
 *  @fn     MV_CODEREADER_RegisterExceptionCallBack()
 *  @brief  ע���쳣��Ϣ�ص����ڴ��豸֮�����
 *  @param  handle���豸���
 *  @param  cbException       [IN]      �쳣�ص�����ָ��
 *  @param  pUser             [IN]      �û��Զ������
 *  @return �����ش�����
 
 *  @fn     MV_CODEREADER_RegisterExceptionCallBack()
 *  @brief  Register Exception Message CallBack, call after open device
 *  @param  handle: Device handle
 *  @param  cbException       [IN]       Exception Message CallBack Function Pointer
 *  @param  pUser             [IN]       User defined variable
 *  @return Refer to error code
************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_RegisterExceptionCallBack(IN void* handle, 
                                                             void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                                             void* pUser);

/************************************************************************
 *  @fn     MV_CODEREADER_RegisterAllEventCallBack()
 *  @brief  ע��ȫ���¼��ص����ڴ��豸֮�����(�ýӿ���Ҫ�̼�֧��)
 *  @remark ֧�ֽڵ�ArithmeticModel��BillCombineEnable�����øýӿں󣬶Խڵ���ֵ���б�����¼��ص������¼�����
 *  @param  handle                      [IN]            �豸���
 *  @param  cbEvent                     [IN][OUT]       �¼��ص�����ָ��
 *  @param  pUser                       [IN]            �û��Զ������
 *  @return �����ش�����
 
 *  @fn     MV_CODEREADER_RegisterAllEventCallBack()
 *  @brief  Register all event callback, which is called after the device is opened(the API need device support)
 *  @remark Support node ArithmeticModel��BillCombineEnable, after event callback, change the node number, 
            the pEventInfo will have data
 *  @param  handle                      [IN]            Device handle
 *  @param  cbEvent                     [IN][OUT]       Event CallBack Function Pointer
 *  @param  pUser                       [IN]            User defined variable
 *  @return Refer to error code
************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_RegisterAllEventCallBack(void* handle,
                                                                           void(__stdcall* cbAllEvent)(MV_CODEREADER_EVENT_OUT_INFO* pEventInfo, void* pUser),
                                                                           void* pUser);

/************************************************************************
 *  @fn     MV_CODEREADER_GIGE_ForceIp()
 *  @brief  ǿ��IP����
 *  @remark �ýӿ�Ϊ�������SIϵ�����ܶ���������֧��������������������쳣ֵ����
            ֻ֧������IP���󱨴�ip����Ϊ0������ΪDHCP�Զ���ȡip��ģʽ��������
 *  @param  handle���豸���
 *  @param  nIP               [IN]      ���õ�IP
 *  @param  nSubNetMask       [IN]      ��������
 *  @param  nDefaultGateWay   [IN]      Ĭ������
 *  @return �����ش�����
 
 *  @fn     MV_CODEREADER_GIGE_ForceIp()
 *  @brief  Force IP 
 *  @remark The interface for the adapter is compatible with SI series intelligent reading code, 
            does not support setting the correct subnet mask and gateway outlier; Only allows you to 
            set the IP error an error, the IP is set to 0 will automatically get configured for DHCP IP mode, is not an error.
 *  @param  handle: Device handle
 *  @param  nIP               [IN]      IP to set
 *  @param  nSubNetMask       [IN]      Subnet mask
 *  @param  nDefaultGateWay   [IN]      Default gateway
 *  @return Refer to error code
************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GIGE_ForceIp(IN void* handle, IN unsigned int nIP, IN unsigned int nSubNetMask, IN unsigned int nDefaultGateWay);

/************************************************************************
 *  @fn     MV_CODEREADER_GIGE_SetIpConfig
 *  @brief  ����IP��ʽ
 *  @remark SIϵ�����ܶ�������֧��ͨ���ýӿ�����IP��������, SIϵ��������STATIC��ֱ�ӷ���OK��
            ����DHCP�����MV_CODEREADER_GIGE_ForceIp()�ӿڵ�nIP����Ϊ0������LLA�򷵻ز�֧��
 *  @param  handle                      [IN]            �豸���
 *  @param  nType                       [IN]            IP���ͣ���MV_IP_CFG_x
 *  @return �����ش�����
 
 *  @fn     MV_CODEREADER_GIGE_SetIpConfig
 *  @brief  IP configuration method 
 *  @remark SI series intelligent reading code device does not support through the interface set IP configuration type, 
            if SI series set STATIC returned directly OK;Set the LLA returns does not support.
            if need DHCP call MV_CODEREADER_GIGE_ForceIp () the nIP of the interface is set to 0.
 *  @param  handle                      [IN]            Device handle
 *  @param  nType                       [IN]            IP type, refer to MV_IP_CFG_x
 *  @return Refer to error code
************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GIGE_SetIpConfig(IN void* handle, IN unsigned int nType);

/************************************************************************
 *  @fn     MV_CODEREADER_FileAccessRead()
 *  @brief  �������ȡ�ļ�
 *  @param  handle                [IN]           �����ַ
 *  @param  pstFileAccess         [IN]           �ļ���ȡ�ṹ��
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_FileAccessRead()
 *  @brief  Read the file from the camera 
 *  @param  handle                [IN]           Handle
 *  @param  pstFileAccess         [IN]           File access structure
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_FileAccessRead(IN void* handle, IN MV_CODEREADER_FILE_ACCESS * pstFileAccess);

/************************************************************************
 *  @fn     MV_CODEREADER_FileAccessWrite()
 *  @brief  ���ļ�д�����
 *  @param  handle                [IN]           �����ַ
 *  @param  pstFileAccess         [IN]           �ļ���ȡ�ṹ��
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_FileAccessWrite()
 *  @brief  Write the file to camera 
 *  @param  handle                [IN]           Handle
 *  @param  pstFileAccess         [IN]           File access structure
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_FileAccessWrite(IN void* handle, IN MV_CODEREADER_FILE_ACCESS * pstFileAccess);

/************************************************************************
 *  @fn     MV_CODEREADER_GetFileAccessProgress
 *  @brief  ��ȡ�ļ���ȡ�Ľ���
 *  @param  handle                      [IN]            �豸���
 *  @param  pstFileAccessProgress       [IN][OUT]       ��������
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� ����ǰ�ļ���ȡ��״̬��
 
 *  @fn     MV_CODEREADER_GetFileAccessProgress
 *  @brief  Get File Access Progress 
 *  @param  handle                      [IN]            Device handle
 *  @param  pstFileAccessProgress       [IN][OUT]       File access Progress
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetFileAccessProgress(IN void* handle, IN OUT MV_CODEREADER_FILE_ACCESS_PROGRESS * pstFileAccessProgress);

/************************************************************************/
/* ���úͻ�ȡ��ͼ�㷨�ӿ� (arm32/aarch64��ƽ̨δ֧��)                        */
/* General interface for getting and setting waybill parameters (armhf(32bit)/aarch64 does not support)*/
/************************************************************************/

/************************************************************************
 *  @fn     MV_CODEREADER_SetWayBillEnable()
 *  @brief  ���ÿ�ͼʹ��
 *  @remark �����������ͼʹ�ܽڵ�DisplayBillInfoEnable�����ɻ�ȡ��ͼ������Ϣ��ͬʱ�ýӿڲ�������True���ɻ�ȡ�浥ͼƬpImageWaybill��
 *  @param  handle                 [IN]          ���
 *  @param  bWaybillEnable         [IN]          ��ͼʹ��
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_SetWayBillEnable()
 *  @brief  Set WayBill Enable 
 *  @param  handle                 [IN]          Handle
 *  @param  bWaybillEnable         [IN]          WayBillEnable
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SetWayBillEnable(IN void* handle, IN bool bWaybillEnable);

/************************************************************************
 *  @fn     MV_CODEREADER_GetWayBillInfo()
 *  @brief  ��ȡ��ǰ����ͼ����浥��Ϣ������ͼ���Ӧ MV_CODEREADER_IMAGE_OUT_INFO_EX �ýṹ����Ϣ��
 *  @param  handle                 [IN]          ���
 *  @param  pData                  [IN]          ԭʼͼ��ָ��
 *  @param  pstFrameInfo           [IN][OUT]     ͼ����Ϣ�ṹ��
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_GetWayBillInfo()
 *  @brief  Get the WayBill Info of current input image 
 *  @param  handle                 [IN]          Handle
 *  @param  pData                  [IN]          Received image data pointer
 *  @param  pstFrameInfo           [IN][OUT]     Image information structure
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetWayBillInfo(IN void* handle, IN unsigned char* pData, IN OUT MV_CODEREADER_IMAGE_OUT_INFO_EX* pstFrameInfo);

/************************************************************************
 *  @fn     MV_CODEREADER_GetWayBillInfoEx()
 *  @brief  ��ȡ��ǰ����ͼ����浥��Ϣ������ͼ���Ӧ MV_CODEREADER_IMAGE_OUT_INFO_EX2 �ýṹ����Ϣ��
 *  @param  handle                 [IN]          ���
 *  @param  pData                  [IN]          ԭʼͼ��ָ��
 *  @param  pstFrameInfoEx         [IN][OUT]     ͼ����Ϣ�ṹ��
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_GetWayBillInfoEx()
 *  @brief  Get the WayBill Info of current input image 
 *  @param  handle                 [IN]          Handle
 *  @param  pData                  [IN]          Received image data pointer
 *  @param  pstFrameInfoEx         [IN][OUT]     Image information structure
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_GetWayBillInfoEx(IN void* handle, IN unsigned char* pData, IN OUT MV_CODEREADER_IMAGE_OUT_INFO_EX2* pstFrameInfo);

/************************************************************************
 *  @fn     MV_CODEREADER_Algorithm_SetIntValue()
 *  @brief  �������Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  nValue                 [IN]          ����ֵ
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_Algorithm_SetIntValue()
 *  @brief  Set Integer Value 
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  nValue                 [IN]          Value
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_Algorithm_SetIntValue(IN void* handle, IN const char* const strParamKeyName, IN const int nValue);

/************************************************************************
 *  @fn     MV_CODEREADER_Algorithm_GetIntValue()
 *  @brief  ��ȡ���Ͳ���
 *  @param  handle                 [IN]          ���
 *  @param  strParamKeyName        [IN]          ���Լ�ֵ
 *  @param  pnValue                [IN][OUT]     ����ֵ
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_Algorithm_GetIntValue()
 *  @brief  Get Integer Value 
 *  @param  handle                 [IN]          Handle
 *  @param  strParamKeyName        [IN]          Param KeyName
 *  @param  pnValue                [IN][OUT]     Value
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_Algorithm_GetIntValue(IN void* handle, IN const char* const strParamKeyName, IN OUT int* const pnValue);

/************************************************************************
 *  @fn     MV_CODEREADER_SaveImage()
 *  @brief  ����ͼƬ��֧��mono8��ʽתBmp��Jpeg.����������50-99֮��
 *  @param  pSaveParam             [IN][OUT]          ����ͼƬ�����ṹ��
                       pData;              [IN]     �������ݻ���
                       nDataLen;           [IN]     �������ݴ�С
                       enPixelType;        [IN]     �������ݵ����ظ�ʽ
                       nWidth;             [IN]     ͼ���
                       nHeight;            [IN]     ͼ���
                       pImageBuffer;       [OUT]    ���ͼƬ����
                       nImageLen;          [OUT]    ���ͼƬ��С
                       nBufferSize;        [IN]     �ṩ�������������С
                       enImageType;        [IN]     ���ͼƬ��ʽ
                       nJpgQuality;        [IN]     ��������, (50-99]
                       nReserved[4];
 *  @return �ɹ�������MV_CODEREADER_OK�����󣬷��ش����� 
 
 *  @fn     MV_CODEREADER_SaveImage()
 *  @brief  Save image, support Bmp and Jpeg. Encoding quality, (50-99] 
 *  @param  pSaveParam             [IN][OUT]           Save image parameters structure
                       pData;              [IN]     Input data buffer
                       nDataLen;           [IN]     Input data size
                       enPixelType;        [IN]     Pixel format of input data
                       nWidth;             [IN]     Image width
                       nHeight;            [IN]     Image height
                       pImageBuffer;       [OUT]    Output image buffer
                       nImageLen;          [OUT]    Output image size
                       nBufferSize;        [IN]     Output buffer size provided
                       enImageType;        [IN]     Output image format
                       nJpgQuality;        [IN]     Encoding quality, (50-99]
                       nReserved[4];
 *  @return Success, return MV_CODEREADER_OK. Failure, return error code
 ************************************************************************/
MV_CODEREADERCTRL_API int __stdcall MV_CODEREADER_SaveImage(IN void* handle, IN OUT MV_CODEREADER_SAVE_IMAGE_PARAM_EX* pSaveParam);

#ifdef __cplusplus
}
#endif 

#endif //_MV_CODEREADER_CTRL_H_