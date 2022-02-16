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
{	// AppController 객체를 생성한다

	AppController* appController;
		appController = NewObject(AppController);
		return appController;
}

void AppController_Delete(AppController* appController) {
	// 사용이 끝난 AppController 객체를 소멸 시킨다.

	free(appController);
}

void AppController_Run()
{
	MagicSquare* MagicSquare;
	int order, count;
	Timer* Time;
	long anExecutionTime;
	Time = Timer_New();
	AppView_Out("<<< 마방진 풀이의 성능 측정을 시작합니다 >>>\n");
	AppView_Out("하나의 차수에 대해 100 회 반복 실행한 시간을 측정합니다.\n");
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
	AppView_Out("<<< 성능 측정을 마칩니다 >>>\n");
} // end of AppController_run ()


/*
void AppController_Run(AppController* appController) {

	MagicSquare* MagicSquare = MagicSquare_New();  // 객체를 동적으로 생성
	int InputOrder;
	AppView_Out("<<< 마방진 풀이를 시작합니다 >>> \n");
	InputOrder = AppView_In_Order(); // 마방진 차수를 입력 받아 inputOrder 에 저장


	while (InputOrder != END_OF_RUN) { // 차수가 -1 이면 프로그램 종료

		MagicSquare_SetOrder(MagicSquare, InputOrder); // 마방진 차수 입력받은걸 객체에 저장

		if (MagicSquare_OrderIsValid(MagicSquare)); { // 차수가 유효한지 검사
			MagicSquare_Solve(MagicSquare); // 주어진 차수의 마방진을 얻는다
			AppController_ShowBoard(appController, MagicSquare); // 마방진 판을 보여준다
		}
		InputOrder = AppView_In_Order(); // 마방진 차수를 입력 받아 inputOrder 에 저장
	}
	MagicSquare_Delete(MagicSquare); // MagicSquare 객체를 소멸시킨다

	AppView_Out("<<< 마방진 풀이를 종료합니다 >>>");
}
*/