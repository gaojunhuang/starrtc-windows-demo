#pragma once
class ILoginManagerListener
{
public:
	/**
	 * msgServer��������״̬
	 */
	virtual int online(int maxContentLen) = 0;

	/**
	 * msgServer�ж�״̬
	 */
	virtual int offline() = 0;
};
