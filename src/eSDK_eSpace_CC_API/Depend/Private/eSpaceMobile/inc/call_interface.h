/** 
* @file call_def.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP ������ϵͳ����ҵ��ӿ�ͷ�ļ��� \n
*/


/**
*
*  @{
*/


#ifndef __CALL_INTERFACE_H__
#define __CALL_INTERFACE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


/*******************************************************************************
 *   ���ļ���Ҫ����������ͷ�ļ�
 *******************************************************************************/
#include "tup_def.h"
#include "call_def.h"


/**
 * @brief ��ʼ������ҵ�����
 * 
 * @param [in] TUP_VOID  
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��ʼ��ǰ��Ҫ������־������������־
 * @see tup_call_uninit
 * @see tup_call_log_start
 **/
TUP_API TUP_RESULT tup_call_init(TUP_VOID);


/**
 * @brief ȥ��ʼ������ҵ�����
 * 
 * @param [in] TUP_VOID  
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����˳�ǰ���ã�����ǰֹͣ���ҵ��
 * @see tup_call_init
 **/
TUP_API TUP_RESULT tup_call_uninit(TUP_VOID);


/**
 * @brief ע�����ҵ����֪ͨ�ص�����
 * 
 * @param [in] CALL_FN_CALLBACK_PTR callback_process_notify <b>:</b> ����ҵ���¼�֪ͨ�ص�������ַ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��ʼ���ɹ�����ã��ڲ��ᴴ��һ����Ӧ�Ĵ����̡߳�
 *            <br>������Ҫʵ�ֻص����������ص���Ϣ����ָ����������������ʹ�ã��������������ܻ��ͷţ����³������
 * @see tup_call_init
 **/
TUP_API TUP_RESULT tup_call_register_process_notifiy(CALL_FN_CALLBACK_PTR callback_process_notify);


/**
 * @brief ע����־�ص�����
 * 
 * @param [in] CALL_FN_DEBUG_CALLBACK_PTR callback_log   <b>:</b> �������Զ�����־������ַ
 * @retval TUP_API TUP_VOID
 * 
 * @attention �˺��������������ã���ΪԤ���ӿ�
 * @see tup_call_log_start
 **/
TUP_API TUP_VOID   tup_call_register_logfun(CALL_FN_DEBUG_CALLBACK_PTR callback_log);


/**
 * @brief SIP�˺�ע��
 * 
 * @param [in] const TUP_CHAR* number     <b>:</b> �û����룬��󳤶�32
 * @param [in] const TUP_CHAR* name       <b>:</b> �û�������󳤶�255
 * @param [in] const TUP_CHAR* password   <b>:</b> ���룬��󳤶�255
 * @retval TUP_API TUP_RESULT : �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ע��ǰ��Ҫ���ע���������
 * @see tup_call_deregister
 * @see tup_call_set_cfg
 **/
TUP_API TUP_RESULT tup_call_register(const TUP_CHAR* number, const TUP_CHAR* name, const TUP_CHAR* password);


/**
 * @brief SIP�˺�ע��
 * 
 * @param [in] const TUP_CHAR* number   <b>:</b> �û����룬��󳤶�32
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ӧ���û���ע��
 * @see tup_call_register
 **/
TUP_API TUP_RESULT tup_call_deregister(const TUP_CHAR* number);


/**
 * @brief ����һ·��ͨVOIP����
 * 
 * @param [out] TUP_UINT32 *callid             <b>:</b> ���е�id����ʶΨһ�ĺ���
 * @param [in] CALL_E_CALL_TYPE call_type      <b>:</b> ��������
 * @param [in] const TUP_CHAR* callee_number   <b>:</b> ���к��룬��󳤶�32
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_accept_call
 * @see tup_call_alerting_call
 * @see tup_call_end_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_start_call(TUP_UINT32 *callid,CALL_E_CALL_TYPE call_type,const TUP_CHAR* callee_number);


/**
 * @brief ����һ·����VOIP����
 * 
 * @param [out] TUP_UINT32 *callid             <b>:</b> ���е�id����ʶΨһ�ĺ���
 * @param [in] const TUP_CHAR* callee_number   <b>:</b> ���к��룬��󳤶�32
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��������ֻ֧����Ƶ����
 * @see tup_call_start_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_accept_call
 * @see tup_call_alerting_call
 * @see tup_call_end_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_anonymous_call(TUP_UINT32* callid, const TUP_CHAR* callee_number);


/**
 * @brief ����һ·ָ����ʽ��VOIP���У���CTD����
 * 
 * @param [in] CALL_S_CALL_PARAMS* call_params  <b>:</b> ���в���������ulCallIdΪ�������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_accept_call
 * @see tup_call_alerting_call
 * @see tup_call_end_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_start_call_ex(CALL_S_CALL_PARAMS* call_params);


/**
 * @brief ��������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_BOOL is_video  <b>:</b> �Ƿ������Ƶ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_alerting_call
 * @see tup_call_end_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_accept_call(TUP_UINT32 callid,TUP_BOOL is_video);


/**
 * @brief �����������û���ͨ����������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_alerting_call
 * @see tup_call_accept_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_end_call(TUP_UINT32 callid);


/**
 * @brief ֪ͨ�Է�������������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_end_call
 * @see tup_call_accept_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_alerting_call(TUP_UINT32 callid);


/**
 * @brief ��ȡ����״̬��Ϣ
 * 
 * @param [out] CALL_S_STREAM_INFO* state  <b>:</b> ����״̬��Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_get_channelinfo
 **/
