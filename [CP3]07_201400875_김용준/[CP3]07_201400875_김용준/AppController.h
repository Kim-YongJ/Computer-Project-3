#pragma once
#include "AppView.h"

#define MAX_NUMBER_OF_STUDENTS 100

typedef struct _AppController AppController;


/********************** AppController ��ü ������, �Ҹ��� **********************/
AppController* AppController_New();
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);

/********************** ���� �Է�, ���, ���� **********************/
void AppController_ShowStatistics(AppController* _this);
void AppController_ShowStudentsSortedByScore(AppController* _this);

// ���ο��� �� ����Ʈ�ѷ� ���� ���

Boolean AppController_InputIsValid(AppController* _this, char* aStudentID, int aScore);
Boolean AppController_InputAndStoreStudents(AppController* _this);