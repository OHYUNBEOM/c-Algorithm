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
	int size; // �迭�� ũ��
	Person* p; //
public:
	PersonGroup() {
		int size;
		cout << "�����? ";
		cin >> size;
		this->size = size;
		p = new Person[size];
		cout << size << "���� �̸��� ��ȭ��ȣ�� �Է����ּ���" << endl;
		for (int i = 0; i < size; i++) {
			string tempName, tempTel;
			cout << "��� " << (i + 1) << ">>";
			cin >> tempName >> tempTel;
			// �ʱ�ȭ
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
				cout << "��ȭ��ȣ�� " << p[i].getTel() << endl;
			}
		}
		if (IsFind == false) {
			cout << "�ش� �̸��� ã�� ���߽��ϴ�" << endl;
		}
	}
	void operator << (string findName) { // �������� �̸� �˻�
		bool IsFind = false;
		for (int i = 0; i < size; i++) {
			if (p[i].getName() == findName) {
				IsFind = true;
				cout << "��ȭ��ȣ�� " << p[i].getTel() << endl;
			}
		}
		if (IsFind == false) {
			cout << "�ش� �̸��� ã�� ���߽��ϴ�" << endl;
		}
	}
};
int main() {
	PersonGroup group;
	string temp;
	cout << "��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ���>>";
	cin >> temp;
	group.SearchTel(temp);
	group << temp;
	return 0;
}