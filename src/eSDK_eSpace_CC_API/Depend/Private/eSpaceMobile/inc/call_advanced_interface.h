
/** 
* @file call_def.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP ������ϵͳ�߼�ҵ��ӿ�ͷ�ļ��� \n
*/


/**
*
*  @{
*/


#ifndef __CALL_ADVANCED_INTERFACE_H__
#define __CALL_ADVANCED_INTERFACE_H__


/*******************************************************************************
 *   ���ļ���Ҫ����������ͷ�ļ�
 *******************************************************************************/

#include "call_advanced_def.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


/*******************************************************************************
 *   �곣��������
*******************************************************************************/

#define IN
#define OUT



/**tup_call_digitmap_create_handle ��һ������typeȡֵ��Χ*/
#define TUP_COMMON_DIGITMAP_INDEX   (0)    //����ƥ����ͼ����
#define TUP_REPLACE_DIGITMAP_INDEX  (1)    //�滻ƥ����ͼ����



/**
 * @brief ������ͼ���
 * 
 * @param [in] const TUP_INT32 type       <b>:</b> ��ͼ���ͣ�0 ����ƥ����ͼ������1 �滻ƥ����ͼ����
 * @param [in] const TUP_CHAR *digit_map  <b>:</b> ��ͼ
 * @param [out] TUP_INT32 *handle         <b>:</b> ��������ͼ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_digitmap_match
 * @see tup_call_digitmap_destroy_handle
 **/
TUP_API TUP_RESULT tup_call_digitmap_create_handle(const TUP_INT32 type, const TUP_CHAR *digit_map, TUP_INT32 *handle);


/**
 * @brief ������ͼ���
 * 
 * @param [in] const TUP_INT32 handle  <b>:</b> �����ٵ���ͼ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_digitmap_create_handle
 * @see tup_call_digitmap_match
 **/
TUP_API TUP_RESULT tup_call_digitmap_destroy_handle(const TUP_INT32 handle);


/**
 * @brief ��ͼƥ�䴦��
 * 
 * @param [in] const TUP_INT32 handle  <b>:</b> ��ͼ���
 * @param [in] const char *input_num   <b>:</b> ԭʼ����ͼ�������
 * @param [out] DMRESULT *dm_result     <b>:</b> ��ͼ������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_digitmap_create_handle
 * @see tup_call_digitmap_destroy_handle
 **/
TUP_API TUP_RESULT tup_call_digitmap_match(const TUP_INT32 handle, const char *input_num, DMRESULT *dm_result);


/**
 * @brief RSA����
 * 
 * @param [in] const TUP_CHAR *src_data         <b>:</b> �����ܴ��������
 * @param [in] const TUP_CHAR *public_key_path  <b>:</b> ��Կ·��
 * @param [out] TUP_CHAR **encrypt_data         <b>:</b> ���ܺ������
 * @param [out] TUP_INT *encrypt_len            <b>:</b> ���ܺ�����ݳ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ܺ������������Ҫ�ͷţ��ͷź���tup_rsa_free_public_encrypt_data
 * @see tup_rsa_free_public_encrypt_data
 **/
TUP_API TUP_RESULT tup_rsa_public_encrypt(const TUP_CHAR *src_data, const TUP_CHAR *public_key_path, TUP_CHAR **encrypt_data, TUP_INT *encrypt_len);


/**
 * @brief �ͷ�RSA��������
 * 
 * @param [in] TUP_CHAR *encrypt_data  <b>:</b> ���ͷŵļ�������
 * @retval TUP_API TUP_VOID <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_rsa_public_encrypt
 **/
TUP_API TUP_VOID tup_rsa_free_public_encrypt_data(TUP_CHAR *encrypt_data);


/**
 * @brief ��ȡָ��ҵ���ҵ��������(ע�����ע����)
 * 
 * @param [in] TUP_UINT32 account_id            <b>:</b> �˺�ID
 * @param [in] CALL_S_IPT_DATA *ipt_data        <b>:</b> ����ȡҵ���������ҵ��������Ϣ
 * @param [out] TUP_CHAR code[]                 <b>:</b> ������������ڴ棬��Ӧ�ò���䣬���鳤�Ȳ�С��32�ֽ�
 * @param [in] TUP_UINT32 size                  <b>:</b> ������������ڴ泤��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_service_code(TUP_UINT32 account_id, CALL_S_IPT_DATA *ipt_data, TUP_CHAR code[], TUP_UINT32 size);


/**
 * @brief ע��ָ���˺�
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> ��ע����˺�id
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_deregister_for_account
 **/
TUP_API TUP_RESULT tup_call_register_for_account(TUP_UINT32 account_id);


/**
 * @brief ע��ָ���˺�
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> ��ע�����˺�id
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_register_for_account
 **/
TUP_API TUP_RESULT tup_call_deregister_for_account(TUP_UINT32 account_id);


/**
 * @brief ��ʼָ���˺ŵ�ˢ��ע��
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�id
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_stop_refreshregister_for_account
 **/
TUP_API TUP_RESULT tup_call_start_refreshregister_for_account(TUP_UINT32 account_id);


/**
 * @brief ָֹͣ���˺ŵ�ˢ��ע��
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�id
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_refreshregister_for_account
 **/
TUP_API TUP_RESULT tup_call_stop_refreshregister_for_account(TUP_UINT32 account_id);


/**
 * @brief ��RLS�б����Ƴ���ϵ��
 * 
 * @param [in] TUP_UINT32 account_id           <b>:</b> �˺�id
 * @param [in] const TUP_CHAR* contact_number  <b>:</b> ��ϵ�˺���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_contact_removed_indicate(TUP_UINT32 account_id, const TUP_CHAR* contact_number);


/**
 * @brief ��ȡSIP����������״̬��Ϣ
 * 
 * @param [in] TUP_UINT8 server_index  <b>:</b> ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_sipserver_link_status(TUP_UINT8 server_index);


/**
 * @brief ��ȡ�˻���Ϣ
 * 
 * @param [out] CALL_S_SIP_ACCOUNT_INFO* account_info <b>:</b> �����˺���Ϣ�Ľṹ����
 * @param [out] TUP_UINT32* count                     <b>:</b> ʵ�ʻ�ȡ���˺���Ϣ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention account_info���ڴ���Ӧ�ò���䣬��СΪsiaeof(CALL_S_SIP_ACCOUNT_INFO) * ����˺���
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_account_info(CALL_S_SIP_ACCOUNT_INFO* account_info, TUP_UINT32* count);


/**
 * @brief ��ȡָ���˻��µĺ�����Ϣ
 * 
 * @param [in] TUP_UINT32 account_id        <b>:</b> �˺�ID
 * @param [out] TUP_UINT32* callids         <b>:</b> �����˺��º���ID������
 * @param [in/out] TUP_UINT32* callsnum     <b>:</b> ����ʱΪcallids����Ĵ�С�����ʱΪʵ�ʵĺ���ID��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����˺��º���ID�����齨��Ϊ��󲢷�������(��ǰΪ24)
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_account_callids(TUP_UINT32 account_id, TUP_UINT32* callids, TUP_UINT32* callsnum);


/**
 * @brief ��������ID
 * 
 * @param [in] TUP_UINT32 account_id       <b>:</b> �˺�ID
 * @param [in] CALL_E_LINE_TYPE line_type  <b>:</b> ��·����
 * @param [in] TUP_UINT32 lineid           <b>:</b> ��·ID
 * @param [out] TUP_UINT32* callid         <b>:</b> �����ɹ��ĺ���ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ݺ���ID���к�̵��õĺ���(*_bycallid)������Ҫ���ô˺���
 * @see tup_call_start_call_bycallid
 * @see tup_call_anonymous_call_bycallid
 * @see tup_call_emergency_call
 **/
TUP_API TUP_RESULT tup_call_create_callid(TUP_UINT32 account_id,  CALL_E_LINE_TYPE line_type, TUP_UINT32 lineid, TUP_UINT32* callid);


/**
 * @brief ���ݺ���ID����һ·����Ƶ����
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] CALL_E_CALL_TYPE call_type     <b>:</b> �������ͣ���Ƶ����Ƶ
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_create_callid
 **/
TUP_API TUP_RESULT tup_call_start_call_bycallid(TUP_UINT32 callid, CALL_E_CALL_TYPE call_type, const TUP_CHAR* callee_number);


/**
 * @brief ����CALLID����һ·ָ����ʽ��VOIP����
 * 
 * @param [in] const CALL_S_CALL_PARAMS* call_params  <b>:</b> ���в���������ulCallIdΪ�������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_start_call
 * @see tup_call_anonymous_call
 * @see tup_call_start_call_ex
 * @see tup_call_accept_call
 * @see tup_call_alerting_call
 * @see tup_call_end_call
 * @see tup_call_hold_call
 * @see tup_call_unhold_call
 **/
TUP_API TUP_RESULT tup_call_start_call_bycallid_ex(const CALL_S_CALL_PARAMS* call_params);



/**
 * @brief ���ݺ���ID����һ·��������
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��������Ϊ��Ƶ����
 * @see tup_call_create_callid
 **/
