#pragma once

#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

#include "IStarIMC2CListener.h"
#include "IStarIMChatroomListener.h"
#include "IVdnListener.h"
#include "ISrcListener.h"
#include "IGroupListener.h"
#include "IStarVoipListener.h"
#include "IStarVoipP2PListener.h"
#include "IRecvDataListener.h"
#include "IChatroomGetListListener.h"
#include "ILoginListener.h"
/*
 * StarRtc�ӿ���
 */
class StarRtcCore
{
private:
	/*
	 * ���캯��
	 * @param pUserManager �û�������Ϣ
	 */
	StarRtcCore();
	
public:

	/*
	 * ��ȡStarRtc�ӿڶ���
	 * @param pUserManager �û�������Ϣ
	 */
	static StarRtcCore* getStarRtcCoreInstance();
	
	/*
	 * ��������
	 */
	~StarRtcCore();

	/*
	 * ע��ص�����
	 */
	void registerCallback();

	/*
	 * �����ڴ�
	 */
	void starRTCMalloc(uint8_t** outPtr, int length);

	/*
	 * �ͷ��ڴ�
	 */
	void starRTCFree(uint8_t* ptr);


	void setLogFile(char *dir);

	void saveFile(int save_mode);

	void setconfigLog(int log_level, int log_filter, int log_freq);
	/**
	 * ���IM����
	 * @param listener
	 */
	void addLoginListener(ILoginListener* listener);
	
	/**
	 * ��ӻ�ȡ�б����
	 * @param listener
	 */
	void addGetListListener(IChatroomGetListListener* listener);

	/**
	 * ���C2C��Ϣ����
	 * @param listener
	 */
	void addC2CListener(IStarIMC2CListener* listener);

	/**
	 * ���group��Ϣ����
	 * @param listener
	 */
	void addGroupListener(IGroupListener* listener);

	/**
	 * ���StarIMChatroom��Ϣ����
	 * @param listener
	 */
	void addStarIMChatroomListener(IStarIMChatroomListener* listener);

	/**
	 * ���Vdn��Ϣ����
	 * @param listener
	 */
	void addVdnListener(IVdnListener* pVdnListener);

	/**
	 * ���Src��Ϣ����
	 * @param listener
	 */
	void addSrcListener(ISrcListener* pSrcListener);

	/**
	 * ���Voip����
	 * @param listener
	 */
	void addVoipListener(IStarVoipListener* listener);

	/**
	 * ���VoipP2P����
	 * @param listener
	 */
	void addVoipP2PListener(IStarVoipP2PListener* listener);

	/**
	 * ���RecvData����
	 * @param listener
	 */
	void addRecvDataListener(IRecvDataListener* listener);

	/**
	 * ����IM����
	 */
	bool startIMServer(char* servIP, int servPort, char* agentId, char* userId, char* starToken);

	/**
	 * ֹͣIM����
	 */
	bool stopIMServer();

	/**
	 * ������Ϣ
	 */
	bool sendMessage(CIMMessage* pIMMessage);

	/**
	 * ����������Ϣ
	 */
	bool sendOnlineMessage(CIMMessage* pIMMessage);

	/**
	 * ����Ⱥ����Ϣ
	 */
	int sendGroupMsg(CIMMessage* pIMMessage);

	/**
	 * ��ȡȺ���б�
	 */
	int applyGetGroupList();
	/**
	 * ��ȡȺ���û��б�
	 */
	int  applyGetUserList(char* groupId);
	
	/**
	 * ���봴��Ⱥ��
	 */
	int applyCreateGroup(char* addUsers, char* userDefineData);
	
	/**
	 * ����ɾ��
	 */
	int applyDelGroup(char* groupId);

	/**
	 * ������Ⱥ������û�
	 */
	int applyAddUserToGroup(char* groupId, char* addUsers, char* userDefineData);
	
	/**
	 * �����Ƴ�Ⱥ���û�
	 */
	int applyRemoveUserToGroup(char* groupId, char* removeUsers);
	
	/**
	 * ����ϵͳ��Ϣ��ָ���û�
	 */
	int sendSystemMsgToUser(char* sendUsers, int msgDataType, char* msgStr, char* msgDigest);
	
