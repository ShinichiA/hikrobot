
#ifndef _MV_CODEREADER_ERROR_DEFINE_H_
#define _MV_CODEREADER_ERROR_DEFINE_H_

// ch:��ȷ�붨��
#define MV_CODEREADER_OK                                    0x00000000  ///< �ɹ����޴���

//ͨ�ô����붨��:��Χ0x80020000-0x800200FF
#define MV_CODEREADER_E_HANDLE                              0x80020000  ///< �������Ч�ľ��
#define MV_CODEREADER_E_SUPPORT                             0x80020001  ///< ��֧�ֵĹ���
#define MV_CODEREADER_E_BUFOVER                             0x80020002  ///< ��������
#define MV_CODEREADER_E_CALLORDER                           0x80020003  ///< ��������˳�����
#define MV_CODEREADER_E_PARAMETER                           0x80020004  ///< ����Ĳ���
#define MV_CODEREADER_E_RESOURCE                            0x80020005  ///< ��Դ����ʧ��
#define MV_CODEREADER_E_NODATA                              0x80020006  ///< ������
#define MV_CODEREADER_E_PRECONDITION                        0x80020007  ///< ǰ���������󣬻����л����ѷ����仯
#define MV_CODEREADER_E_VERSION                             0x80020008  ///< �汾��ƥ��
#define MV_CODEREADER_E_NOENOUGH_BUF                        0x80020009  ///< ������ڴ�ռ䲻��
#define MV_CODEREADER_E_ABNORMAL_IMAGE                      0x8002000A  ///< �쳣ͼ�񣬿����Ƕ�������ͼ������
#define MV_CODEREADER_E_LOAD_LIBRARY                        0x8002000B  ///< ��̬����DLLʧ��
#define MV_CODEREADER_E_NOOUTBUF                            0x8002000C  ///< û�п�����Ļ���
#define MV_CODEREADER_E_FILE_PATH                           0x8002000F  ///< �ļ�·������
#define MV_CODEREADER_E_UNKNOW                              0x800200FF  ///< δ֪�Ĵ���

// GenICamϵ�д���:��Χ0x80020100-0x800201FF
#define MV_CODEREADER_E_GC_GENERIC                          0x80020100  ///< ͨ�ô���
#define MV_CODEREADER_E_GC_ARGUMENT                         0x80020101  ///< �����Ƿ�
#define MV_CODEREADER_E_GC_RANGE                            0x80020102  ///< ֵ������Χ
#define MV_CODEREADER_E_GC_PROPERTY                         0x80020103  ///< ���Դ���
#define MV_CODEREADER_E_GC_RUNTIME                          0x80020104  ///< ���л���������
#define MV_CODEREADER_E_GC_LOGICAL                          0x80020105  ///< �߼�����
#define MV_CODEREADER_E_GC_ACCESS                           0x80020106  ///< �ڵ������������
#define MV_CODEREADER_E_GC_TIMEOUT                          0x80020107  ///< ��ʱ
#define MV_CODEREADER_E_GC_DYNAMICCAST                      0x80020108  ///< ת���쳣
#define MV_CODEREADER_E_GC_UNKNOW                           0x800201FF  ///< GenICamδ֪����

//GigE_STATUS��Ӧ�Ĵ�����:��Χ0x80020200-0x80020206
#define MV_CODEREADER_E_NOT_IMPLEMENTED                     0x80020200  ///< ������豸֧��
#define MV_CODEREADER_E_INVALID_ADDRESS                     0x80020201  ///< ���ʵ�Ŀ���ַ������
#define MV_CODEREADER_E_WRITE_PROTECT                       0x80020202  ///< Ŀ���ַ����д
#define MV_CODEREADER_E_ACCESS_DENIED                       0x80020203  ///< �豸�޷���Ȩ��
#define MV_CODEREADER_E_BUSY                                0x80020204  ///< �豸æ��������Ͽ�
#define MV_CODEREADER_E_PACKET                              0x80020205  ///< ��������ݴ���
#define MV_CODEREADER_E_NETER                               0x80020206  ///< ������ش���

// GigE������еĴ�����
#define MV_CODEREADER_E_IP_CONFLICT                         0x80020221  ///< �豸IP��ͻ

//USB_STATUS��Ӧ�Ĵ�����:��Χ0x80020300-0x800203FF
#define MV_CODEREADER_E_USB_READ                            0x80020300  ///< ��usb����
#define MV_CODEREADER_E_USB_WRITE                           0x80020301  ///< дusb����
#define MV_CODEREADER_E_USB_DEVICE                          0x80020302  ///< �豸�쳣
#define MV_CODEREADER_E_USB_GENICAM                         0x80020303  ///< GenICam��ش���
#define MV_CODEREADER_E_USB_BANDWIDTH                       0x80020304  ///< ������
#define MV_CODEREADER_E_USB_DRIVER                          0x80020305  ///< ������ƥ�����δװ����
#define MV_CODEREADER_E_USB_UNKNOW                          0x800203FF  ///< USBδ֪�Ĵ���

//����ʱ��Ӧ�Ĵ�����:��Χ0x80020400-0x800204FF
#define MV_CODEREADER_E_UPG_MIN_ERRCODE                     0x80020400  ///< ����ģ���������Сֵ
#define MV_CODEREADER_E_UPG_FILE_MISMATCH                   0x80020400  ///< �����̼���ƥ��
#define MV_CODEREADER_E_UPG_LANGUSGE_MISMATCH               0x80020401  ///< �����̼����Բ�ƥ��
#define MV_CODEREADER_E_UPG_CONFLICT                        0x80020402  ///< ������ͻ
#define MV_CODEREADER_E_UPG_INNER_ERR                       0x80020403  ///< ����ʱ����ڲ����ִ���

