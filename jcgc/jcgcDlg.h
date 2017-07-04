
// jcgcDlg.h : ͷ�ļ�
//

#pragma once
#include "opencv2/opencv.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
using namespace cv;


// CjcgcDlg �Ի���
class CjcgcDlg : public CDialogEx
{
// ����
public:
	CjcgcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_JCGC_DIALOG };

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
	Mat m_srcImg, AfterImg;
	float n_Diameter;
	float n_imgWidth1;
	float n_imgWidth2;
	float n_imgWidth3;
	double shapehorn1;
	double shapehorn2;
	afx_msg void OnBnClickedOpenimg();
	afx_msg void OnBnClickedXingbian();
	afx_msg void OnBnClickedSaveimg();
	void ShoeImage(Mat& img, int nID);
	void ShowImage(Mat& img, int nID);
};
