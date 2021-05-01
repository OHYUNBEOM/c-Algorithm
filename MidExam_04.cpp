#include<iostream>
#include<string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {
		name = "";
		tel = "";
	}
	string getName() { return name; }
	string getTel() { return tel; }

	void set(string name, string tel) {
		this->name = name;
		this->tel = tel;
	}
};
class PersonGroup {
	int size; // 배열의 크기
	Person* p; //
public:
	PersonGroup() {
		int size;
		cout << "사람수? ";
		cin >> size;
		this->size = size;
		p = new Person[size];
		cout << size << "명의 이름과 전화번호를 입력해주세요" << endl;
		for (int i = 0; i < size; i++) {
			string tempName, tempTel;
			cout << "사람 " << (i + 1) << ">>";
			cin >> tempName >> tempTel;
			// 초기화
			p[i].set(tempName, tempTel);
		}
	}
	~PersonGroup() {
		delete[] p;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << p[i].getName() << ' ' << p[i].getTel() << endl;
		}
	}
	void SearchTel(string findName) {
		bool IsFind = false;
		for (int i = 0; i < size; i++) {
			if (p[i].getName() == findName) {
				IsFind = true;
				cout << "전화번호는 " << p[i].getTel() << endl;
			}
		}
		if (IsFind == false) {
			cout << "해당 이름을 찾지 못했습니다" << endl;
		}
	}
	void operator << (string findName) { // 참여자의 이름 검색
		bool IsFind = false;
		for (int i = 0; i < size; i++) {
			if (p[i].getName() == findName) {
				IsFind = true;
				cout << "전화번호는 " << p[i].getTel() << endl;
			}
		}
		if (IsFind == false) {
			cout << "해당 이름을 찾지 못했습니다" << endl;
		}
	}
};
int main() {
	PersonGroup group;
	string temp;
	cout << "전화번호를 검색합니다. 이름을 입력하세요>>";
	cin >> temp;
	group.SearchTel(temp);
	group << temp;
	return 0;
}