	/**
	 * ����ϵͳ��Ϣ��Ⱥ��
	 */
	int sendSystemGroupMsg(char* groupId, int msgDataType, char* msgStr, char* msgDigest);
	
	/**
	 * �������Ⱥ����Ϣ
	 */
	int applySetGroupPushIgnore(char* groupId);
	
	/**
	 * ����ȡ������Ⱥ����Ϣ
	 */
	int applyUnsetGroupPushIgnore(char* groupId);
	
	/**
	 * ��������ģʽ
	 */
	int setPushMode(char* pushMode);
	
	/**
	 * ��ȡ����ģʽ
	 */
	int getPushMode();

	int queryAllChatRoomList(char* servAddr, int servPort, char* userId, char* listType);
	
	int saveToChatRoomList(char* servAddr, int servPort, char* userId, int listType, char* roomId, char* data);
	
	int delFromChatRoomList(char* servAddr, int servPort, char* userId, int listType, char* roomId);

	/*
	 * ����ChatRoom
	 */
	bool createChatRoom(string serverIp, int serverPort, string strName, int chatroomType, string strAgentId, string strUserId, string strTokenId);

	/*
	 * ����ChatRoom
	 */
	bool joinChatRoom(string serverIp, int serverPort, string strChatroomId, string strAgentId, string strUserId, string strTokenId);

	/*
	 * ��ѯchatroom��������
	 */
	bool getOnlineNumber(string strChatroomId);

	bool banToSendMsg(char* banUserId, int banTime);
	bool kickOutUser(char* kickOutUserId);
	bool sendChat(CIMMessage* pIMMessage);
	bool sendPrivateChat(char* targetId, CIMMessage* pIMMessage);
	bool deleteChatRoom();

	/*
	 *  ��ChatRoom�Ͽ�����
	 */
	bool stopChatRoomConnect();

	//==================================voip====================================
	int startVoipEncoder(int audioSampleRateInHz, int audioChannels, int audioBitRate, int rotation);
	void voipCalling(char* servAddr, int servPort, char* agentId, char* userId, char* starToken, char* responserUserId);
	void voipResponse(char* servAddr, int servPort, char* agentId, char* userId, char* starToken, char* callerUserId);
	void stopVoip(int isActive);//�����ر�һ����1   �����ر�һ����0  
	void voipSpeedTest(char* servIp, int port);
	void voipEchoTest(char* servIp, int port);

	void initStarVoipDirectLink();
	void stopStarVoipDirectLink();
	// �������˳��ִ�� :interface_connectFarVoip-interface_startTransVoipData-interface_startVoipDirectLinkEncoder-interface_closeFarVoip
	void connectFarVoip(char* farUrl_c);
	void startTransVoipData();
	int  startVoipDirectLinkEncoder(int audioSampleRateInHz, int audioChannels, int audioBitRate, int rotation);
	void closeFarVoip();
	void sendMsgDataToFar(CIMMessage* pIMMessage);

	/*
	 * Channel ��������
	 */
	bool applyDownload(string serverIp, int port, string channelId, string strAgentId, string strUserId, string strTokenId);

	/*
	 * Channel ֹͣ����
	 */
	bool stopDownload();

	/*
	 * ��������������
	 */
	bool setStreamConfigVdn(int* sendBuf, int length);

	void setGlobalSetting(int videoEnable, int audioEnable,
		int videoBigIsHw,
		int videoBigWidth, int videoBigHeight, int videoBigFps, int videoBigBitrate,
		int videoSmallWidth, int videoSmallHeight, int videoSmallFps, int videoSmallBitrate,
		int openGLESEnable, int dynamicBitrateAndFpsEnable, int voipP2PEnable);

	void setRuntimeAudioEnable(int audioEnable);
	void setRuntimeVideoEnable(int videoEnable);
	/*
	 * ��������������
	 */
	bool setStreamConfigSrc(int* sendBuf, int length);
	//int queryAllChannelList(char* servAddr, int servPort, char* userId, char* listType);

	/*
	 * ����Channel
	 */
	bool createPublicChannel(string strServerIp, int port, string strName, int listType, string strChatroomId, string strAgentId, string strUserId, string strTokenId);
	
	/*
	 * ����Channel
	 */
	bool starLiveCreateLoginChannel(string strServerIp, int servPort, string strName, int listType, string strChatroomId, string strAgentId, string strUserId, string strTokenId);

