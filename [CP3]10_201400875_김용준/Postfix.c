#pragma once
#include "Postfix.h"
#include "Stack.h"
#include "AppView.h"
#include <string.h>
#include <stdio.h>

typedef struct _Postfix {
	int _maxNumberOfTokens;
	char* _expression;
	int _evaluatedValue;
	Stack* _operandStack;
};


Postfix* Postfix_New(int givenMaxNumberOfTokens)
{
	Postfix* _this = NewObject(Postfix);
	(*_this)._maxNumberOfTokens = givenMaxNumberOfTokens;
	(*_this)._expression = NewVector(char, givenMaxNumberOfTokens);
	(*_this)._operandStack = Stack_New(givenMaxNumberOfTokens);
	return _this;
}

void Postfix_Delete(Postfix* _this)
{
	Stack_Delete((*_this)._operandStack);
	free((*_this)._expression);
	free(_this);
}


void Postfix_SetExpression(Postfix* _this, char* anExpression)
{
	strcpy((*_this)._expression, anExpression);
}


int Postfix_EvaluatedValue(Postfix* _this)
{
	return ((*_this)._evaluatedValue);
}


Boolean Postfix_Evaluate(Postfix* _this)
{
	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0;
	Stack_Reset((*_this)._operandStack);
	while ((*_this)._expression[i] != '\0') {
		currentToken = (*_this)._expression[i];
		if (currentToken >= '0' && currentToken <= '9') {
			// token is an operand. Push it into stack
			operand = (currentToken - '0');
			if (Stack_IsFull((*_this)._operandStack)) {
				return PostfixError_ExpressionTooLong; // 수식이 너무 길어 처리가 불가능합니다.
			}
			else {
				Stack_Push((*_this)._operandStack, operand);
			}
		}
		else { // The token is an operator
			if (currentToken == '+') {
				if (Stack_Size((*_this)._operandStack) >= 2) {
					operand2 = Stack_Pop((*_this)._operandStack);
					operand1 = Stack_Pop((*_this)._operandStack);
					calculated = operand1 + operand2;
					Stack_Push((*_this)._operandStack, calculated);
				}
				else {
					return PostfixError_OperandsTooFew; // [오류] 연산자에 비해 연산값의 수가 적습니다.
				}
			}
			else if (currentToken == '-') {
				if (Stack_Size((*_this)._operandStack) >= 2) {
					operand2 = Stack_Pop((*_this)._operandStack);
					operand1 = Stack_Pop((*_this)._operandStack);
					calculated = operand1 - operand2;
					Stack_Push((*_this)._operandStack, calculated);
				}
				else {
					return PostfixError_OperandsTooFew; // [오류] 연산자에 비해 연산값의 수가 적습니다.
				}
			}
			else if (currentToken == '*') {
				if (Stack_Size((*_this)._operandStack) >= 2) {
					operand2 = Stack_Pop((*_this)._operandStack);
					operand1 = Stack_Pop((*_this)._operandStack);
					calculated = operand1 * operand2;
					Stack_Push((*_this)._operandStack, calculated);
			}
				else {
					return PostfixError_OperandsTooFew; // [오류] 연산자에 비해 연산값의 수가 적습니다.
				}
			}
			else if (currentToken == '/') {
				if (Stack_Size((*_this)._operandStack) >= 2) {
					operand2 = Stack_Pop((*_this)._operandStack);
					operand1 = Stack_Pop((*_this)._operandStack);
					if (operand2 == 0) {
						return PostfixError_DivideByZero; // [오류] 나눗셈의 분모가 0 입니다.
					}
					else {
						calculated = operand1 / operand2;
						Stack_Push((*_this)._operandStack, calculated);
					}
			}
				else {
					return PostfixError_OperandsTooFew; // [오류] 연산자에 비해 연산값의 수가 적습니다.
				}
			}
			else if (currentToken == '%') {
				if (Stack_Size((*_this)._operandStack) >= 2) {
					operand2 = Stack_Pop((*_this)._operandStack);
					operand1 = Stack_Pop((*_this)._operandStack);
					if (operand2 == 0) {
						return PostfixError_DivideByZero; // [오류] 나눗셈의 분모가 0 입니다.
					}
					else {
						calculated = operand1 % operand2;
						Stack_Push((*_this)._operandStack, calculated);
					}
			}
			else {
					return PostfixError_OperandsTooFew; // [오류] 연산자에 비해 연산값의 수가 적습니다.
			}

		}
		Postfix_ShowTokenAndStack(_this, currentToken); // 여기에 출력이 있는 이유는?
		i++;
	} // end of while
	// At this point, the result is on top of stack
	if (Stack_Size((*_this)._operandStack) == 1) {
		(*_this)._evaluatedValue = Stack_Pop((*_this)._operandStack);
	}
	else if (Stack_Size((*_this)._operandStack) > 1) {
		return PostfixError_OperandsTooMany; // [오류] 연산자에 비해 연산값의 수가 너무 많습니다
	}
	return PostfixError_None; // 오류 없음. 성공적으로 계산 완료.
}
}


void Postfix_ShowTokenAndStack(Postfix* _this, char currentToken)
{
	// 여기 좀 생각해봐야함.




}