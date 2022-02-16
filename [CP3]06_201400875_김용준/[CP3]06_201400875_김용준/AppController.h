#pragma once
#include "AppView.h"

#define MAX_NUMBER_OF_STUDENTS 100

typedef struct _AppController AppController;


/********************** AppController 객체 생성자, 소멸자 **********************/
AppController* AppController_New();
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);

/********************** 점수 입력, 출력, 정렬 **********************/
Boolean AppController_InputAndStoreStudents(AppController* _this);
void AppController_ShowStatistics(AppController* _this);
void AppController_ShowStudentsSortedByScore(AppController* _this);