TUP_API TUP_RESULT tup_call_anonymous_call_bycallid(TUP_UINT32 callid, const TUP_CHAR* callee_number);


/**
 * @brief ���ݺ���ID����һ·��������
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��������Ϊ��Ƶ����
 * @see tup_call_create_callid
 **/
TUP_API TUP_RESULT tup_call_emergency_call(TUP_UINT32 callid, const TUP_CHAR* callee_number);


/**
 * @brief �Ǽ�ָ���˺ŵ�DNDҵ��
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ҵ����������Ҫ����ȷ����
 * @see tup_call_cancel_DND_for_account
 **/
TUP_API TUP_RESULT tup_call_set_DND_for_account(TUP_UINT32 account_id);

 
/**
 * @brief ע��ָ���˺ŵ�DNDҵ��
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ҵ����������Ҫ����ȷ����
 * @see tup_call_set_DND_for_account
 **/
TUP_API TUP_RESULT tup_call_cancel_DND_for_account(TUP_UINT32 account_id);


/**
 * @brief �Ǽ�ָ���˺ŵ����羲��ҵ��
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ҵ����������Ҫ����ȷ����
 * @see tup_call_set_alertsilence_off
 **/
TUP_API TUP_RESULT tup_call_set_alertsilence_on(TUP_UINT32 account_id);


/**
 * @brief ע��ָ���˺ŵ����羲��ҵ��
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ҵ����������Ҫ����ȷ����
 * @see tup_call_set_alertsilence_off
 **/
TUP_API TUP_RESULT tup_call_set_alertsilence_off(TUP_UINT32 account_id);


/**
 * @brief �Ǽ�privacyҵ��(˽�˺���)
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_privacy_off
 **/
TUP_API TUP_RESULT tup_call_set_privacy_on(TUP_UINT32 account_id);


/**
 * @brief ע��privacyҵ��(˽�˺���)
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_privacy_on
 **/
TUP_API TUP_RESULT tup_call_set_privacy_off(TUP_UINT32 account_id);


/**
 * @brief ����reinvite��Э��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_reinvite(TUP_UINT32 callid);


/**
 * @brief ����ָ����·�ĺ���
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_UINT32 lineid  <b>:</b> ��·ID
 * @param [in] TUP_BOOL is_video  <b>:</b> �Ƿ������Ƶ����
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_accept_call_with_lineid(TUP_UINT32 callid, TUP_UINT32 lineid, TUP_BOOL is_video);


/**
 * @brief ����ԭ���������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_UINT32 cause   <b>:</b> �������е�ԭ��
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_end_call
 **/
TUP_API TUP_RESULT tup_call_end_call_with_cause(TUP_UINT32 callid, TUP_UINT32 cause);


/**
 * @brief �������к���
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_end_call
 * @see tup_call_end_call_with_cause
 **/
TUP_API TUP_RESULT tup_call_end_allcall(TUP_VOID);



/**
 * @brief ���ݺ���ID����CTD����
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �����ӿڣ������tup_call_end_call
 * @see tup_call_end_call
 **/
TUP_API TUP_RESULT tup_call_ctd_destroy_call(TUP_UINT32 callid);


/**
 * @brief �Է�������Ƶת��Ƶ����(ɾ����Ƶ)ʱ������ѡ��ͬ����߾ܾ�
 * 
 * @param [in] TUP_UINT32 callid   <b>:</b> ����ID
 * @param [in] TUP_BOOL is_accept  <b>:</b> �Ƿ�ͬ��
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��ʵ��ʹ�ó������û��޷��ܾ�
 * @see tup_call_add_video
 * @see tup_call_reply_add_video
 * @see tup_call_del_video
 **/
TUP_API TUP_RESULT tup_call_reply_del_video(TUP_UINT32 callid,TUP_BOOL is_accept);



/**
 * @brief �����˺�ID��ȡ��ͨ����Ϣ
 * 
 * @param [in] TUP_UINT32 accountid            <b>:</b> �˺�ID
 * @param [in] CALL_S_STREAM_INFO* streaminfo  <b>:</b> ��ͨ����Ϣ
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_get_callstatics
 **/
TUP_API TUP_RESULT tup_call_get_channelinfo(TUP_UINT32 accountid, CALL_S_STREAM_INFO* streaminfo);


/**
 * @brief ���Ų�����
 * 
 * @param [in] TUP_UINT32 callid         <b>:</b> ����ID
 * @param [in] CALL_E_SIGTONE_TYPE tone  <b>:</b> �ź�������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_stop_signaltone
 **/
TUP_API TUP_RESULT tup_call_play_signaltone(TUP_UINT32 callid, CALL_E_SIGTONE_TYPE tone);


/**
 * @brief ֹͣ���Ų�����
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_play_signaltone
 **/
TUP_API TUP_RESULT tup_call_stop_signaltone(TUP_UINT32 callid);


/**
 * @brief �����п�ҵ���б��ֺ���
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_pnotification_unholdcall
 **/
TUP_API TUP_RESULT tup_call_pnotification_holdcall(TUP_UINT32 callid);

 
/**
 * @brief �����п�ҵ����ȡ�����ֺ���
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_pnotification_holdcall
 **/
TUP_API TUP_RESULT tup_call_pnotification_unholdcall(TUP_UINT32 callid);


/**
 * @brief ����������¼/��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_server_recordcall_off
 **/
TUP_API TUP_RESULT tup_call_server_recordcall_on(TUP_UINT32 callid);


/**
 * @brief �رշ�����¼/��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_server_recordcall_on
 **/
TUP_API TUP_RESULT tup_call_server_recordcall_off(TUP_UINT32 callid);


/**
 * @brief �Ǽ��Զ��غ�ҵ��
 * 
 * @param [in] TUP_UINT32 account_id       <b>:</b> �˺�ID
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ҵ����������Ҫ����ȷ����
 * @see tup_call_cancel_callback
 **/
TUP_API TUP_RESULT tup_call_callback(TUP_UINT32 account_id, const TUP_CHAR* callee_number);

 
/**
 * @brief ע���Զ��غ�ҵ��
 * 
 * @param [in] TUP_UINT32 account_id       <b>:</b> �˺�ID
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ҵ����������Ҫ����ȷ����
 * @see tup_call_callback
 **/
TUP_API TUP_RESULT tup_call_cancel_callback(TUP_UINT32 account_id, const TUP_CHAR* callee_number);


/**
 * @brief ȡ��ֱ�Ӻ���פ��ҵ��
 * 
 * @param [in] TUP_UINT32 callid           <b>:</b> ����ID
 * @param [in] CALL_E_CALL_TYPE call_type  <b>:</b> �������ͣ���Ƶ����Ƶ
 * @param [in] const TUP_CHAR* pszparknum  <b>:</b> ����פ������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_callpark
 * @see tup_call_set_direct_callpark
 **/
TUP_API TUP_RESULT tup_call_get_callpark(TUP_UINT32 callid, CALL_E_CALL_TYPE call_type, const TUP_CHAR* pszparknum);


/**
 * @brief ��ȡ��ǰ���е�SIP��������Ϣ
 * 
 * @param [in] TUP_UINT32 callid                        <b>:</b> ����ID
 * @param [in] CALL_S_CURRENT_SIPSERVER* server_info  <b>:</b> SIP��������Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_sipserver_info(TUP_UINT32 callid, CALL_S_CURRENT_SIPSERVER* server_info);


/**
 * @brief ��ȡָ���˺ŵķ�������ַ�б�
 * 
 * @param [in] TUP_UINT32 account_id                <b>:</b> �˺�ID
 * @param [out] TUP_UINT32* addr_num                <b>:</b> ��ַ��Ϣ����
 * @param [out] CALL_S_SIP_ADDR_INFO* addr_info     <b>:</b> �����ַ��Ϣ������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention addr_info�ڴ���Ӧ�ò���䣬�����СΪ������������������Ϊ5
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_sipserver_addrlist(TUP_UINT32 account_id, 
                        TUP_UINT32* addr_num,  CALL_S_SIP_ADDR_INFO* addr_info);


/**
 * @brief �����߼���bridge���� 
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_SCA_in_bridgeconf(TUP_UINT32 callid);


/**
 * @brief �ɱ�̼�/��չ�尴�����ñ��֪ͨ
 * 
 * @param [in] TUP_INT32 broad_id     <b>:</b> 0:�����ɱ�̼���1:��չ��һ��2:��չ�����3:��չ����
 * @param [in] const TUP_INT32* keys  <b>:</b> ���÷����仯�İ���Loc�������, ����һ�δ���������仯�İ�����ţ�����Loc����Ǵ�1��ʼ������
 * @param [in] TUP_INT32 number       <b>:</b> ����Loc��������С��
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_progkey_modify_ind(TUP_INT32 broad_id, const TUP_INT32* keys, TUP_INT32 number);


/**
 * @brief ��ȡ��ϵ��״̬����һ�λ�ȡ�����ϵ��״̬
 * 
 * @param [in] TUP_UINT32 number               <b>:</b> ��ϵ�˸�������pastStatus�����С
 * @param [in/out] CALL_S_CONTACT_STATUS status[]  <b>:</b> ��ϵ��״̬���飬����������룬���������Ӧ�����״̬
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_contact_status(TUP_UINT32 number, CALL_S_CONTACT_STATUS status[]);


/**
 * @brief ������ϵ��״̬
 * 
 * @param [in] TUP_UINT32 account_id        <b>:</b> �˺�ID
 * @param [in] TUP_UINT32 contact_type      <b>:</b> ��ϵ������:0 ��ͨ��ϵ�ˣ�1 HUNTGROUP ��ϵ��
 * @param [in] const TUP_CHAR* contact_num  <b>:</b> ��ϵ�˺���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_unsubscribe_contact
 **/
