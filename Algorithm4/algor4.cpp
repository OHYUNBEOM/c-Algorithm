#include<iostream>			
int main() {
	int n, i, j, flag, cnt = 0;
	std::cin >> n;
	for (i = 2; i <= n; i++) {
		flag = 1;
		for (j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) cnt++;
	}
	std::cout << cnt << "\n";
	return 0;

	//소수의 개수 출력
}