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
	// 하나의 스케줄을 구현
	//8개 좌석, 예약 취소 보기 관리

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
	//스케줄 3개생성
	// 예약시스템 작동
	int time;
	int seatNumber;
	string name;
	Schedule* s = new Schedule[3];
public:
	void book(){
		cout << "07시:1, 12시: 2, 17시:3>>";
		cin >> this->time;
		s[time - 1].state();
		cout << "좌석번호>>";
		cin >> this->seatNumber;
		cout << "이름 입력>>";
		cin >> this->name;

		if (s[time - 1].check(seatNumber - 1) == "---")
			s[time - 1].book(seatNumber - 1, name);
		else{
			cout << "이미 예약된 자리입니다." << endl;
		}
	}
	void cancel(){
		cout << "07시:1, 12시: 2, 17시:3>>";
		cin >> this->time;
		s[time - 1].state();
		cout << "좌석번호>>";
		cin >> this->seatNumber;
		cout << "이름 입력>>";
		cin >> this->name;

		if (s[time - 1].check(seatNumber - 1) == name){
			cout << "취소되었습니다." << endl;
			s[time - 1].cancel(seatNumber - 1);
		}
		else
			cout << "해당정보와 다릅니다" << endl;
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
	cout << "**** 한성항공에 오신것을 환영합니다. ****" << endl;
	cout << endl;
	while (true){
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
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
			cout << "예약 시스템을 종료합니다." << endl;
			break;
		}
	}
	delete a;
}