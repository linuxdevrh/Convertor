
// ConvertorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Convertor.h"
#include "ConvertorDlg.h"
#include "afxdialogex.h"
#include "Convert.h"

#pragma commment (lib, "convert.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CConvertorDlg dialog



CConvertorDlg::CConvertorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONVERTOR_DIALOG, pParent)
	, m_size_type(0)
	, m_intTxtBin(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvertorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_HEX, m_edt_hex);
	DDX_Control(pDX, IDC_EDT_DEC, m_edt_dec);
	DDX_Control(pDX, IDC_EDT_BIN, m_edt_bin);
	DDX_Radio(pDX, IDC_RD_BYTE, m_size_type);
	DDX_Text(pDX, IDC_EDT_BIN, m_intTxtBin);
}

BEGIN_MESSAGE_MAP(CConvertorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDT_HEX, &CConvertorDlg::OnEnChangeEdtHex)
	ON_EN_CHANGE(IDC_EDT_DEC, &CConvertorDlg::OnEnChangeEdtDec)
	ON_EN_SETFOCUS(IDC_EDT_DEC, &CConvertorDlg::OnEnSetfocusEdtDec)
	ON_EN_SETFOCUS(IDC_EDT_HEX, &CConvertorDlg::OnEnSetfocusEdtHex)
	ON_EN_CHANGE(IDC_EDT_BIN, &CConvertorDlg::OnEnChangeEdtBin)
	ON_EN_SETFOCUS(IDC_EDT_BIN, &CConvertorDlg::OnEnSetfocusEdtBin)
	
	ON_BN_CLICKED(IDC_RD_BYTE, &CConvertorDlg::OnBnClickedRdByte)
	ON_BN_CLICKED(IDC_RD_WORD, &CConvertorDlg::OnBnClickedRdWord)
	ON_BN_CLICKED(IDC_RD_DWORD, &CConvertorDlg::OnBnClickedRdDword)
	ON_BN_CLICKED(IDC_RD_QWORD, &CConvertorDlg::OnBnClickedRdQword)
END_MESSAGE_MAP()


// CConvertorDlg message handlers

BOOL CConvertorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_size_type = 1;
	size = MODE_WORD;

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CConvertorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CConvertorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CConvertorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CConvertorDlg::OnEnChangeEdtHex() //Hex textbox changed
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	//CString sHex;
	//TCHAR sDec[80] = L"";
	long int dNumber = 0;
	if (nActive == 1)
	{
		m_edt_hex.GetWindowText(sHex);
		//dNumber = (long)_tcstol(sHex.operator LPCWSTR(), NULL, 16);
		//_stprintf_s(sDec, 20, L"%ld", dNumber);
		ConverttoDec(sHex, sResult, 16);
		//m_edt_dec.SetWindowText(sDec);
		m_edt_dec.SetWindowText(sResult);

		ConverttoBin(sHex, sResult, 16);
		AddSpace(sResult);
		m_edt_bin.SetWindowText(sResult);
	}
}


void CConvertorDlg::OnEnChangeEdtDec()  //Decimal textbox changed
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	//CString sDec;
	//TCHAR sHex[51] = L"";
	long int dNumber = 0;
	if (nActive == 2)
	{
		m_edt_dec.GetWindowText(sDec);
	//	dNumber = (long)_tcstol(sDec.operator LPCWSTR(), NULL, 10);
	//	_stprintf_s(sHex, 20, L"%#x", dNumber);
		/////////////////////////////////////////////////////ConverttoHex(sDec, sResult, 10);

		stringtohex(sDec.operator LPCWSTR(), sResult, 10);

		m_edt_hex.SetWindowText(sResult);
		ConverttoBin(sDec, sResult, 10);
		AddSpace(sResult);
		m_edt_bin.SetWindowText(sResult);
	}
}


void CConvertorDlg::OnEnSetfocusEdtDec()
{
	
	nActive = 2;
}


void CConvertorDlg::OnEnSetfocusEdtHex()
{
	

	nActive = 1;
}


