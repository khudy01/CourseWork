#pragma once
#include "BirthDate.h"
#include "Session.h"

class Student{

public:

	char surName[20]; //Фамилия
	char name[20]; //Имя
	char patronymic[25]; // Отчество
	char faculty[20]; //Институт
	char department[10]; //Кафедра
	char group[12];// Группа
	char recordBook[10];//зачетка
	char sex; //1-M 0-W
	int firstYear; // Дата начала обучения
	// ДР
	int day;
	int month;
	int year;
	Session newStudent[9];// Сессии
	int sizeSession; // Кол-во сессий
	int pThree = 0; //Наличие "3"
	

	void setInfo();
	void getInfo();
	void checkThree();
	void returnpThree();
	int returnYear();
	



};

