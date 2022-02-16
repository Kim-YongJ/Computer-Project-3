#include "Student.h"

struct _Student {
	char _studentID[MAX_STUDENT_ID_LENGTH + 1];
	int _score;
};

Student* Student_New(char* givenStudentID, int givenScore)
{
	Student* _this = NewObject(Student);
	strcpy((*_this)._studentID, givenStudentID);
	(*_this)._score = givenScore;
	return _this;
}void Student_Delete(Student* _this)
{
	free(_this);
}

char* Student_StudentID(Student* _this)
{
	char* copiedStudentID = NewVector(char, 10);
	strcpy(copiedStudentID, (*_this)._studentID);
	return copiedStudentID;
}

int Student_Score(Student* _this)
{
	return (*_this)._score;
}Boolean Student_StudentIDIsValid(char* aStudentID)
{
	int length = 0;
	while (*aStudentID != '\0') {
		length++;
		aStudentID++;
	}
	return (length <= MAX_STUDENT_ID_LENGTH);
	// �й� (���ڿ�)�� ���̰� �ִ� ������ 9 ���� ª�ų� ���ƾ� �Ѵ�.
}

Boolean Student_ScoreIsValid(int aScore)
{
	return (aScore >= 0 && aScore <= 100);
	// ������ 0�� 100 ���� �̾�� �Ѵ�.
}