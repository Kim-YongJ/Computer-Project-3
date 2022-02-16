#pragma once
#include "Common.h"

/*********************** Class AppView 의 공개함수의 구현[1] ***********************/
char AppView_In_CharDirectlyFromKeyboard();
char GetCharDirectlyFromKeyboard(void);


/*********************** Class AppView 의 공개함수의 구현[2] ***********************/
void AppView_Out_QueueIsFullAgainstAdd(char anElementForPush);
void AppView_Out_AddedElement(char anElement);
void AppView_Out_QueueIsEmptyAgainstRemove1();
void AppView_Out_RemovedElementByRemove1(char anElement);
void AppView_Out_BeginRemoveN(int numberOfElements);
void AppView_Out_EndRemoveN();
void AppView_Out_QueueIsEmptyAgainstRemoveN();
void AppView_Out_FrontElement(char anElement);
void AppView_Out_NoFrontElement();


/*********************** Class AppView 의 공개함수의 구현[3] ***********************/
void AppView_Out_RearOfQueue();
void AppView_Out_Element(char anElement);
void AppView_Out_FrontOfQueue();
void AppView_Out_NewLine();
void AppView_Out_QueueSize(int QueueSize);
void AppView_Out_IgnoredChar();
void AppView_Out_EndInput();
void AppView_Out_RemovedElementByEndInput(char anElement);


/*********************** Class AppView 의 공개함수의 구현[4] ***********************/
void AppView_Out_NumberOfInputChars(int numberOfChars);
void AppView_Out_NumberOfNormallyProcessedChars(int numberOfChars);
void AppView_Out_NumberOfIgnoredChars(int numberOfChars);
void AppView_Out_NumberOfAddedChars(int numberOfChars);
void AppView_Out_StartProgram();
void AppView_Out_EndProgram();

