#include<iostream>
using namespace std;
int N, ans;
int main(void)
{
	cin >> N;
	ans = (N > 99) ? 99 : N;
	while (N > 99) ans += (N / 100 - N / 10 % 10 == N / 10 % 10 - N-- % 10);
	cout << ans;

	return 0;
}