#include "AppController.h"

typedef struct _GradeCounter {
	int _numberOfA;
	int _numberOfB;
	int _numberOfC;
	int _numberOfD;
	int _numberOfF;
};

/********************** GradeCounter 객체 생성자, 소멸자 **********************/
GradeCounter* GradeCounter_New(void)
{
	GradeCounter* _this = NewObject(GradeCounter);
	(*_this)._numberOfA = 0;
	(*_this)._numberOfB = 0;
	(*_this)._numberOfC = 0;
	(*_this)._numberOfD = 0;
	(*_this)._numberOfF = 0;
	return _this;
}

void GradeCounter_Delete(GradeCounter* _this)
{
	free(_this);
}


/********************** GradeCounter 학점 및 학점별 학생수 세기 **********************/
void GradeCounter_Count(GradeCounter* _this, char aGrade)
{
	switch (aGrade) {
	case 'A':
		(* _this)._numberOfA++;
		break;
	case 'B':
		(*_this)._numberOfB++;
		break;
	case 'C':
		(*_this)._numberOfC++;
		break;
	case 'D':
		(*_this)._numberOfD++;
		break;
	default:
		(*_this)._numberOfF++;
	}
}
int GradeCounter_NumberOfA(GradeCounter* _this)
{
	return (*_this)._numberOfA;
}

int GradeCounter_NumberOfB(GradeCounter* _this)
{
	return (*_this)._numberOfB;
}

int GradeCounter_NumberOfC(GradeCounter* _this)
{
	return (*_this)._numberOfC;
}

int GradeCounter_NumberOfD(GradeCounter* _this)
{
	return (*_this)._numberOfD;
}

int GradeCounter_NumberOfF(GradeCounter* _this)
{
	return (*_this)._numberOfF;
}
