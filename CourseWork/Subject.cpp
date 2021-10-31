#include "Subject.h"
#include "Student.h"

void Subject::setSubject(){
	
	cout << "Введите оценку и предмет:" << endl;
	cin >> mark;
	cin >> subjectName;

}

void Subject::getSubject(){
	cout << this->mark << "\t" << "|" << "\t "<< this->subjectName << endl;
}

int Subject::getMark(){
	return mark;
}
