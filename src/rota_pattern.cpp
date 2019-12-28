#include <iostream>
#include "cli_arguments.h"

using namespace std;



int main(int count, char* argum[]) {

	for (int i = 1; i < count; i++)
		cout <<"argument "<<i<<" | "<< argum[i]<<endl;

	cout << "\n----------------------------\n";

	CLIarguments Argument;
	for (int i = 1; i <count; i++)
	Argument.Parse(argum[i]);
	
	Argument.Show();
	
  return 0;
}
