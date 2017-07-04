
// jcgcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "jcgc.h"
#include "jcgcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


using namespace cv;
using namespace std;

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


// CjcgcDlg �Ի���




CjcgcDlg::CjcgcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjcgcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CjcgcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CjcgcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENIMG, &CjcgcDlg::OnBnClickedOpenimg)
	ON_BN_CLICKED(IDC_XINGBIAN, &CjcgcDlg::OnBnClickedXingbian)
	ON_BN_CLICKED(IDC_SAVEIMG, &CjcgcDlg::OnBnClickedSaveimg)
END_MESSAGE_MAP()


// CjcgcDlg ��Ϣ�������

BOOL CjcgcDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CjcgcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CjcgcDlg::OnPaint()
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
HCURSOR CjcgcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CjcgcDlg::OnBnClickedOpenimg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_srcImg = (0,0,CV_8UC1);
	CFileDialog dlg(TRUE,_T(".bmp"),_T("*.bmp"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("λͼ�ļ� (*.bmp)|*.bmp|JPEG�ļ� (*.jpg)|*.jpg|PNG�ļ� (*.png)|*.png||"));//ѡ��ͼƬ
	if (IDOK==dlg.DoModal())//��ѡ���ͼƬ
	{
		string filename=dlg.GetPathName();//��ȡͼƬ��·�����ļ���
		m_srcImg = imread(filename);//��ͼƬ������ȫ�ֱ���theImage������
	}
	cvtColor(m_srcImg,m_srcImg,CV_BGR2GRAY);
	ShoeImage(m_srcImg, IDC_YUANTU);
}


void CjcgcDlg::OnBnClickedXingbian()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double Pi=3.1415926;//����pai��ֵ
	char ch1[10],ch2[10],ch3[10],ch4[10];
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1,10);//ͼ��ʵ�ʿ�
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2,10);//Բֱ��
	GetDlgItem(IDC_EDIT3)->GetWindowText(ch3,10);//����λ��ʵ�ʿ�
	GetDlgItem(IDC_EDIT4)->GetWindowText(ch4,10);//����λ��ʵ�ʿ�
	int nr = m_srcImg.rows;//ͼ����������
	int nc = m_srcImg.cols;//ͼ����������
	n_imgWidth1=atof(ch1);//floatת��
	n_Diameter=atof(ch2);
	n_imgWidth2=atof(ch3);
	n_imgWidth3=atof(ch4);
	float t=(n_imgWidth1-n_imgWidth2-n_imgWidth3)/2;//Բ������ռ�õĿ�ȵ�һ��
	if(t>0)
	{
	double J1=Pi/2-(asin((double)t/(n_Diameter/2))); //�������Ƕ�
	double J2=J1;//�������Ƕ�
	double q1=n_imgWidth2/n_imgWidth1;//������ԭͼ�Ĵ�С��ֵ
	double q2=n_imgWidth3/n_imgWidth1;//������ԭͼ�Ĵ�С��ֵ
	int i1=m_srcImg.cols*q1;//������ԭͼ�е����ؿ��
	int i2=m_srcImg.cols*q2;//������ԭͼ�е����ؿ��
	int i3=m_srcImg.cols-i1-i2;
	int w1=i1/sin(J1);//����ʵ�����ؿ��
	int w2=i2/sin(J2);//����ʵ�����ؿ��
	int pixel =i3 * (n_Diameter/(2*t));//����ֱ����ռ�õ����ؿ��
	
	double r =pixel / 2;
	double x =r * asin(i3/(2*r));//ʵ�ʵ����ؿ�ȵ�һ��;
	int dr = nr;
	int dc = 2 * x;
	int rc=dc+w1+w2;//����ʵ���ܿ��
	Mat dst(m_srcImg.rows,rc,CV_8UC1);//�����α���ͼ��
	//��ʼ����ͼ������Ȱ����ڰ��н��б任
	for(int j=0;j<m_srcImg.rows;j++)// ÿһ��ͼ���ָ��
	{
		uchar* data=dst.ptr<uchar>(j);
		uchar* data1=m_srcImg.ptr<uchar>(j);
		for(int i=0;i<w1;i++)//����ӳ���ϵ
		{
			int n=i*sin(J1);
			data[i]=data1[n];
		}
		for(int i=w1;i<w1+x;i++)//��Բ����ӳ���ϵ
		{
			int m ;
			double gap;
			gap=i-w1;
			m = r * sin(gap/r);
			data[i] = data1[i1+m]; 
		}
		for(int i=w1+x;i <w1+dc; i++)//��Բ����ӳ���ϵ
		{
			int b = r * sin((i-w1-x)/r);
			data[i] = data1[(int)(i1+i3/2+b)];
		}
		for(int i=w1+dc;i<w1+w2+dc;i++)
		{
			int c=(m_srcImg.cols-i2)+(i-(w1+dc))*sin(J2);//����ӳ���ϵ
			data[i]=data1[c];
		}
   }
	AfterImg=dst;
	ShowImage(AfterImg,IDC_XIAOGUOTU);//��ʾ
	}
	else
	{
		MessageBox("����������Ҫ��");
	}
}


void CjcgcDlg::OnBnClickedSaveimg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(FALSE,_T(".bmp"),_T("*.bmp"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("λͼ�ļ� (*.bmp)|*.bmp|JPEG�ļ� (*.jpg)|*.jpg|PNG�ļ� (*.png)|*.png||"));
	if (IDOK==dlg.DoModal())
	{
		string filename=dlg.GetPathName();//��ȡͼƬ��·�����ļ���
		imwrite(filename,AfterImg);//��ͼƬ����
	}
}


void CjcgcDlg::ShoeImage(Mat& img, int nID)
{
	CWnd* pimgShowCtrl = this->GetDlgItem(nID); //���nID�ؼ��ľ��
	CRect ctrlRect;		//����������Ա���picture�ؼ��Ĵ�С
	pimgShowCtrl->GetClientRect(&ctrlRect); //���picture�ؼ��Ĵ�С

	CDC* pDC = pimgShowCtrl->GetDC(); //����豸�����ģ���Ϊ������ʾ�����Ĳ�������Ҫ��

	//��ʼ��һ��λͼ��Ϣͷ
	BITMAPINFOHEADER BHEADER = {40, 0, 0, 1, 0, BI_RGB, 0, 0, 0, 0};

	//��ô���ͼ��������Ϣ����ֵ��λͼ��Ϣͷ��
	int width, height, depth, channel, width1;
	width = img.cols;
	height = img.rows;
	depth = img.depth();
	channel = img.channels();

	int bits, colors, i;
	bits = ( 8<< (depth/2) )*channel;//8����0��1��2��3�ֱ����8��16��32��64��ÿ��������ռ��λ��
	if(bits > 8)
	{
		colors = 0;//���ɫλͼû����ɫ��
	}
	else
	{
		colors = ( 1<<bits );//�����ɫ��λͼ����Ӧ����ɫ��
	}

	//�����ɫͼ��ʱ����ÿ������ռ�ĸ��ֽڣ������ͽ�������ɫͼ���4�ֽڱ߽��������
	if (bits == 24)
	{
		bits = 32;
	}

	//��λͼ��Ϣͷ��ֵ
	//���Ҷ�ͼ��ʱ������ÿ������ռһ���ֽڣ�������ÿ�����أ���ͼ��Ŀ�ȣ�����4�ֽڱ߽����
	if(bits == 8)
	{
		width1 = (width*8 + 31)/32 * 4; //4�ֽڱ߽������ͼ��Ŀ��
		BHEADER.biWidth = width1;
	}
	else
	{
		BHEADER.biWidth = width;//���ɫͼ��ʱ��ͼ������ؿ�Ȼ���ԭ��ͼ������ؿ��
	}
	BHEADER.biHeight = height;			
	BHEADER.biBitCount = bits;

	LPBITMAPINFO lpBitsInfo = (LPBITMAPINFO) malloc(40 + 4*colors);//����λͼ��Ϣָ������������ڴ�

	memcpy(lpBitsInfo, &BHEADER, 40);//��λͼ��Ϣͷ�����ݸ��Ƶ�λͼ��Ϣ��

	//��λͼ��Ϣ������ɫ��ĸ�ֵ
	if(colors == 256)
	{
		RGBQUAD* colorsTab = lpBitsInfo->bmiColors;
		for(i=0; i<256; i++)
		{	
			colorsTab[i].rgbBlue = colorsTab[i].rgbGreen = colorsTab[i].rgbRed = (BYTE)i;
			colorsTab[i].rgbReserved = 0;
		}	
	}

	//======�ߵ�����
	//======Mat �д������´棬��bitmap�д������ϴ档  ���Ǵ������ң�����bitmapÿһ�����ռһ�������ֽڣ�������ɫͼ��Ϊ��4�ֽڶ��룩��
	//		Ĭ��255���Ҷ�ͼ���������ֶ��뷽��
	unsigned char *m_pDibBits;//�洢ͼ���е����ݣ��������ϣ���������
	//x�� * Y��
	int x,y; 
	unsigned char * bmpdata; // �����а���
	unsigned char * imgData = img.data;
	if (bits == 8)
	{	
		m_pDibBits = new unsigned char[width1 * height];//ע��˴��õ���width1��������ͼ������ؿ�ȣ�������width

		//��imgData�еĵ�һ�и��Ƶ�  m_pDibBits �����һ��,���εߵ�
		for (x=0;  x<height;  x++ )
		{
			bmpdata = m_pDibBits + (height-1-x)*width1;
			memcpy(bmpdata,imgData,width); // Mat�п���width���ֽڣ�����width1
			imgData = imgData + width; // Mat�п���width���ֽڣ�����width1
		}
	} 
	else if (bits == 32)
	{
		m_pDibBits = new unsigned char[ width * height*4 ];

		//��imgData�еĵ�һ�и��Ƶ�  m_pDibBits �����һ��,���εߵ�
		for (x=0;  x<height;  x++ )
		{
			bmpdata = m_pDibBits + (height-1-x)*width*4;
			for (y = 0; y<width; y++)
			{
				memcpy(bmpdata,imgData,3);
				bmpdata[3] = 255;   // ע�͵� û��Ӱ��
				bmpdata = bmpdata+4;
				imgData = imgData+3;
			}    
		}
	}

	//��ʾͼ�񲿷�
	SetStretchBltMode(pDC->GetSafeHdc(), COLORONCOLOR);
	int w =img.cols; //min(img.cols,ctrlRect.Width());
	int h =img.rows; //min(img.rows,ctrlRect.Height());

	StretchDIBits(pDC->GetSafeHdc(),
		0,
		0,
		w,
		h,
		0,
		0,
		width,
		height,
		m_pDibBits,
		lpBitsInfo,
		DIB_RGB_COLORS,
		SRCCOPY);

	//�ͷ������Դ
	pimgShowCtrl->ReleaseDC(pDC);
	free(lpBitsInfo);
	delete []m_pDibBits;
}


void CjcgcDlg::ShowImage(Mat& img, int nID)
{
	CWnd* pimgShowCtrl = this->GetDlgItem(nID); //���nID�ؼ��ľ��
	CRect ctrlRect;		//����������Ա���picture�ؼ��Ĵ�С
	pimgShowCtrl->GetClientRect(&ctrlRect); //���picture�ؼ��Ĵ�С

	CDC* pDC = pimgShowCtrl->GetDC(); //����豸�����ģ���Ϊ������ʾ�����Ĳ�������Ҫ��

	//��ʼ��һ��λͼ��Ϣͷ
	BITMAPINFOHEADER BHEADER = {40, 0, 0, 1, 0, BI_RGB, 0, 0, 0, 0};

	//��ô���ͼ��������Ϣ����ֵ��λͼ��Ϣͷ��
	int width, height, depth, channel, width1;
	width = img.cols;
	height = img.rows;
	depth = img.depth();
	channel = img.channels();

	int bits, colors, i;
	bits = ( 8<< (depth/2) )*channel;//8����0��1��2��3�ֱ����8��16��32��64��ÿ��������ռ��λ��
	if(bits > 8)
	{
		colors = 0;//���ɫλͼû����ɫ��
	}
	else
	{
		colors = ( 1<<bits );//�����ɫ��λͼ����Ӧ����ɫ��
	}

	//�����ɫͼ��ʱ����ÿ������ռ�ĸ��ֽڣ������ͽ�������ɫͼ���4�ֽڱ߽��������
	if (bits == 24)
	{
		bits = 32;
	}

	//��λͼ��Ϣͷ��ֵ
	//���Ҷ�ͼ��ʱ������ÿ������ռһ���ֽڣ�������ÿ�����أ���ͼ��Ŀ�ȣ�����4�ֽڱ߽����
	if(bits == 8)
	{
		width1 = (width*8 + 31)/32 * 4; //4�ֽڱ߽������ͼ��Ŀ��
		BHEADER.biWidth = width1;
	}
	else
	{
		BHEADER.biWidth = width;//���ɫͼ��ʱ��ͼ������ؿ�Ȼ���ԭ��ͼ������ؿ��
	}
	BHEADER.biHeight = height;			
	BHEADER.biBitCount = bits;

	LPBITMAPINFO lpBitsInfo = (LPBITMAPINFO) malloc(40 + 4*colors);//����λͼ��Ϣָ������������ڴ�

	memcpy(lpBitsInfo, &BHEADER, 40);//��λͼ��Ϣͷ�����ݸ��Ƶ�λͼ��Ϣ��

	//��λͼ��Ϣ������ɫ��ĸ�ֵ
	if(colors == 256)
	{
		RGBQUAD* colorsTab = lpBitsInfo->bmiColors;
		for(i=0; i<256; i++)
		{	
			colorsTab[i].rgbBlue = colorsTab[i].rgbGreen = colorsTab[i].rgbRed = (BYTE)i;
			colorsTab[i].rgbReserved = 0;
		}	
	}

	//======�ߵ�����
	//======Mat �д������´棬��bitmap�д������ϴ档  ���Ǵ������ң�����bitmapÿһ�����ռһ�������ֽڣ�������ɫͼ��Ϊ��4�ֽڶ��룩��
	//		Ĭ��255���Ҷ�ͼ���������ֶ��뷽��
	unsigned char *m_pDibBits;//�洢ͼ���е����ݣ��������ϣ���������
	//x�� * Y��
	int x,y; 
	unsigned char * bmpdata; // �����а���
	unsigned char * imgData = img.data;
	if (bits == 8)
	{	
		m_pDibBits = new unsigned char[width1 * height];//ע��˴��õ���width1��������ͼ������ؿ�ȣ�������width

		//��imgData�еĵ�һ�и��Ƶ�  m_pDibBits �����һ��,���εߵ�
		for (x=0;  x<height;  x++ )
		{
			bmpdata = m_pDibBits + (height-1-x)*width1;
			memcpy(bmpdata,imgData,width); // Mat�п���width���ֽڣ�����width1
			imgData = imgData + width; // Mat�п���width���ֽڣ�����width1
		}
	} 
	else if (bits == 32)
	{
		m_pDibBits = new unsigned char[ width * height*4 ];

		//��imgData�еĵ�һ�и��Ƶ�  m_pDibBits �����һ��,���εߵ�
		for (x=0;  x<height;  x++ )
		{
			bmpdata = m_pDibBits + (height-1-x)*width*4;
			for (y = 0; y<width; y++)
			{
				memcpy(bmpdata,imgData,3);
				bmpdata[3] = 255;   // ע�͵� û��Ӱ��
				bmpdata = bmpdata+4;
				imgData = imgData+3;
			}    
		}
	}

	//��ʾͼ�񲿷�
	SetStretchBltMode(pDC->GetSafeHdc(), COLORONCOLOR);
	int w =AfterImg.cols; //min(img.cols,ctrlRect.Width());
	int h =AfterImg.rows; //min(img.rows,ctrlRect.Height());

	StretchDIBits(pDC->GetSafeHdc(),
		0,
		0,
		w,
		h,
		0,
		0,
		width,
		height,
		m_pDibBits,
		lpBitsInfo,
		DIB_RGB_COLORS,
		SRCCOPY);

	//�ͷ������Դ
	pimgShowCtrl->ReleaseDC(pDC);
	free(lpBitsInfo);
	delete []m_pDibBits;
}
