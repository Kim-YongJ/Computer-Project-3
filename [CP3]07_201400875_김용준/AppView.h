#pragma once
#include "Ban.h"

/****************** 입력을 위한 함수들 - AppView_in  *********************/
Boolean AppView_In_DoesContinueToInputNextStudent();
int AppView_In_Score();
char GetcharDirectlyFromKeyboard();


/****************** 출력을 위한 함수들 - AppView_out *********************/
void AppView_Out(char* aString);
void AppView_Out_AverageScore(float anAverageScore);
void AppView_Out_NumberOfStudentsAboveAverage(int aNumber);
void AppView_Out_MaxScore(int aMaxScore);
void AppView_Out_MinScore(int aMinScore);
void AppView_Out_GradeCountFor(char aGrade, int aCount);
void AppView_Out_StudentInfo(char* aStudentID, int aScore, char aGrade);

// 입력, 출력을 관리해주는 헤더

void AppView_Out_Msg_InvalidStudentID(char* aStudentID, int maxLength);
void AppView_In_StudentID(char* aStudentID);
void AppView_Out_TitleForSortedStudentList();
int AppView_Out_Msg_InvalidScore(int aScore);
