#include <iostream>
#include <string>

#include "cli_arguments.h"
#include "tga_file.h"
#include "canvas.h"
#include "math.h"

using namespace std;



int main(int count, char* argum[]) {

	for (int i = 1; i < count; i++)
		cout <<"argument "<<i<<" | "<< argum[i]<<endl;

	cout << "\n--------------------------\n";

	CLIarguments arguments;
	int padding = 20;
	try {
		for (int i = 1; i < count; i++)
			arguments.Parse(argum[i]);
	}
	catch (const char * error) {
		cout << error << endl;
	}
	//arguments.Show();
	int side_length = arguments.getDoutValue() + padding;
	Canvas canvas(side_length);

	RGB main_color = { (byte)0, (byte)0, (byte)0 };

	Math math(arguments.getDoutValue(), arguments.getDinValue(), padding);

	vector<Position> coordinates = math.drawCircle();
	
	for (int i = 0; i < coordinates.size(); i++) {
		canvas.putPixelAt(coordinates.at(i).x, coordinates.at(i).y, main_color);
	}

	vector<RGB> pixels_data = canvas.getAllpixels();

    WriteTGA file(side_length);

	string fileName = to_string(arguments.getDoutValue()) + '_' + to_string(arguments.getDinValue()) + "_pattern.tga";
	file.save(fileName, pixels_data);

	cout << "file " + fileName <<" is loaded! "<<endl;
  return 0;
}