	bool createBroadcastChannel(string strServerIp, int port, string strName, int listType, string strChatroomId, string strAgentId, string strUserId, string strTokenId);
	int startLiveSrcEncoder(int audioSampleRateInHz, int audioChannels, int audioBitRate, int rotation);
	int startUploadSrcServer(char* servAddr, int servPort, char* agentId, char* userId, char* starToken, char* channelId/* ,int maxAudioPacketNum,int maxVideoPacketNum */);
	void setUploader(char* userId);
	
	int stopUploadSrcServer();
	int stopLiveSrcCodec(int disable_decoder);

	void insertAudioRaw(uint8_t* audioData, int dataLen);
	//videoData���ͷ��ɴ˺�������
	void insertVideoNalu(uint8_t* videoData, int dataLen);
	//videoData���ͷ��ɴ˺�������
	void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	//�ü���Ƶ������Сͼ,outVideoDataBig��outVideoDataSmall�ں�����malloc,��ios�Լ�free������Сͼ����outVideoDataSmallָ���ΪNULL
	//videoData���ں������ͷ�
	//�ɹ�����0��ʧ�ܷ���-1
	int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	//realtimeData���ͷ��ɴ˺�������
	void insertRealtimeData(uint8_t* realtimeData, int dataLen);
	void querySoundData(uint8_t** pData, int* nLength);
	//=========================================================================
	//===========================    Msg�ص�    ===========================
	//=========================================================================
	/**
	 * msgServer����,������������̵߳���
	 */
	static int msgErr(char* errString, void* userData);

	/**
	 * ���Զ�κ��Բ������ӵ�msgServer�����û���������stop��ص�
	 */
	static int stop(void* userData);

	/**
	 * msgServer��������״̬
	 */
	static int online(int maxContentLen, void* userData);

	/**
	 * msgServer�ж�״̬
	 */
	static int offline(void* userData);

	/**
	 * ������Ϣ��Ⱥ��Ϣ��δͬ����ɣ��ȴ�5������
	 */
	static int groupIsSyncing(char* groupId, void* userData);

	/**
	 * �յ�������Ϣ���ͳɹ�����
	 */
	static int sendMsgFin(int msgIndex, char* toUserId, uint32_t time, void* userData);

	/**
	 * �յ�������Ϣ
	 */
	static int getNewMsg(char* fromUserId, uint32_t time, char* msgData, void* userData);

	/**
	 * �յ�Ⱥ��Ϣ
	 */
	static int getNewGroupMsg(char* groupId, char* fromUserId, uint32_t time, char* msgData, void* userData);

	/**
	 * �յ�Ⱥ������Ϣ
	 */
	static int getGroupSystemMsg(char* groupId, uint32_t time, char* msgData, void* userData);

	/**
	 * �յ�ϵͳ������Ϣ
	 */
	static int getSystemMsg(uint32_t time, char* msgData, void* userData);

	/**
	 * ���漸��������status����Ϊ����״̬��
	 * status�����ִ�:
	 * AECERRID_AEC_AUTH_FAILED, //AEC��Ȩʧ��
	 * AECERRID_AEC_URL_CONNECT_FAILED, //AEC url����ʧ��
	 * AECERRID_AEC_RESPONSE_JSON_PARSE_ERR, //AEC���ص�json��ʽ��������
	 * GROUPPUSH_ERRID_GROUPID_IS_SYNCING
	 * GROUPPUSH_ERRID_USERID_IS_NOT_IN_GROUP, //���û�����ָ����Ⱥ��
	 * �յ�Ⱥ��Ϣ���ͳɹ�����
	 */
	static int sendGroupMsgFin(char* status, int groupMsgIndex, char* groupId, uint32_t time, void* userData);
	static int applyCreateGroupFin(char* status, int reqIndex, char* groupId, void* userData);
	static int applyDelGroupFin(char* status, int reqIndex, char* groupId, void* userData);

	//ray0306-3
	static int applyGetGroupListFin(char* status, int reqIndex, char* groupIdList, char* groupNameList, char* creatorList, void* userData);
	static int applyGetUserListFin(char* status, int reqIndex, int isIgnore, char* userIdList, void* userData);

	//ray0306-3


