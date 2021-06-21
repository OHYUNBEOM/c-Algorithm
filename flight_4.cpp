#include <iostream>
#include <string>
using namespace std;

class Seat{
	string name = "---";
public:
	string outName(){ return name; }
	void inName(string name) { this->name = name; }
	void cancle() { this->name = "---"; }
	~Seat(){}
};

class Schedule{
	// �ϳ��� �������� ����
	//8�� �¼�, ���� ��� ���� ����

	Seat* se = new Seat[8];
public:
	void state(){
		for (int i = 0; i < 8; i++){
			cout << se[i].outName() << "   ";
		}
		cout << endl;
	}
	void book(int n, string name){
		se[n].inName(name);
	}
	string check(int n){
		return se[n].outName();
	}
	void cancel(int n){
		se[n].cancle();
	}
	~Schedule(){ delete[] se; }
};

class AirlineBook{
	//������ 3������
	// ����ý��� �۵�
	int time;
	int seatNumber;
	string name;
	Schedule* s = new Schedule[3];
public:
	void book(){
		cout << "07��:1, 12��: 2, 17��:3>>";
		cin >> this->time;
		s[time - 1].state();
		cout << "�¼���ȣ>>";
		cin >> this->seatNumber;
		cout << "�̸� �Է�>>";
		cin >> this->name;

		if (s[time - 1].check(seatNumber - 1) == "---")
			s[time - 1].book(seatNumber - 1, name);
		else{
			cout << "�̹� ����� �ڸ��Դϴ�." << endl;
		}
	}
	void cancel(){
		cout << "07��:1, 12��: 2, 17��:3>>";
		cin >> this->time;
		s[time - 1].state();
		cout << "�¼���ȣ>>";
		cin >> this->seatNumber;
		cout << "�̸� �Է�>>";
		cin >> this->name;

		if (s[time - 1].check(seatNumber - 1) == name){
			cout << "��ҵǾ����ϴ�." << endl;
			s[time - 1].cancel(seatNumber - 1);
		}
		else
			cout << "�ش������� �ٸ��ϴ�" << endl;
	}
	void space(){
		for (int i = 0; i < 3; i++){
			s[i].state();
		}
	}
	~AirlineBook(){ delete[] s; }

};


int main(){
	AirlineBook* a = new AirlineBook();
	int choice;
	cout << "**** �Ѽ��װ��� ���Ű��� ȯ���մϴ�. ****" << endl;
	cout << endl;
	while (true){
		cout << "����:1, ���:2, ����:3, ������:4>>";
		cin >> choice;

		if (choice == 1){
			a->book();
		}
		else if (choice == 2){
			a->cancel();
		}
		else if (choice == 3){
			a->space();
		}
		else if (choice == 4){
			cout << "���� �ý����� �����մϴ�." << endl;
			break;
		}
	}
	delete a;
}