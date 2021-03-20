#include<iostream>
int main() {
	int n, m, i, sum = 0;
	std::cin >> n >> m;
	for (i = 1; i <= n; i++) {
		if (i % m == 0) {
			sum = sum + i;
		}
	}
	std::cout << sum;
	return 0;
	//1 부터 N 까지 M의 배수의 합
}