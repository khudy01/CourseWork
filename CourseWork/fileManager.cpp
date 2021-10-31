#include "fileManager.h"

void addObj(Student &obj , string fileName) {
	ofstream fout;
	fout.open(fileName, ofstream::app);

	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!";
	}
	else {
		fout.write((char*)&obj, sizeof(Student));
		//cout << "Запись прошла успешно!" << endl;
	}
	fout.close();
}

int showBD_45(string &fileName) {
	ifstream fin;
	fin.open(fileName);
	if(fin.peek() == EOF) {
		cout << "БД пуста" << endl;
		return -1;
	}
	fin.close();
	char firstLetter = 'А';
	char lastLetter = 'Я';
	cout << "==============================================================================================" << endl;
	cout << "-----------------------------------------БАЗА ДАННЫХ------------------------------------------" << endl;
	cout << "--------------------------СТУДЕНТЫ С ОЦЕНКАМИ 4, 5 ПО СПЕЦ.ПРЕДМЕТАМ--------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl << endl;
	Student temp_obj1;
	int countStud = 0;
	int minYearNow45 = minYear45(fileName);
	int maxYearNow45 = maxYear45(fileName);
	for (minYearNow45; minYearNow45 < maxYearNow45 + 1; minYearNow45 += 5) {
		//cout << "Интервал года рождения : " << minYearNow45 << "-" << minYearNow45 + 4   << endl;
		if (minYearNow45 >= maxYearNow45) {
			cout << "Интервал года рождения : " << endl;
			cout << minYearNow45 - 4 << "-" << maxYearNow45 << endl << endl;
		}
		else {
			cout << "Интервал года рождения : " << endl;
			cout << minYearNow45 << "-" << minYearNow45 + 4 << endl << endl;
		}
		
		for (int i = (int)firstLetter; i < (int)lastLetter + 1; i++) {
			//cout << (char)i << endl;
			//ifstream fin;
			fin.open(fileName);
			//Student temp_obj1;
			while (fin.read((char*)&temp_obj1, sizeof(Student))) {
				int curYear = temp_obj1.returnYear();
				if ((i == temp_obj1.surName[0]) && temp_obj1.pThree == 0 && ((minYearNow45 <= curYear)&&(curYear <= minYearNow45 + 5))) {
					temp_obj1.getInfo();
					cout << endl;
					countStud++;
				}
			}
			fin.close();
		}
	}
	cout << "==============================================================================================" << endl;
	cout << "Кол-во студентов с оценками 4,5 : ";
	cout << countStud << endl << endl;
	return 0;
}
int showBD_345(string &fileName) {
	ifstream fin;
	fin.open(fileName);
	if (fin.peek() == EOF) {
		return -1;
	}
	fin.close();
	char firstLetter = 'А';
	char lastLetter = 'Я';
	int minYearNow345 = minYear345(fileName);
	int maxYearNow345 = maxYear345(fileName);
	cout << "==============================================================================================" << endl;
	cout << "------------------------СТУДЕНТЫ С ОЦЕНКАМИ 3, 4, 5 ПО СПЕЦ.ПРЕДМЕТАМ-------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl << endl;
	
	cout << "" << endl;
	Student temp_obj1;
	int countStud = 0;
	for (minYearNow345; minYearNow345 < maxYearNow345 + 1; minYearNow345 += 5) {
		if (minYearNow345 >= maxYearNow345) {
			cout << "Интервал года рождения : " << endl;
			cout << minYearNow345 - 4 << "-" << maxYearNow345 << endl << endl;
		}
		else {
			cout << "Интервал года рождения : " << endl;
			cout << minYearNow345 << "-" << minYearNow345 + 4 << endl << endl;
		}
		for (int i = (int)firstLetter; i < (int)lastLetter + 1; i++) {
			//cout << (char)i << endl;
			//ifstream fin;
			fin.open(fileName);
			//Student temp_obj1;
			while (fin.read((char*)&temp_obj1, sizeof(Student))) {
				int curYear = temp_obj1.returnYear();
				if ((i == temp_obj1.surName[0]) && temp_obj1.pThree == 1 && minYearNow345 < curYear < minYearNow345 + 5) {
					temp_obj1.getInfo();
					cout << endl;
					countStud++;
				}
			}
			fin.close();
		}
	}
	cout << "==============================================================================================" << endl;
	cout << "Кол-во студентов с оценками 3,4,5 : ";
	cout << countStud << endl << endl;
	return 0;
}

int minYear345(string & fileName){
	Student temp_obj1;
	ifstream fin;
	fin.open(fileName);
	int valueMinYear345 = 9999;
	while (fin.read((char*)&temp_obj1, sizeof(Student))) {
		if (temp_obj1.returnYear() < valueMinYear345 && temp_obj1.pThree == 1) {
			valueMinYear345 = temp_obj1.returnYear();
		}
	}
		
	fin.close();
	return valueMinYear345;
}

