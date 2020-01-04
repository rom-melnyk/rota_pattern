#ifndef __CLI_ARGUMENTS_H_INCLUDED__
#define __CLI_ARGUMENTS_H_INCLUDED__

#include <iostream>
#include <cstring>

using namespace std;
class CLIarguments {

	int dout;
	int din;
	int pen;

public:

	void SetDoutValue(int dout) { this->dout = dout; }
	void SetDinValue(int din) { this->din = din;}
	void SetPenValue(int pen) { this->pen = pen;}

	int GetDoutValue() { return this->dout; }
	int GetDinValue() { return this->din; }
	int GetPenValue() { return this->pen; }

	CLIarguments() { //def constructor
		this->din = 0;
		this->dout = 0;
		this->pen = 0;
	}
	// --dout=120
	void Parse(char *arg) {
		int size = strlen(arg)+1;
		char *tmpArgument = new char[size];
		int tmpSize = 0, numberPartIndex= 0, namePartIndex = 0;  //iterators or counters


		for (int i = 0; i < size; i++) {
			if (arg[i] != '-' && arg[i] != '=') {
				tmpArgument[tmpSize] = arg[i];
				tmpSize++;
			}
		}

		char* namePart = new char[tmpSize];
		char* numberPart = new char[tmpSize];

		for (int i = 0; i < tmpSize; i++) {
			if ((int)tmpArgument[i] >= 48 && (int)tmpArgument[i] <= 57) {
				numberPart[numberPartIndex] = tmpArgument[i];
				numberPartIndex++;
			}
			else {
				namePart[namePartIndex] = tmpArgument[i];
				namePartIndex++;
			}
		}
		int newNumber = atoi(numberPart);
		if (strcmp(namePart, "dout") == 0)
			SetDoutValue(newNumber);
		else if (strcmp(namePart, "din") == 0)
			SetDinValue(newNumber);
		else if (strcmp(namePart, "pen") == 0) 
			SetPenValue(newNumber);

		delete[] numberPart;
		delete[] namePart;
		delete[] tmpArgument;
	}
	void Show() {
		cout << "Dout: " << GetDoutValue() << endl;
		cout << "Din: " << GetDinValue() << endl;
		cout << "Pen: " << GetPenValue() << endl;
	}
};


#endif