TUP_API TUP_RESULT tup_call_get_callstatics(CALL_S_STREAM_INFO* state);


/**
 * @brief ��ͨ���з��Ͷ��β�����Ϣ
 * 
 * @param [in] TUP_UINT32 callid      <b>:</b> ����ID
 * @param [in] CALL_E_DTMF_TONE tone  <b>:</b> DTMF��Ϣֵ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ͨ���вſ��Է���
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_send_DTMF(TUP_UINT32 callid,CALL_E_DTMF_TONE tone);


/**
 * @brief ����ͨ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_end_call
 * @see tup_call_accept_call
 * @see tup_call_alerting_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_hold_call(TUP_UINT32 callid);


/**
 * @brief ȡ������ͨ��(�ָ�ͨ��)
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_start_call_bycallid_ex
 * @see tup_call_end_call
 * @see tup_call_accept_call
 * @see tup_call_alerting_call
 * @see tup_call_hold_call
 **/
TUP_API TUP_RESULT tup_call_unhold_call(TUP_UINT32 callid);


/**
 * @brief �������ƫת����
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] const TUP_CHAR* divert_number  <b>:</b> ƫתĿ�ĺ��룬��󳤶�32
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_divert_call(TUP_UINT32 callid,const TUP_CHAR* divert_number);


/**
 * @brief �������äת����
 * 
 * @param [in] TUP_UINT32 callid               <b>:</b> ����ID
 * @param [in] const TUP_CHAR* transto_number  <b>:</b> äתĿ�ĺ��룬��󳤶�32
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_consult_transfer
 **/
TUP_API TUP_RESULT tup_call_blind_transfer(TUP_UINT32 callid,const TUP_CHAR* transto_number);


/**
 * @brief ���������ѯת/����ѯת����
 * 
 * @param [in] TUP_UINT32 callid                <b>:</b> ������ת�Ƶĺ���ID
 * @param [in] const TUP_UINT32 transto_callid  <b>:</b> ����ת�Ƶ�Ŀ�ĺ���ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_blind_transfer
 **/
TUP_API TUP_RESULT tup_call_consult_transfer(TUP_UINT32 callid, const TUP_UINT32 transto_callid);


/**
 * @brief ������Ƶ����
 * 
 * @param [in] TUP_UINT32 count                    <b>:</b> ���ڸ�����һ��Ϊ2
 * @param [in] const CALL_S_VIDEOWND_INFO* window  <b>:</b> �������� 
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ں���δ����(���к���)ʱ��Ԥ�ȴ���(����)��Ƶ����
             <br>��tup_call_set_video_window�ӿ�������ѷ���
 * @see tup_call_destroy_video_window
 * @see tup_call_set_video_window
 **/
TUP_API TUP_RESULT tup_call_create_video_window(TUP_UINT32 count, const CALL_S_VIDEOWND_INFO* window);


/**
 * @brief ������Ƶ������Ϣ
 * 
 * @param [in] TUP_UINT32 Count                    <b>:</b> ���ڸ�����һ��Ϊ2
 * @param [in] const CALL_S_VIDEOWND_INFO* window  <b>:</b> �������� 
 * @param [in] TUP_UINT32 callid                   <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��tup_call_set_video_window�ӿ�������ѷ���
 * @see tup_call_set_video_window
 **/
TUP_API TUP_RESULT tup_call_update_video_window(TUP_UINT32 count, const CALL_S_VIDEOWND_INFO * window, TUP_UINT32 callid);


/**
 * @brief ������Ƶ������Ϣ(���ھ��)
 * 
 * @param [in] TUP_UINT32 Count                    <b>:</b> ���ڸ�����һ��Ϊ2
 * @param [in] const CALL_S_VIDEOWND_INFO* window  <b>:</b> �������� 
 * @param [in] TUP_UINT32 callid                   <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���д���ʱ��callid��д��Ӧ����Чֵ�����в�����(δ���������к���ʱ)��callid��д�Ƿ�ֵ
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_video_window(TUP_UINT32 count, const CALL_S_VIDEOWND_INFO * window, TUP_UINT32 callid);


/**
 * @brief �Է�������Ƶת��Ƶ����ʱ������ѡ��ͬ����߾ܾ�
 * 
 * @param [in] TUP_UINT32 callid   <b>:</b> ����ID
 * @param [in] TUP_BOOL is_accept  <b>:</b> �Ƿ�ͬ��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_add_video
 * @see tup_call_del_video
 **/
TUP_API TUP_RESULT tup_call_reply_add_video(TUP_UINT32 callid,TUP_BOOL is_accept);



/**
 * @brief ������Ƶת��Ƶ��������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_reply_add_video
 * @see tup_call_del_video
 * @see tup_call_reply_del_video
 **/
TUP_API TUP_RESULT tup_call_add_video(TUP_UINT32 callid);


/**
 * @brief ������Ƶת��Ƶ����(ɾ����Ƶ)����
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_add_video
 * @see tup_call_reply_add_video
 **/
TUP_API TUP_RESULT tup_call_del_video(TUP_UINT32 callid);


/**
 * @brief �������򿪱���Ԥ������
 * 
 * @param [in] TUP_UPTR handle   <b>:</b> ���ھ��
 * @param [in] TUP_UINT32 index  <b>:</b> ����ͷ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_close_preview
 **/
