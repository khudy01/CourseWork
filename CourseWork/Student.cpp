#include "Student.h"

void Student::setInfo(){
	cout << "Введите фамилию:" << endl;
	cin >> surName;
	cout << "Введите имя:" << endl;
	cin >> name;
	cout << "Введите отчество:" << endl;
	cin >> patronymic;
	cout << "Введите день рождения:" << endl;
	cin >> day;
	cout << "Введите месяц рождения:" << endl;
	cin >> month;
	cout << "Введите введите год рождения:" << endl;
	cin >> year;
	cout << "Введите институт:" << endl;
	cin >> faculty;
	cout << "Введите кафедру:" << endl;
	cin >> department;
	cout << "Введите группу:" << endl;
	cin >> group;
	cout << "Введите номер зач.книги:" << endl;
	cin >> recordBook;
	cout << "Введите пол ( M / Ж ):" << endl;
	cin >> sex;
	cout << "Введите год начала обучения:" << endl;
	cin >> firstYear;
	cout << "Введите дату рождения" << endl;
	//birthDateStudent.setBD();
	cout << "Введите кол-во сессий: ";
	cin >> sizeSession;
	for (int i = 0; i < sizeSession; i++) {
		cout << "Введите информацию по сессии № " << i + 1 << endl;
		newStudent[i].setSessionInfo();
	}
}

void Student::getInfo(){
	cout << "==============================================================================================" << endl;
	cout << surName << "\t" << name << "\t" << patronymic << endl;
	cout << "Пол : "<< sex << "\t" << "Год начала обучения : " <<firstYear << endl;
	cout << "Институт : "<< faculty << "\t" << "Кафедра : " << department << "\t" << "Группа : "<< group << "\t" << "Номер зач.книжки : " << recordBook << endl;
	//birthDateStudent.getBD();
	cout << "Дата рождения : " << day << " " << month << " " << year << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < sizeSession; i++) {
		cout << "Информацию по сессии № " << i + 1 << endl;
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