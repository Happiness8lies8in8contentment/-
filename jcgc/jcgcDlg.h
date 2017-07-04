
// jcgcDlg.h : 头文件
//

#pragma once
#include "opencv2/opencv.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
using namespace cv;


// CjcgcDlg 对话框
class CjcgcDlg : public CDialogEx
{
// 构造
public:
	CjcgcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JCGC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
