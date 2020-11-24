#pragma once

#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

#include<string>
using namespace std;
#include "ILoginListener.h"
#include "ILoginManagerListener.h"
#include "CUserManager.h"
class MATH_API CLogin :public ILoginListener
{
public:
	CLogin(CUserManager* pUserManager, ILoginManagerListener* pLoginManagerListener);

	~CLogin();
	/*
	 * ��¼
	 */
	bool logIn();

	/*
	 * ����IM����
	 */
	bool startIMServer(string strIP, int nPort, string userId, string agentId, string strToken);

	/*
	 * ����IM����
	 */
	bool stopIMServer();
public:
	/**
	 * msgServer����,������������̵߳���
	 */
	virtual int msgErr(char* errString);

	/**
	 * ���Զ�κ��Բ������ӵ�msgServer�����û���������stop��ص�
	 */
	virtual int stop();

	/**
	 * msgServer��������״̬
	 */
	virtual int online(int maxContentLen);

	/**
	 * msgServer�ж�״̬
	 */
	virtual int offline();
private:
	/*
	 * ��ȡauthKey
	 */
	bool getAuthKey();

	/*
	 * ��ȡToken
	 */
	bool getToken();

	/*
	 * ͨ�����Ȼ�ȡIM�����ַ
	 */
	bool getIMServerAddr();
private:
	ILoginManagerListener* m_pLoginManagerListener;
};

