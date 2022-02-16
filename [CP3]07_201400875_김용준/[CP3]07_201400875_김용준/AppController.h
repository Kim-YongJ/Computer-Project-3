#pragma once
#include "AppView.h"

#define MAX_NUMBER_OF_STUDENTS 100

typedef struct _AppController AppController;


/********************** AppController 객체 생성자, 소멸자 **********************/
AppController* AppController_New();
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);

/********************** 점수 입력, 출력, 정렬 **********************/
void AppController_ShowStatistics(AppController* _this);
void AppController_ShowStudentsSortedByScore(AppController* _this);

// 메인에서 쓸 앱컨트롤러 관리 헤더

Boolean AppController_InputIsValid(AppController* _this, char* aStudentID, int aScore);
Boolean AppController_InputAndStoreStudents(AppController* _this);