#pragma once
#include "Common.h"

typedef struct _Postfix Postfix;


Postfix* Postfix_New(int givenMaxNumberOfTokens);

void Postfix_Delete(Postfix* _this);

void Postfix_SetExpression(Postfix* _this, char* anExpression);

int Postfix_EvaluatedValue(Postfix* _this);

Boolean Postfix_Evaluate(Postfix* _this);


// ���� ��� ���� ���� ��¹�
void Postfix_ShowTokenAndStack(Postfix* _this, char currentToken);