#ifndef __CLI_ARGUMENTS_H_INCLUDED__
#define __CLI_ARGUMENTS_H_INCLUDED__

#include<iostream>

using namespace std;
class CLIarguments {

	int dout;
	int din;
	int pen;

public:

	void SetDoutValue(int dout) { this->dout = dout; }
	void SetDinValue(int din) { this->din = din; }
	void SetPenValue(int pen) { this->pen = pen; }

	int GetDoutValue() { return this->dout; }
	int GetDinValue() { return this->din; }
	int GetPenValue() { return this->pen; }

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
			SetDoutValue(atoi(right_side.c_str()));
		else if (left_side == "--din" || left_side == "din")
			SetDinValue(atoi(right_side.c_str()));
		else if (left_side == "--pen" || left_side == "pen")
			SetPenValue(atoi(right_side.c_str()));
		else
			throw "uncorrect data input";
	}
	void Show() {
		cout << "Dout: " << GetDoutValue() << endl;
		cout << "Din: " << GetDinValue() << endl;
		cout << "Pen: " << GetPenValue() << endl;
	}

};


#endif