TUP_API TUP_RESULT tup_call_subscribe_contact(TUP_UINT32 account_id, TUP_UINT32 contact_type, const TUP_CHAR* contact_num);


/**
 * @brief ȡ������ϵ��״̬�Ķ���
 * 
 * @param [in] TUP_UINT32 account_id        <b>:</b> �˺�ID
 * @param [in] const TUP_CHAR* contact_num  <b>:</b> ��ϵ�˺���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_subscribe_contact
 **/
TUP_API TUP_RESULT tup_call_unsubscribe_contact(TUP_UINT32 account_id, const TUP_CHAR* contact_num);


/**
 * @brief ����RLS(Resource List Server)�б�
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_unsubscriber_RLS
 **/
TUP_API TUP_RESULT tup_call_subscriber_RLS(TUP_UINT32 accountid);


/**
 * @brief ȡ������RLS(Resource List Server)�б�
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_subscriber_RLS
 **/
TUP_API TUP_RESULT tup_call_unsubscriber_RLS(TUP_UINT32 accountid);


/**
 * @brief ���ù�����·˽�˺���
 * 
 * @param [in] TUP_UINT32 accountid               <b>:</b> �˺�ID
 * @param [in] CALL_E_SERVICE_CALL_TYPE calltype  <b>:</b> ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_SCA_private(TUP_UINT32 accountid, CALL_E_SERVICE_CALL_TYPE calltype);


/**
 * @brief ͬ���������ҵ��Ȩ��
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention Ӳ�ն�ʹ�ã�������������( ��"�ֻ�Я��"��"�����·�����")ʱ���ɲ�Ʒ����
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_sync_service_right(TUP_VOID);


/**
 * @brief ���¼���ҵ��Ȩ��
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_update_serviceright
 **/
TUP_API TUP_RESULT tup_call_reload_serviceright(TUP_VOID);


/**
 * @brief ����ָ��ҵ��Ȩ��
 * 
 * @param [in] TUP_UINT32 accountid                       <b>:</b> �˺�ID
 * @param [in] const CALL_S_SERVICERIGHT_CFG* servicecfg  <b>:</b> �����µ�ҵ��Ȩ��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_reload_serviceright
 **/
TUP_API TUP_RESULT tup_call_update_serviceright(TUP_UINT32 accountid, const CALL_S_SERVICERIGHT_CFG* servicecfg);


/**
 * @brief ����Ǽ�ҵ��ɹ���֪ͨ����ҵ��Ȩ�޵Ǽ����
 * 
 * @param [in] TUP_UINT32 accountid                    <b>:</b> �˺�ID
 * @param [in] CALL_E_SERVICE_RIGHT_TYPE service_type  <b>:</b> ҵ������
 * @param [in] TUP_UINT32 reg                          <b>:</b> �Ǽ������CALL_E_SEVICEREGISTER_STATUS
 * @param [in] const TUP_CHAR* param                   <b>:</b> ҵ���������ǰת��Ŀ�ĺ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_service_register(TUP_UINT32 accountid, 
                    CALL_E_SERVICE_RIGHT_TYPE service_type, TUP_UINT32 reg, const TUP_CHAR* param);


/**
 * @brief ��ȡҵ��Ȩ��
 * 
 * @param [in] TUP_UINT32 accountid                 <b>:</b> �˺�ID
 * @param [out] CALL_S_SERVICERIGHT_CFG* servicecfg  <b>:</b> ҵ��Ȩ����Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_get_serviceright(TUP_UINT32 accountid, CALL_S_SERVICERIGHT_CFG* servicecfg);


/**
 * @brief ����SIP�˻���Ȩ
 * 
 * @param [in] const TUP_CHAR* number    <b>:</b> �û�����
 * @param [in] const TUP_CHAR* name      <b>:</b> �û���
 * @param [in] const TUP_CHAR* password  <b>:</b> ��Ȩ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_authorize_account(const TUP_CHAR* number, const TUP_CHAR* name, const TUP_CHAR* password);


/**
 * @brief ������������Ŀ��ƿ�
 * 
 * @param [out] TUP_UINT32 *confid  <b>:</b> ����(���ƿ�)ID
 * @param [out] TUP_UINT32 *callid  <b>:</b> ����(���ƿ�)ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ������ʹ�ã��ڴ���֮ǰ���ã�������������Ŀ��ƿ�
 * @see tup_call_serverconf_set_type
 * @see tup_call_serverconf_create_by_confid
 **/
TUP_API TUP_RESULT tup_call_serverconf_create_confid(TUP_UINT32 *confid, TUP_UINT32 *callid);


/**
 * @brief ���û�������
 * 
 * @param [in] TUP_UINT32 confid            <b>:</b> ����(���ƿ�)ID
 * @param [in] CALL_E_SERVERCONF_TYPE type  <b>:</b> ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ������ʹ�ã��ڴ���֮ǰ����,�Կ��ƴ������������
 * @see tup_call_serverconf_create_confid
 * @see tup_call_serverconf_create_by_confid
 **/
TUP_API TUP_RESULT tup_call_serverconf_set_type(TUP_UINT32 confid, CALL_E_SERVERCONF_TYPE type);


/**
 * @brief ���ݻ���id�½�����
 * 
 * @param [in] TUP_UINT32 confid         <b>:</b> ����(���ƿ�)ID
 * @param [in] const TUP_CHAR *groupuri  <b>:</b> Ⱥ��URI�������Ⱥ�����ʱ��д
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ������ʹ�ã��ڴ���֮ǰ��Ҫ����������ƿ�����û�������, 
 * @see tup_call_serverconf_create_confid
 * @see tup_call_serverconf_set_type
 **/
TUP_API TUP_RESULT tup_call_serverconf_create_by_confid(TUP_UINT32 confid, const TUP_CHAR *groupuri);


/**
 * @brief ����ָ���˻����е�callid������������Ŀ��ƿ�
 * 
 * @param [in] TUP_UINT32 accountid    <b>:</b> �˺�ID
 * @param [in] TUP_UINT32 incallid     <b>:</b> ԭ�к���ID
 * @param [out] TUP_UINT32* confid     <b>:</b> ����(���ƿ�)ID
 * @param [out] TUP_UINT32* outcallid  <b>:</b> �������Ӧ�ĺ���ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_create_confid
 **/
TUP_API TUP_RESULT tup_call_serverconf_create_confid_ex (TUP_UINT32 accountid, 
                    TUP_UINT32 incallid , TUP_UINT32* confid, TUP_UINT32* outcallid);


/**
 * @brief ����ָ����·�Ļ�������
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����(���ƿ�)ID
 * @param [in] TUP_UINT32 lineid  <b>:</b> ��·ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_accept
 **/
TUP_API TUP_RESULT tup_call_serverconf_accept_with_lineid(TUP_UINT32 confid, TUP_UINT32 lineid);


/**
 * @brief ���������CTD����
 * 
 * @param [in] TUP_UINT32 confid       <b>:</b> ����ID
 * @param [in] const TUP_CHAR *number  <b>:</b> ������CTD����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ���ڻ�ΪUC��ת����
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_add_extra_num(TUP_UINT32 confid, const TUP_CHAR *number);


/**
 * @brief �ܾ���Ե����ݻ��� 
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_reject_p2pdataconf(TUP_UINT32 confid);


/**
 * @brief ֱ�ӽ���ԤԼ����
 * 
 * @param [in] TUP_UINT32 callid           <b>:</b> ����ID
 * @param [in] const TUP_CHAR *accesscode  <b>:</b> ���������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ֱ�ӽ���ԤԼ���飬��Ҫ����callid���ṩ���������ʺŵ������ʹ��
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_access_reserved_conf_directly(TUP_UINT32 callid, const TUP_CHAR *accesscode);


/**
 * @brief ���û�������
 * 
 * @param [in] TUP_UINT32 confid            <b>:</b> ����(���ƿ�)ID
 * @param [in] const TUP_CHAR* confsubject  <b>:</b> ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ݽ�Ӳ�ն�ʹ�ã��ڴ�����������ñ��ػ������⣬���ڻ��鴰�ڴ���������ʾ
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_set_confsubject(TUP_UINT32 confid, const TUP_CHAR* confsubject);


/**
 * @brief ��ȡ�û������˺�ԤԼ�����б�
 * 
 * @param [in] TUP_VOID
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ݽ�����ʹ��
 * @see tup_call_get_conf_list_for_account
 **/
TUP_API TUP_RESULT tup_call_get_all_conf_list(TUP_VOID);


