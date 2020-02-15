#ifndef __CLI_ARGUMENTS_H_INCLUDED__
#define __CLI_ARGUMENTS_H_INCLUDED__

#include<iostream>
#include<string>

using namespace std;

class CLIarguments {

	int dout;
	int din;
	int pen;

public:

	void setDoutValue(int dout) { this->dout = dout; }
	void setDinValue(int din) { this->din = din; }
	void setPenValue(int pen) { this->pen = pen; }

	int getDoutValue() { return this->dout; }
	int getDinValue() { return this->din; }
	//int GetPenValue() { return this->pen; }

	CLIarguments() :dout(0), din(0), pen(0) {}

	void Parse(char* argum) {
		string argument = "";
		argument += argum;
		string left_side = "";
		string right_side = "";

		for (int i = 0; i < argument.length(); i++) {
			if (argument.at(i) == '=')
			{
				left_side += argument.substr(0, i);
				right_side += argument.substr(i + 1, argument.length());
			}
		}
		if (left_side == "--dout" || left_side == "dout")
			setDoutValue(atoi(right_side.c_str()));
		else if (left_side == "--din" || left_side == "din")
			setDinValue(atoi(right_side.c_str()));
		else if (left_side == "--pen" || left_side == "pen")
			setPenValue(atoi(right_side.c_str()));
		else
			throw "uncorrect data input";
	}
	/*void Show() {
		cout << "Dout: " << GetDoutValue() << endl; //use for debug purposes
		cout << "Din: " << GetDinValue() << endl;
		cout << "Pen: " << GetPenValue() << endl;
	}*/ 

};


#endif