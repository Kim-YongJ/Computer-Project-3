#include "Timer.h"
void AppView_Out(char* aString) {
	printf(aString);
}

void AppView_Out_ExecutionTime(int anOrder, long anExecutionTime) {
	printf("����: %2d, �ð�: %ld (����ũ�� ��)\n", anOrder, anExecutionTime);
}



int AppView_In_Order(void) {
	int aMagicSquare;

	printf("�������� ���� ������ �Է��Ͻÿ�:");
	scanf("%d", &aMagicSquare); // %d�� int���� �Է¹޴´�

	return aMagicSquare;
}

