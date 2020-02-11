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
	int side_length = Arguments.GetDoutValue() + 20;
	Canvas canvas(side_length);

	RGB main_color = { (byte)0, (byte)0, (byte)0 };

	/*for (int i = 20; i <= 100; i++)
		canvas.put_pixel_at(i, 20, main_color);

	for (int i = 40; i <= 100; i++)
		canvas.put_pixel_at(40, i, main_color);

	for (int i = 20; i <= 100; i++)
		canvas.put_pixel_at(100, i, main_color);

	for (int i = 40; i <= 100; i++)
		canvas.put_pixel_at(i, 100, main_color);
		*/
	vector<RGB> pixels_data = canvas.get_all_pixels();


    WriteTGA file(side_length);
	file.save("tgafile.tga", pixels_data);
  return 0;
}