	static int applyAddUserToGroupFin(char* status, int reqIndex, char* groupId, void* userData);
	static int applyRemoveUserFromGroupFin(char* status, int reqIndex, char* groupId, void* userData);
	static int sendSystemMsgToUserFin(char* status, int reqIndex, void* userData);
	static int sendSystemGroupMsgFin(char* status, int reqIndex, char* groupId, void* userData);
	static int setPushModeOK(void* userData);
	static int setPushModeFailed(void* userData);
	static int getPushMode(char* pushMode, void* userData);
	static int setPushIgnoreFin(char* status, char* groupId, void* userData);
	static int unsetPushIgnoreFin(char* status, char* groupId, void* userData);
	static int msg_getAllUserListOk(int totalPageNum, int reqPageNum, char* userIdList, void* userData);
	static int msg_getAllUserListFailed(int totalPageNum, int reqPageNum, void* userData);
	static int msg_getAliveNum(int userCount, int totalPageNum, void* userData);
	//=========================================================================
	//===========================    Voip�ص�    ===========================
	//=========================================================================
	static void voipStopOK(void* userData, int stopType);
	//������յ�calling���󣬴�ʱ�ͻ��˿���ͨ����Ϣϵͳ֪ͨ�Է�
	static void voipCallingAck(void* userData);
	//callingʧ��
	static void voipCallingFailed(char* errString, void* userData);
	//���շ�׼���ã����Կ�ʼ��������
	static void voipResponseOk(char* recSessionId, void* userData);
	//responseʧ��
	static void voipResponseFailed(char* errString, void* userData);
	//���ͷ�׼���ã����Կ�ʼ��������
	static void voipCallingOk(char* recSessionId, void* userData);
	static int voipError(char* errString, void* userData);
	static int voipSpeedTestFinish(char* userIp, int uploadVariance, int uploadSpeed, int downloadVariance, int downSpeed, void* userData);
	static int voipEchoTestFinish(int index, int len, int timeCost, void* userData);
	static int voipGetRealtimeData(uint8_t* data, int len, void* userData);
	// 1��p2p, 2����ת
	static int reportVoipTransState(int state, void* userData);
	//=============================    voip direct�ص�    ============================
	static void connectFarVoipOK(void* userData);
	static void connectFarVoipFailed(void* userData);
	static void starVoipDirectLinkError(char* errString, void* userData);
	static void voipDirectLinkRecvMsg(char* msg, void* userData);
	//=========================================================================
	//===========================    live chatroom�ص�    ===========================
	//=========================================================================
	static int createChatroomOK(char* roomId, int maxContentLen, void* userData);

	static int createChatroomFailed(void* userData, char* errString);

	static int joinChatroomOK(char* roomId, int maxContentLen, void* userData);

	static int joinChatroomFailed(char* roomId, char* errString, void* userData);

	static int chatroomError(char* errString, void* userData);

	static int chatroomStop(void* userData);

	static int chatroomQueryAllListOK(char* listData, void* userData);

	static int deleteChatroomOK(char* roomId, void* userData);
	static int deleteChatroomFailed(char* roomId, char* errString, void* userData);

	static int chatroomBanToSendMsgOK(char* banUserId, int banTime, void* userData);
	static int chatroomBanToSendMsgFailed(char* banUserId, int banTime, char* errString, void* userData);

	static int chatroomKickOutOK(char* kickOutUserId, void* userData);
	static int chatroomKickOutFailed(char* kickOutUserId, char* errString, void* userData);

	//������
	static int chatroomSendMsgBanned(unsigned int remainTimeSec, void* userData);
	//���߳�����
	static int chatroomKickedOut(void* userData);
	//�յ���Ϣ
	static int chatroomGetNewMsg(char* fromUserId, char* msgData, void* userData);
	//�յ�˽����Ϣ
	static int chatroomGetNewPrivateMsg(char* fromUserId, char* msgData, void* userData);
	//�յ�����������Ϣ
	static int chatroomGetRoomOnlineNumber(char* roomId, int onlineNum, void* userData);
	//��Ϣ����ʧ�ܣ�����
	static int chatroomSendMsgNoFee(void* userData);

	//�¼ӽӿ�
	static int chatroomSaveToChatRoomListOK(char* roomId, void* userData);
	static int chatroomSaveToChatRoomListFailed(char* roomId, void* userData);
	static int chatroomDelFromChatRoomListOK(char* roomId, void* userData);
	static int chatroomDelFromChatRoomListFailed(char* roomId, void* userData);

