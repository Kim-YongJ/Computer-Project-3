#pragma once
#include "Common.h"

typedef int Element;
typedef struct {
	int _capacity;
	int _top;
	Element* _elements; // 포인터만 선언. 배열은 동적으로 생성
}Stack;



/********************************* 기본적인 공개 함수 *********************************/
Stack* Stack_New(int givenCapacity);
void Stack_Delete(Stack* _this);
Boolean Stack_IsEmpty(Stack* _this);
Boolean Stack_IsFull(Stack* _this);
int Stack_Size(Stack* _this);
void Stack_Push(Stack* _this, Element anElement);
Element Stack_Pop(Stack* _this);
void Stack_Reset(Stack* _this);


/********************************* 추가로 필요한 공개 함수 *********************************/
Element Stack_TopElement(Stack* _this);
Element Stack_ElementAt(Stack* _this, int anOrder);
