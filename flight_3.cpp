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
			cout << "이미 예약되어있는 좌석입니다." << endl;
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
			cout << "입력한 이름이 자리에 예약되지 않았습니다." << endl;
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
			cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
			cin >> i1;
			if (i1 == 1) Menu1();
			else if (i1 == 2) Menu2();
			else if (i1 == 3) Menu3();
			else if (i1 == 4) {
				cout << "예약 시스템을 종료합니다." << endl;
				break;
			}
			else {					
				cout << "잘못 입력했습니다." << endl;
				break;
			}
		}
	}
	void Menu1(){
		try{
			int i2 = 4;
			cout << "07시:1, 12시:2, 17시:3>>";
			cin >> i2;
				switch (i2){
				case 1:
					cout << "07시:";
					break;
				case 2:
					cout << "12시:";
					break;
				case 3:
					cout << "17시:";
					break;
				default:
					cout << "잘못 입력했습니다." << endl;
					return;
				}
				sc[i2 - 1].WatchSeat();
				int seat; string name;
				cout << "좌석 번호>> ";
				cin >> seat;
				if (0 < seat && seat <= 8){
					cout << "이름 입력>> ";
					cin >> name;
					sc[i2 - 1].MakeSeat(seat, name);
				}
				else{
					cout << "입력한 좌석은 없는 좌석입니다." << endl;
				}
		}
		catch (exception ex){
			cout << "오류가 발생했습니다." << endl;
			return;
		}
	}
	void Menu2(){
		try{
			int i2 = 4;
			cout << "07시:1, 12시:2, 17시:3>>";
			cin >> i2;
			switch (i2){
			case 1:
				cout << "07시:";
				break;
			case 2:
				cout << "12시:";
				break;
			case 3:
				cout << "17시:";
				break;
			default:
				cout << "잘못 입력했습니다." << endl;
				return;
			}
				sc[i2 - 1].WatchSeat();
				int seat; string name;
				cout << "좌석 번호>> ";
				cin >> seat;
				if (0 < seat && seat <= 8){
					cout << "이름 입력>> ";
					cin >> name;
					sc[i2 - 1].CancelSeat(seat, name);
				}
				else{
					cout << "입력한 좌석은 없는 좌석입니다." << endl;
				}
		}
		catch (exception ex){
			cout << "오류가 발생했습니다." << endl;
			return;
		}
	}
	void Menu3(){
		cout << "07시:"; sc[0].WatchSeat();
		cout << "12시:"; sc[1].WatchSeat();
		cout << "17시:"; sc[2].WatchSeat();
	}
	AirlineBook(){
		cout << "***** 한성항공에 오신 것을 환영합니다. *****" << endl << endl;
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