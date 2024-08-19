
// ConvertorDlg.h : header file
//

#pragma once

#define BYTE_MODE 8
#define WORD_MODE 16
#define DWORD_MODE 32
#define QWORD_MODE 64
#define TEXT_SIZE 80

// CConvertorDlg dialog
class CConvertorDlg : public CDialogEx
{
// Construction
public:
	CConvertorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONVERTOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edt_hex;
	CEdit m_edt_dec;
	afx_msg void OnEnChangeEdtHex();
	afx_msg void OnEnChangeEdtDec();
	afx_msg void OnEnSetfocusEdtDec();
	afx_msg void OnEnSetfocusEdtHex();
	int nActive = 1;
	CEdit m_edt_bin;
	afx_msg void OnEnChangeEdtBin();
	afx_msg void OnEnSetfocusEdtBin();
    void ConverttoHex(const CString& szSource,LPWSTR pszDest, int rate);
	void ConverttoDec(const CString& szSource, LPWSTR pszDest, int rate);
	void ConverttoBin(const CString& szSource, LPWSTR pszDest, int rate);

	CString Text;
	CString sHex;
	CString sDec;
	CString sBin;
	enum mode  { MODE_BYTE = 8, MODE_WORD=16, MODE_DWORD = 32, MODE_QWORD =64};
	int size = MODE_BYTE;
	afx_msg void OnBnClickedRdByte();
	afx_msg void OnBnClickedRdWord();
	afx_msg void OnBnClickedRdDword();
	afx_msg void OnBnClickedRdQword();
//	void AddSpace(const CString& szSource, CString& pszDest);
//	void AddSpace(CString& szSource);
	void ConvertAll(void);
	void AddSpace(LPWSTR szSource);
	int m_size_type;
	TCHAR sResult[TEXT_SIZE] = { L"" };
	int m_intTxtBin;
};
