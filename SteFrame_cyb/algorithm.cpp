#include "algorithm.h"
#define BYTE unsigned char

using namespace std;

Algorithm::Algorithm()
{

}

Algorithm::~Algorithm()
{

}

Algorithm::Algorithm(QImage &img){
    Algorithm::img = img;
}

void Algorithm::EmbedText(QString &text){

    int width = img.width();
    int height = img.height();

    int size = width * height;

    if(8 * text.length() >= size){
        printf("Text Too Long");
    }

    int length = 8 * text.length();

    BYTE * textB = new BYTE[length];

    char temp;

    for(int i = 0; i < text.length(); i++){
        temp = text.at(i).unicode();
        for(int j = 0; j < 8; j++){
            textB[i*8+j] = (BYTE)(temp & 0x0001);//let the lowest bit of temp to textB
            temp = temp >> 1;
        }
    }

    int k = 0;
	int length_copy = length;

    for (int i = 0; i < width;i++)
    {
        for(int j = 0; j < height;j++)
        {
            QRgb rgb = img.pixel(i,j);
            int red = qRed(rgb);

            if(k < 32){
                red = red & 0xFFFFFFFE;
                red += length_copy & 0x00000001;
                length_copy = length_copy >> 1;
                rgb = qRgb(red, qGreen(rgb),qBlue(rgb));  // set new red & pixel to (i,j)
                img.setPixel(i,j,rgb);
            }
            else if(k < length + 32){
                red = red & 0xFFFFFFFE;
                red += textB[k-32];
                rgb = qRgb(red,qGreen(rgb),qBlue(rgb));
                img.setPixel(i,j,rgb);
            }
            k++;
        }
    }
	return;
}

void Algorithm::ExtractText(){

    int width = img.width();
    int height = img.height();

    int k = 0;

    int length = 0;

    BYTE * result;

    for (int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            QRgb rgb = img.pixel(i,j);
            int red = qRed(rgb);

            if(k < 32){
                int temp = red & 0x00000001;
                temp = temp << k;
                length += temp;
            }
            else if(k < length + 32 && k >= 32){
                if(k == 32){
                    result = new BYTE[length];
                }
                result[k-32] = (BYTE)red & 0x00000001;
            }
            k++;
        }
    }

    vector<char> resultLast;// = new char[l];

    char temp = 0;
    k = 0;

    for(int i = 0; i < length; i++){
        k = i / 8;
        int j = i % 8;
        char temptemp = (char)result[i];
        temptemp = temptemp << j;
        if(j == 0)
        {
            temp = temptemp;
        }
        else if (j > 0)
        {
            temp += temptemp;
			if (j == 7){
                resultLast.push_back(temp);
                cout <<"temp = "<<temp<<endl;
			}
        }       
    }

    string ss,ss_temp;
    for (size_t i = 0; i < resultLast.size(); i++)
    {
        char cc = resultLast.at(i);
        ss_temp = cc;
        ss.append(ss_temp);
    }
    resultSte = QString::fromStdString(ss);
    return;
}