/**
 * @brief ��ȡ�û�ָ���˺�ԤԼ�����б�
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> ����ȡ�����б���˺�ID
 * @param [in] TUP_UINT32 pagesize   <b>:</b> �������б�ҳ�� 
 * @param [in] TUP_UINT32 curpage    <b>:</b> ��ǰ�����б�ҳ������ 
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ݽ�����ʹ��
 * @see tup_call_get_all_conf_list
 **/
TUP_API TUP_RESULT tup_call_get_conf_list_for_account(TUP_UINT32 accountid, TUP_UINT32 pagesize, TUP_UINT32 curpage);




/**
 * @brief ��ȡ���ػ���᳡״̬
 * 
 * @param [in] CALL_S_CONFER_LOCAL_INFO* confinfo  <b>:</b> ���ػ���᳡��Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_localconf_get_conferstate(CALL_S_CONFER_LOCAL_INFO* confinfo);


/**
 * @brief ���ػ����о����Լ�
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_unmute_self
 **/
TUP_API TUP_RESULT tup_call_localconf_mute_self(TUP_UINT32 callid);


/**
 * @brief ���ػ�����ȡ�������Լ�
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_mute_self
 **/
TUP_API TUP_RESULT tup_call_localconf_unmute_self(TUP_UINT32 callid);


/**
 * @brief ���ֱ��ػ���᳡
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_unhold
 **/
TUP_API TUP_RESULT tup_call_localconf_hold(TUP_VOID);


/**
 * @brief ȡ�����ֱ��ػ���᳡
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_hold
 **/
TUP_API TUP_RESULT tup_call_localconf_unhold(TUP_VOID);


/**
 * @brief ����Ⱥ�����
 * 
 * @param [in] TUP_UINT32 callid           <b>:</b> ����ID
 * @param [in] CALL_E_CALL_TYPE call_type  <b>:</b> ��������
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_group_pickup(TUP_UINT32 callid, CALL_E_CALL_TYPE call_type);


/**
 * @brief ���ú���ǰת
 * 
 * @param [in] const CALL_S_FORWARD_INFO* fwdconfig  <b>:</b> ǰת������������
 * @param [in] TUP_UINT32 configcount                <b>:</b> ǰת���������������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_forward_config(const CALL_S_FORWARD_INFO* fwdconfig , TUP_UINT32 configcount);


/**
 * @brief ����intercom����
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_intercom_call(TUP_UINT32 callid, const TUP_CHAR* callee_number);


/**
 * @brief ��������
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���(VVM�������)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_query
 * @see tup_call_VVM_forward
 * @see tup_call_VVM_delete
 * @see tup_call_VVM_pausal
 * @see tup_call_VVM_fast_forward
 * @see tup_call_VVM_rewind
 **/
TUP_API TUP_RESULT tup_call_VVM_listen(TUP_UINT32 callid,  const TUP_CHAR* callee_number);


/**
 * @brief ��������
 * 
 * @param [in] const CALL_S_VVM_QUERY_MSG* query  <b>:</b> VVM���������������ݽṹ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_listen
 * @see tup_call_VVM_forward
 * @see tup_call_VVM_delete
 * @see tup_call_VVM_pausal
 * @see tup_call_VVM_fast_forward
 * @see tup_call_VVM_rewind
 **/
TUP_API TUP_RESULT tup_call_VVM_query(const CALL_S_VVM_QUERY_MSG* query);


/**
 * @brief ת������
 * 
 * @param [in] const CALL_S_VVM_FWD_MSG* fwd  <b>:</b> VVMת���������ݽṹ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_listen
 * @see tup_call_VVM_query
 * @see tup_call_VVM_delete
 * @see tup_call_VVM_pausal
 * @see tup_call_VVM_fast_forward
 * @see tup_call_VVM_rewind
 **/
 
TUP_API TUP_RESULT tup_call_VVM_forward(const CALL_S_VVM_FWD_MSG* fwd);


/**
 * @brief ɾ������
 * 
 * @param [in] const CALL_S_VVM_DEL_MSG* del  <b>:</b> VVMת���������ݽṹ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_listen
 * @see tup_call_VVM_query
 * @see tup_call_VVM_forward
 * @see tup_call_VVM_pausal
 * @see tup_call_VVM_fast_forward
 * @see tup_call_VVM_rewind
 **/
TUP_API TUP_RESULT tup_call_VVM_delete(const CALL_S_VVM_DEL_MSG* del);


/**
 * @brief ���Բ���(��ͣ)
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_listen
 * @see tup_call_VVM_query
 * @see tup_call_VVM_forward
 * @see tup_call_VVM_delete
 * @see tup_call_VVM_fast_forward
 * @see tup_call_VVM_rewind
 **/
TUP_API TUP_RESULT tup_call_VVM_pausal(TUP_UINT32 callid);


/**
 * @brief ���Կ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_listen
 * @see tup_call_VVM_query
 * @see tup_call_VVM_forward
 * @see tup_call_VVM_delete
 * @see tup_call_VVM_pausal
 * @see tup_call_VVM_rewind
 **/
TUP_API TUP_RESULT tup_call_VVM_fast_forward(TUP_UINT32 callid);


/**
 * @brief ���Կ���
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_VVM_listen
 * @see tup_call_VVM_query
 * @see tup_call_VVM_forward
 * @see tup_call_VVM_delete
 * @see tup_call_VVM_pausal
 * @see tup_call_VVM_fast_forward
 **/
TUP_API TUP_RESULT tup_call_VVM_rewind(TUP_UINT32 callid);


/**
 * @brief ��¼������ȡ����¼
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_cancel_login(TUP_VOID);


/**
 * @brief ���û�������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @param [in] TUP_BOOL islink    <b>:</b> �Ƿ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_set_linked(TUP_UINT32 callid, TUP_BOOL islink);


/**
 * @brief ������������β���
 * 
 * @param [in] TUP_UINT32 confid        <b>:</b> ����ID
 * @param [in] CALL_E_DTMF_TONE keyevt  <b>:</b> DTMF��ֵ
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_send_DTMF(TUP_UINT32 confid, CALL_E_DTMF_TONE keyevt);


/**
 * @brief �����Ե㷽�������ݻ���
 * 
 * @param [in] TUP_UINT32 confid           <b>:</b> ����ID
 * @param [in] const TUP_CHAR* p2p_number  <b>:</b> �������P2P����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��ΪUC�����£�CTD������²���Ҫ����
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_add_p2p_to_dataconf(TUP_UINT32 confid, const TUP_CHAR* p2p_number);


/**
 * @brief ������������
 * 
 * @param [in] TUP_UINT32 confid              <b>:</b> ����ID
 * @param [in] TUP_UINT32 attendcount         <b>:</b> ���������
 * @param [in] const  TUP_CHAR* attendnumber  <b>:</b> ����ߺ�������
 * @param [in] TUP_UINT32 pernumsize          <b>:</b> ÿ��������󳤶�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_create_linkage_conf(TUP_UINT32 confid, 
                    TUP_UINT32 attendcount, const  TUP_CHAR* attendnumber, TUP_UINT32 pernumsize);


/**
 * @brief ���þܾ�ǰת���翪��
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> �˺�ID
 * @param [in] TUP_BOOL switches     <b>:</b> 1 ������0 �ر�
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_DICF_switct(TUP_UINT32 accountid, TUP_BOOL switches);



/**
 * @brief ���������˺�DND
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_all_account_DND_off
 **/
TUP_API TUP_RESULT tup_call_set_all_account_DND_on(TUP_VOID);


/**
 * @brief �ر������˺�DND
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_all_account_DND_on
 **/
TUP_API TUP_RESULT tup_call_set_all_account_DND_off(TUP_VOID);


/**
 * @brief ���������˺�ȱϯҵ��
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_all_account_absent_off
 **/
TUP_API TUP_RESULT tup_call_set_all_account_absent_on(TUP_VOID);


/**
 * @brief ���������˺�ȡ��ȱϯ
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_all_account_absent_on
 **/
TUP_API TUP_RESULT tup_call_set_all_account_absent_off(TUP_VOID);


/**
 * @brief ����MCID(������и�*��)
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_MCID(TUP_UINT32 accountid);


/**
 * @brief �����Ǽ������˺�IPTҵ��
 * 
 * @param [in] const CALL_S_IPT_DATA* IPTdata  <b>:</b> ���Ǽǵ�IPTҵ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_IPTservice_batch(const CALL_S_IPT_DATA* IPTdata);


/**
 * @brief �����Ǽ�ָ���˺�IPTҵ��
 * 
 * @param [in] TUP_UINT32 accountid      <b>:</b> �˺�ID
 * @param [in] CALL_S_IPT_DATA* IPTdata  <b>:</b> ���Ǽǵ�IPTҵ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_IPTservice_for_accout(TUP_UINT32 accountid, CALL_S_IPT_DATA* IPTdata);


/**
 * @brief ����ָ���˺������޺�
 * 
 * @param [in] TUP_UINT32 accountid            <b>:</b> �˺�ID
 * @param [in] const CALL_S_IPT_DATA* IPTdata  <b>:</b> �����޺�ҵ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_cancel_callbarring_for_account
 **/
