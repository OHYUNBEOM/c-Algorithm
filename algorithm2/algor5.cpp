#include<iostream>
using namespace std;
int main() {
	int a[101], b[101], i, j, n, A = 0, B = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (i = 1; i <= n; i++) {
		if (a[i] == b[i]) cout << "D\n";
		else if (a[i] == 1 && b[i] == 3) cout << "A\n";
		else if (a[i] == 2 && b[i] == 1) cout << "A\n";
		else if (a[i] == 3 && b[i] == 2) cout << "A\n";
		else cout << "B\n";
	}
	return 0;

	//���������� ���α׷�
	//N �� ���� , A �� �̱�� A ��� B �� �̱�� B ���
	//��� ��� D ���
	// ex) 5 / 2 3 3 1 3 / 1 1 2 2 3 --> A / B / A / B / D ���
}