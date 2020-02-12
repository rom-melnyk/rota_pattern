#ifndef __MATH_H_INCLUDED__
#define __MATH_H_INCLUDED__

#include<iostream>
#include<cmath>
#include <vector>

using namespace std;

struct Position {
	int x;
	int y;
};

class Math {
private:
	Position center;
	int r;
	const double PI = 3.1415;
public:

	Math(int side_length) {
		r = (side_length - 20) / 2;
		center.x = side_length / 2;
		center.y = side_length / 2;
	}
	vector<Position> drawCircle() {
		int dx, dy = 0;
		vector<Position> coordinates;
		for (double alpha = 0; alpha < PI*2; alpha += PI/180) {
			dx = sin(alpha) * r;
			dy = cos(alpha) * r;
			coordinates.push_back({ dx + center.x, dy + center.y });
		}
		return coordinates;
	}
};
#endif
