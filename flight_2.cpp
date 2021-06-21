#include <iostream>
#include <string>

using namespace std;

#pragma region Seat
class Seat{
private:
	bool canUsed;
	string owner;
public:
	Seat();
	string getOwner();
	void setOwner(string o);
	bool isNotUsed();
	void setUsed(bool u);
};

Seat::Seat(){
	canUsed = true;
}
void Seat::setOwner(string s){
	owner = s;
}
string Seat::getOwner(){
	if (canUsed){
		return "---";
	}
	else{
		return owner;
	}
}
bool Seat::isNotUsed(){
	return canUsed;
}
void Seat::setUsed(bool u){
	canUsed = u;
}
#pragma endregion

#pragma region Airplane
class Ariplane {
private:
	string time;
	Seat seats[8];
public:
	Ariplane();	
	void setTime(string s);
	void display();
	string getTime();
	bool checkSeat(int i);
	bool cancelSeat(int i, string name);
	void bookSeat(int i, string name);
};
Ariplane::Ariplane(){
	
}
void Ariplane::display(){
	cout << time << ":";
	for (int i = 0; i < 8; i++){
		cout.width(5);
		cout << seats[i].getOwner();
	}
	cout << endl;
}
void Ariplane::setTime(string s){
	time = s;
}
string Ariplane::getTime(){
	return time;
}
bool Ariplane::checkSeat(int i){
	return seats[i].isNotUsed();
}
void Ariplane::bookSeat(int i, string name){
	seats[i].setUsed(false);
	seats[i].setOwner(name);
}
bool Ariplane::cancelSeat(int i, string name){
	if (name == seats[i].getOwner()){
		seats[i].setUsed(true);
		return true;
	}
	else{
		return false;
	}
}
#pragma endregion

#pragma region Company
class Company{
private:
	string company_name;
	Ariplane airs[3];
public:
	Company();
	void showAll();
	void show(int row);
	void start();
	void select();
	void cancel();
	string getCompanyName();
};
Company::Company(){
	company_name = "�Ѽ��װ�";
	start();
}
string Company::getCompanyName(){
	return company_name;
}
void Company::start(){
	cout << "***** " << company_name << "�� ���Ű��� ȯ���մϴ� *****" << endl;
	airs[0].setTime("07��");
	airs[1].setTime("12��");
	airs[2].setTime("17��");
	
	int user_select, exit = 0;
	while (true){
		cout << "����:1, ���:2, ����:3, ������:4>>";
		cin >> user_select;
		
		switch (user_select){
		case 1:
			select();
			break;
		case 2:
			cancel();
			break;
		case 3:
			showAll();
			break;
		case 4:
			exit = 1;
			break;
		}

		if (exit == 1) break;
	}
}
void Company::cancel(){
	int air_select, seat_select;

	for (int i = 0; i < 2; i++){
		cout << airs[i].getTime() << ":" << i + 1 << ", ";
	}
	cout << airs[2].getTime() << ":" << 3 << ">>";

	cin >> air_select;
	if (air_select > 0 && air_select <= 3){
		airs[air_select - 1].display();
	}
	else{
		cout << "�ùٸ� �װ����� �ƴմϴ�." << endl;;
	}
	cout << "�¼� ��ȣ>>";
	cin >> seat_select;
	string name;
	cout << "�̸� �Է�>>";
	cin >> name;
	if (seat_select > 0 && seat_select <= 8){
		if (!airs[air_select - 1].checkSeat(seat_select - 1)){			
			if (airs[air_select - 1].cancelSeat(seat_select - 1, name)){
				
			}
		}
		else{
			cout << "����� �� ���� �ڸ��Դϴ�." << endl;
		}
	}
	else{
		cout << "�ùٸ� �¼��� �ƴմϴ�." << endl;
	}
}
void Company::showAll(){
	for (int i = 0; i < 3; i++){
		airs[i].display();
	}
}
void Company::select(){
	int air_select, seat_select;

	for (int i = 0; i < 2; i++){
		cout << airs[i].getTime() << ":" << i + 1 << ", ";
	}
	cout << airs[2].getTime() << ":" << 3 << ">>";	

	cin >> air_select;
	if (air_select > 0 && air_select <= 3){
		airs[air_select - 1].display();
	}
	else{
		cout << "�ùٸ� �װ����� �ƴմϴ�." << endl;;
	}
	cout << "�¼� ��ȣ>>";
	cin >> seat_select;
	string name;
	cout << "�̸� �Է�>>";
	cin >> name;
	if (seat_select > 0 && seat_select <= 8){		
		if (airs[air_select - 1].checkSeat(seat_select-1)){						
			airs[air_select - 1].bookSeat(seat_select-1, name);
		}
	}
	else{
		cout << "�ùٸ� �¼��� �ƴմϴ�." << endl;
	}
}
#pragma endregion


int main(){
	Company a;
}