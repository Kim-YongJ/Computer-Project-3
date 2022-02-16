#pragma once
#include "Common.h"

/*********************** Class AppView �� �����Լ��� ����[1] ***********************/
char AppView_In_CharDirectlyFromKeyboard();
char GetCharDirectlyFromKeyboard(void);


/*********************** Class AppView �� �����Լ��� ����[2] ***********************/
void AppView_Out_StackIsFullAgainstPush(char anElementForPush);
void AppView_Out_PushedElement(char anElement);
void AppView_Out_StackIsEmptyAgainstPop1();
void AppView_Out_PoppedElementByPop1(char anElement);
void AppView_Out_BeginPops(int numberOfElements);
void AppView_Out_EndPops();
void AppView_Out_StackIsEmptyAgainstPops();
void AppView_Out_TopElement(char anElement);
void AppView_Out_NoTopElement();


/*********************** Class AppView �� �����Լ��� ����[3] ***********************/
void AppView_Out_BottomOfStack();
void AppView_Out_Element(char anElement);
void AppView_Out_TopOfStack();
void AppView_Out_NewLine();
void AppView_Out_StackSize(int stackSize);
void AppView_Out_IgnoredChar();
void AppView_Out_EndInput();
void AppView_Out_PoppedElementByEndInput(char anElement);


/*********************** Class AppView �� �����Լ��� ����[4] ***********************/
void AppView_Out_NumberOfInputChars(int numberOfChars);
void AppView_Out_NumberOfNormallyProcessedChars(int numberOfChars);
void AppView_Out_NumberOfIgnoredChars(int numberOfChars);
void AppView_Out_NumberOfPushedChars(int numberOfChars);
void AppView_Out_StartProgram();
void AppView_Out_EndProgram();

