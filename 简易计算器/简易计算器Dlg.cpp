
// 简易计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "简易计算器.h"
#include "简易计算器Dlg.h"
#include "afxdialogex.h"
#include "Calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Calculator calcu;
C简易计算器Dlg *pDlg;
HWND g_hWnd;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C简易计算器Dlg 对话框



C简易计算器Dlg::C简易计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C简易计算器Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C简易计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_IN, expression_in);
	//  DDX_Control(pDX, IDC_EDIT_IN, m_inEdit);
	DDX_Control(pDX, IDC_LIST_IN, m_list);
	DDX_Control(pDX, IDC_LIST_OUT, m_outList);
}

BEGIN_MESSAGE_MAP(C简易计算器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BTN_MAKEZERO, &C简易计算器Dlg::OnBnClickedBtnMakezero)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &C简易计算器Dlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_LBKT, &C简易计算器Dlg::OnBnClickedBtnLbkt)
	ON_BN_CLICKED(IDC_BTN_RBKT, &C简易计算器Dlg::OnBnClickedBtnRbkt)
	ON_BN_CLICKED(IDC_BTN_ADD, &C简易计算器Dlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &C简易计算器Dlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_PLUS, &C简易计算器Dlg::OnBnClickedBtnPlus)
	ON_BN_CLICKED(IDC_BTN_DIVI, &C简易计算器Dlg::OnBnClickedBtnDivi)
	ON_BN_CLICKED(IDC_BTN_POINT, &C简易计算器Dlg::OnBnClickedBtnPoint)
	ON_BN_CLICKED(IDC_BTN_ZERO, &C简易计算器Dlg::OnBnClickedBtnZero)
	ON_BN_CLICKED(IDC_BTN_ONE, &C简易计算器Dlg::OnBnClickedBtnOne)
	ON_BN_CLICKED(IDC_BTN_TWO, &C简易计算器Dlg::OnBnClickedBtnTwo)
	ON_BN_CLICKED(IDC_BTN_THREE, &C简易计算器Dlg::OnBnClickedBtnThree)
	ON_BN_CLICKED(IDC_BTN_FOUR, &C简易计算器Dlg::OnBnClickedBtnFour)
	ON_BN_CLICKED(IDC_BTN_FIVE, &C简易计算器Dlg::OnBnClickedBtnFive)
	ON_BN_CLICKED(IDC_BTN_SIX, &C简易计算器Dlg::OnBnClickedBtnSix)
	ON_BN_CLICKED(IDC_BTN_SEVEN, &C简易计算器Dlg::OnBnClickedBtnSeven)
	ON_BN_CLICKED(IDC_BTN_EIGHT, &C简易计算器Dlg::OnBnClickedBtnEight)
	ON_BN_CLICKED(IDC_BTN_NINE, &C简易计算器Dlg::OnBnClickedBtnNine)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &C简易计算器Dlg::OnBnClickedBtnEqual)

END_MESSAGE_MAP()


// C简易计算器Dlg 消息处理程序

BOOL C简易计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	pDlg = this;
	CWnd *p = AfxGetMainWnd();
	g_hWnd = p->m_hWnd;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C简易计算器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C简易计算器Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C简易计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




// 以下为自行添加代码
//
//

void C简易计算器Dlg::OnBnClickedBtnMakezero()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.MakeZero();
}


void C简易计算器Dlg::OnBnClickedBtnClear()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.DelChar();
}


void C简易计算器Dlg::OnBnClickedBtnLbkt()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("(");
}


void C简易计算器Dlg::OnBnClickedBtnRbkt()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar(")");
}


void C简易计算器Dlg::OnBnClickedBtnAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("+");
}


void C简易计算器Dlg::OnBnClickedBtnSub()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("-");
}


void C简易计算器Dlg::OnBnClickedBtnPlus()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("*");
}


void C简易计算器Dlg::OnBnClickedBtnDivi()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("/");
}


void C简易计算器Dlg::OnBnClickedBtnPoint()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar(".");
}


void C简易计算器Dlg::OnBnClickedBtnZero()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("0");
}


void C简易计算器Dlg::OnBnClickedBtnOne()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("1");
}


void C简易计算器Dlg::OnBnClickedBtnTwo()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("2");
}


void C简易计算器Dlg::OnBnClickedBtnThree()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("3");
}


void C简易计算器Dlg::OnBnClickedBtnFour()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("4");
}


void C简易计算器Dlg::OnBnClickedBtnFive()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("5");
}


void C简易计算器Dlg::OnBnClickedBtnSix()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("6");
}


void C简易计算器Dlg::OnBnClickedBtnSeven()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("7");
}


void C简易计算器Dlg::OnBnClickedBtnEight()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("8");
}


void C简易计算器Dlg::OnBnClickedBtnNine()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.AddChar("9");
}


void C简易计算器Dlg::OnBnClickedBtnEqual()
{
	// TODO:  在此添加控件通知处理程序代码
	calcu.ShowResult(true);
}