TUP_API TUP_RESULT tup_call_set_callbarring_for_account(TUP_UINT32 accountid, const CALL_S_IPT_DATA* IPTdata);


/**
 * @brief �ر�ָ���˺������޺�
 * 
 * @param [in] TUP_UINT32 accountid            <b>:</b> �˺�ID
 * @param [in] const CALL_S_IPT_DATA* IPTdata  <b>:</b> �����޺�ҵ����������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_callbarring_for_account
 **/
TUP_API TUP_RESULT tup_call_cancel_callbarring_for_account(TUP_UINT32 accountid, const CALL_S_IPT_DATA* IPTdata);


/**
 * @brief �ϲ�����
 * 
 * @param [in] TUP_UINT32 confid                  <b>:</b> ����ID
 * @param [in] const TUP_CHAR* security_conf_num  <b>:</b> ��ȫ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_split
 **/
TUP_API TUP_RESULT tup_call_serverconf_merger(TUP_UINT32 confid, const TUP_CHAR* security_conf_num);


/**
 * @brief ��ֻ���
 * 
 * @param [in] TUP_UINT32 confid                  <b>:</b> ����ID
 * @param [in] const TUP_CHAR* security_conf_num  <b>:</b> ��ȫ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_serverconf_merger
 **/
TUP_API TUP_RESULT tup_call_serverconf_split(TUP_UINT32 confid, const TUP_CHAR* security_conf_num);


/**
 * @brief ������Ƶ����
 * 
 * @param [in] CALL_E_VIDEOWND_TYPE wndtype  <b>:</b> ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention Ӳ�ն���Ҫʹ��
 * @see tup_call_create_video_window
 * @see tup_call_set_video_window
 **/
TUP_API TUP_RESULT tup_call_destroy_video_window(CALL_E_VIDEOWND_TYPE wndtype);



/**
 * @brief ������Ƶ����
 * 
 * @param [in] TUP_UINT32 ctrl_type                <b>:</b> ��Ƶ���ڿ������ͣ���ӦCALL_E_VIDEOWND_CTRL_TYPE
 * @param [in] const CALL_S_VIDEOWND_INFO* window  <b>:</b> ��Ƶ������Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention Ӳ�ն���Ҫʹ��
 * @see tup_call_destroy_video_window
 **/
TUP_API TUP_RESULT tup_call_change_video_window(TUP_UINT32 ctrl_type, const CALL_S_VIDEOWND_INFO* window);


/**
 * @brief ͨ���д򿪱���Ԥ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_close_local_preview_in_dialog
 **/
TUP_API TUP_RESULT tup_call_open_local_preview_in_dialog(TUP_UINT32 callid);


/**
 * @brief ͨ���йرձ���Ԥ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_open_local_preview_in_dialog
 **/
TUP_API TUP_RESULT tup_call_close_local_preview_in_dialog(TUP_UINT32 callid);


/**
 * @brief ͨ���д�Զ��Ԥ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_close_remote_preview_in_dialog
 **/
TUP_API TUP_RESULT tup_call_open_remote_preview_in_dialog(TUP_UINT32 callid);


/**
 * @brief ͨ���йر�Զ��Ԥ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_open_remote_preview_in_dialog
 **/
TUP_API TUP_RESULT tup_call_close_remote_preview_in_dialog(TUP_UINT32 callid);


/**
 * @brief ������Ƶ�ػ������ڲ��Ա���MIC��Speaker
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_close_audio_preview
 **/
TUP_API TUP_RESULT tup_call_open_audio_preview(TUP_VOID);


/**
 * @brief �ر���Ƶ�ػ������ڲ��Ա���MIC��Speaker
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_open_audio_preview
 **/
TUP_API TUP_RESULT tup_call_close_audio_preview(TUP_VOID);


/**
 * @brief ����ָ���˺ŵ�ȱϯҵ��
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_cancel_absent_for_account
 **/
TUP_API TUP_RESULT tup_call_set_absent_for_account(TUP_UINT32 accountid);


/**
 * @brief ȡ��ָ���˺ŵ�ȱϯҵ��
 * 
 * @param [in] TUP_UINT32 accountid  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_absent_for_account
 **/
TUP_API TUP_RESULT tup_call_cancel_absent_for_account(TUP_UINT32 accountid);

/**
 * @brief �����˺�״̬
 * 
 * @param [in] IN TUP_UINT32 account_id     <b>:</b> �˺�ID
 * @param [in] IN TUP_UINT32 status_type    <b>:</b> ״̬��Ϣ����ӦCALL_E_CONTACT_STATUS
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_publish_setting_status(IN TUP_UINT32 account_id, IN TUP_UINT32 status_type);


/**
 * @brief �Ự���ֻ��ֻ��л�
 * 
 * @param [in] TUP_UINT32 callid      <b>:</b> ����ID
 * @param [in] const TUP_CHAR* MPnum  <b>:</b> �ֻ��ֻ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_mobile_extend_call(TUP_UINT32 callid, const TUP_CHAR* pszMPNum);


/**
 * @brief ����intercom˫��ͨ������
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_answer_intercom_call(TUP_UINT32 callid);


/**
 * @brief ����ֱ�Ӻ���פ��ҵ��
 * 
 * @param [in] TUP_UINT32 callid             <b>:</b> ����ID
 * @param [in] const TUP_CHAR*  direct_num   <b>:</b> ����פ������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 
 * @attention NA
 * @see tup_call_set_callpark
 * @see tup_call_get_callpark
 **/
TUP_API TUP_RESULT tup_call_direct_callpark(TUP_UINT32 callid, const TUP_CHAR* direct_num);


/**
 * @brief ���ú���פ��ҵ��
 * 
 * @param [in] TUP_UINT32 callid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_direct_callpark
 * @see tup_call_get_callpark
 **/
TUP_API TUP_RESULT tup_call_callpark(TUP_UINT32 callid);


/**
 * @brief ����˽�˱���
 * 
 * @param [in] TUP_UINT32 ulCallID  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_private_hold_call (TUP_UINT32 callid);


/**
 * @brief ������λ����
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> �˺�ID
 * @param [in] CALL_E_CALL_TYPE call_type     <b>:</b> ��������
 * @param [in] const TUP_CHAR* callee_number  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_abbrdial_Call(TUP_UINT32 callid, CALL_E_CALL_TYPE call_type, const TUP_CHAR* callee_number);

/**
 * @brief ����ָ������
 * 
 * @param [in] TUP_UINT32 callid             <b>:</b> ����ID
 * @param [in] CALL_E_CALL_TYPE call_type    <b>:</b> ��������
 * @param [in] const TUP_CHAR* calleenumber  <b>:</b> ���к���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_point_pickup(TUP_UINT32 callid, CALL_E_CALL_TYPE call_type, const TUP_CHAR* callee_number);


/**
 * @brief �������ػ���
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_join
 * @see tup_call_localconf_drop_conferee
 * @see tup_call_localconf_mute_conferee
 * @see tup_call_localconf_unmute_conferee
 * @see tup_call_localconf_end
 **/
TUP_API TUP_RESULT tup_call_localconf_create(TUP_UINT32 call_id);


/**
 * @brief ���뱾�ػ���
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_create
 * @see tup_call_localconf_drop_conferee
 * @see tup_call_localconf_mute_conferee
 * @see tup_call_localconf_unmute_conferee
 * @see tup_call_localconf_end
 **/
TUP_API TUP_RESULT tup_call_localconf_join(TUP_UINT32 call_id);


/**
 * @brief �޳������
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_create
 * @see tup_call_localconf_join
 * @see tup_call_localconf_mute_conferee
 * @see tup_call_localconf_unmute_conferee
 * @see tup_call_localconf_end
 **/
TUP_API TUP_RESULT tup_call_localconf_drop_conferee(TUP_UINT32 call_id);

/**
 * @brief ���������
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_create
 * @see tup_call_localconf_join
 * @see tup_call_localconf_drop_conferee
 * @see tup_call_localconf_unmute_conferee
 * @see tup_call_localconf_end
 **/
TUP_API TUP_RESULT tup_call_localconf_mute_conferee(TUP_UINT32 call_id);


/**
 * @brief ȡ�����������
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_create
 * @see tup_call_localconf_join
 * @see tup_call_localconf_drop_conferee
 * @see tup_call_localconf_mute_conferee
 * @see tup_call_localconf_end
 **/
TUP_API TUP_RESULT tup_call_localconf_unmute_conferee(TUP_UINT32 call_id);


/**
 * @brief �������ػ���
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_localconf_create
 * @see tup_call_localconf_join
 * @see tup_call_localconf_drop_conferee
 * @see tup_call_localconf_mute_conferee
 * @see tup_call_localconf_unmute_conferee
 **/
TUP_API TUP_RESULT tup_call_localconf_end(TUP_VOID);


/**
 * @brief ��������·ǿ��
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_SCA_retrieve
 * @see tup_call_SCA_sub_state
 * @see tup_call_SCA_offhook
 **/
TUP_API TUP_RESULT tup_call_SCA_insert (TUP_UINT32 call_id);


