#pragma once
#include "Subject.h"

class Session{

public:

	int sizeSubject;
	Subject newSession[10];

	void setSessionInfo();
	void getSessionInfo();
	int getMarkSesson();
};

