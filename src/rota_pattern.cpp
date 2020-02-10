#include <iostream>

#include "cli_arguments.h"
#include "tga_file.h"
#include "Canvas.h"

using namespace std;



int main(int count, char* argum[]) {

	for (int i = 1; i < count; i++)
		cout <<"argument "<<i<<" | "<< argum[i]<<endl;

	cout << "\n--------------------------\n";

	CLIarguments Arguments;
	try {
		for (int i = 1; i < count; i++)
			Arguments.Parse(argum[i]);
	}
	catch (const char * error) {
		cout << error << endl;
	}
	Arguments.Show();

    WriteTGA file(Arguments.GetDoutValue() + 20, Arguments.GetDoutValue() + 20);
	file.writeTargaFile("tgafile.tga");

	

  return 0;
}
