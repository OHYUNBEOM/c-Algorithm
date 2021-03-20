#include<iostream>
using namespace std;
int main() {
	int n, i, cnt = 0, tmp;
	cin >> n;
	for (i = 1; i <= n; i++) {
		tmp = i;
		while (tmp > 0) {
			tmp = tmp / 10;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;

	//자연수 N 입력시 1부터 N 까지 자연수를 종이에 적을때 쓰이는 숫자 개수
	// ex 1 ~ 15 --> 1.2.3.4.5.6.7.8.9.1.0.1.1.1.2.1.3.1.4.1.5 총 21개 사용
}