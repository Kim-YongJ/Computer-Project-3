#pragma once
#include "Common.h"

typedef struct _GradeCounter GradeCounter;

/********************** GradeCounter ��ü ������, �Ҹ��� **********************/
GradeCounter* GradeCounter_New(void);
void GradeCounter_Delete(GradeCounter* _this);

/********************** GradeCounter ���� �� ������ �л��� ���� **********************/
void GradeCounter_Count(GradeCounter* _this, char aGrade);
int GradeCounter_NumberOfA(GradeCounter* _this);
int GradeCounter_NumberOfB(GradeCounter* _this);
int GradeCounter_NumberOfC(GradeCounter* _this);
int GradeCounter_NumberOfD(GradeCounter* _this);
int GradeCounter_NumberOfF(GradeCounter* _this);


