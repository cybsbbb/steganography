#pragma once
#pragma pack(1)

#include <iostream>
#include <string>
using namespace std;

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned char BYTE;

//BMP文件头
typedef struct tagBITMAPFILEHEADER
{
	WORD	bfType;
	DWORD	bfSize;
	WORD	bfReserved1;
	WORD	bfReserved2;
	DWORD	bfOffBits;
};

//BMP文件信息头
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
	tagBITMAPFILEHEADER	*_pbmfh;	//指向BMP文件头
	tagBITMAPINFOHEADER	*_pbmih;	//指向BMP文件信息头
	BYTE	*_pbmd;		//指向BMP数据区
	DWORD	_size;		//BMP数据区大小（以字节为单位）
};
