#pragma once
#include "Common.h"

typedef char Element;
typedef struct _Stack Stack;


/********************************* �⺻���� ���� �Լ� *********************************/
Stack* Stack_New();
void Stack_Delete(Stack* _this);
Boolean Stack_IsEmpty(Stack* _this);
Boolean Stack_IsFull(Stack* _this);
int Stack_Size(Stack* _this);
void Stack_Push(Stack* _this, Element anElement);
Element Stack_Pop(Stack* _this);


/********************************* �߰��� �ʿ��� ���� �Լ� *********************************/
Element Stack_TopElement(Stack* _this);
Element Stack_ElementAt(Stack* _this, int anOrder);
