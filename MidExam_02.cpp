#include<iostream>
using namespace std;
class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n;
		p = new int[size];
	}
	void read() {
		int i;
		cout << "입력>> ";
		int num;
		for (i = 0; i < size; i++) {
			cin >> num;
			p[i] = num;
		}
	}
	void write() {
		int i;
		for (i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << "\n";
	}
	int biggestOne() {
		int max = p[0];
		int i;
		for (i = 0; i < size; i++) {
			if (p[i] > max) {
				max = p[i];
			}
		}
		return max;
	}
	~Sample() {
		delete[]p;
	}
};
int main(void) {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수: " << s.biggestOne() << "\n";
	return 0;
}