#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
	string model, manufacturer;
	int printedCount, availableCount;
public:
	Printer(string mod, string manu, int avCn) : model(mod), manufacturer(manu), printedCount(0), availableCount(avCn) { }
	void print(int pages) {
		if (availableCount >= pages)
			availableCount - pages;
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mod, string manu, int avCn, int avInk) : Printer(mod, manu, avCn), availableInk(avInk) { }
	void printInkJet(int pages) {
		if (availableCount < pages || availableInk < pages) {
			if (availableCount < pages)
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			else cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			return;
		}
		availableCount -= pages;
		availableInk -= pages;
		printedCount += pages;
		cout << "프린트하였습니다." << endl;
	}
	string getInfo() const {
		return model + "," + manufacturer + ", 남은 종이 " + to_string(availableCount) + "장, 남은 잉크 " + to_string(availableInk);
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mod, string manu, int avCn, int avTon) : Printer(mod, manu, avCn), availableToner(avTon) { }
	void printLaser(int pages) {
		if (availableCount < pages || availableToner < pages * 0.5) {
			if (availableCount < pages)
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			else cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			return;
		}
		availableCount -= pages;
		availableToner -= pages * 0.5;
		printedCount += pages;
		cout << "프린트하였습니다." << endl;
	}
	string getInfo() const {
		return model + "," + manufacturer + ", 남은 종이 " + to_string(availableCount) + "장, 남은 토너 " + to_string(availableToner);
	}
};

int main() {
	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	int input, pages;
	char answer;

	cout << "현재 작동 중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : " << inkjet->getInfo() << endl;
	cout << "레이저 : " << laser->getInfo() << endl << endl;

	while (true) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> input >> pages;

		if (pages <= 0) {
			cout << "페이지 수는 0 이하의 값이 될 수 없습니다." << endl;
			continue;
		}

		switch (input) {
		case 1: inkjet->printInkJet(pages); break;
		case 2: laser->printLaser(pages); break;
		default: cout << "입력값이 잘못되었습니다." << endl; continue;
		}
		cout << inkjet->getInfo() << endl;
		cout << laser->getInfo() << endl;

		while (true) {
			cout << "계속 프린트 하시겠습니까(y/n)>>";
			cin >> answer;
			if (answer == 'y' || answer == 'n')
				break;
			cout << "잘못된 입력값입니다." << endl;
		}
		cout << endl;

		switch (answer) {
		case 'y': continue;
		case 'n': delete inkjet; delete laser; return 0;
		}
	}
}