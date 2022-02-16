#pragma once

#include "Timer.h"


void AppController_ShowBoard(AppController* appController , MagicSquare* MagicSquare)
{
	char messageBuffer[255];
	int order = MagicSquare_Order(MagicSquare);
	sprintf(messageBuffer, "Magic Square Board: Order %2d\n", order);
	AppView_Out(messageBuffer);
	AppView_Out(" ");
	for (int col = 0; col < order; col++) {
		sprintf(messageBuffer, " [%2d] ", col);
		AppView_Out(messageBuffer);
	}
	AppView_Out("\n");
	for (int row = 0; row < order; row++) {
		sprintf(messageBuffer, "[%2d]", row);
		AppView_Out(messageBuffer);
		for (int col = 0; col < order; col++) {
			sprintf(messageBuffer, "%5d ", MagicSquare_Cell(MagicSquare, row, col));
			AppView_Out(messageBuffer);
		}
		AppView_Out("\n");
	}
}

AppController* AppController_New() 
{	// AppController ��ü�� �����Ѵ�

	AppController* appController;
		appController = NewObject(AppController);
		return appController;
}

void AppController_Delete(AppController* appController) {
	// ����� ���� AppController ��ü�� �Ҹ� ��Ų��.

	free(appController);
}

void AppController_Run()
{
	MagicSquare* MagicSquare;
	int order, count;
	Timer* Time;
	long anExecutionTime;
	Time = Timer_New();
	AppView_Out("<<< ������ Ǯ���� ���� ������ �����մϴ� >>>\n");
	AppView_Out("�ϳ��� ������ ���� 100 ȸ �ݺ� ������ �ð��� �����մϴ�.\n");
	for (order = 9; order <= MAX_ORDER; order += 10) {
		Timer_Start(Time);
		for (count = 0; count < 100; count++) {
			aMagicSquare = MagicSquare_New();
			MagicSquare_SetOrder(aMagicSquare, order);
			MagicSquare_Solve(aMagicSquare);
		}
		Timer_Stop(Time);
		MagicSquare_Delete(aMagicSquare);
		anExecutionTime = Timer_Duration(Time);
		AppView_Out_ExecutionTime(order, anExecutionTime);
	}
	Timer_Delete(Time);
	AppView_Out("<<< ���� ������ ��Ĩ�ϴ� >>>\n");
} // end of AppController_run ()


/*
void AppController_Run(AppController* appController) {

	MagicSquare* MagicSquare = MagicSquare_New();  // ��ü�� �������� ����
	int InputOrder;
	AppView_Out("<<< ������ Ǯ�̸� �����մϴ� >>> \n");
	InputOrder = AppView_In_Order(); // ������ ������ �Է� �޾� inputOrder �� ����


	while (InputOrder != END_OF_RUN) { // ������ -1 �̸� ���α׷� ����

		MagicSquare_SetOrder(MagicSquare, InputOrder); // ������ ���� �Է¹����� ��ü�� ����

		if (MagicSquare_OrderIsValid(MagicSquare)); { // ������ ��ȿ���� �˻�
			MagicSquare_Solve(MagicSquare); // �־��� ������ �������� ��´�
			AppController_ShowBoard(appController, MagicSquare); // ������ ���� �����ش�
		}
		InputOrder = AppView_In_Order(); // ������ ������ �Է� �޾� inputOrder �� ����
	}
	MagicSquare_Delete(MagicSquare); // MagicSquare ��ü�� �Ҹ��Ų��

	AppView_Out("<<< ������ Ǯ�̸� �����մϴ� >>>");
}
*/