/**
 * @brief ��������·ʰ��
 * 
 * @param [in] TUP_UINT32 call_id  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_SCA_insert
 * @see tup_call_SCA_sub_state
 * @see tup_call_SCA_offhook
 **/
TUP_API TUP_RESULT tup_call_SCA_retrieve (TUP_UINT32 call_id);


/**
 * @brief �������߶���
 * 
 * @param [in] TUP_UINT32 account_id  <b>:</b> �˺�ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_SCA_insert
 * @see tup_call_SCA_retrieve
 * @see tup_call_SCA_offhook
 **/
TUP_API TUP_RESULT tup_call_SCA_sub_state(TUP_UINT32 account_id);


/**
 * @brief ������·ժ��
 * 
 * @param [in] TUP_UINT32 account_id   <b>:</b> �˺�ID
 * @param [in] TUP_UINT32 sca_line_id  <b>:</b> ��������·ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_SCA_insert
 * @see tup_call_SCA_retrieve
 * @see tup_call_SCA_sub_state
 **/
TUP_API TUP_RESULT tup_call_SCA_offhook (TUP_UINT32 account_id, TUP_UINT32 sca_line_id);


/**
 * @brief ֹͣ�����ź���
 * 
 * @param [in] TUP_UINT32 sender_handle  <b>:</b> �ź������ͷ��Ĵ���ģ��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_play_signal_tone
 **/
TUP_API TUP_RESULT tup_call_media_stop_signal_tone(TUP_UINT32 sender_handle);


/**
 * @brief �����ź���
 * 
 * @param [in] TUP_UINT32 toneid         <b>:</b> �ź���ID
 * @param [in] TUP_BOOL is_cycle         <b>:</b> �Ƿ�ѭ������
 * @param [in] TUP_UINT32 sender_handle  <b>:</b> �ź������ͷ��Ĵ���ģ��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_stop_signal_tone
 **/
TUP_API TUP_RESULT tup_call_media_play_signal_tone(TUP_UINT32 toneid, TUP_BOOL is_cycle, TUP_UINT32 sender_handle);


/**
 * @brief ���Ż᳡�ź���
 * 
 * @param [in] TUP_UINT32 toneid         <b>:</b> �ź���ID
 * @param [in] TUP_BOOL is_cycle         <b>:</b> �Ƿ�ѭ������
 * @param [in] TUP_UINT32 sender_handle  <b>:</b> �ź������ͷ��Ĵ���ģ��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_stop_signal_tone_to_conf
 **/
TUP_API TUP_RESULT tup_call_media_play_signal_tone_to_conf(TUP_UINT32 toneid, TUP_BOOL iscycle, TUP_UINT32 sender_handle);


/**
 * @brief ֹͣ���Ż᳡�ź���
 * 
 * @param [in] TUP_UINT32 sender_handle  <b>:</b> �ź������ͷ��Ĵ���ģ��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_play_signal_tone_to_conf
 **/
TUP_API TUP_RESULT tup_call_media_stop_signal_tone_to_conf(TUP_UINT32 senderhandle);


/**
 * @brief ������������
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE aud_direction  <b>:</b> ��Ƶ��������豸����(Ӳ�ն�ʹ��)
 * @param [in] TUP_UINT32 volume                  <b>:</b> ����ֵ��ȡֵ��Χ[0, 100]
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_get_mic_volume
 * @see tup_call_media_get_mic_level
 **/
TUP_API TUP_RESULT tup_call_media_set_mic_volume(CALL_E_AUDDEV_ROUTE aud_direction, TUP_UINT32 volume);


/**
 * @brief ��ȡ�������
 * 
 * @param [out] TUP_UINT32* volume  <b>:</b> ����ֵ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_set_speak_volume
 * @see tup_call_media_get_speak_level
 **/
TUP_API TUP_RESULT tup_call_media_get_speak_volume(TUP_UINT32* volume);


/**
 * @brief ��ȡ�����������
 * 
 * @param [out] TUP_UINT32* level  <b>:</b> ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_set_speak_volume
 * @see tup_call_media_get_speak_volume
 **/
TUP_API TUP_RESULT tup_call_media_get_speak_level(TUP_UINT32* level);


/**
 * @brief ��ȡ��������
 * 
 * @param [out] TUP_UINT32* volume  <b>:</b> ����ֵ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_set_mic_volume
 * @see tup_call_media_get_mic_level
 **/
TUP_API TUP_RESULT tup_call_media_get_mic_volume(TUP_UINT32* volume);


/**
 * @brief ��ȡ������������
 * 
 * @param [out] TUP_UINT32* level  <b>:</b> ��������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_set_mic_volume
 * @see tup_call_media_get_mic_volume
 **/
TUP_API TUP_RESULT tup_call_media_get_mic_level(TUP_UINT32* level);


/**
 * @brief ��ȡϵͳ����������״̬
 * 
 * @param [out] TUP_BOOL* is_mute  <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_get_sys_mic_mute
 **/
TUP_API TUP_RESULT tup_call_media_get_sys_spk_mute(TUP_BOOL* is_mute);

 
/**
 * @brief ��ȡϵͳ��˷羲��״̬
 * 
 * @param [out] TUP_BOOL* is_mute  <b>:</b> �Ƿ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_get_sys_spk_mute
 **/
TUP_API TUP_RESULT tup_call_media_get_sys_mic_mute(TUP_BOOL* is_mute);


/**
 * @brief ��ȡӲ����������
 * 
 * @param [out] CALL_S_VIDEO_HDACCELERATE *hd_accelerate  <b>:</b> ��Ƶ�������������Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_media_get_hdaccelerate(CALL_S_VIDEO_HDACCELERATE *hd_accelerate);


/**
 * @brief ��ʼ��������
 * 
 * @param [in] const TUP_INT8* ringfile  <b>:</b> �����ļ�
 * @param [in] TUP_UINT32 senderhandler  <b>:</b> �������ŷ��Ĵ���ģ��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_stop_ring_tone
 **/
TUP_API TUP_RESULT tup_call_media_play_ring_tone(const TUP_INT8* ringfile,  TUP_UINT32 senderhandler);


/**
 * @brief ֹͣ��������
 * 
 * @param [in] TUP_UINT32 senderhandler  <b>:</b> �������ŷ��Ĵ���ģ��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_media_play_ring_tone
 **/
TUP_API TUP_RESULT tup_call_media_stop_ring_tone(TUP_UINT32 senderhandler);


/**
 * @brief ����Ӳ��(����ͷ)����
 * 
 * @param [in] const CALL_S_HARDWARE_PARAMS* hardwareparams  <b>:</b> Ӳ��(����ͷ)�����ṹ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_get_hardware_params
 **/
TUP_API TUP_RESULT tup_call_set_hardware_params(const CALL_S_HARDWARE_PARAMS* hardwareparams);


/**
 * @brief ��ȡӲ��(����ͷ)����
 * 
 * @param [in] CALL_S_HARDWARE_PARAMS* hardwareparams  <b>:</b> Ӳ��(����ͷ)�����ṹ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_hardware_params
 **/
TUP_API TUP_RESULT tup_call_get_hardware_params(CALL_S_HARDWARE_PARAMS* hardwareparams);


/**
 * @brief �ı���Ƶ������ʾλ��
 * 
 * @param [in] CALL_E_VIDEOWND_TYPE wndtype                        <b>:</b> ��������
 * @param [in] const TUP_INT32 coordinate[CALL_E_COORDINATE_BUTT]  <b>:</b> Ŀ��������Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ݽ�Ӳ�ն���Ҫʹ��
 * @see tup_call_change_video_window_type
 **/
TUP_API TUP_RESULT tup_call_change_video_window_pos(CALL_E_VIDEOWND_TYPE wndtype, const TUP_INT32 coordinate[CALL_E_COORDINATE_BUTT]);


/**
 * @brief �ı���Ƶ������ʾ����
 * 
 * @param [in] CALL_E_VIDEOWND_TYPE wndtype  <b>:</b> ��������
 * @param [in] TUP_UINT32 displaytype        <b>:</b> Ŀ����ʾ���ͣ�0:����ģʽ 1:(������)�ڱ�ģʽ 2:(������)�ü�ģʽ)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �ݽ�Ӳ�ն���Ҫʹ��
 * @see tup_call_change_video_window_pos
 **/
TUP_API TUP_RESULT tup_call_change_video_window_type(CALL_E_VIDEOWND_TYPE wndtype, TUP_UINT32 displaytype);


/**
 * @brief ��ȡ��ȫ���������
 * 
 * @param [in] TUP_UINT32 confid         <b>:</b> ����ID
 * @param [out] TUP_CHAR*  security_num  <b>:</b> ��ȫ�����
 * @param [in] TUP_UINT32 numsize        <b>:</b> �洢��ȫ������ڴ�Ĵ�С
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_serverconf_get_securitynum(TUP_UINT32 confid, TUP_CHAR* security_num, TUP_UINT32 numsize);


/**
 * @brief һ��ת��������
 * 
 * @param [in] TUP_UINT32 callid              <b>:</b> ����ID
 * @param [in] const TUP_CHAR* divert_number  <b>:</b> ����פ��
 * @param [in] TUP_BOOL is_callpicked         <b>:</b> ͨ���Ƿ��Ѿ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_onekey_transferto_VM(TUP_UINT32 callid, const TUP_CHAR* divert_number, TUP_BOOL is_callpicked);


/**
 * @brief ������Ƶ���鴰��
 * 
 * @param [in] TUP_UINT32 confid                         <b>:</b> ����ID
 * @param [in] const CALL_S_VIDEOWND_INFO* videowndinfo  <b>:</b> ��Ƶ������Ϣ
 * @param [in] TUP_UINT32 wndnum                         <b>:</b> ����������ȡֵ[1,20]
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_destroy_wnd
 **/
