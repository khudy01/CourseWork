#pragma once
#include "BirthDate.h"
#include "Session.h"

class Student{

public:

	char surName[20]; //�������
	char name[20]; //���
	char patronymic[25]; // ��������
	char faculty[20]; //��������
	char department[10]; //�������
	char group[12];// ������
	char recordBook[10];//�������
	char sex; //1-M 0-W
	int firstYear; // ���� ������ ��������
	// ��
	int day;
	int month;
	int year;
	Session newStudent[9];// ������
	int sizeSession; // ���-�� ������
	int pThree = 0; //������� "3"
	

	void setInfo();
	void getInfo();
	void checkThree();
	void returnpThree();
	int returnYear();
	



};

