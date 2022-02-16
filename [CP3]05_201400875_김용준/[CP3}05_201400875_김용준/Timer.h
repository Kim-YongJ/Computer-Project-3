#pragma once

#include "AppController.h"
typedef struct _Timer Timer;


Timer* Timer_New(); //  타이머 생성

void Timer_Delete(Timer* Time); // 타이머 소멸
void Timer_Start(Timer* Time); // 타이머 작동 시작
void Timer_Stop(Timer* Time); // 타이머 작동 중지
double Timer_Duration(Timer* Time); // 타이머 작동 시작부터 중지까지의 시간(단위: micro second)