	//=========================================================================
	//===========================    liveVdn�ص�    ===========================
	//=========================================================================

	static int applyDownloadChannelOK(void* userData);
	static int applyDownloadChannelFailed(char* errString, void* userData);
	static int downloadChannelError(char* errString, void* userData);

	static int downloadStopOK(void* userData);
	static int downloadChannelClosed(void* userData);
	static int downloadChannelLeave(void* userData);

	static int downloadNetworkUnnormal(void* userData);
	static int queryVDNChannelOnlineNumberFin(char* channelId, int totalOnlineNum, void* userData);
	static int uploaderAdd(char* upUserId, int upId, void* userData);
	static int uploaderRemove(char* upUserId, int upId, void* userData);
	static int downloadStreamConfigOK(char* channelId, void* userData);
	static int downloadStreamConfigFailed(void* userData);
	static int getRealtimeData(int upId, uint8_t* data, int len, void* userData);

	//=========================================================================
	//===========================    liveSrc�ص�    ===========================
	//=========================================================================
	static int createChannelOK(char* channelId, void* userData);
	static int createChannelFailed(char* errString, void* userData);

	static int applyUploadChannelOK(char* channelId, char* recSessionId, void* userData);
	static int applyUploadChannelFailed(char* errString, char* channelId, void* userData);

	static int setUploaderOK(char* channelId, char* uploadUserId, void* userData);
	static int setUploaderFailed(char* errString, char* channelId, char* uploadUserId, void* userData);

	static int unsetUploaderOK(char* channelId, char* uploadUserId, void* userData);
	static int unsetUploaderFailed(char* errString, char* channelId, char* uploadUserId, void* userData);

	static int muteUploaderOK(char* channelId, char* uploadUserId, void* userData);
	static int muteUploaderFailed(char* errString, char* channelId, char* uploadUserId, void* userData);

	static int unmuteUploaderOK(char* channelId, char* uploadUserId, void* userData);
	static int unmuteUploaderFailed(char* errString, char* channelId, char* uploadUserId, void* userData);

	static int deleteChannelOK(char* channelId, void* userData);
	static int deleteChannelFailed(char* errString, char* channelId, void* userData);

	static int uploadUnseted(char* channelId, void* userData);
	static int uploadMuted(char* channelId, void* userData);
	static int uploadUnmuted(char* channelId, void* userData);

	static int setPeerStreamDownloadConfigOK(char* channelId, void* userData);
	static int setPeerStreamDownloadConfigFailed(char* channelId, void* userData);

	static int stopOK(void* userData);
	static int isRetrying(void* userData);
	static int networkUnnormal(void* userData);

	static int srcError(char* errString, void* userData);
	static int querySrcChannelOnlineNumberFin(char* channelId, int totalOnlineNum, void* userData);

	static int uploaderAddSrc(char* upUserId, int upId, void* userData);
	static int uploaderRemoveSrc(char* upUserId, int upId, void* userData);
	static int getRealtimeDataSrc(int upId, uint8_t* data, int len, void* userData);
	
	//�¼�
	static int pushRtmpOKSrc(char* channelId, void* userData);
	static int pushRtmpFailedSrc(char* errString, char* channelId, void* userData);
	static int stopPushRtmpOKSrc(char* channelId, void* userData);
	static int stopPushRtmpFailedSrc(char* errString, char* channelId, void* userData);
	//static int channelQueryAllListOK(char* listData, void* userData);
	
	static int getVideoRaw(int upId, int w, int h, uint8_t* videoData, int videoDataLen, void* userData);
private:
	ILoginListener* m_pLoginListener;
	IChatroomGetListListener* m_pGetListListener;
	IStarIMC2CListener* m_pc2cMsgListener;
	IGroupListener* m_pGroupMsgListener;
	IStarIMChatroomListener *m_pStarIMChatroomListener;
	IVdnListener* m_pVdnListener;
	ISrcListener* m_pSrcListener;
	IStarVoipListener* m_pStarVoipListener;
	IStarVoipP2PListener* m_pStarVoipP2PListener;
	IRecvDataListener* m_pRecvDataListener;
	int m_groupReqIndex;
};
