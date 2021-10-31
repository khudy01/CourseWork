#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Student.h"
#include "fileManager.h"


using namespace std;


string path = "Template.txt";

void funMain(Student &obj, string fileName) {
	int j;
	
	while (1)
	{
		
		cout << "\n";
		cout << "====================================" << endl;
		cout << "| 1 - Добавить студента в БД       |" << endl;
		cout << "| 2 - Вывести БД                   |" << endl;
		cout << "| 3 - Вывести БД студентов с 4,5   |" << endl;
		cout << "| 4 - Вывести БД студентов с 3,4,5 |" << endl;
		cout << "| 5 - Удалить студента             |" << endl;
		cout << "| 6 - Изменить данные              |" << endl;
		cout << "| 7 - Завершить работу программы   |" << endl;
		cout << "====================================" << endl;
		cout << "\n";
		cout << "Выберите пункт меню: ";
		cin >> j;
		cout << "\n";
		switch (j)
		{
		case 1:	
			
			obj.setInfo();
			obj.checkThree();
			addObj(obj, path);
			obj.returnpThree();
			
			break;

		case 2: 
			showBD_45(fileName); 
			showBD_345(fileName);
			break;
		case 3:
			showBD_45(fileName);
			break;
		case 4:
			showBD_345(fileName);
			break;
		case 5:
			popStud(fileName);
			break;
		case 6:
			changeInfo(fileName);
			break;
		case 7:
			exit(0);
		default: cout << "\nНеверно выбран пункт меню!\n" << endl;

		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	
	Student obj1;
	
	funMain(obj1, path);
	
}

	