#define MV_CODEREADER_E_UPG_REGRESH_TYPE_ERR                0x80020404  ///< ��ȡ����ͺ�ʧ��
#define MV_CODEREADER_E_UPG_COPY_FPGABIN_ERR                0x80020405  ///< ����FPGA�ļ�ʧ��
#define MV_CODEREADER_E_UPG_ZIPEXTRACT_ERR                  0x80020406  ///< ZIP�ļ���ѹʧ��
#define MV_CODEREADER_E_UPG_DAVEXTRACT_ERR                  0x80020407  ///< DAV�ļ���ѹʧ��
#define MV_CODEREADER_E_UPG_DAVCOMPRESS_ERR                 0x80020408  ///< DAV�ļ�ѹ��ʧ��
#define MV_CODEREADER_E_UPG_ZIPCOMPRESS_ERR                 0x80020409  ///< ZIP�ļ�ѹ��ʧ��
#define MV_CODEREADER_E_UPG_GET_PROGRESS_TIMEOUT_ERR        0x80020410  ///< ��ȡ�������ȳ�ʱ
#define MV_CODEREADER_E_UPG_SEND_QUERY_PROGRESS_ERR         0x80020411  ///< ���ͽ��Ȳ�ѯָ��ʧ��
#define MV_CODEREADER_E_UPG_RECV_QUERY_PROGRESS_ERR         0x80020412  ///< ���ս��Ȳ�ѯָ��ʧ��
#define MV_CODEREADER_E_UPG_GET_QUERY_PROGRESS_ERR          0x80020413  ///< ��ȡ��ѯ����ʧ��
#define MV_CODEREADER_E_UPG_GET_MAX_QUERY_PROGRESS_ERR      0x80020414  ///< ���������ʧ��

#define MV_CODEREADER_E_UPG_CHECKT_PACKET_FAILED            0x80020465  ///< �ļ���֤ʧ��
#define MV_CODEREADER_E_UPG_FPGA_PROGRAM_FAILED             0x80020466  ///< FPGA��������ʧ��
#define MV_CODEREADER_E_UPG_WATCHDOG_FAILED                 0x80020467  ///< ���Ź�����ʧ��
#define MV_CODEREADER_E_UPG_CAMERA_AND_BARE_FAILED          0x80020468  ///< ���������ʧ��
#define MV_CODEREADER_E_UPG_RETAIN_CONFIG_FAILED            0x80020469  ///< ���������ļ�ʧ��
#define MV_CODEREADER_E_UPG_FPGA_DRIVER_FAILED              0x8002046A  ///< FPGA��������ʧ��
#define MV_CODEREADER_E_UPG_SPI_DRIVER_FAILED               0x8002046B  ///< SPI��������ʧ��
#define MV_CODEREADER_E_UPG_REBOOT_SYSTEM_FAILED            0x8002046C  ///< ��������ʧ��
#define MV_CODEREADER_E_UPG_UPSELF_FAILED                   0x8002046D  ///< ������������ʧ��
#define MV_CODEREADER_E_UPG_STOP_RELATION_PROGRAM_FAILED    0x8002046E  ///< ֹͣ��ط���ʧ��
#define MV_CODEREADER_E_UPG_DEVCIE_TYPE_INCONSISTENT        0x8002046F  ///< �豸���Ͳ�һ��
#define MV_CODEREADER_E_UPG_READ_ENCRYPT_INFO_FAILED        0x80020470  ///< ��ȡ������Ϣʧ��
#define MV_CODEREADER_E_UPG_PLAT_TYPE_INCONSISTENT          0x80020471  ///< �豸ƽ̨����
#define MV_CODEREADER_E_UPG_CAMERA_TYPE_INCONSISTENT        0x80020472  ///< ����ͺŴ���
#define MV_CODEREADER_E_UPG_DEVICE_UPGRADING                0x80020473  ///< �����������
#define MV_CODEREADER_E_UPG_UNZIP_FAILED                    0x80020474  ///< ��������ѹʧ��
#define MV_CODEREADER_E_UPG_UNKNOW                          0x800204FF  ///< ����ʱδ֪����

//���������Ӧ�Ĵ�����:��Χ0x80020500-0x800205FF
#define MV_CODEREADER_E_CREAT_SOCKET                        0x80020500  ///< ����Socket����
#define MV_CODEREADER_E_BIND_SOCKET                         0x80020501  ///< �󶨴���
#define MV_CODEREADER_E_CONNECT_SOCKET                      0x80020502  ///< ���Ӵ���
#define MV_CODEREADER_E_GET_HOSTNAME                        0x80020503  ///< ��ȡ����������
#define MV_CODEREADER_E_NET_WRITE                           0x80020504  ///< д�����ݴ���
#define MV_CODEREADER_E_NET_READ                            0x80020505  ///< ��ȡ���ݴ���
#define MV_CODEREADER_E_NET_SELECT                          0x80020506  ///< Select����
#define MV_CODEREADER_E_NET_TIMEOUT                         0x80020507  ///< ��ʱ
#define MV_CODEREADER_E_NET_ACCEPT                          0x80020508  ///< ���մ���
#define MV_CODEREADER_E_NET_UNKNOW                          0x800205FF  ///< ����δ֪����

#endif //_MV_CODEREADER_ERROR_DEFINE_H_
