#include<iostream>
using namespace std;
int main() {
	int n, sum = 1, i;
	cin >> n;
	cout << "1";
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			sum += i;
			cout << " + " << i;
		}
	}
	cout << " = " << sum;
	return 0;

	//진약수의 합
}