TUP_API TUP_RESULT tup_call_videoconf_create_wnd(TUP_UINT32 confid, const CALL_S_VIDEOWND_INFO* videowndinfo, TUP_UINT32 wndnum);


/**
 * @brief ������Ƶ���鴰��
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_create_wnd
 **/
TUP_API TUP_RESULT tup_call_videoconf_destroy_wnd(TUP_UINT32 confid);


/**
 * @brief ����Ƶ�����Լ�����Ƶ
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_close_self_video
 **/
TUP_API TUP_RESULT tup_call_videoconf_open_self_video(TUP_UINT32 confid);


/**
 * @brief �ر���Ƶ�����Լ�����Ƶ
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_close_self_video
 **/
TUP_API TUP_RESULT tup_call_videoconf_close_self_video(TUP_UINT32 confid);


/**
 * @brief ֪ͨ��Ƶ��������ߴ���Ƶ
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_notify_attend_close_video
 **/
TUP_API TUP_RESULT tup_call_videoconf_notify_attend_open_video(TUP_UINT32 confid, const TUP_CHAR* attendnum);


/**
 * @brief ֪ͨ��Ƶ��������ߴ���Ƶ
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_notify_attend_open_video
 **/
TUP_API TUP_RESULT tup_call_videoconf_notify_attend_close_video(TUP_UINT32 confid, const TUP_CHAR* attendnum);



/**
 * @brief ��ʾ�������Ƶ������
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @param [in] TUP_UINT32 wndid           <b>:</b> ����ID
 * @param [in] TUP_UINT32 ishighstream    <b>:</b> �Ƿ��Ǹ�(����)��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_detach_attend_video_from_wnd
 **/
TUP_API TUP_RESULT tup_call_videoconf_attach_attend_video_to_wnd(TUP_UINT32 confid, 
                    const TUP_CHAR* attendnum, TUP_UINT32 wndid, TUP_UINT32 ishighstream);


/**
 * @brief ȡ����ʾ�������������
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @param [in] TUP_UINT32 wndid           <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_attach_attend_video_to_wnd
 **/
TUP_API TUP_RESULT tup_call_videoconf_detach_attend_video_from_wnd(TUP_UINT32 confid, 
                    const TUP_CHAR* attendnum, TUP_UINT32 wndid);

/**
 * @brief �ı���Ƶ�����������Ƶ���ڴ�С
 * 
 * @param [in] TUP_UINT32 confid                    <b>:</b> ����ID
 * @param [in] TUP_UINT32 wndid                     <b>:</b> ����ID
 * @param [in] const CALL_S_VIDEOWND_INFO* wndinfo  <b>:</b> ������Ϣ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_change_wnd_size(TUP_UINT32 confid, TUP_UINT32 wndid, const CALL_S_VIDEOWND_INFO* wndinfo);


/**
 * @brief �л���Ƶ�����������Ƶ�ֱ��ʣ������͵���
 * 
 * @param [in] TUP_UINT32 confid            <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum    <b>:</b> ����ߺ���
 * @param [in] TUP_UINT32 ishighresolution  <b>:</b> �Ƿ��Ǹ�(����)��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_switch_attend_video_resolution(TUP_UINT32 confid, const TUP_CHAR* attendnum, TUP_UINT32 ishighresolution);


/**
 * @brief �ر���Ƶ���������������Ƶ
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_close_self_all_video(TUP_UINT32 confid);


/**
 * @brief ��ͣ��Ƶ���鱾����Ƶ
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_resume_attend_local_video
 **/
TUP_API TUP_RESULT tup_call_videoconf_pause_attend_local_video(TUP_UINT32 confid, const TUP_CHAR* attendnum);


/**
 * @brief �ָ���Ƶ���鱾����Ƶ
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_pause_attend_local_video
 **/
TUP_API TUP_RESULT tup_call_videoconf_resume_attend_local_video(TUP_UINT32 confid, const TUP_CHAR* attendnum);


/**
 * @brief �ı���Ƶ�����������Ƶ����"Z"��
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @param [in] TUP_UINT32 zorder  <b>:</b> "Z"��
 * @param [in] TUP_UINT32 wndid   <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_change_wnd_zorder(TUP_UINT32 confid, TUP_UINT32 zorder, TUP_UINT32 wndid);


/**
 * @brief ��Ƶ����ת��Ƶ����
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_voiceconf_tranfto_videoconf(TUP_UINT32 confid);


/**
 * @brief �ı���Ƶ�������������Ƶ���ڴ�С�ʹ���Z��
 * 
 * @param [in] TUP_UINT32 confid                      <b>:</b> ����ID
 * @param [in] const CALL_S_VIDEOWND_INFO* videoinfo  <b>:</b> ������Ϣ
 * @param [in] TUP_UINT32 infocount                   <b>:</b> ������Ϣ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_change_wnd_pos(TUP_UINT32 confid, const CALL_S_VIDEOWND_INFO* videoinfo, TUP_UINT32 infocount);


/**
 * @brief ����Ƶ����Ԥ��
 * 
 * @param [in] TUP_UINT32 confid                               <b>:</b> ����ID
 * @param [in] TUP_UINT32 wndid                                <b>:</b> ����ID
 * @param [in] const CALL_S_VIDEOCONF_VIDEO_PARAM* videoparam  <b>:</b> ��Ƶ����Ԥ������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_videoconf_close_preview
 **/
TUP_API TUP_RESULT tup_call_videoconf_open_preview(TUP_UINT32 confid, TUP_UINT32 wndid, const CALL_S_VIDEOCONF_VIDEO_PARAM* videoparam);


/**
 * @brief �ر���Ƶ����Ԥ��
 * 
 * @param [in] TUP_UINT32 confid  <b>:</b> ����ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_close_preview(TUP_UINT32 confid);


/**
 * @brief ��ȡ��Ƶ�����������Ƶ״̬
 * 
 * @param [in] TUP_UINT32 confid          <b>:</b> ����ID
 * @param [in] const TUP_CHAR* attendnum  <b>:</b> ����ߺ���
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_videoconf_get_video_device_status(TUP_UINT32 confid, const TUP_CHAR* attendnum);


/**
 * @brief  װ�����Կ�ʼͬ������
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE audioinputdev  <b>:</b> ��Ƶ�����豸
 * @param [in] TUP_UINT32 volume                  <b>:</b> ����
 * @param [in] TUP_UINT32 samplefreq              <b>:</b> ������
 * @param [in] TUP_UINT32 bitwide                 <b>:</b> ����
 * @param [in] TUP_UINT32 recordtime              <b>:</b> ͬ������ʱ��
 * @param [in] TUP_UINT32 audiotype               <b>:</b> ��Ƶ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_eqpt_test_stop_record
 **/
TUP_API TUP_RESULT tup_call_eqpt_test_start_record(CALL_E_AUDDEV_ROUTE audioinputdev, TUP_UINT32 volume, 
                    TUP_UINT32 samplefreq, TUP_UINT32 bitwide, TUP_UINT32 recordtime, TUP_UINT32 audiotype);


/**
 * @brief װ������ֹͣͬ������
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE audioinputdev  <b>:</b> ��Ƶ�����豸
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_eqpt_test_start_record
 **/
TUP_API TUP_RESULT tup_call_eqpt_test_stop_record(CALL_E_AUDDEV_ROUTE audioinputdev);


/**
 * @brief װ�����Կ�ʼ����
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE audioinputdev  <b>:</b> ��Ƶ�����豸
 * @param [in] TUP_UINT32 volume                  <b>:</b> ����
 * @param [in] TUP_UINT32 samplefreq              <b>:</b> ������
 * @param [in] TUP_UINT32 bitwide                 <b>:</b> ����
 * @param [in] TUP_UINT32 AMPtype                 <b>:</b> AMP����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_eqpt_test_stop_play
 **/
TUP_API TUP_RESULT tup_call_eqpt_test_start_play(CALL_E_AUDDEV_ROUTE audiooutputdev, 
                    TUP_UINT32 volume, TUP_UINT32 samplefreq, TUP_UINT32 bitwide, TUP_UINT32 AMPtype);


/**
 * @brief װ�����Կ�ʼ����
 * 
 * @param [in] CALL_E_AUDDEV_ROUTE audiooutputdev  <b>:</b> ��Ƶ�����豸
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_eqpt_test_start_play
 **/
TUP_API TUP_RESULT tup_call_eqpt_test_stop_play(CALL_E_AUDDEV_ROUTE audiooutputdev);