TUP_API TUP_RESULT tup_call_open_preview(TUP_UPTR handle, TUP_UINT32 index);


/**
 * @brief �رղ�ɾ������Ԥ������
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_open_preview
 **/
TUP_API TUP_RESULT tup_call_close_preview(TUP_VOID);


/**
 * @brief �������������С
 * 
 * @param [in] CALL_E_AO_DEV dev  <b>:</b> �豸����
 * @param [in] TUP_UINT32 volume  <b>:</b> ������С��ȡֵ��Χ[0, 100]
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_mute_mic
 * @see tup_call_media_mute_video
 **/
TUP_API TUP_RESULT tup_call_media_set_speak_volume(CALL_E_AO_DEV dev, TUP_UINT32 volume);


/**
 * @brief ������Ƶ����豸
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE route_dev  <b>:</b> ��Ƶ��������豸����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_set_audio_indev
 **/
TUP_API TUP_RESULT tup_call_media_set_audio_outdev(CALL_E_AUDDEV_ROUTE route_dev);


/**
 * @brief ������Ƶ�����豸
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE route_dev  <b>:</b> ��Ƶ��������豸����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_set_audio_outdev
 **/
TUP_API TUP_RESULT tup_call_media_set_audio_indev(CALL_E_AUDDEV_ROUTE route_dev);


/**
 * @brief ����(��ȡ��)����������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_BOOL is_on     <b>:</b> ������ȡ������  TRUE Ϊ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_mute_mic
 **/
TUP_API TUP_RESULT tup_call_media_mute_speak(TUP_UINT32 callid, TUP_BOOL is_on);


/**
 * @brief ����(��ȡ��)��˷羲��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_BOOL is_on     <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_mute_video
 **/
TUP_API TUP_RESULT tup_call_media_mute_mic(TUP_UINT32 callid, TUP_BOOL is_on);


/**
 * @brief ����(��ȡ��)��ͣ��Ƶ�豸����(��Ƶ�ɼ�)
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_BOOL is_on     <b>:</b> �Ƿ���ͣ��Ƶ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_mute_mic
 **/
TUP_API TUP_RESULT tup_call_media_mute_video(TUP_UINT32 callid, TUP_BOOL is_on);


/**
 * @brief �������ؼ�¼��������Ƶ(¼*����¼*��)
 * 
 * @param [in] TUP_UINT32 callid           <b>:</b> ����ID
 * @param [in] const TUP_CHAR* file_name   <b>:</b> ¼��������ļ���һ��Ϊ*.wav�ļ�
 * @param [in] TUP_BOOL is_video           <b>:</b> �Ƿ�Ϊ��Ƶ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ݲ�֧������Ƶ����¼��
 * @see tup_call_media_stoprecord
 **/
TUP_API TUP_RESULT tup_call_media_startrecord(TUP_UINT32 callid, const TUP_CHAR* file_name, TUP_BOOL is_video);


/**
 * @brief ֹͣ���ؼ�¼��������Ƶ(¼*����¼*��)
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_startrecord
 **/
TUP_API TUP_RESULT tup_call_media_stoprecord(TUP_UINT32 callid);


/**
 * @brief ���ű�����Ƶ�ļ�(��������������������(��ʾ)����DTMF����æµ��ʾ���ͱ��ذ�������) 
 * 
 * @param [in] TUP_UINT32 loops           <b>:</b> ѭ��������0��ʾѭ�����ţ�
 * @param [in] const TUP_CHAR* play_file  <b>:</b> ���������ļ�����������·����Ŀǰ֧��wav��ʽ��
 * @param [out] TUP_INT32* play_handle    <b>:</b> ���ž��(����ֹͣ����ʱ�Ĳ���)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention WAV�ļ���Ŀǰ֧��PCMA��PCMU��G.729��ʽ���������Ϊ8��16λ��������8k��48K��PCM���ݣ�֧��˫����
 * @see tup_call_media_startTcplay
 * @see tup_call_media_startLocalplay
 * @see tup_call_media_stopplay
 **/
TUP_API TUP_RESULT tup_call_media_startplay(TUP_UINT32 loops, const TUP_CHAR* play_file, TUP_INT32* play_handle);


/**
 * @brief ����TC���� 
 * 
 * @param [in] TUP_INT32 tc_file_value   <b>:</b> �ļ���Ӧ��ֵ
 * @param [out] TUP_INT32* play_handle   <b>:</b> ���ž��(����ֹͣ����ʱ�Ĳ���)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_startplay
 * @see tup_call_media_startLocalplay
 * @see tup_call_media_stopplay
 **/
TUP_API TUP_RESULT tup_call_media_startTcplay(TUP_INT32 tc_file_value, TUP_INT32* play_handle);


/**
 * @brief ǿ�Ʊ��ز������� 
 * 
 * @param [in] TUP_UINT32 loops           <b>:</b> ѭ������
 * @param [in] const TUP_CHAR* play_file  <b>:</b> ���������ļ���
 * @param [out] TUP_INT32* play_handle    <b>:</b> ���ž��(����ֹͣ����ʱ�Ĳ���)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_startplay
 * @see tup_call_media_startTcplay
 * @see tup_call_media_stopplay
 **/
TUP_API TUP_RESULT tup_call_media_startLocalplay(TUP_UINT32 loops, const TUP_CHAR* play_file, TUP_INT32* play_handle);


