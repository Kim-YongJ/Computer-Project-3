#include "Stack.h"

#define DEFAULT_STACK_CAPACITY 100


struct _Stack {
	int _capacity;
	int _top;
	Element* _elements; // 배열을 동적으로 할당한다.
};



/********************************* 기본적인 공개 함수 *********************************/
Stack* Stack_New()
{
	Stack* _this;
	_this = NewObject(Stack);
	(*_this)._elements = NewVector(Element, DEFAULT_STACK_CAPACITY);
	(*_this)._capacity = DEFAULT_STACK_CAPACITY;
	(*_this)._top = -1;
	return _this;
}

void Stack_Delete(Stack* _this)
{
	free((*_this)._elements);
	free(_this);
}

Boolean Stack_IsEmpty(Stack* _this)
{
	return (((*_this)._top) < 0);
}

Boolean Stack_IsFull(Stack* _this)
{
	return (((*_this)._top) == ((*_this)._capacity - 1));
}

int Stack_Size(Stack* _this)
{
	return ((*_this)._top + 1);
}

void Stack_Push(Stack* _this, Element anElement)
{
	if (!Stack_IsFull(_this)) {
		(*_this)._top++;
		(*_this)._elements[(*_this)._top] = anElement;
	} // Stack이 empty이면 push를 무시한다.
}

Element Stack_Pop(Stack* _this)
{
	// Stack 은 empty 가 아니라고 가정한다. (위험한 코드. 이유는?)
	Element poppedElement;
	poppedElement = (*_this)._elements[(*_this)._top];
	(*_this)._top--;
	return poppedElement;
	}


/********************************* 추가로 필요한 공개 함수 *********************************/
Element Stack_TopElement(Stack* _this)
{
	return ((*_this)._elements[(*_this)._top]);
	// 스택의 Top 원소를 얻음
}

Element Stack_ElementAt(Stack* _this, int anOrder)
{
	return ((*_this)._elements[anOrder]);
	// 스택 리스트의 anOrder번째 원소를 얻음
}
