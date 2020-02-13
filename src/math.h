#ifndef __MATH_H_INCLUDED__
#define __MATH_H_INCLUDED__

#include<iostream>
#include<cmath>
#include <vector>

#define PI 3.1415

using namespace std;

struct Position {
	double x;
	double y;
};

struct Circle {
	Position center;
	int R;
	double angle;
};

class Math {
private:
	Circle big;
	Circle small;

	double normalize(double angle) {
		if (angle > PI * 2) {
			return angle - PI * 2;
		} else if (angle < 0) {
			return PI * 2 + angle;
		} else {
			return angle;
		}
	}

	bool isAroundInitialPosition(double angle) {
		double treshhold = 0.001;
		return (PI * 2 - angle < treshhold || angle < treshhold);
	}

public:

	Math( int dout, int din, int padding) {  
		big.R = dout / 2;
		big.center.x = (dout + padding) / 2;
		big.center.y = (dout + padding) / 2;
		big.angle = 0.0;

		small.R = din / 2;
		small.angle = 0.0;
	}

	vector<Position> drawCircle() {
		vector<Position> coordinates;
		double bigCircleAngleStep = PI / 360;
		do {
			double bigDx = sin(big.angle) * big.R;
			double bigDy = cos(big.angle) * big.R;
			//coordinates.push_back({ bigDx + big.center.x, bigDy + big.center.y });

			int trajectR = big.R - small.R;
			double trajectDx = sin(big.angle) * trajectR;
			double trajectDy = cos(big.angle) * trajectR;
			small.center.x = trajectDx + big.center.x;
			small.center.y = trajectDy + big.center.y;

			double smallCirlceAngleStep = bigCircleAngleStep * big.R / small.R;
			small.angle -= smallCirlceAngleStep;
			small.angle = normalize(small.angle);

			double smallDx = sin(small.angle) * small.R;
			double smallDy = cos(small.angle) * small.R;
			coordinates.push_back({ smallDx + small.center.x, smallDy + small.center.y });


			big.angle += bigCircleAngleStep;
			big.angle = normalize(big.angle);
		} while (!(isAroundInitialPosition(big.angle) && isAroundInitialPosition(small.angle)));

		return coordinates;
	}
};
#endif
