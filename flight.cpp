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
		cout << "�¼� ��ȣ>> ";
		cin >> input;

		if (input < 1 || input > 8) {
			cout << "�Է°��� �߸��Ǿ����ϴ�." << endl;
			return;
		}
		else if (seats[input - 1].isBooked == true) {
			cout << "�̹� ����� �¼��Դϴ�." << endl;
			return;
		}
		else {
			string name;

			cout << "�̸� �Է�>> ";
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
			cout << "����� �� �ִ� �¼��� �����ϴ�." << endl;
			return;
		}

		cout << "�¼� ��ȣ>> ";
		cin >> input;

		if (input < 1 || input > 8) {
			cout << "�Է°��� �߸��Ǿ����ϴ�." << endl;
			return;
		}
		else if (seats[input - 1].isBooked == false) {
			cout << "������� ���� �¼��Դϴ�." << endl;
			return;
		}
		else {
			string name;

			cout << "�̸� �Է�>> ";
			cin >> name;
			if (name != seats[input - 1].getName()) {
				cout << "�̸��Է��� �߸��Ǿ����ϴ�." << endl;
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
		schedules[0].setTime("07��");
		schedules[1].setTime("12��");
		schedules[2].setTime("17��");
	}
	~AirlineBook() { delete[] schedules; }

	void book() {
		int input;

		cout << "07��:1, 12��:2, 17��:3>> ";
		cin >> input;
		if (input < 1 || input > 3) {
			cout << "�Է°��� �߸��Ǿ����ϴ�." << endl;
			return;
		}

		schedules[input - 1].book();
	}

	void cancel() {
		int input;

		cout << "07��:1, 12��:2, 17��:3>> ";
		cin >> input;
		if (input < 1 || input > 3) {
			cout << "�Է°��� �߸��Ǿ����ϴ�." << endl;
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

	cout << "***** �Ѽ��װ��� ���� ���� ȯ���մϴ� *****" << endl << endl;

	while (true) {
		cout << "����:1, ���:2, ����:3, ������:4>> ";
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
		default: cout << "�Է°��� �߸��Ǿ����ϴ�." << endl << endl;
		}
	}
}