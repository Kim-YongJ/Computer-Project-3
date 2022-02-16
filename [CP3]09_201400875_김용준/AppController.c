#include "AppController.h"
#include "Stack.h"
#include "AppView.h"

#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <= '9'))
#define isAlpha(CHAR) (('a' <= CHAR) && (CHAR <= 'z') || ('A' <= CHAR) && (CHAR <= 'Z'))
#define Esc 27

struct _AppController {
	Stack* _stack;
	int _inputChars; // 입력된 문자의 개수
	int _ignoredChars; // 무시된 문자의 개수
	int _pushedChars; // 스택에 넣은 문자의 개수
};


/********************************* 객체 생성, 소멸, 실행 *********************************/
AppController* AppController_New()
{
	AppController* _this;
	_this = NewObject(AppController);
	(*_this)._stack = Stack_New();
	return _this;
}


void AppController_Delete(AppController* _this)
{
	Stack_Delete((*_this)._stack);
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
			AppController_Push(_this, c);
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_Pops(_this, digitValue);
		}
		else if (c == '-') {
			AppController_Pop1(_this);
		}
		else if (c == '#') {
			AppController_ShowSize(_this);
		}
		else if (c == '/') {
			AppController_ShowAllFromBottom(_this);
		}
		else if (c == '\\') {
			AppController_ShowAllFromTop(_this);
		}
		else if (c == '^') {
			AppController_ShowTopElement(_this);
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

void AppController_Push(AppController* _this, char aChar)
{
	if (Stack_IsFull((*_this)._stack)) {
		AppView_Out_StackIsFullAgainstPush(aChar);
	}

	else {
		Stack_Push((*_this)._stack, aChar);
		AppController_CountPushedChars(_this);
		AppView_Out_PushedElement(aChar);
	}
}

void AppController_Pops(AppController* _this, int numberOfChars)
{
	AppView_Out_BeginPops(numberOfChars);

	for (int i = 0; (i < numberOfChars); i++) {

		if (Stack_IsEmpty((*_this)._stack)) {
			AppView_Out_StackIsEmptyAgainstPops();
			return;
		}

		char poppedChar = Stack_Pop((*_this)._stack);
		AppView_Out_PoppedElementByPop1(poppedChar);
	}
	AppView_Out_EndPops();
}

void AppController_Pop1(AppController* _this)
{
	if (Stack_IsEmpty((*_this)._stack)) {
		AppView_Out_StackIsEmptyAgainstPop1();
	}

	else {
		char poppedChar = Stack_Pop((*_this)._stack);
		AppView_Out_PoppedElementByPop1(poppedChar);
	}
}

void AppController_ShowSize(AppController* _this)
{
	int stacksize = Stack_Size((*_this)._stack);
	AppView_Out_StackSize(stacksize);

}

void AppController_ShowAllFromBottom(AppController* _this)
{
	char stackElement;
	AppView_Out_BottomOfStack();

	for (int i = 0; i < Stack_Size((*_this)._stack); i++) {
		stackElement = Stack_ElementAt((*_this)._stack, i);
		AppView_Out_Element(stackElement);
	}

	AppView_Out_TopOfStack();
	AppView_Out_NewLine();
}

void AppController_ShowAllFromTop(AppController* _this)
{
	char stackElement;
	AppView_Out_TopOfStack();

	for (int i = 0; i < Stack_Size((*_this)._stack); i++) {
		stackElement = Stack_ElementAt((*_this)._stack, i);
		AppView_Out_Element(stackElement);
	}

	AppView_Out_BottomOfStack();
	AppView_Out_NewLine();

}

void AppController_ShowTopElement(AppController* _this)
{
	if (Stack_IsEmpty(_this)) {
		AppView_Out_NoTopElement(_this);
	}
	else {
		AppView_Out_TopElement(_this);
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
	(*_this)._pushedChars = 0;
}

void AppController_CountInputChars(AppController* _this)
{
	(*_this)._inputChars++;
}

void AppController_CountIgnoredChars(AppController* _this)
{
	(*_this)._ignoredChars++;
}

void AppController_CountPushedChars(AppController* _this)
{
	(*_this)._pushedChars++;
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

int AppController_NumberOfPushedChars(AppController* _this)
{
	return ((*_this)._inputChars - (*_this)._pushedChars);
}


/********************************* 통계 정보 출력하기 *********************************/
void AppController_ShowStatistics(AppController* _this)
{
	AppView_Out_NewLine();

	AppView_Out_NumberOfInputChars(AppController_NumberOfInputChars(_this));
	AppView_Out_NumberOfNormallyProcessedChars(AppController_NumberOfNormallyProcessedChars(_this));
	AppView_Out_NumberOfIgnoredChars(AppController_NumberOfIgnoredChars(_this));
	AppView_Out_NumberOfPushedChars(AppController_NumberOfPushedChars(_this));

}