int maxYear345(string & fileName){
	Student temp_obj1;
	ifstream fin;
	fin.open(fileName);
	int maxYear345 = 0;
	while (fin.read((char*)&temp_obj1, sizeof(Student))) {
		if (temp_obj1.returnYear() > maxYear345 && temp_obj1.pThree == 1) {
			maxYear345 = temp_obj1.returnYear();
		}
	}

	fin.close();
	return maxYear345;
	
}
int minYear45(string & fileName) {
	Student temp_obj1;
	ifstream fin;
	fin.open(fileName);
	int minYear45 = 9999;
	while (fin.read((char*)&temp_obj1, sizeof(Student))) {
		if (temp_obj1.returnYear() < minYear45 && temp_obj1.pThree == 0) {
			minYear45 = temp_obj1.returnYear();
		}
	}

	fin.close();
	return minYear45;
}

int maxYear45(string & fileName) {
	Student temp_obj1;
	ifstream fin;
	fin.open(fileName);
	int maxYear45 = 0;
	while (fin.read((char*)&temp_obj1, sizeof(Student))) {
		if (temp_obj1.returnYear() > maxYear45 && temp_obj1.pThree == 0) {
			maxYear45 = temp_obj1.returnYear();
		}
	}

	fin.close();
	return maxYear45;

}

void popStud(string &fileName) {

	
	string fileName2 = "Template2.txt";
	cout << "Введите номер зачетки :" << endl;
	char tempRecordBook[10];
	cin >> tempRecordBook;

	ifstream fin;
	ofstream fout;

	fin.open(fileName);
	fout.open(fileName2, ios::trunc);
	Student curStud;
	while (fin.read((char*)&curStud, sizeof(Student))) {
		if(strcmp(curStud.recordBook, tempRecordBook) != 0) {
			fout.write((char*)&curStud, sizeof(Student));
		}
	}
	if (sizeof(fileName) == sizeof(fileName2)) {
		cout << "Студент не найден" << endl;
	}
	else {
		cout << "Студент удален" << endl;
	}

	fin.close();
	fout.close();

	fin.open(fileName2);
	fout.open(fileName, ios::trunc);

	while (fin.read((char*)&curStud, sizeof(Student))) {
		fout.write((char*)&curStud, sizeof(Student));
	}

	fin.close();
	fout.close();
}


void changeInfo(string &fileName) {

	string fileName2 = "Template2.txt";
	cout << "Введите номер зачетки студета :" << endl;
	char tempForFindRecordBook[15];
	cin >> tempForFindRecordBook;

	ifstream fin;
	ofstream fout;

	fin.open(fileName);
	fout.open(fileName2, ios::trunc);
	Student curStud;
	while (fin.read((char*)&curStud, sizeof(Student))) {
		if (strcmp(curStud.recordBook, tempForFindRecordBook) != 0) {
			fout.write((char*)&curStud, sizeof(Student));
		}
		else {
			int num = 0;
			cout << "\n";
			cout << "====================================" << endl;
			cout << "| 1 - Дата Рождения                |" << endl;
			cout << "| 2 - ФИО                          |" << endl;
			cout << "| 3 - Пол                          |" << endl;
			cout << "| 4 - Институт                     |" << endl;
			cout << "| 5 - Группа                       |" << endl;
			cout << "| 6 - Номер зачетки                |" << endl;
			cout << "====================================" << endl;
			cout << "\n";
			cout << "Выберите пункт меню: ";
			cout << "\n";
			cin >> num;
			switch (num)
			{
			case 1:

				int tempDay;
				cout << "Введите день рождения:" << endl;
				cin >> tempDay;
				int tempMonth;
				cout << "Введите месяц рождения:" << endl;
				cin >> tempMonth;
				int tempYear;
				cout << "Введите введите год рождения:" << endl;
				cin >> tempYear;
				curStud.day = tempDay;
				curStud.month = tempMonth;
				curStud.year = tempYear;
				break;

			case 2:

				char tempSurName[20];
				cout << "Введите фамилию:" << endl;
				cin >> tempSurName;
				char tempName[20];
				cout << "Введите имя:" << endl;
				cin >> tempName;
				char tempPatronymic[25];
				cout << "Введите отчество:" << endl;
				cin >> tempPatronymic;
				strcpy_s(curStud.surName, tempSurName);
				strcpy_s(curStud.name, tempName);
				strcpy_s(curStud.patronymic, tempPatronymic);
				break;

			case 3:

				char tempSex;
				cout << "Введите пол ( M / Ж ):" << endl;
				cin >> tempSex;
				curStud.sex = tempSex;
				break;

			case 4:

				char tempFaculty[15];
				cout << "Введите институт:" << endl;
				cin >> tempFaculty;
				strcpy_s(curStud.faculty, tempFaculty);
				break;

			case 5:

				char tempGroup[15];
				cout << "Введите группу:" << endl;
				cin >> tempGroup;
				strcpy_s(curStud.group, tempGroup);
				break;

			case 6:

				char tempRecordBook[15];
				cout << "Введите номер зач.книги:" << endl;
				cin >> tempRecordBook;
				strcpy_s(curStud.recordBook, tempRecordBook);
				break;

			default: cout << "\nНеверно выбран пункт меню!\n" << endl;
				
			}
			fout.write((char*)&curStud, sizeof(Student));
		}
	}
	fin.close();
	fout.close();
	
	fin.open(fileName2);
	fout.open(fileName, ios::trunc);

	while (fin.read((char*)&curStud, sizeof(Student))) {
		fout.write((char*)&curStud, sizeof(Student));
	}

	fin.close();
	fout.close();
}

