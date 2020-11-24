// PlaySound.cpp : ʵ���ļ�
//

#include "stdafx.h"
//#include "VideoPlay.h"
#include "PlaySound.h"


// CPlaySound

IMPLEMENT_DYNCREATE(CPlaySound, CWinThread)

CPlaySound::CPlaySound()
{
	//��ʼ����Ƶ��ʽ�ṹ��
	memset(&m_WaveFormatEx, 0, sizeof(m_WaveFormatEx));
	m_WaveFormatEx.wFormatTag = WAVE_FORMAT_PCM;
	m_WaveFormatEx.nChannels = 1;
	m_WaveFormatEx.wBitsPerSample = 16;
	m_WaveFormatEx.cbSize = 0;
	m_WaveFormatEx.nSamplesPerSec = 16000;
	m_WaveFormatEx.nBlockAlign = 2;
	m_WaveFormatEx.nAvgBytesPerSec = 32000;
	m_IsPlaying = FALSE;	
}

CPlaySound::~CPlaySound()
{

}

BOOL CPlaySound::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	return TRUE;
}

int CPlaySound::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

void CPlaySound::OnStartPlaying(WPARAM wParam, LPARAM lParam)
{
	MMRESULT mmReturn = 0;

	if(m_IsPlaying) //�Ѿ���ʼ������ֱ�ӷ���
		return; //FALSE;
	//����Ƶ����豸
	mmReturn = ::waveOutOpen( &m_hPlay, WAVE_MAPPER,
		&m_WaveFormatEx, ::GetCurrentThreadId(), 0, CALLBACK_THREAD);

	if(mmReturn) //���豸ʧ��
		displayError(mmReturn,"PlayStart");	
	else
	{	
		m_IsPlaying = TRUE;
		DWORD volume = 0xffffffff;
		waveOutSetVolume(m_hPlay, volume);//��������豸�������
	}			
}

void CPlaySound::displayError(int code,char mesg[])
{
	TCHAR errorbuffer[MAX_PATH];
	TCHAR errorbuffer1[MAX_PATH];

	waveOutGetErrorText( code,errorbuffer,MAX_PATH);
	wsprintf(errorbuffer1, TEXT("PLAY : %s :%x:%s") ,mesg,code,errorbuffer);
	AfxMessageBox(errorbuffer1);  
}

void CPlaySound::OnStopPlaying(WPARAM wParam, LPARAM lParam)
{

	MMRESULT mmReturn = 0;

	if(m_IsPlaying == FALSE)
		return;// FALSE;

	mmReturn = ::waveOutReset(m_hPlay);//��������豸�������ܹ�ʹ����豸ȫ��buffer�������

	if(!mmReturn)
	{
		m_IsPlaying = FALSE;
		Sleep(500); //�ȴ�����buffer������
		mmReturn = ::waveOutClose(m_hPlay);//�ر��豸
	}
}

void CPlaySound::OnEndPlaySoundData(WPARAM wParam, LPARAM lParam)
{
	LPWAVEHDR lpHdr = (LPWAVEHDR) lParam;

	if(lpHdr)
	{
		::waveOutUnprepareHeader(m_hPlay, lpHdr, sizeof(WAVEHDR));//��Ƶ������������buffer
	}
	return ;//ERROR_SUCCESS;
}

void CPlaySound::OnWriteSoundData(WPARAM wParam, LPARAM lParam)
{
	MMRESULT mmResult = 0;
	int length=(int) wParam;
	char* pData = (char *)lParam;
	if (m_IsPlaying == FALSE)
	{
		return; //FALSE;
	}
		
	// Prepare wave header for playing 
	WAVEHDR *lpHdr=new WAVEHDR;
	memset(lpHdr,0,sizeof(WAVEHDR));
	lpHdr->lpData= pData;
	lpHdr->dwBufferLength=length;

	//��Ҫ���������д��buffer
	mmResult = ::waveOutPrepareHeader(m_hPlay, lpHdr, sizeof(WAVEHDR));

	if(mmResult)
	{
		return ;//ERROR_SUCCESS;
	}

	//��������ݷ��͸�����豸
	mmResult = ::waveOutWrite(m_hPlay, lpHdr, sizeof(WAVEHDR));
	if(mmResult)
	{
		return ;//ERROR_SUCCESS;				
	}
	return ;//ERROR_SUCCESS;
}

void CPlaySound::OnEndThread(WPARAM wParam, LPARAM lParam)
{
	// If already playing then stop it...
	if(m_IsPlaying)
		OnStopPlaying(0, 0);
	// Quit this thread...
	::PostQuitMessage(0);

	return ;//TRUE;
}

BEGIN_MESSAGE_MAP(CPlaySound, CWinThread)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_STARTPLAYING, OnStartPlaying)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_STOPPLAYING, OnStopPlaying)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_PLAYBLOCK, OnWriteSoundData)
	ON_THREAD_MESSAGE(MM_WOM_DONE, OnEndPlaySoundData)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_ENDTHREAD,OnEndThread)
END_MESSAGE_MAP()


// CPlaySound ��Ϣ�������
