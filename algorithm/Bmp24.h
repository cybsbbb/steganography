#pragma once
#pragma pack(1)

#include <iostream>
#include <string>
using namespace std;

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned char BYTE;

//BMP�ļ�ͷ
typedef struct tagBITMAPFILEHEADER
{
	WORD	bfType;
	DWORD	bfSize;
	WORD	bfReserved1;
	WORD	bfReserved2;
	DWORD	bfOffBits;
};

//BMP�ļ���Ϣͷ
typedef struct tagBITMAPINFOHEADER
{
	DWORD	biSize;
	DWORD	biWidth;
	DWORD	biHeight;
	WORD	biPlanes;
	WORD	biBitCount;
	DWORD	biCompression;
	DWORD	biSizeImage;
	DWORD	biXPelsPerMeter;
	DWORD	biYPelsPerMeter;
	DWORD	biClrUsed;
	DWORD	biClrImportant;
};

class Bmp24
{
public:
	Bmp24(void);
	~Bmp24(void);
	void LoadFile(const char *filename);
	void SaveFile(const char *filename);
	void EmbedTxt(const char *filename);
	void ExtractTxt(const char *filename);

private:
	tagBITMAPFILEHEADER	*_pbmfh;	//ָ��BMP�ļ�ͷ
	tagBITMAPINFOHEADER	*_pbmih;	//ָ��BMP�ļ���Ϣͷ
	BYTE	*_pbmd;		//ָ��BMP������
	DWORD	_size;		//BMP��������С�����ֽ�Ϊ��λ��
};
