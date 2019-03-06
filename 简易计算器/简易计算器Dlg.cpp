
// ���׼�����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���׼�����.h"
#include "���׼�����Dlg.h"
#include "afxdialogex.h"
#include "Calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Calculator calcu;
C���׼�����Dlg *pDlg;
HWND g_hWnd;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C���׼�����Dlg �Ի���



C���׼�����Dlg::C���׼�����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���׼�����Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���׼�����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_IN, expression_in);
	//  DDX_Control(pDX, IDC_EDIT_IN, m_inEdit);
	DDX_Control(pDX, IDC_LIST_IN, m_list);
	DDX_Control(pDX, IDC_LIST_OUT, m_outList);
}

BEGIN_MESSAGE_MAP(C���׼�����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BTN_MAKEZERO, &C���׼�����Dlg::OnBnClickedBtnMakezero)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &C���׼�����Dlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_LBKT, &C���׼�����Dlg::OnBnClickedBtnLbkt)
	ON_BN_CLICKED(IDC_BTN_RBKT, &C���׼�����Dlg::OnBnClickedBtnRbkt)
	ON_BN_CLICKED(IDC_BTN_ADD, &C���׼�����Dlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &C���׼�����Dlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_PLUS, &C���׼�����Dlg::OnBnClickedBtnPlus)
	ON_BN_CLICKED(IDC_BTN_DIVI, &C���׼�����Dlg::OnBnClickedBtnDivi)
	ON_BN_CLICKED(IDC_BTN_POINT, &C���׼�����Dlg::OnBnClickedBtnPoint)
	ON_BN_CLICKED(IDC_BTN_ZERO, &C���׼�����Dlg::OnBnClickedBtnZero)
	ON_BN_CLICKED(IDC_BTN_ONE, &C���׼�����Dlg::OnBnClickedBtnOne)
	ON_BN_CLICKED(IDC_BTN_TWO, &C���׼�����Dlg::OnBnClickedBtnTwo)
	ON_BN_CLICKED(IDC_BTN_THREE, &C���׼�����Dlg::OnBnClickedBtnThree)
	ON_BN_CLICKED(IDC_BTN_FOUR, &C���׼�����Dlg::OnBnClickedBtnFour)
	ON_BN_CLICKED(IDC_BTN_FIVE, &C���׼�����Dlg::OnBnClickedBtnFive)
	ON_BN_CLICKED(IDC_BTN_SIX, &C���׼�����Dlg::OnBnClickedBtnSix)
	ON_BN_CLICKED(IDC_BTN_SEVEN, &C���׼�����Dlg::OnBnClickedBtnSeven)
	ON_BN_CLICKED(IDC_BTN_EIGHT, &C���׼�����Dlg::OnBnClickedBtnEight)
	ON_BN_CLICKED(IDC_BTN_NINE, &C���׼�����Dlg::OnBnClickedBtnNine)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &C���׼�����Dlg::OnBnClickedBtnEqual)

END_MESSAGE_MAP()


// C���׼�����Dlg ��Ϣ�������

BOOL C���׼�����Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	pDlg = this;
	CWnd *p = AfxGetMainWnd();
	g_hWnd = p->m_hWnd;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���׼�����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C���׼�����Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���׼�����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




// ����Ϊ������Ӵ���
//
//

void C���׼�����Dlg::OnBnClickedBtnMakezero()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.MakeZero();
}


void C���׼�����Dlg::OnBnClickedBtnClear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.DelChar();
}


void C���׼�����Dlg::OnBnClickedBtnLbkt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("(");
}


void C���׼�����Dlg::OnBnClickedBtnRbkt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar(")");
}


void C���׼�����Dlg::OnBnClickedBtnAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("+");
}


void C���׼�����Dlg::OnBnClickedBtnSub()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("-");
}


void C���׼�����Dlg::OnBnClickedBtnPlus()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("*");
}


void C���׼�����Dlg::OnBnClickedBtnDivi()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("/");
}


void C���׼�����Dlg::OnBnClickedBtnPoint()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar(".");
}


void C���׼�����Dlg::OnBnClickedBtnZero()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("0");
}


void C���׼�����Dlg::OnBnClickedBtnOne()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("1");
}


void C���׼�����Dlg::OnBnClickedBtnTwo()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("2");
}


void C���׼�����Dlg::OnBnClickedBtnThree()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("3");
}


void C���׼�����Dlg::OnBnClickedBtnFour()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("4");
}


void C���׼�����Dlg::OnBnClickedBtnFive()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("5");
}


void C���׼�����Dlg::OnBnClickedBtnSix()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("6");
}


void C���׼�����Dlg::OnBnClickedBtnSeven()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("7");
}


void C���׼�����Dlg::OnBnClickedBtnEight()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("8");
}


void C���׼�����Dlg::OnBnClickedBtnNine()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.AddChar("9");
}


void C���׼�����Dlg::OnBnClickedBtnEqual()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	calcu.ShowResult(true);
}


