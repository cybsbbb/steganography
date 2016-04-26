#include "Bmp24.h"
#include <iostream>
#include <string>
#include <fstream>

Bmp24::Bmp24(void)
{
	_pbmfh = new tagBITMAPFILEHEADER;
	_pbmih = new tagBITMAPINFOHEADER;
	_pbmd = NULL;
	_size = 0;
}

Bmp24::~Bmp24(void)
{
	delete _pbmfh;
	delete _pbmih;
	if (_pbmd)
	{
		delete _pbmd;
	}
}

//载入BMP文件
void Bmp24::LoadFile(const char *filename)
{
	ifstream InFile;
	InFile.open(filename, ios::in | ios::binary);

	InFile.read((char*)_pbmfh, sizeof(tagBITMAPFILEHEADER));
	cout << "+-----------+" << endl
		 << "Read bmfh OK!" << endl;
	InFile.read((char*)_pbmih, sizeof(tagBITMAPINFOHEADER));
	cout << "Read bmih OK!" << endl;

	//直接定位BMP数据区，跳过调色板
	_size = _pbmfh->bfSize - _pbmfh->bfOffBits;
	_pbmd = new BYTE[_size];
	InFile.read((char*)_pbmd, _size);
	cout << "Read bmd  OK!" << endl;
	InFile.close();
	cout << "Load file OK!" << endl
		 << "+-----------+" << endl;
}

//保存BMP文件
void Bmp24::SaveFile(const char *filename)
{
	ofstream OutFile;
	OutFile.open(filename, ios::out | ios::binary);
	
	OutFile.write((char*)_pbmfh, sizeof(tagBITMAPFILEHEADER));
	cout << "+============+" << endl
		 << "Write bmfh OK!" << endl;
	OutFile.write((char*)_pbmih, sizeof(tagBITMAPINFOHEADER));
	cout << "Write bmih OK!" << endl;
	OutFile.write((char*)_pbmd, _size);
	cout << "Write bmd  OK!" << endl;
	OutFile.close();
	cout << "Save  file OK!" << endl
		 << "+============+" << endl;
}

//嵌入文本文件
void Bmp24::EmbedTxt(const char *filename)
{
	ifstream TxtFile;
	TxtFile.open(filename, ios::in | ios::binary);
	TxtFile.seekg(0, TxtFile.end);
	DWORD TxtFileLength = TxtFile.tellg();
	if (_size < TxtFileLength * 8)
	{
		return ;
	}

	cout << "M  file length: " << TxtFileLength << endl;
	BYTE *pTxtFile = new BYTE[TxtFileLength];
	TxtFile.seekg(0, TxtFile.beg);
	TxtFile.read((char*)pTxtFile, TxtFileLength);
	TxtFile.close();

	for (int i = 0, k = 0; i < TxtFileLength; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((pTxtFile[i] >> j & 0x01) == 0)
				_pbmd[k+32] &= 0xfe;
			else
				_pbmd[k+32] |= 0x01;
			++k;
		}
	}

	for (int i = 0; i < 32; ++i)
	{
		if ((TxtFileLength >> i & 0x00000001) == 0)
			_pbmd[i] &= 0xfe;
		else
			_pbmd[i] |= 0x01;
	}
	delete pTxtFile;
	cout << "Embedding file OK!" << endl;
}

//提取文本文件
void Bmp24::ExtractTxt(const char *filename)
{
	DWORD TxtFileLength = 0x00000000;
	for (int i = 0; i < 32; ++i)
	{
		if ((_pbmd[i] & 0x01) == 0)
			TxtFileLength &= 0x7fffffff;
		else
			TxtFileLength |= 0x80000000;

		if (i < 31)
			TxtFileLength >>= 1;
	}
	cout << "M' file length: " << TxtFileLength << endl;

	BYTE *pTxtFile = new BYTE[TxtFileLength];
	for (int i = 0, k = 0; i < TxtFileLength * 8; ++i)
	{
		if (i && i % 8 == 0)
			++k;
		if ((_pbmd[i + 32] & 0x01) == 0)
			pTxtFile[k] &= 0x7f;
		else
			pTxtFile[k] |= 0x80;
		if (i % 8 != 7)
			pTxtFile[k] >>= 1;
	}

	ofstream TxtFile;
	TxtFile.open(filename, ios::out | ios::binary);
	TxtFile.write((char*)pTxtFile, TxtFileLength);
	TxtFile.close();
	delete pTxtFile;
	cout << "Extrating file OK!" << endl;
}