/**
 * @brief ֹͣ��������
 * 
 * @param [in] TUP_INT32 play_handle  <b>:</b> ���ž��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_startplay
 * @see tup_call_media_startTcplay
 * @see tup_call_media_startLocalplay
 **/
TUP_API TUP_RESULT tup_call_media_stopplay(TUP_INT32 play_handle);


/**
 * @brief ����ʹ�õ���˷��豸���
 * 
 * @param [in] TUP_UINT32 index  <b>:</b> ��˷��豸���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �豸���һ����ϵͳ��ʼ����ͨ��tup_call_media_get_devices��ȡ
 * @see tup_call_media_get_mic_index
 * @see tup_call_media_get_devices
 **/
TUP_API TUP_RESULT tup_call_media_set_mic_index(TUP_UINT32 index);


/**
 * @brief ����ʹ�õ��������豸���
 * 
 * @param [in] TUP_UINT32 index  <b>:</b> �������豸���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �豸���һ����ϵͳ��ʼ����ͨ��tup_call_media_get_devices��ȡ
 * @see tup_call_media_get_speak_index
 * @see tup_call_media_get_devices
 **/
TUP_API TUP_RESULT tup_call_media_set_speak_index(TUP_UINT32 index);


/**
 * @brief ����ʹ�õ���Ƶ�豸���
 * 
 * @param [in] TUP_UINT32 index  <b>:</b> ��Ƶ�豸���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �豸���һ����ϵͳ��ʼ����ͨ��tup_call_media_get_devices��ȡ
 * @see tup_call_media_get_video_index
 * @see tup_call_media_get_devices
 **/
TUP_API TUP_RESULT tup_call_media_set_video_index(TUP_UINT32 index);


/**
 * @brief ��ȡʹ�õ���˷��豸���
 * 
 * @param [out] TUP_UINT32* index  <b>:</b> ��˷��豸���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ڽӿڲ��Ի��Ʒ���ԣ�ʵ�ʲ�Ʒҵ�񳡾����������
 * @see tup_call_media_set_mic_index
 **/
TUP_API TUP_RESULT tup_call_media_get_mic_index(TUP_UINT32* index);


/**
 * @brief ��ȡʹ�õ��������豸���
 * 
 * @param [out] TUP_UINT32* index  <b>:</b> �������豸���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ڽӿڲ��Ի��Ʒ���ԣ�ʵ�ʲ�Ʒҵ�񳡾����������
 * @see tup_call_media_set_speak_index
 **/
TUP_API TUP_RESULT tup_call_media_get_speak_index(TUP_UINT32* index);


/**
 * @brief ��ȡʹ�õ���Ƶ�豸���
 * 
 * @param [out] TUP_UINT32* index  <b>:</b> ��Ƶ�豸���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ڽӿڲ��Ի��Ʒ���ԣ�ʵ�ʲ�Ʒҵ�񳡾����������
 * @see tup_call_media_set_video_index
 **/
TUP_API TUP_RESULT tup_call_media_get_video_index(TUP_UINT32* index);


/**
 * @brief ����������������
 * 
 * @param [in] TUP_FLOAT in_gain  <b>:</b> ���棬ȡֵ��Χ [0,1)����˥����1������Ҳ��˥����(1,10]����Ŵ�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ó���:TCģʽ������С����Ҫ����/�������
 * @see tup_call_media_get_audio_ingain
 **/
TUP_API TUP_RESULT tup_call_media_set_audio_ingain(TUP_FLOAT in_gain);


/**
 * @brief ��ȡ������������
 * 
 * @param [out] TUP_FLOAT* in_gain  <b>:</b> ���棬[0,1)����˥����1������Ҳ��˥����(1,10]����Ŵ�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ó���:TCģʽ������С����Ҫ����/�������
 * @see tup_call_media_set_audio_ingain
 **/
TUP_API TUP_RESULT tup_call_media_get_audio_ingain(TUP_FLOAT* in_gain);


/**
 * @brief ���������������
 * 
 * @param [in] TUP_FLOAT out_gain  <b>:</b> ���棬ȡֵ��Χ [0,1)����˥����1������Ҳ��˥����(1,10]����Ŵ�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ó���:TCģʽ������С����Ҫ����/�������
 * @see tup_call_media_get_audio_outgain
 **/
TUP_API TUP_RESULT tup_call_media_set_audio_outgain(TUP_FLOAT out_gain);


/**
 * @brief ��ȡ�����������
 * 
 * @param [out] TUP_FLOAT* pfOutGain  <b>:</b> ���棬[0,1)����˥����1������Ҳ��˥����(1,10]����Ŵ�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ó���:TCģʽ������С����Ҫ����/�������
 * @see tup_call_media_set_audio_outgain
 **/
TUP_API TUP_RESULT tup_call_media_get_audio_outgain(TUP_FLOAT* out_gain);


