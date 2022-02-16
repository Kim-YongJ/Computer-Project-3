
#pragma once
#include "Common.h"

typedef struct _AppController AppController;


/********************************* ��ü ����, �Ҹ�, ���� *********************************/
AppController* AppController_New();
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);


/********************************* ���� ���� �ؾ��� �ϵ� *********************************/
void AppController_Add(AppController* _this, char aChar);
void AppController_RemoveN(AppController* _this, int numberOfChars);
void AppController_Remove1(AppController* _this);
void AppController_ShowSize(AppController* _this);
void AppController_ShowAllFromFront(AppController* _this);
void AppController_ShowFront(AppController* _this);
void AppController_Ignore(AppController* _this);
void AppController_EndInput(AppController* _this);


/********************************* �� ���� ���� Ƚ�� ���� *********************************/
void AppController_InitCountingChars(AppController* _this);
void AppController_CountInputChars(AppController* _this);
void AppController_CountIgnoredChars(AppController* _this);
void AppController_CountAddedChars(AppController* _this);


/********************************* �� ���� Ƚ�� ��� *********************************/
int AppController_NumberOfInputChars(AppController* _this);
int AppController_NumberOfIgnoredChars(AppController* _this);
int AppController_NumberOfNormallyProcessedChars(AppController* _this);
int AppController_NumberOfAddedChars(AppController* _this);


/********************************* ��� ���� ����ϱ� *********************************/
void AppController_ShowStatistics(AppController* _this);