#pragma once
#include <fstream>
#include "Student.h"
#include <windows.h>
#include <locale>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS


void addObj(Student &obj, string fileName);
int showBD_45(string &fileName );
int showBD_345(string &fileName);
int minYear345(string &fileName);
int maxYear345(string &fileName);
int minYear45(string &fileName);
int maxYear45(string &fileName);
void popStud(string &fileName);
void changeInfo(string &fileName);