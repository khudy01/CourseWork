#include "Student.h"

void Student::setInfo(){
	cout << "������� �������:" << endl;
	cin >> surName;
	cout << "������� ���:" << endl;
	cin >> name;
	cout << "������� ��������:" << endl;
	cin >> patronymic;
	cout << "������� ���� ��������:" << endl;
	cin >> day;
	cout << "������� ����� ��������:" << endl;
	cin >> month;
	cout << "������� ������� ��� ��������:" << endl;
	cin >> year;
	cout << "������� ��������:" << endl;
	cin >> faculty;
	cout << "������� �������:" << endl;
	cin >> department;
	cout << "������� ������:" << endl;
	cin >> group;
	cout << "������� ����� ���.�����:" << endl;
	cin >> recordBook;
	cout << "������� ��� ( M / � ):" << endl;
	cin >> sex;
	cout << "������� ��� ������ ��������:" << endl;
	cin >> firstYear;
	cout << "������� ���� ��������" << endl;
	//birthDateStudent.setBD();
	cout << "������� ���-�� ������: ";
	cin >> sizeSession;
	for (int i = 0; i < sizeSession; i++) {
		cout << "������� ���������� �� ������ � " << i + 1 << endl;
		newStudent[i].setSessionInfo();
	}
}

void Student::getInfo(){
	cout << "==============================================================================================" << endl;
	cout << surName << "\t" << name << "\t" << patronymic << endl;
	cout << "��� : "<< sex << "\t" << "��� ������ �������� : " <<firstYear << endl;
	cout << "�������� : "<< faculty << "\t" << "������� : " << department << "\t" << "������ : "<< group << "\t" << "����� ���.������ : " << recordBook << endl;
	//birthDateStudent.getBD();
	cout << "���� �������� : " << day << " " << month << " " << year << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < sizeSession; i++) {
		cout << "���������� �� ������ � " << i + 1 << endl;
		cout << "-------------------------" << endl;
		newStudent[i].getSessionInfo();
		cout << "-------------------------" << endl;
	}
}

void Student::checkThree(){
	int flag = 0;
	for (int i = 0; i < sizeSession; i++) {
		if (newStudent[i].getMarkSesson() == 3) {
			pThree = 1;
		}
	}
}

void Student::returnpThree(){
	pThree = 0;
}

int Student::returnYear(){
	return year;
}



/*int Student::returnYear(){
	return birthDateStudent.year;
}*/

/*
void checkThree(Student &obj) {
	obj.pThree = TRUE;
}

void returnThree(Student &obj) {
	obj.pThree = FALSE;
}*/