#pragma once
#include "Common.h"

typedef struct _AppController AppController;


/********************************* ��ü ����, �Ҹ�, ���� *********************************/
AppController* AppController_New();
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);


/********************************* ���� ���� �ؾ��� �ϵ� *********************************/
void AppController_Push(AppController* _this, char aChar);
void AppController_Pops(AppController* _this, int numberOfChars);
void AppController_Pop1(AppController* _this);
void AppController_ShowSize(AppController* _this);
void AppController_ShowAllFromBottom(AppController* _this);
void AppController_ShowAllFromTop(AppController* _this);
void AppController_ShowTopElement(AppController* _this);
void AppController_Ignore(AppController* _this);
void AppController_EndInput(AppController* _this);


/********************************* �� ���� ���� Ƚ�� ���� *********************************/
void AppController_InitCountingChars(AppController* _this);
void AppController_CountInputChars(AppController* _this);
void AppController_CountIgnoredChars(AppController* _this);
void AppController_CountPushedChars(AppController* _this);


/********************************* �� ���� Ƚ�� ��� *********************************/
int AppController_NumberOfInputChars(AppController* _this);
int AppController_NumberOfIgnoredChars(AppController* _this);
int AppController_NumberOfNormallyProcessedChars(AppController* _this);
int AppController_NumberOfPushedChars(AppController* _this);


/********************************* ��� ���� ����ϱ� *********************************/
void AppController_ShowStatistics(AppController* _this);