/**
 * @brief ��ȡ��Ƶ��Ƶ�豸�б�
 * 
 * @param [in/out] TUP_UINT32* num               <b>:</b> ����ʱ��ʾ�ϲ������豸���������ʱ��ʾ��ȡ�����豸�ĸ���
 * @param [in] CALL_S_DEVICEINFO* device_info    <b>:</b> �豸��Ϣ����ָ��
 * @param [in] CALL_E_DEVICE_TYPE device_type    <b>:</b> �豸����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_media_get_devices(TUP_UINT32* num, CALL_S_DEVICEINFO* device_info, CALL_E_DEVICE_TYPE device_type);


/**
 * @brief �ǼǺ���IPTҵ��
 * 
 * @param [in] CALL_E_SERVICE_CALL_TYPE type  <b>:</b> ҵ������
 * @param [in] void* data                     <b>:</b> �Ǽ�ҵ����Ҫ�Ĳ������ݣ���ǰ��ǰת��ҵ����Ҫ(ǰת��Ŀ�ĺ��룬�ַ���)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �������IPTҵ���Ӧ�����������������
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_IPTservice(CALL_E_SERVICE_CALL_TYPE type, void* data);


/**
 * @brief ��ȡctd�����б�
 * 
 * @param [in] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_ctd_get_list(TUP_VOID);


/**
 * @brief ���ú���ҵ�����
 * 
 * @param [in] TUP_UINT32 cfgid  <b>:</b> ����ID,��call_def.h���壬ǰ׺ΪCALL_D_CFG_
 * @param [in] TUP_VOID * val    <b>:</b> ����ֵ���������õĲ���IDȷ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention 1 ʵ��������ĺ���ҵ�񣬱�����ô˽ӿڷֱ�����:
             <br>CALL_D_CFG_ENV_PRODUCT_TYPE����Ʒ���ͣ���
             <br>CALL_D_CFG_NET_NETADDRESS�����ص�ַ����
             <br>CALL_D_CFG_SERVER_REG_PRIMARY��sipע����������� CALL_D_CFG_SERVER_PROXY_PRIMARY��sip�����������
             <br>������Ҫ���ô˽ӿڷֱ�����:
             <br>CALL_D_CFG_SIP_TRANS_MODE��SIP����ģʽ����
             <br> 
             <br>2 ��IMϵͳ���ʹ��ʱ������ýӿڵ����ֱ��ͨ��tup_im_getserviceprofile�ӿڻ�ȡ��
 * @see tup_call_get_cfg
 **/
TUP_API TUP_RESULT tup_call_set_cfg(TUP_UINT32 cfgid, TUP_VOID * val);


/**
 * @brief ��ȡ����ҵ�����
 * 
 * @param [in] TUP_UINT32 cfgid  <b>:</b> ����ID,��call_def.h���壬ǰ׺ΪCALL_D_CFG_
 * @param [out] TUP_VOID* val    <b>:</b> ����ֵ���������õĲ���IDȷ����������
 * @param [in] TUP_UINT32 size   <b>:</b> ����ֵ��С���������õĲ���IDȷ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_cfg
 **/
TUP_API TUP_RESULT tup_call_get_cfg(TUP_UINT32 cfgid, TUP_VOID* val,  TUP_UINT32 size);


/**
 * @brief ������������
 * 
 * @param [in] TUP_UINT32 accountid        <b>:</b> �˺�ID
 * @param [in] TUP_BOOL right              <b>:</b> ����Ȩ��
 * @param [in] const char* linkage_number  <b>:</b> ������Ŀ�껰�����룬��󳤶�32
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ڿ�������ǰ����
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_joint_setting(TUP_UINT32 accountid, TUP_BOOL right, const char* linkage_number);


/**
 * @brief ��������
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ����ǰ�����������������
 * @see tup_call_joint_stop
 **/
TUP_API TUP_RESULT tup_call_joint_start(TUP_VOID);


/**
 * @brief �ر�����
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_joint_start
 **/
TUP_API TUP_RESULT tup_call_joint_stop(TUP_VOID);


/**
 * @brief ����ͨ��Desktop��IP Phone�л�
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_joint_switch(TUP_VOID);


/**
 * @brief ͨ��ת����
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_joint_conf_result
 **/
TUP_API TUP_RESULT tup_call_joint_uptoconference(TUP_VOID);


/**
 * @brief ����������֪ͨ������
 * 
 * @param [in] TUP_UINT32 result  <b>:</b> ������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_joint_uptoconference
 **/
TUP_API TUP_RESULT tup_call_joint_conf_result(TUP_UINT32 result);


/**
 * @brief �½�����
 * 
 * @param [out] TUP_UINT32 *confid        <b>:</b> ����(���ƿ�)ID
 * @param [out] TUP_UINT32 *callid        <b>:</b> ����(���ƿ�)ID
 * @param [in] const TUP_CHAR *groupuri   <b>:</b> Ⱥ��URI�������Ⱥ�����ʱ��д
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_create(TUP_UINT32 *confid, TUP_UINT32 *callid, const TUP_CHAR *groupuri);


/**
 * @brief ���������
 * 
 * @param [in] TUP_UINT32 confid       <b>:</b> ����(���ƿ�)ID
 * @param [in] TUP_UINT32 count        <b>:</b> ����߸���
 * @param [in] const TUP_CHAR *number  <b>:</b> ����ߺ����б�(�����ַ)
 * @param [in] TUP_UINT32 persize      <b>:</b> �洢����ߺ����BUF����(�����Ա����)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˲���ֻ�л�����ϯ���ܵ���
 * @see tup_call_serverconf_kick_attendee
 **/
TUP_API TUP_RESULT tup_call_serverconf_add_attendee(TUP_UINT32 confid,TUP_UINT32 count,const TUP_CHAR *number, TUP_UINT32 persize);


/**
 * @brief ɾ�������
 * 
 * @param [in] TUP_UINT32 confid       <b>:</b> ����(���ƿ�)ID
 * @param [in] const TUP_CHAR* number  <b>:</b> ����ߺ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˲���ֻ�л�����ϯ���ܵ���
 * @see tup_call_serverconf_add_attendee
 **/
