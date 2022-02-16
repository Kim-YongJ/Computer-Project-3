#include "AppView.h"
#include <stdio.h>
#include <conio.h>


/*********************** Class AppView 의 공개함수의 구현[1] ***********************/
char AppView_In_CharDirectlyFromKeyboard()
{
	printf("문자를 입력하시오 : ");
	char charDirectlyFromKeyboard = GetCharDirectlyFromKeyboard();
	AppView_Out_NewLine();
	return charDirectlyFromKeyboard;
}

char GetCharDirectlyFromKeyboard(void)
{
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

/*********************** Class AppView 의 공개함수의 구현[2] ***********************/
void AppView_Out_QueueIsFullAgainstAdd(char anElementForAdd)
{
	printf("[Add: Full] 큐가 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n", anElementForAdd);
}

void AppView_Out_AddedElement(char anElement)
{
	printf("[Add] 삽입된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_Out_QueueIsEmptyAgainstRemove1()
{
	printf("[Remove1:Empty] 큐에 삭제할 원소가 없습니다.\n");
}

void AppView_Out_RemovedElementByRemove1(char anElement)
{
	printf("[Remove1] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_Out_BeginRemoveN(int numberOfElements)
{
	printf("[Removes] % d 개의 원소를 삭제하려고 합니다 : \n", numberOfElements);
}

void AppView_Out_EndRemoveN()
{
	printf("[Removes] 삭제를 종료합니다. \n");
}
void AppView_Out_QueueIsEmptyAgainstRemoveN()
{
	printf("[Removes: Empty] 큐에 더 이상 삭제할 원소가 없습니다.\n");
}

void AppView_Out_FrontElement(char anElement)
{
	printf("[Front] Front 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_Out_NoFrontElement()
{
	printf("[Front:Empty] 현재 큐는 비어 있습니다.\n");
}

/*********************** Class AppView 의 공개함수의 구현[3] ***********************/
void AppView_Out_RearOfQueue()
{
	printf("<Rear of Queue> ");
}
void AppView_Out_Element(char anElement)
{
	printf("%c ", anElement);
}
void AppView_Out_FrontOfQueue()
{
	printf("<Front of Queue> ");
}
void AppView_Out_NewLine()
{
	printf("\n");
}
void AppView_Out_QueueSize(int QueueSize)
{
	printf("[Size] 현재 큐의 크기는 %d 입니다.\n", QueueSize);
}
void AppView_Out_IgnoredChar()
{
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}
void AppView_Out_EndInput()
{
	printf("[End Input] 입력을 종료하며, 큐의 모든 원소를 삭제합니다 : \n");
}
void AppView_Out_RemovedElementByEndInput(char anElement)
{
	printf(" - End Input : 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}


/*********************** Class AppView 의 공개함수의 구현[4] ***********************/
void AppView_Out_NumberOfInputChars(int numberOfChars)
{
	printf("......입력된 문자는 모두 %d 개 입니다.\n ", numberOfChars);
}
void AppView_Out_NumberOfNormallyProcessedChars(int numberOfChars)
{
	printf("......정상으로 처리된 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppView_Out_NumberOfIgnoredChars(int numberOfChars)
{
	printf("......무시된 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppView_Out_NumberOfAddedChars(int numberOfChars)
{
	printf("......큐에 넣은 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppView_Out_StartProgram()
{
	printf(" << < 큐 처리 프로그램을 시작합니다 >> > \n ");
	AppView_Out_NewLine();
}
void AppView_Out_EndProgram()
{
	AppView_Out_NewLine();
	printf(" << < 큐 처리 프로그램을 종료합니다 >> > \n ");
}
