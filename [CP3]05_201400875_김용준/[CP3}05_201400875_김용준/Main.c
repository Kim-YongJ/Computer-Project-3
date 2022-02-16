/* 201400875 김용준 컴퓨터프로그래밍3
   5주차 마방진객체 실습 소스			*/

#include "Timer.h" // 가장 많이 포함하고 있는 헤더 참조

#define END_OF_RUN -1 // 숫자 정의


int main()
{
	AppController* appController;
	appController = AppController_New(); // appController 객체 생성
	AppController_Run(appController); // app 실행
	AppController_Delete(appController);// appController 객체 삭제
	return 0;


}
/*
#include "Timer.h"

#define MAX_NUMBER 1000

int main()
{
	int i, sum;
	double excutionTime;
	Timer* Time;
	Time = Timer_New();
	Timer_Start(Time); // Start Timer
	// 실행시간을 측정할 코드
	i = 0;
	sum = 0;
	while (i < MAX_NUMBER) {
		sum = sum + i;
		i++;
	}
	Timer_Stop(Time); // Stop Timer
	excutionTime = Timer_Duration(Time); // 코드 실행 시간 ( 단위: micro second)
	printf("\n실행시간 : %ld(micro seconds)", (long)excutionTime);
	Timer_Delete(Time);
	return 0;
}
*/