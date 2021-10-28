// Emerson Racca
// 10/27/2021
// Lab 8c - Pentagon Methods

/*
Create methods and implement them in your Pentagon struct.

1. A print method

2. A Perimeter method.

	perimeter = 5 * s
	where s = side length

3. An Area method.

	area = (5*s^2)/(4*tan(36))

Note:
	let R be the radius of a circumscribed circle of a regular polygon

		R = s/(2*sin(36))

	let r be the radius of an inscribed circle of a regular polygon

		r = s/(2*tan(36))
*/

#include<iostream>
#include<cstdlib> // srand(), rand()
#include<ctime> // time()
#include<iomanip> // setprecision()
#include<cmath>

using namespace std;

struct Pentagon {
	double side = 1.0; //Initialized to remove warning from compiler.
	string color = "black";

	double r(void); //for inscribed circle
	double R(void); //for circumscribed circle
	void print(void); //print
	double area();
	double perimeter();
};

void populatePentagon(Pentagon p[], const int s);

int main(void) {
	srand((unsigned int)time(0));
	cout << fixed << setprecision(2);

	const int size = 50;
	Pentagon pent[size];

	cout << "Pentagon Methods\n\n";

	populatePentagon(pent, size);

	for (int i = 0; i < size; i++) {
		cout << "Element with index " << i << " --" << endl;
		pent[i].print();
	}

	return 0;
}

void populatePentagon(Pentagon p[], const int s) {
	// To choose from random colors.
	string c[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white" };

	for (int i = 0; i < s; i++) {
		p[i].side = 1.0 + rand() % 100 + 1.0 * rand() / RAND_MAX;
		p[i].color = c[rand() % 10];

	}
}

// Print pentagon object.
void Pentagon::print(void) {
	cout << "Side length : " << side << endl;
	cout << "Inner Radius: " << r() << endl;
	cout << "Outer Radius: " << R() << endl;
	cout << "Color       : " << color << endl;
	cout << "Area        : " << area() << endl;
	cout << "Perimeter   : " << perimeter() << endl;
	cout << endl;
}

// Compute r, where r is the radius of the inscribed circle. Also known as the apothem.
double Pentagon::r(void) {
	return (1.0 * side / (2.0 * tan(36.0 * 3.1415926 / 180))); // radian conversion
}

// Compute R, where R is the radius of the circumscribed circle.
double Pentagon::R(void) {
	return ((1.0 * side) / (2.0 * sin(36.0 * 3.1415926 / 180)));
}

// Compute area.
double Pentagon::area() {
	return ((5.0 * pow(side, 2.0)) / (4.0 * tan(36.0 * 3.1415926 / 180)));
}

// Compute perimeter.
double Pentagon::perimeter() {
	return 5.0 * side;
}
