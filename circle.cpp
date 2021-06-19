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
	cout << "원의 개수 >> ";
	cin >> n;
	int r;
	int cnt = 0;
	int num = 0;
	Circle* c;
	c = new Circle[n];
	for (int i = 0; i < n; i++) {
		cout << "원 " << cnt + 1 << "의 반지름 >>";
		cin >> r;
		c[i].setRadius(r);
		cnt++;
		if (c[i].getArea() > 100) {
			num++;
		}
	}
	cout << "면적이 100보다 큰 원은 " << num << "개 입니다.";
	delete[] c;
}