#pragma once
#include "Common.h"

typedef struct _AppController AppController;


/********************************* 객체 생성, 소멸, 실행 *********************************/
AppController* AppController_New();
void AppController_Delete(AppController* _this);
void AppController_Run(AppController* _this);


/********************************* 문자 별로 해야할 일들 *********************************/
void AppController_Push(AppController* _this, char aChar);
void AppController_Pops(AppController* _this, int numberOfChars);
void AppController_Pop1(AppController* _this);
void AppController_ShowSize(AppController* _this);
void AppController_ShowAllFromBottom(AppController* _this);
void AppController_ShowAllFromTop(AppController* _this);
void AppController_ShowTopElement(AppController* _this);
void AppController_Ignore(AppController* _this);
void AppController_EndInput(AppController* _this);


/********************************* 각 행위 실행 횟수 세기 *********************************/
void AppController_InitCountingChars(AppController* _this);
void AppController_CountInputChars(AppController* _this);
void AppController_CountIgnoredChars(AppController* _this);
void AppController_CountPushedChars(AppController* _this);


/********************************* 각 실행 횟수 얻기 *********************************/
int AppController_NumberOfInputChars(AppController* _this);
int AppController_NumberOfIgnoredChars(AppController* _this);
int AppController_NumberOfNormallyProcessedChars(AppController* _this);
int AppController_NumberOfPushedChars(AppController* _this);


/********************************* 통계 정보 출력하기 *********************************/
void AppController_ShowStatistics(AppController* _this);