/**
 * @brief �л�DND����(����/������)
 * 
 * @param [in] TUP_UINT32 DNDtype       <b>:</b> DNDģʽ����ӦCALL_E_DND_TYPE
 * @param [in] TUP_UINT32 localDNDtype  <b>:</b> DND���ͣ���ӦCALL_E_LOCALDND_TYPE
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_switch_DND_type(TUP_UINT32 DNDtype, TUP_UINT32 localDNDtype);


/**
 * @brief ������Ƶ�豸����
 * 
 * @param [in] TUP_UINT32 anc  <b>:</b> ��������
 * @param [in] TUP_UINT32 aec  <b>:</b> ��������
 * @param [in] TUP_UINT32 agc  <b>:</b> �Զ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_AEC_params
 **/
TUP_API TUP_RESULT tup_call_set_audio_dev_options(TUP_UINT32 anc, TUP_UINT32 aec, TUP_UINT32 agc);


/**
 * @brief ������ƵAEC����
 * 
 * @param [in] const CALL_S_AUDIO_AEC_PARAMS* pstAecParams  <b>:</b> ��ƵAEC����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_set_audio_dev_options
 **/
TUP_API TUP_RESULT tup_call_set_AEC_params(const CALL_S_AUDIO_AEC_PARAMS* aec_params);


/**
 * @brief ������ƵEQ����
 * 
 * @param [in] const CALL_S_AUDIO_EQ_CONFIG* pstEqConfig  <b>:</b> ��ƵEQ����
 * @param [in] CALL_E_AO_DEV enAudDirection               <b>:</b> ��Ƶ��������豸����(���ն�ʹ��)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_get_EQ_param
 * @see tup_call_set_preset_EQ_param
 **/
TUP_API TUP_RESULT tup_call_set_EQ_param(const CALL_S_AUDIO_EQ_CONFIG* pstEqConfig, CALL_E_AO_DEV enAudDirection);


/**
 * @brief ��ȡ��ƵEQ����
 * 
 * @param [out] CALL_S_AUDIO_EQ_CONFIG* pstEqConfig  <b>:</b> ��ƵEQ����
 * @param [in] CALL_E_AO_DEV enAudDirection          <b>:</b> ��Ƶ��������豸����(���ն�ʹ��)
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @see tup_call_set_EQ_param
 * @see tup_call_set_preset_EQ_param
 **/
TUP_API TUP_RESULT tup_call_get_EQ_param(CALL_S_AUDIO_EQ_CONFIG* pstEqConfig, CALL_E_AO_DEV enAudDirection);


/**
 * @brief ����Ԥ����ƵEQ����
 * 
 * @param [in] CALL_E_PRESET_EQ_TYPE enPresetEqType  <b>:</b> Ԥ����ƵEQ����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @see tup_call_set_EQ_param
 * @see tup_call_get_EQ_param
 **/
TUP_API TUP_RESULT tup_call_set_preset_EQ_param(CALL_E_PRESET_EQ_TYPE enPresetEqType);


/**
 * @brief �ر�ָ���˻�ˢ��ע��
 * 
 * @param [in] const TUP_CHAR* number  <b>:</b> �˻�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˻���������Ǽ�Ȩ����
 * @see tup_call_start_refreshregister
 **/
TUP_API TUP_RESULT tup_call_stop_refreshregister(const TUP_CHAR* number);


/**
 * @brief ����ָ���˻�ˢ��ע��
 * 
 * @param [in] const TUP_CHAR* number  <b>:</b> �˻�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention �˻���������Ǽ�Ȩ����
 * @see tup_call_stop_refreshregister
 **/
TUP_API TUP_RESULT tup_call_start_refreshregister(const TUP_CHAR* number);


/**
 * @brief ������Ϣ���ȡԭʼ��Ϣ
 * 
 * @param [in] TUP_UINT8* msgbody  <b>:</b> ��Ϣ��
 * @retval TUP_API TUP_VOID* <b>:</b> �ɹ�����ԭʼ��Ϣָ�룬ʧ�ܷ��ؿ�
 * 
 * @attention �����������ȫ����ֹ��ʹ��(���ݲ�Ʒ��ʷ�汾�ݱ����Ľӿ�)
 * @see NA
 **/
TUP_API TUP_VOID* tup_call_get_notifiy_msg_by_msgbody(TUP_UINT8* msgbody);


/**
 * @brief ���ÿͻ�����
 * 
 * @param [in] const TUP_CHAR* client_name  <b>:</b> �ͻ������ַ��������Ȳ�����11���ֽ�
 * @retval TUP_API TUP_VOID <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_VOID tup_call_set_client_name(const TUP_CHAR* client_name);


/**
 * @brief ����(CALL����)Ӧ�ò���Ϣ��������
 * 
 * @param [in] const TUP_CHAR* client_name  <b>:</b> ��Ϣ��������
 * @param [in] TUP_BOOL bIsUI               <b>:</b> �Ƿ�UI
 * @param [in] TUP_BOOL bIsReg              <b>:</b> �Ƿ�ע��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_notify_client_name(const TUP_CHAR* client_name, TUP_BOOL bIsUI, TUP_BOOL bIsReg);


/**
 * @brief ע��ص�����(�����ص�����) 
 * 
 * @param [in] CALL_FN_CALLBACK_PTR callback_process_notify  <b>:</b> �ص�������ַ
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_deregister_process_notifiy_ex
 **/
TUP_API TUP_RESULT tup_call_register_process_notifiy_ex(CALL_FN_CALLBACK_PTR callback_process_notify);


/**
 * @brief ע���ص�����(�����ص�����) 
 * 
 * @param [in] TUP_VOID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_register_process_notifiy_ex
 **/
TUP_API TUP_RESULT tup_call_deregister_process_notifiy_ex(TUP_VOID);


/**
 * @brief huntgroupǩ��
 * 
 * @param [in] TUP_UINT32 callid             <b>:</b> ����ID
 * @param [in] const TUP_CHAR *group_number  <b>:</b> HuntGroup��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see  tup_call_huntgroup_signout
 **/
TUP_API TUP_RESULT tup_call_huntgroup_signin(TUP_UINT32 callid, const TUP_CHAR *group_number);


/**
 * @brief huntgroupǩ��
 * 
 * @param [in] TUP_UINT32 callid             <b>:</b> ����ID
 * @param [in] const TUP_CHAR *group_number  <b>:</b> HuntGroup��
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see tup_call_huntgroup_signin
 **/
TUP_API TUP_RESULT tup_call_huntgroup_signout(TUP_UINT32 callid, const TUP_CHAR *group_number);


/**
 * @brief ��ȡHuntGroup״̬
 * 
 * @param [in] TUP_UINT32 ulSipAccountID          <b>:</b> �˺�ID
 * @param [out] CALL_S_CONTACT_STATUS *pstStatus  <b>:</b> ��ϵ��״̬
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_huntgroup_getstatus(TUP_UINT32 ulSipAccountID, CALL_S_CONTACT_STATUS *pstStatus);


/**
 * @brief ����paging��
 * 
 * @param [in] TUP_UINT32 ulGroupID  <b>:</b> Paging��ID
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see CALL_E_EVT_PAGING_INCOMING
 * @see tup_call_paging_end
 **/
TUP_API TUP_RESULT tup_call_paging_accept(TUP_UINT32 ulGroupID);


/**
 * @brief ����paging�鲥��
 * 
 * @param [in] TUP_UINT32 ulGroupID  <b>:</b> Paging��ID
 * @param [out] NA
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see  CALL_E_EVT_PAGING_ENDED
 * @see  tup_call_paging_accept
 **/
TUP_API TUP_RESULT tup_call_paging_end(TUP_UINT32 ulGroupID);


/**
 * @brief �����˺ŵ��û�����Ϣ
 * 
 * @param [in] CALL_S_ACCOUNT_USER_NAME* user_name  <b>:</b> �˺��û�����Ϣ����
 * @param [in] TUP_UINT32 data_num                  <b>:</b> �˺��û�����Ϣ�������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_set_user_name(CALL_S_ACCOUNT_USER_NAME* user_name, TUP_UINT32 data_num);


/**
 * @brief �����Ƿ�֧��H264 cabca���뷽ʽ
 * 
 * @param [in] TUP_UINT32 callid            <b>:</b> ����ID
 * @param [in] TUP_BOOL is_enable           <b>:</b> �Ƿ���
 * @param [in] CALL_E_MEDIATYPE media_type  <b>:</b> ý������
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_enable_cabac_encode(TUP_UINT32 callid, TUP_BOOL is_enable, CALL_E_MEDIATYPE media_type);


/**
 * @brief ˢ��uportal��token
 * 
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention ��������token�������ʧ��ʱʹ��
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_uportal_refresh_token();


/**
 * @brief �����Զ������Թ���
 * 
 * @param [in] TUP_BOOL bEnable  <b>:</b> �Ƿ�����
 * @retval TUP_API TUP_RESULT <b>:</b> �ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_call_enable_test_callback(TUP_BOOL bEnable);



#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#endif  /* __CALL_ADVANCED_INTERFACE_H__ */
/** @}*/

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
*
* vi: set expandtab ts=4 sw=4 tw=80:
*/


