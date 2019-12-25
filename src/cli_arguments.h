#ifndef __CLI_ARGUMENTS_H_INCLUDED__
#define __CLI_ARGUMENTS_H_INCLUDED__

#include<iostream>

using namespace std;
class CLIarguments {

	int dout;
	int din;
	int pen;

public:

	bool SetDout(int dout) { this->dout = dout; return 1; }
	bool SetDin(int din) { this->din = din; return 1; }
	bool SetPen(int pen) { this->pen = pen; return 1; }
	int GetDout() { return this->dout; }
	int GetDin() { return this->din; }
	int GetPen() { return this->pen; }

	CLIarguments(int dout = 0, int din = 0, int pen = 0) { //def constructor
		this->din = din;
		this->dout = dout;
		this->pen = pen;
	}
	// --dout=120
	void Parsing(char *arg) {
		int size = strlen(arg) + 1;
		char *buff = new char[size];
		int j = 0, a = 0, p = 0;  //iterators or counters


		for (int i = 0; i < size; i++) {
			if (arg[i] != '-' && arg[i] != '=') {
				buff[j] = arg[i];
				j++;
			}
		}

		char* namePart = new char[j];
		char* numberPart = new char[j];

		for (int i = 0; i < j; i++) {
			if ((int)buff[i] >= 48 && (int)buff[i] <= 57) {
				numberPart[a] = buff[i];
				a++;
			}
			else {
				namePart[p] = buff[i];
				p++;
			}
		}
		p--;
		int newNumber = atoi(numberPart);
		if (strcmp(namePart, "dout") == 0) {
			SetDout(newNumber);
		}
		else if (strcmp(namePart, "din") == 0) {
			SetDin(newNumber);
		}
		else if (strcmp(namePart, "pen") == 0) {
			SetPen(newNumber);
		}
		delete[] numberPart;
		delete[]namePart;
		delete[] buff;
	}
	void Show() {
		cout << "Dout: " << GetDout() << endl;
		cout << "Din: " << GetDin() << endl;
		cout << "Pen: " << GetPen() << endl;
	}
};


#endif