#pragma once

#include "AppController.h"
typedef struct _Timer Timer;


Timer* Timer_New(); //  Ÿ�̸� ����

void Timer_Delete(Timer* Time); // Ÿ�̸� �Ҹ�
void Timer_Start(Timer* Time); // Ÿ�̸� �۵� ����
void Timer_Stop(Timer* Time); // Ÿ�̸� �۵� ����
double Timer_Duration(Timer* Time); // Ÿ�̸� �۵� ���ۺ��� ���������� �ð�(����: micro second)