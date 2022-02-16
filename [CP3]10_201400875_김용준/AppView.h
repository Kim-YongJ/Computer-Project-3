#pragma once
#include "Postfix.h"
#include "AppController.h"

Boolean AppView_In_PostfixExpression(char* s);

void AppView_Out_StartingMessage();
void AppView_Out_ErrorInExpression();
void AppView_Out_EvaluatedValue(int result);
void AppView_Out_EndingMessage();


/**************** void Postfix_showTokenAndStack �Լ����� ����ϴ� ��¹�(���� �������) ***************/
void AppView_Out_CurrentTokenAndBottom(char currentToken);
void AppView_Out_StackElement(int anElement);
void AppView_Out_Top();

void AppView_Out_PostfixEvaluationErrorMessage(PostfixError aPostfixError);