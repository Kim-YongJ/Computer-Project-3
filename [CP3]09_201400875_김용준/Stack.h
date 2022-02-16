#pragma once
#include "Common.h"

typedef char Element;
typedef struct _Stack Stack;


/********************************* 기본적인 공개 함수 *********************************/
Stack* Stack_New();
void Stack_Delete(Stack* _this);
Boolean Stack_IsEmpty(Stack* _this);
Boolean Stack_IsFull(Stack* _this);
int Stack_Size(Stack* _this);
void Stack_Push(Stack* _this, Element anElement);
Element Stack_Pop(Stack* _this);


/********************************* 추가로 필요한 공개 함수 *********************************/
Element Stack_TopElement(Stack* _this);
Element Stack_ElementAt(Stack* _this, int anOrder);
