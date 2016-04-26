#include "Bmp24.h"
#include <iostream>
using namespace std;

int main()
{
	int op = -1;
	char *filename = new char;
	Bmp24 cover;

	while(op)
	{
		cout << "1.Embed" << endl
			 << "2.Extract" << endl
			 << "3.Quit" << endl
			 << "Select OP: ";
		cin >> op;
		switch(op)
		{
		case 1:
			cout << "Enter C  file name: ";
			cin >> filename;
			cover.LoadFile(filename);
			cout << "Enter M  file name: ";
			cin >> filename;
			cover.EmbedTxt(filename);
			cout << "Enter C' file name: ";
			cin >> filename;
			cover.SaveFile(filename);
			break;
		case 2:
			cout << "Enter C' file name: ";
			cin >> filename;
			cover.LoadFile(filename);
			cout << "Enter M' file name: ";
			cin >> filename;
			cover.ExtractTxt(filename);
			break;
		case 3:
			op = 0;
			break;
		default:
			cout << "Illegal input!";
		}
	}
	system("pause");
	delete filename;
	return 0;
}