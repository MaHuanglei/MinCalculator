
// ���׼�����Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "resource.h"


// C���׼�����Dlg �Ի���
class C���׼�����Dlg : public CDialogEx
{
// ����
public:
	C���׼�����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedBtnMakezero();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnLbkt();
	afx_msg void OnBnClickedBtnRbkt();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnPlus();
	afx_msg void OnBnClickedBtnDivi();
	afx_msg void OnBnClickedBtnPoint();
	afx_msg void OnBnClickedBtnZero();
	afx_msg void OnBnClickedBtnOne();
	afx_msg void OnBnClickedBtnTwo();
	afx_msg void OnBnClickedBtnThree();
	afx_msg void OnBnClickedBtnFour();
	afx_msg void OnBnClickedBtnFive();
	afx_msg void OnBnClickedBtnSix();
	afx_msg void OnBnClickedBtnSeven();
	afx_msg void OnBnClickedBtnEight();
	afx_msg void OnBnClickedBtnNine();
	afx_msg void OnBnClickedBtnEqual();
	CListBox m_list;
	CListBox m_outList;
};
