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
		else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mod, string manu, int avCn, int avInk) : Printer(mod, manu, avCn), availableInk(avInk) { }
	void printInkJet(int pages) {
		if (availableCount < pages || availableInk < pages) {
			if (availableCount < pages)
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			else cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			return;
		}
		availableCount -= pages;
		availableInk -= pages;
		printedCount += pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
	string getInfo() const {
		return model + "," + manufacturer + ", ���� ���� " + to_string(availableCount) + "��, ���� ��ũ " + to_string(availableInk);
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mod, string manu, int avCn, int avTon) : Printer(mod, manu, avCn), availableToner(avTon) { }
	void printLaser(int pages) {
		if (availableCount < pages || availableToner < pages * 0.5) {
			if (availableCount < pages)
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			else cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			return;
		}
		availableCount -= pages;
		availableToner -= pages * 0.5;
		printedCount += pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
	string getInfo() const {
		return model + "," + manufacturer + ", ���� ���� " + to_string(availableCount) + "��, ���� ��� " + to_string(availableToner);
	}
};

int main() {
	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);
	int input, pages;
	char answer;

	cout << "���� �۵� ���� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : " << inkjet->getInfo() << endl;
	cout << "������ : " << laser->getInfo() << endl << endl;

	while (true) {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> input >> pages;

		if (pages <= 0) {
			cout << "������ ���� 0 ������ ���� �� �� �����ϴ�." << endl;
			continue;
		}

		switch (input) {
		case 1: inkjet->printInkJet(pages); break;
		case 2: laser->printLaser(pages); break;
		default: cout << "�Է°��� �߸��Ǿ����ϴ�." << endl; continue;
		}
		cout << inkjet->getInfo() << endl;
		cout << laser->getInfo() << endl;

		while (true) {
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
			cin >> answer;
			if (answer == 'y' || answer == 'n')
				break;
			cout << "�߸��� �Է°��Դϴ�." << endl;
		}
		cout << endl;

		switch (answer) {
		case 'y': continue;
		case 'n': delete inkjet; delete laser; return 0;
		}
	}
}