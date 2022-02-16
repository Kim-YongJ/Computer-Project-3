#pragma once
#include "Ban.h"

/****************** �Է��� ���� �Լ��� - AppView_in  *********************/
Boolean AppView_In_DoesContinueToInputNextStudent();
int AppView_In_Score();
char GetcharDirectlyFromKeyboard();


/****************** ����� ���� �Լ��� - AppView_out *********************/
void AppView_Out(char* aString);
void AppView_Out_AverageScore(float anAverageScore);
void AppView_Out_NumberOfStudentsAboveAverage(int aNumber);
void AppView_Out_MaxScore(int aMaxScore);
void AppView_Out_MinScore(int aMinScore);
void AppView_Out_GradeCountFor(char aGrade, int aCount);
void AppView_Out_StudentInfo(int aScore);
