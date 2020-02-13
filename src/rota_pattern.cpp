#include <iostream>
#include <string>

#include "cli_arguments.h"
#include "tga_file.h"
#include "Canvas.h"
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
	arguments.Show();
	int side_length = arguments.GetDoutValue() + padding;
	Canvas canvas(side_length);

	RGB main_color = { (byte)0, (byte)0, (byte)0 };


	Math math(arguments.GetDoutValue(), arguments.GetDinValue(), padding);

	vector<Position> coordinates = math.drawCircle();
	
	for (int i = 0; i < coordinates.size(); i++) {
		canvas.put_pixel_at(coordinates.at(i).x, coordinates.at(i).y, main_color);
	}


	vector<RGB> pixels_data = canvas.get_all_pixels();

    WriteTGA file(side_length);
	string fileName = to_string(arguments.GetDoutValue()) + '_' + to_string(arguments.GetDinValue()) + "_pattern.tga";
	file.save(fileName, pixels_data);

  return 0;
}
