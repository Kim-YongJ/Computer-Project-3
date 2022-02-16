#include "AppView.h"
#include <stdio.h>
#include <conio.h>


/*********************** Class AppView �� �����Լ��� ����[1] ***********************/
char AppView_In_CharDirectlyFromKeyboard()
{
	printf("���ڸ� �Է��Ͻÿ� : ");
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

/*********************** Class AppView �� �����Լ��� ����[2] ***********************/
void AppView_Out_QueueIsFullAgainstAdd(char anElementForAdd)
{
	printf("[Add: Full] ť�� �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForAdd);
}

void AppView_Out_AddedElement(char anElement)
{
	printf("[Add] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_Out_QueueIsEmptyAgainstRemove1()
{
	printf("[Remove1:Empty] ť�� ������ ���Ұ� �����ϴ�.\n");
}

void AppView_Out_RemovedElementByRemove1(char anElement)
{
	printf("[Remove1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_Out_BeginRemoveN(int numberOfElements)
{
	printf("[Removes] % d ���� ���Ҹ� �����Ϸ��� �մϴ� : \n", numberOfElements);
}

void AppView_Out_EndRemoveN()
{
	printf("[Removes] ������ �����մϴ�. \n");
}
void AppView_Out_QueueIsEmptyAgainstRemoveN()
{
	printf("[Removes: Empty] ť�� �� �̻� ������ ���Ұ� �����ϴ�.\n");
}

void AppView_Out_FrontElement(char anElement)
{
	printf("[Front] Front ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_Out_NoFrontElement()
{
	printf("[Front:Empty] ���� ť�� ��� �ֽ��ϴ�.\n");
}

/*********************** Class AppView �� �����Լ��� ����[3] ***********************/
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
	printf("[Size] ���� ť�� ũ��� %d �Դϴ�.\n", QueueSize);
}
void AppView_Out_IgnoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}
void AppView_Out_EndInput()
{
	printf("[End Input] �Է��� �����ϸ�, ť�� ��� ���Ҹ� �����մϴ� : \n");
}
void AppView_Out_RemovedElementByEndInput(char anElement)
{
	printf(" - End Input : ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}


/*********************** Class AppView �� �����Լ��� ����[4] ***********************/
void AppView_Out_NumberOfInputChars(int numberOfChars)
{
	printf("......�Էµ� ���ڴ� ��� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_Out_NumberOfNormallyProcessedChars(int numberOfChars)
{
	printf("......�������� ó���� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_Out_NumberOfIgnoredChars(int numberOfChars)
{
	printf("......���õ� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_Out_NumberOfAddedChars(int numberOfChars)
{
	printf("......ť�� ���� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_Out_StartProgram()
{
	printf(" << < ť ó�� ���α׷��� �����մϴ� >> > \n ");
	AppView_Out_NewLine();
}
void AppView_Out_EndProgram()
{
	AppView_Out_NewLine();
	printf(" << < ť ó�� ���α׷��� �����մϴ� >> > \n ");
}