TUP_API TUP_RESULT tup_call_serverconf_kick_attendee(TUP_UINT32 confid, const TUP_CHAR* number);


/**
 * @brief �޸�����߷���Ȩ��
 * 
 * @param [in] TUP_UINT32 confid       <b>:</b> ����(���ƿ�)ID
 * @param [in] const TUP_CHAR* number  <b>:</b> ����ߺ���
 * @param [in] TUP_UINT32 right        <b>:</b> �Ƿ�������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˲���ֻ�л�����ϯ���ܵ���
 * @see tup_call_serverconf_mute
 **/
TUP_API TUP_RESULT tup_call_serverconf_modify_right(TUP_UINT32 confid, const TUP_CHAR* number, TUP_UINT32 right);


/**
 * @brief ���û᳡����
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @param [in] TUP_BOOL muted     <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˲���ֻ�л�����ϯ���ܵ��ã�������������ϯ�⣬������ֻ��
 * @see tup_call_serverconf_modify_right
 **/
TUP_API TUP_RESULT tup_call_serverconf_mute(TUP_UINT32 confid, TUP_BOOL muted);


/**
 * @brief ���û᳡����(������������)
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @param [in] TUP_BOOL locked    <b>:</b> �Ƿ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˲���ֻ�л�����ϯ���ܵ���
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_lock(TUP_UINT32 confid, TUP_BOOL locked);


/**
 * @brief �˳�����
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ����ϯ�˳����飬������ϯȨ�޲�ת��(��û����ϯ����֧�ֽ�����ϯ��ػ�أ�������������˳��󣬻������)
 * @see tup_call_serverconf_end
 **/
TUP_API TUP_RESULT tup_call_serverconf_leave(TUP_UINT32 confid);


/**
 * @brief ��������
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˲���ֻ�л�����ϯ���ܵ���
 * @see tup_call_serverconf_leave
 **/
TUP_API TUP_RESULT tup_call_serverconf_end(TUP_UINT32 confid);


/**
 * @brief ������������
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_accept(TUP_UINT32 confid); 


/**
 * @brief ���ֻ���
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_unhold
 **/
TUP_API TUP_RESULT tup_call_serverconf_hold(TUP_UINT32 confid); 


/**
 * @brief ȡ�����ֻ���
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_hold
 **/
TUP_API TUP_RESULT tup_call_serverconf_unhold(TUP_UINT32 confid);


/**
 * @brief ����ͨ��ת����(Refer����)
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @param [in] TUP_UINT32 callid  <b>:</b> ��תΪ����ĺ���(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ô˽ӿ���Ҫ�ȵ���tup_call_serverconf_create��ɻ��鴴��
 * @see tup_call_serverconf_create
 * @see tup_call_serverconf_transferto_conf_non_refer
 **/
TUP_API TUP_RESULT tup_call_serverconf_transferto_conf(TUP_UINT32 confid, TUP_UINT32 callid);


/**
 * @brief ����ͨ��ת����(��Refer����)
 * 
 * @param [in] TUP_UINT32 callid         <b>:</b> ��תΪ����ĺ���(���ƿ�)ID
 * @param [out] TUP_UINT32 *confid       <b>:</b> ����(���ƿ�)ID
 * @param [in] const TUP_CHAR *groupuri  <b>:</b> Ⱥ��URI�������Ⱥ�����ʱ��д
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_transferto_conf
 **/
TUP_API TUP_RESULT tup_call_serverconf_transferto_conf_non_refer(TUP_UINT32 callid, TUP_UINT32 *confid, const TUP_CHAR *groupuri);


/**
 * @brief ��������ת���ݻ���
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_p2p_transferto_dataconf
 **/
TUP_API TUP_RESULT tup_call_serverconf_transferto_dataconf(TUP_UINT32 confid);


/**
 * @brief ��Ե�ֱ��ת��ý�����
 * 
 * @param [out] TUP_UINT32* confid        <b>:</b> ת�ɶ�ý�������Ӧ�Ļ���(���ƿ�)ID
 * @param [out] TUP_UINT32* callid        <b>:</b> ת�ɶ�ý�������Ӧ�ĺ���(���ƿ�)ID
 * @param [in] TUP_UINT32 p2p_callid      <b>:</b> ԭP2P����(���ƿ�)ID
 * @param [in] const TUP_CHAR* groupuri   <b>:</b> Ⱥ��URI�������Ⱥ�����ʱ��д
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ת�����ԭ��Ե����Ƶ���ڱ��֡�TODO
 * @see tup_call_serverconf_transferto_dataconf
 **/
TUP_API TUP_RESULT tup_call_serverconf_p2p_transferto_dataconf(TUP_UINT32* confid, TUP_UINT32* callid, TUP_UINT32 p2p_callid, const TUP_CHAR* groupuri);


