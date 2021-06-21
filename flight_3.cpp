#include <iostream>
#include<string>
using namespace std;

class Seat{
public:
	string name;
	bool reserved;
	Seat(){
		string name = "";
		reserved = false;
	}
	~Seat(){}
};

class Schedule{
	Seat *seat;
public:
	Schedule(){
		seat = new Seat[8];
	}
	void MakeSeat(int num, string name) {
		if (seat[num - 1].reserved){
			cout << "�̹� ����Ǿ��ִ� �¼��Դϴ�." << endl;
		}
		else{
			seat[num - 1].name = name;
			seat[num - 1].reserved = true;
		}
	}
	void CancelSeat(int num, string name) {
		if (seat[num - 1].name == name){
			seat[num - 1].name = "";
			seat[num - 1].reserved = false;
		}
		else{
			cout << "�Է��� �̸��� �ڸ��� ������� �ʾҽ��ϴ�." << endl;
		}
		
	}
	void WatchSeat(){
		for (int i = 0; i < 8; i++){
			cout << "\t";
			if (seat[i].reserved)
				cout << seat[i].name;
			else
				cout << "---";
		}
		cout << endl;
	}
	~Schedule() {
		delete [] seat;
	}

};

class AirlineBook{
	Schedule *sc;
public:
	void Book(){
		while (true){
			int i1 = 5;
			cout << "����:1, ���:2, ����:3, ������:4>>";
			cin >> i1;
			if (i1 == 1) Menu1();
			else if (i1 == 2) Menu2();
			else if (i1 == 3) Menu3();
			else if (i1 == 4) {
				cout << "���� �ý����� �����մϴ�." << endl;
				break;
			}
			else {					
				cout << "�߸� �Է��߽��ϴ�." << endl;
				break;
			}
		}
	}
	void Menu1(){
		try{
			int i2 = 4;
			cout << "07��:1, 12��:2, 17��:3>>";
			cin >> i2;
				switch (i2){
				case 1:
					cout << "07��:";
					break;
				case 2:
					cout << "12��:";
					break;
				case 3:
					cout << "17��:";
					break;
				default:
					cout << "�߸� �Է��߽��ϴ�." << endl;
					return;
				}
				sc[i2 - 1].WatchSeat();
				int seat; string name;
				cout << "�¼� ��ȣ>> ";
				cin >> seat;
				if (0 < seat && seat <= 8){
					cout << "�̸� �Է�>> ";
					cin >> name;
					sc[i2 - 1].MakeSeat(seat, name);
				}
				else{
					cout << "�Է��� �¼��� ���� �¼��Դϴ�." << endl;
				}
		}
		catch (exception ex){
			cout << "������ �߻��߽��ϴ�." << endl;
			return;
		}
	}
	void Menu2(){
		try{
			int i2 = 4;
			cout << "07��:1, 12��:2, 17��:3>>";
			cin >> i2;
			switch (i2){
			case 1:
				cout << "07��:";
				break;
			case 2:
				cout << "12��:";
				break;
			case 3:
				cout << "17��:";
				break;
			default:
				cout << "�߸� �Է��߽��ϴ�." << endl;
				return;
			}
				sc[i2 - 1].WatchSeat();
				int seat; string name;
				cout << "�¼� ��ȣ>> ";
				cin >> seat;
				if (0 < seat && seat <= 8){
					cout << "�̸� �Է�>> ";
					cin >> name;
					sc[i2 - 1].CancelSeat(seat, name);
				}
				else{
					cout << "�Է��� �¼��� ���� �¼��Դϴ�." << endl;
				}
		}
		catch (exception ex){
			cout << "������ �߻��߽��ϴ�." << endl;
			return;
		}
	}
	void Menu3(){
		cout << "07��:"; sc[0].WatchSeat();
		cout << "12��:"; sc[1].WatchSeat();
		cout << "17��:"; sc[2].WatchSeat();
	}
	AirlineBook(){
		cout << "***** �Ѽ��װ��� ���� ���� ȯ���մϴ�. *****" << endl << endl;
		sc = new Schedule[3];
		Book();
	}
	~AirlineBook(){
		delete [] sc;
	}
};

int main() {
	AirlineBook* newtrip = new AirlineBook();
	delete newtrip;
	
	return 0;
}