#include "BirthDate.h"

void BirthDate::setBD(){
	cout << "������� ����:" << endl;
	cin >> day;
	cout << "������� �����:" << endl;
	cin >> month;
	cout << "������� ������� ���:" << endl;
	cin >> year;
}

void BirthDate::getBD(){
	cout << "���� �������� : " << day << " "<< month << " " << year << endl;
}