/**
 * @brief ����ԤԼ����
 * 
 * @param [out] TUP_UINT32 *callid         <b>:</b> ����ԤԼ����󣬶�Ӧ�ĺ���ID
 * @param [in] const TUP_CHAR *accesscode  <b>:</b> ���������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_access_reservedconf(TUP_UINT32 *callid, const TUP_CHAR *accesscode);


/**
 * @brief ����CALL�����־������������־
 * 
 * @param [in] TUP_INT32 log_level        <b>:</b> ��־����ȡֵ:ö����CALL_E_LOG_LEVEL
 * @param [in] TUP_INT32 max_size         <b>:</b> ÿ����־�ļ������ֵ����λ: KB�����ֵΪTUP_INT32����ȡ�������ֵ
 * @param [in] TUP_INT32 file_count       <b>:</b> ��־�ļ����������ֵΪTUP_INT32����ȡ�������ֵ 
 * @param [in] const TUP_CHAR* log_path   <b>:</b> ��־���·�� 
 * @retval TUP_API TUP_VOID <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����ڳ�ʼ��֮ǰ����
 * @see tup_call_log_stop
 **/
TUP_API TUP_VOID tup_call_log_start(TUP_INT32 log_level, TUP_INT32 max_size, TUP_INT32 file_count, const TUP_CHAR* log_path);


/**
 * @brief ����CALL���HMEģ����־����
 * 
 * @param [in] TUP_INT32 audio_log_level   <b>:</b> HME-Audio ��־����(����ֵ��Դ:ö����CALL_E_LOG_LEVEL)
 * @param [in] TUP_INT32 audio_max_size    <b>:</b> HME-Audio ��־��ֵ(��λΪM, ��������Ϊ10, ��С1M, ���100M; Ĭ��Ϊ1M)
 * @param [in] TUP_INT32 video_log_level   <b>:</b> HME-Video ��־����(����ֵ��Դ:ö����CALL_E_LOG_LEVEL)
 * @param [in] TUP_INT32 video_max_size    <b>:</b> HME-Video ��־��ֵ(��λM, ��������Ϊ50, ��С1M, ���512M; Ĭ��Ϊ5M)
 * @retval TUP_API TUP_VOID <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ڵ�������ý���������־��������������ʹ��Ĭ��ֵ
 * @see NA
 **/
TUP_API TUP_VOID tup_call_hme_log_info(TUP_INT32 audio_log_level, 
            TUP_INT32 audio_max_size, TUP_INT32 video_log_level, TUP_INT32 video_max_size);


/**
 * @brief ֹͣCALL�����־
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_VOID <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_log_start
 **/
TUP_API TUP_VOID tup_call_log_stop(TUP_VOID);


/**
 * @brief ���ݺ�����ϵͳ�������ȡ��������
 * 
 * @param [in] TUP_UINT32 errornum  <b>:</b> �����룬ȡֵtagCALL_E_ERR_ID
 * @retval TUP_API const TUP_CHAR*  <b>:</b> �ɹ����ش��������ִ���ʧ��NULL
 * 
 * @attention ��ֻ֧�ֺ�����ϵͳ����Ĵ�������
 * @see NA
 **/
TUP_API const TUP_CHAR* tup_call_get_err_description(TUP_UINT32 errornum);


/**
 * @brief ��ȡЭ�̺�����������ֱ���
 * 
 * @param [in]  TUP_UINT32 callid           <b>:</b> ����(���ƿ�)ID
 * @param [out] TUP_UINT32 *max_frame_size  <b>:</b> ���ֱ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_data_maxframesize(TUP_UINT32 callid, TUP_UINT32 *max_frame_size);


/**
 * @brief ����IP���й���
 * 
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_disable_ipaddr_call
 **/
TUP_API TUP_RESULT tup_call_enable_ipaddr_call();


/**
 * @brief �ر�IP���й���
 * 
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_enable_ipaddr_call
 **/
TUP_API TUP_RESULT tup_call_disable_ipaddr_call();


/**
 * @brief ��Ƶ����
 * 
 * @param [in] CALL_S_VIDEOCONTROL *video_control  <b>:</b> ��Ƶ���Ʋ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_data_control
 **/
TUP_API TUP_RESULT tup_call_video_control(CALL_S_VIDEOCONTROL *video_control);


/**
 * @brief ����(����)����
 * 
 * @param [in] CALL_S_VIDEOCONTROL *data_control  <b>:</b> ����(����)���Ʋ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_video_control
 **/
TUP_API TUP_RESULT tup_call_data_control(CALL_S_VIDEOCONTROL *data_control);


/**
 * @brief �����ƶ���Ƶ·���豸
 * 
 * @param [in] CALL_E_MOBILE_AUIDO_ROUTE route  <b>:</b> �ƶ���Ƶ·���豸����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����ƶ��豸
 * @see tup_call_get_mobile_audio_route
 **/
TUP_API TUP_RESULT tup_call_set_mobile_audio_route(CALL_E_MOBILE_AUIDO_ROUTE route);


/**
 * @brief ��ȡ�ƶ���Ƶ·���豸
 * 
 * @param [out] CALL_E_MOBILE_AUIDO_ROUTE *route  <b>:</b> �ƶ���Ƶ·���豸����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_mobile_audio_route
 **/
TUP_API TUP_RESULT tup_call_get_mobile_audio_route(CALL_E_MOBILE_AUIDO_ROUTE *route);


/**
 * @brief ��������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_stop_data
 **/
TUP_API TUP_RESULT tup_call_start_data(TUP_UINT32 callid);


/**
 * @brief ֹͣ����
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_stop_data
 **/
TUP_API TUP_RESULT tup_call_stop_data(TUP_UINT32 callid);


