#include "AppController.h"
#include "Queue.h"
#include "AppView.h"

#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <= '9'))
#define isAlpha(CHAR) (('a' <= CHAR) && (CHAR <= 'z') || ('A' <= CHAR) && (CHAR <= 'Z'))
#define Esc 27

struct _AppController {
	Queue* _queue;
	int _inputChars; // 입력된 문자의 개수
	int _ignoredChars; // 무시된 문자의 개수
	int _addedChars; // 스택에 넣은 문자의 개수
};


/********************************* 객체 생성, 소멸, 실행 *********************************/
AppController* AppController_New()
{
	AppController* _this;
	_this = NewObject(AppController);
	(*_this)._queue = Queue_New();
	return _this;
}


void AppController_Delete(AppController* _this)
{
	Queue_Delete((*_this)._queue);
	free(_this);
}


void AppController_Run(AppController* _this)
{
	AppView_Out_StartProgram();
	AppController_InitCountingChars(_this);
	AppView_Out_NewLine();
	char c = AppView_In_CharDirectlyFromKeyboard();
	while (c != Esc) {
		AppController_CountInputChars(_this);
		if (isAlpha(c)) {
			AppController_Add(_this, c);
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_RemoveN(_this, digitValue);
		}
		else if (c == '-') {
			AppController_Remove1(_this);
		}
		else if (c == '#') {
			AppController_ShowSize(_this);
		}
		else if (c == '/') {
			AppController_ShowAllFromFront(_this);
		}
		else if (c == '^') {
			AppController_ShowFront(_this);
		}
		else {
			AppController_Ignore(_this);
		}
		AppView_Out_NewLine();
		c = AppView_In_CharDirectlyFromKeyboard();
	}
	AppController_EndInput(_this);
	AppController_ShowStatistics(_this);
	AppView_Out_EndProgram();
}



/********************************* 문자 별로 해야할 일들 *********************************/

void AppController_Add(AppController* _this, char aChar)
{
	if (Queue_IsFull((*_this)._queue)) {
		AppView_Out_QueueIsFullAgainstAdd(aChar);
	}

	else {
		Queue_Add((*_this)._queue, aChar);
		AppController_CountAddedChars(_this);
		AppView_Out_AddedElement(aChar);
	}
}

void AppController_RemoveN(AppController* _this, int numberOfChars)
{
	AppView_Out_BeginRemoveN(numberOfChars);

	for (int i = 0; (i < numberOfChars); i++) {

		if (Queue_IsEmpty((*_this)._queue)) {
			AppView_Out_QueueIsEmptyAgainstRemoveN();
			return;
		}

		char removedChar = Queue_Remove((*_this)._queue);
		AppView_Out_RemovedElementByRemove1(removedChar);
	}
	AppView_Out_EndRemoveN();
}

void AppController_Remove1(AppController* _this)
{
	if (Queue_IsEmpty((*_this)._queue)) {
		AppView_Out_QueueIsEmptyAgainstRemove1();
	}

	else {
		char removedChar = Queue_Remove((*_this)._queue);
		AppView_Out_RemovedElementByRemove1(removedChar);
	}
}

void AppController_ShowSize(AppController* _this)
{
	int queuesize = Queue_Size((*_this)._queue);
	AppView_Out_QueueSize(queuesize);

}

void AppController_ShowAllFromFront(AppController* _this) // Stack의 바텀
{
	char queueElement;
	AppView_Out_RearOfQueue();

	for (int i = 0; i < Queue_Size((*_this)._queue); i++) {
		queueElement = Queue_ElementAt((*_this)._queue, i);
		AppView_Out_Element(queueElement);
	}

	AppView_Out_FrontOfQueue();
	AppView_Out_NewLine();
}

void AppController_ShowFront(AppController* _this)
{
	if (Queue_IsEmpty(_this)) {
		AppView_Out_NoFrontElement(_this);
	}
	else {
		AppView_Out_FrontElement(_this);
	}
}

void AppController_Ignore(AppController* _this)
{
	AppView_Out_IgnoredChar();
}

void AppController_EndInput(AppController* _this)
{
	AppView_Out_EndInput();
}



/********************************* 각 행위 실행 횟수 세기 *********************************/
void AppController_InitCountingChars(AppController* _this)
{
	(*_this)._inputChars = 0;
	(*_this)._ignoredChars = 0;
	(*_this)._addedChars = 0;
}

void AppController_CountInputChars(AppController* _this)
{
	(*_this)._inputChars++;
}

void AppController_CountIgnoredChars(AppController* _this)
{
	(*_this)._ignoredChars++;
}

void AppController_CountAddedChars(AppController* _this)
{
	(*_this)._addedChars++;
}


/********************************* 각 실행 횟수 얻기 *********************************/
int AppController_NumberOfInputChars(AppController* _this)
{
	return ((*_this)._inputChars);
}

int AppController_NumberOfIgnoredChars(AppController* _this)
{
	return ((*_this)._inputChars - (*_this)._ignoredChars);
}

int AppController_NumberOfNormallyProcessedChars(AppController* _this)
{
	return ((*_this)._inputChars);
}

int AppController_NumberOfAddedChars(AppController* _this)
{
	return ((*_this)._inputChars - (*_this)._addedChars);
}


/********************************* 통계 정보 출력하기 *********************************/
void AppController_ShowStatistics(AppController* _this)
{
	AppView_Out_NewLine();

	AppView_Out_NumberOfInputChars(AppController_NumberOfInputChars(_this));
	AppView_Out_NumberOfNormallyProcessedChars(AppController_NumberOfNormallyProcessedChars(_this));
	AppView_Out_NumberOfIgnoredChars(AppController_NumberOfIgnoredChars(_this));
	AppView_Out_NumberOfAddedChars(AppController_NumberOfAddedChars(_this));

}