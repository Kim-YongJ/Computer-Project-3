#include "Timer.h"
void AppView_Out(char* aString) {
	printf(aString);
}

void AppView_Out_ExecutionTime(int anOrder, long anExecutionTime) {
	printf("차수: %2d, 시간: %ld (마이크로 초)\n", anOrder, anExecutionTime);
}



int AppView_In_Order(void) {
	int aMagicSquare;

	printf("마방진을 만들 차수를 입력하시오:");
	scanf("%d", &aMagicSquare); // %d로 int값을 입력받는다

	return aMagicSquare;
}

