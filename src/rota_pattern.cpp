#include <iostream>
#include "cli_arguments.h"
#include "tga_file.h"


using namespace std;



int main(int count, char* argum[]) {

	for (int i = 1; i < count; i++)
		cout <<"argument "<<i<<" | "<< argum[i]<<endl;

	cout << "\n--------------------------\n";

	CLIarguments Arguments;

	for (int i = 1; i < count; i++)
	Arguments.Parse(argum[i]);
	
	Arguments.Show();

	WriteTGA file;
	file.writeTargaFile("tgafile.tga", Arguments.GetDoutValue() + 20,Arguments.GetDoutValue()+20);

  return 0;
}
