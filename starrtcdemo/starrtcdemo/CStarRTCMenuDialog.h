#pragma once
#include "CUserManager.h"
#include "CConfigManager.h"
#include "CLogin.h"
// CStarRTCMenuDialog 对话框
#include "ILoginManagerListener.h"
class CStarRTCMenuDialog : public CDialogEx, public ILoginManagerListener
{
	DECLARE_DYNAMIC(CStarRTCMenuDialog)

public:
	CStarRTCMenuDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStarRTCMenuDialog();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_UserIDEdit;
	CStatic m_UserPicPicControl;
	afx_msg void OnBnClickedButtonIm();
	afx_msg void OnBnClickedButtonMultipleMeeting();
	afx_msg void OnBnClickedButtonInteracteLive();
public:
	/**
	 * msgServer处于在线状态
	 */
	virtual int online(int maxContentLen);

	/**
	 * msgServer中断状态
	 */
	virtual int offline();
private:
	CUserManager* m_pUserManager;
	CConfigManager* m_pConfig;
public:
	//afx_msg void OnBnClickedButtonParamSetting();
	virtual BOOL OnInitDialog();
	bool m_bLogIn;
	afx_msg void OnBnClickedButtonLiveMonitor();
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonVoip();
	afx_msg void OnBnClickedButtonVoiceChatroom();
	afx_msg void OnBnClickedButtonVoipP2p();
	afx_msg void OnBnClickedButtonMinClass();
	afx_msg void OnBnClickedButtonSuperChatroom();
private:
	CLogin* m_pLogin;
};
