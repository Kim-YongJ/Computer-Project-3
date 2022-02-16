#pragma once
#include "AppController.h"

typedef struct _Student Student;

Student* Student_New(char* givenStudentID, int givenScore);
void Student_Delete(Student* _this);
char* Student_StudentID(Student* _this);
int Student_Score(Student* _this);

Boolean Student_StudentIDIsValid(char* aStudentID);
Boolean Student_ScoreIsValid(int aScore);