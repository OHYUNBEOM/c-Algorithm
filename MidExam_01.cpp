#include<iostream>
#include<string>
using namespace std;
class Account {
	string name;
	int id;
	int money;
public:
	Account() {
		name = "";
		id = 0;
		money = 0;
	}
	Account(string name, int id, int money) {
		this->name = name;
		this->id = id;
		this->money = money;
	}
	void deposit(int m) {
		money += m;
	}
	string getOwner() {
		return name;
	}
	int inquiry() {
		return money;
	}
	int withdraw(int m) {
		money -= m;
		return money;
	}
};
int main(void) {
	Account a("kitea", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << "입니다\n";
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << "입니다\n";
	return 0;
}