/**
 * @brief ������Ƶ����(������)
 * 
 * @param [in] TUP_UINT32 callid                        <b>:</b> ����ID
 * @param [in] TUP_UINT32 index                         <b>:</b> �豸(����ͷ)����
 * @param [in] const CALL_S_VIDEO_ORIENT *video_orient  <b>:</b> ��Ƶ����(������)����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ҫ�����ƶ��豸
 * @see tup_call_set_video_render
 **/
TUP_API TUP_RESULT tup_call_set_video_orient(TUP_UINT32 callid, TUP_UINT32 index, const CALL_S_VIDEO_ORIENT *video_orient);


/**
 * @brief ������Ƶ��ʾ��������
 * 
 * @param [in] TUP_UINT32 callid                        <b>:</b> ����ID
 * @param [in] const CALL_S_VIDEO_RENDER_INFO* render   <b>:</b> ��Ƶ��ʾ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_video_orient
 **/
TUP_API TUP_RESULT tup_call_set_video_render(TUP_UINT32 callid, const CALL_S_VIDEO_RENDER_INFO* render);


/**
 * @brief ��������ͷ�ɼ�����
 * 
 * @param [in] TUP_UINT32 callid            <b>:</b> ����ID
 * @param [in] TUP_UINT32 capture_index     <b>:</b> �ɼ��豸(����ͷ)����
 * @param [in] TUP_UINT32 capture_rotation  <b>:</b> ����ͷ�ɼ��Ƕ� {0,1,2,3} �����ƶ�ƽ̨��Ч��Ĭ��Ϊ0
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_display_rotation
 **/
TUP_API TUP_RESULT tup_call_set_capture_rotation(TUP_UINT32 callid, TUP_UINT32 capture_index, TUP_UINT32 capture_rotation);


/**
 * @brief ���ô�����ʾ����
 * 
 * @param [in] TUP_UINT32 callid            <b>:</b> ����ID
 * @param [in] TUP_UINT32 render_type       <b>:</b> ��Ƶ�������ͣ�ȡֵCALL_E_VIDEOWND_TYPE
 * @param [in] TUP_UINT32 rotation          <b>:</b> ��Ƶ��ʾ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_capture_rotation
 **/
TUP_API TUP_RESULT tup_call_set_display_rotation(TUP_UINT32 callid, TUP_UINT32 render_type, TUP_UINT32 rotation);


/**
 * @brief ��������ͷͼƬ
 * 
 * @param [in] TUP_UINT32 callid    <b>:</b> ����ID
 * @param [in] TUP_CHAR *file_name  <b>:</b> �ļ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_video_capture_file(TUP_UINT32 callid, TUP_CHAR *file_name);


/**
 * @brief ����H.264��ƵB֡����
 * 
 * @param [in] TUP_BOOL is_enable  <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_vpuorder_enable(TUP_BOOL is_enable);


/**
 * @brief ���ͻỰ��INFO��Ϣ
 * 
 * @param [in] TUP_UINT32 callid ����ID
 * @param [in] CALL_S_DIALOG_INFO *dialog_info �Ự��INFO��Ϣ�ṹ 
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ʒ����Ҫʱʹ�ô˺������Ͷ��Ƶ�SIP INFO��Ϣ����ʵ���ض�ҵ��
 * @see NA
 **/ 
TUP_API TUP_RESULT tup_call_send_diaglog_info(TUP_UINT32 callid, CALL_S_DIALOG_INFO *dialog_info);


/**
 * @brief ���ӻ�ΪTC
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��ʼ����ע��ǰ���ã���������TC��IE�ƣ������سɹ��������ƻ���
 * @see tup_call_disconnect_tc
 **/
TUP_API TUP_RESULT tup_call_connect_tc(TUP_VOID);


/**
 * @brief �Ͽ���ΪTC������
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ϊ��TC�豸ʹ��
 * @see tup_call_connect_tc
 **/
TUP_API TUP_RESULT tup_call_disconnect_tc(TUP_VOID);


/**
 * @brief ��ȡTC��IP��ַ
 * 
 * @param [out] CALL_S_IF_INFO* inetaddr  <b>:</b> IP��ַ��Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see ��Ϊ��TC�豸ʹ��
 **/
TUP_API TUP_RESULT tup_call_get_tc_ipaddr(CALL_S_IF_INFO* inetaddr);


/**
 * @brief ��ȡ��Ƶģʽ
 * 
 * @param [out] TUP_UINT32* auido_mode  <b>:</b> ��Ƶģʽ @enum tagCALL_E_AUDIO_MODE
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ϊ��TC�豸ʹ��
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_audio_mode(TUP_UINT32* auido_mode);


/**
 * @brief ��ȡTC��־
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ϊ��TC�豸ʹ��
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_tc_log(TUP_VOID);


/**
 * @brief ����TC��MIC����
 * 
 * @param [out] TUP_INT32 is_mute  <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ϊ��TC�豸ʹ��
 * @see tup_call_set_spkdev_mute
 **/
TUP_API TUP_RESULT tup_call_set_micdev_mute(TUP_INT32 is_mute);


/**
 * @brief ����TC������������
 * 
 * @param [in] TUP_INT32 is_mute  <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��Ϊ��TC�豸ʹ��
 * @see tup_call_set_micdev_mute
 **/
TUP_API TUP_RESULT tup_call_set_spkdev_mute(TUP_INT32 is_mute);


#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#endif  /* __CALL_INTERFACE_H__ */

/** @}*/

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
 *
* vi: set expandtab ts=4 sw=4 tw=80:
*/


