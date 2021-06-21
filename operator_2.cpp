#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << "ÀÎ ¿ø " << endl; }
	friend Circle operator + (int n, Circle& a);
	friend Circle operator + (Circle& a, int n);
};

Circle operator + (int n, Circle& a) { return n + a.radius; }
Circle operator + (Circle& a, int n) { return a.radius + n; }


int main() {
	Circle a(5), b(4), c;
	b = 1 + a;
	a.show();
	b.show();
	c = b + 1;
	c.show();
}