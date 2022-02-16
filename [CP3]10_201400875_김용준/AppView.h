#pragma once
#include "Postfix.h"
#include "AppController.h"

Boolean AppView_In_PostfixExpression(char* s);

void AppView_Out_StartingMessage();
void AppView_Out_ErrorInExpression();
void AppView_Out_EvaluatedValue(int result);
void AppView_Out_EndingMessage();


/**************** void Postfix_showTokenAndStack 함수에서 사용하는 출력문(따로 만들었음) ***************/
void AppView_Out_CurrentTokenAndBottom(char currentToken);
void AppView_Out_StackElement(int anElement);
void AppView_Out_Top();

void AppView_Out_PostfixEvaluationErrorMessage(PostfixError aPostfixError);