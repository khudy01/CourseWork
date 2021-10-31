#include "Session.h"

void Session::setSessionInfo(){
	cout << "Введите кол-во предметов : ";
	cin >> sizeSubject;
	for (int i = 0; i < sizeSubject; i++) {
		newSession[i].setSubject();
	}
}

void Session::getSessionInfo(){
	for (int i = 0; i < sizeSubject; i++) {
		newSession[i].getSubject();
	}
}

int Session::getMarkSesson(){
	for (int i = 0; i < sizeSubject; i++) {
		return newSession[i].getMark();
	}
}
