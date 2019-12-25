#include <iostream>
#include "cli_arguments.h"

using namespace std;



int main(int count, char* argum[]) {

	for (int i = 1; i < count; i++)
		cout <<"argument "<<i<<" | "<< argum[i]<<endl;

	cout << "\n----------------------------\n";

	CLIarguments abc;

	abc.Parsing(argum[1]);
	abc.Parsing(argum[2]);
	abc.Parsing(argum[3]);
	abc.Show();
	
  return 0;
}
