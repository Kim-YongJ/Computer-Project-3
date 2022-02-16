#include "Stack.h"

#define DEFAULT_STACK_CAPACITY 100


struct _Stack {
	int _capacity;
	int _top;
	Element* _elements; // �迭�� �������� �Ҵ��Ѵ�.
};



/********************************* �⺻���� ���� �Լ� *********************************/
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
	} // Stack�� empty�̸� push�� �����Ѵ�.
}

Element Stack_Pop(Stack* _this)
{
	// Stack �� empty �� �ƴ϶�� �����Ѵ�. (������ �ڵ�. ������?)
	Element poppedElement;
	poppedElement = (*_this)._elements[(*_this)._top];
	(*_this)._top--;
	return poppedElement;
	}


/********************************* �߰��� �ʿ��� ���� �Լ� *********************************/
Element Stack_TopElement(Stack* _this)
{
	return ((*_this)._elements[(*_this)._top]);
	// ������ Top ���Ҹ� ����
}

Element Stack_ElementAt(Stack* _this, int anOrder)
{
	return ((*_this)._elements[anOrder]);
	// ���� ����Ʈ�� anOrder��° ���Ҹ� ����
}
