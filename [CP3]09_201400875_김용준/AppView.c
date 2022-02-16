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
void AppView_Out_StackIsFullAgainstPush(char anElementForPush)
{
	printf("[Push: Full] ������ �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForPush);
}

void AppView_Out_PushedElement(char anElement)
{
	printf("[Push] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_Out_StackIsEmptyAgainstPop1()
{
	printf("[Pop1:Empty] ���ÿ� ������ ���Ұ� �����ϴ�.\n");
}

void AppView_Out_PoppedElementByPop1(char anElement)
{
	printf("[Pop1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_Out_BeginPops(int numberOfElements)
{
	printf("[Pops] % d ���� ���Ҹ� �����Ϸ��� �մϴ� : \n", numberOfElements);
}

void AppView_Out_EndPops()
{
	printf("[Pops] ������ �����մϴ�. \n");
}
void AppView_Out_StackIsEmptyAgainstPops()
{
	printf("[Pops: Empty] ���ÿ� �� �̻� ������ ���Ұ� �����ϴ�.\n");
}

void AppView_Out_TopElement(char anElement)
{
	printf("[Top] Top ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_Out_NoTopElement()
{
	printf("[Top:Empty] ���� ������ ��� �ֽ��ϴ�.\n");
}

/*********************** Class AppView �� �����Լ��� ����[3] ***********************/
void AppView_Out_BottomOfStack()
{
	printf("<Bottom of Stack> ");
}
void AppView_Out_Element(char anElement)
{
	printf("%c ", anElement);
}
void AppView_Out_TopOfStack()
{
	printf("<Top of Stack> ");
}
void AppView_Out_NewLine()
{
	printf("\n");
}
void AppView_Out_StackSize(int stackSize)
{
	printf("[Size] ���� ������ ũ��� %d �Դϴ�.\n", stackSize);
}
void AppView_Out_IgnoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}
void AppView_Out_EndInput()
{
	printf("[End Input] �Է��� �����ϸ�, ������ ��� ���Ҹ� �����մϴ� : \n");
}
void AppView_Out_PoppedElementByEndInput(char anElement)
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
void AppView_Out_NumberOfPushedChars(int numberOfChars)
{
	printf("......���ÿ� ���� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_Out_StartProgram()
{
	printf(" << < ���� ó�� ���α׷��� �����մϴ� >> > \n ");
	AppView_Out_NewLine();
}
void AppView_Out_EndProgram()
{
	AppView_Out_NewLine();
	printf(" << < ���� ó�� ���α׷��� �����մϴ� >> > \n ");
}
