#include <iostream>
#include <string>
using namespace std;

class Circle {
	Circle* c;
	int radius;
public:
	Circle() {
		radius = 0;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

int main() {
	int n;
	cout << "���� ���� >> ";
	cin >> n;
	int r;
	int cnt = 0;
	int num = 0;
	Circle* c;
	c = new Circle[n];
	for (int i = 0; i < n; i++) {
		cout << "�� " << cnt + 1 << "�� ������ >>";
		cin >> r;
		c[i].setRadius(r);
		cnt++;
		if (c[i].getArea() > 100) {
			num++;
		}
	}
	cout << "������ 100���� ū ���� " << num << "�� �Դϴ�.";
	delete[] c;
}