void CConvertorDlg::OnEnChangeEdtBin() //Binary textbox changed
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	//CString sDec;
	//TCHAR sBin[51] = L"";
	//long int dNumber = 0;
	if (nActive == 3)
	{
		m_edt_bin.GetWindowText(sDec);
		ConverttoHex(sDec, sResult, 2);
		m_edt_hex.SetWindowText(sResult);
	
		//m_edt_bin.GetWindowText(sDec);
		ConverttoDec(sDec, sResult, 2);
		//if (sBin)
		//AddSpace(sBin, sDec);

		m_edt_dec.SetWindowText(sResult);

	}
	

}


void CConvertorDlg::OnEnSetfocusEdtBin()
{
	// TODO: Add your control notification handler code here
	nActive = 3;
}

void CConvertorDlg::ConverttoHex(const CString& szSource,LPWSTR pszDest, int rate)
{
	
	//CString sDec;
	//TCHAR sHex[51] = L"";
	//long int dNumber = 0;
	////if (nActive == 2)
	////{
	//	dNumber = (long)_tcstol(szSource.operator LPCWSTR(), NULL, rate);
	//	//_stprintf_s(pszDest, 51, L"%#x", dNumber);
	//	_stprintf_s(pszDest, 51, L"0x%llx", dNumber);
	//
	//}

		long long dNumber = 0;
		if( (dNumber = _tcstoll(szSource.operator LPCWSTR(), NULL, rate)) == 0)
			AfxMessageBox (L"Cannot conver to Hex value");

		_stprintf_s(pszDest, TEXT_SIZE, L"0x%llx", dNumber);



}

void CConvertorDlg::ConverttoDec(const CString& szSource, LPWSTR pszDest, int rate)
{

	
	long long dNumber = 0;
	
	if ((dNumber = wcstoll(szSource.operator LPCWSTR(), NULL, rate)) == 0)
	{
		AfxMessageBox(L"Cannot convert the value");
		}
	_stprintf_s(pszDest, TEXT_SIZE, L"%lld", dNumber);
		

}

void CConvertorDlg::ConverttoBin(const CString& szSource, LPWSTR pszDest, int rate)
{


	long long dNumber = 0;

	dNumber = wcstoll(szSource.operator LPCWSTR(), NULL, rate);
	
	
	ZeroMemory(pszDest, size);
	size_t stringlen = _tcslen(pszDest);
	for (int i =  size-1; i >= 0; i--) {
		int k = dNumber >> i; // right shift
		//if ((size -1 -i) % 5 == 0 )
		
			if (k & 1) // helps us know the state of first bit
			pszDest[size-i -1] = '1';
		else
			pszDest[size-i -1] = '0';


	}
	
	pszDest[size] = '\0';
	//_tcsncat_s(pszDest,)

}



void CConvertorDlg::OnBnClickedRdByte()
{
	// TODO: Add your control notification handler code here
	size = MODE_BYTE;
	ConvertAll();
}


void CConvertorDlg::OnBnClickedRdWord()
{
	// TODO: Add your control notification handler code here
	size = MODE_WORD;
	ConvertAll();
}


void CConvertorDlg::OnBnClickedRdDword()
{
	// TODO: Add your control notification handler code here
	size = MODE_DWORD;
	ConvertAll();
}


void CConvertorDlg::OnBnClickedRdQword()
{
	// TODO: Add your control notification handler code here
	size = MODE_QWORD;
	ConvertAll();
}

void CConvertorDlg::AddSpace(LPWSTR szSource)//, CString &pszDest)
{
	CString temp = szSource;
	

	int nLen = temp.GetLength();
	
	for (int i = 1; i * 4 < nLen; i++)
	{

		temp.Insert(nLen - (i * 4), L" ");
	}
	
	
	_tcscpy_s(szSource, temp.GetLength() + 1, temp);
	//for (int i = nLen; i >3 ; i=-4)
	//{
	//	temp.Insert(nLen - i * 4, L",");
	//}
//	pszDest = temp;

}

void CConvertorDlg::ConvertAll(void)
{
	m_edt_hex.GetWindowText(sHex);
	//dNumber = (long)_tcstol(sHex.operator LPCWSTR(), NULL, 16);
	//_stprintf_s(sDec, 20, L"%ld", dNumber);
	ConverttoDec(sHex, sResult, 16);
	//m_edt_dec.SetWindowText(sDec);
	m_edt_dec.SetWindowText(sResult);

	ConverttoBin(sHex, sResult, 16);
	AddSpace(sResult);
	m_edt_bin.SetWindowText(sResult);
}