#include <iostream>
#include <string>
using namespace std;

class Seat {
	string userName;
public:
	bool isBooked;
	Seat() : userName("---"), isBooked(false) { }
	void book() { isBooked = true; }
	void setName(string name) { userName = name; }
	string getName() const { return userName; }
};

class Schedule {
	Seat* seats;
	string time;
public:
	Schedule() {
		seats = new Seat[8];
	}
	~Schedule() { delete[] seats; }

	void show() const {
		cout << time << ":";
		for (int i = 0; i < 8; i++) {
			cout << "\t" << seats[i].getName();
		}
		cout << endl;
	}

	void setTime(string time) { this->time = time; }

	void book() {
		int input;

		show();
		cout << "좌석 번호>> ";
		cin >> input;

		if (input < 1 || input > 8) {
			cout << "입력값이 잘못되었습니다." << endl;
			return;
		}
		else if (seats[input - 1].isBooked == true) {
			cout << "이미 예약된 좌석입니다." << endl;
			return;
		}
		else {
			string name;

			cout << "이름 입력>> ";
			cin >> name;

			seats[input - 1].isBooked = true;
			seats[input - 1].setName(name);
		}
	}

	void cancel() {
		int input;
		bool cancelable = false;

		show();

		for (int i = 0; i < 8; i++) {
			if (seats[i].getName() != "---") {
				cancelable = true;
				break;
			}
		}
		if (!cancelable) {
			cout << "취소할 수 있는 좌석이 없습니다." << endl;
			return;
		}

		cout << "좌석 번호>> ";
		cin >> input;

		if (input < 1 || input > 8) {
			cout << "입력값이 잘못되었습니다." << endl;
			return;
		}
		else if (seats[input - 1].isBooked == false) {
			cout << "예약되지 않은 좌석입니다." << endl;
			return;
		}
		else {
			string name;

			cout << "이름 입력>> ";
			cin >> name;
			if (name != seats[input - 1].getName()) {
				cout << "이름입력이 잘못되었습니다." << endl;
				return;
			}

			seats[input - 1].isBooked = false;
			seats[input - 1].setName("---");
		}
	}
};

class AirlineBook {
	Schedule* schedules;
public:
	AirlineBook() {
		schedules = new Schedule[3];
		schedules[0].setTime("07시");
		schedules[1].setTime("12시");
		schedules[2].setTime("17시");
	}
	~AirlineBook() { delete[] schedules; }

	void book() {
		int input;

		cout << "07시:1, 12시:2, 17시:3>> ";
		cin >> input;
		if (input < 1 || input > 3) {
			cout << "입력값이 잘못되었습니다." << endl;
			return;
		}

		schedules[input - 1].book();
	}

	void cancel() {
		int input;

		cout << "07시:1, 12시:2, 17시:3>> ";
		cin >> input;
		if (input < 1 || input > 3) {
			cout << "입력값이 잘못되었습니다." << endl;
			return;
		}

		schedules[input - 1].cancel();
	}

	void view() const {
		for (int i = 0; i < 3; i++)
			schedules[i].show();
	}
};

int main() {
	AirlineBook* airlineBook = new AirlineBook();
	int input;

	cout << "***** 한성항공에 오신 것을 환영합니다 *****" << endl << endl;

	while (true) {
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
		cin >> input;

		switch (input) {
		case 1: airlineBook->book();
			cout << endl;
			break;
		case 2: airlineBook->cancel();
			cout << endl;
			break;
		case 3: airlineBook->view();
			cout << endl;
			break;
		case 4: delete airlineBook; return 0;
		default: cout << "입력값이 잘못되었습니다." << endl << endl;
		}
	}
}