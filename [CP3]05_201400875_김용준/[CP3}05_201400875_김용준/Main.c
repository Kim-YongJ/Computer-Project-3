/* 201400875 ����� ��ǻ�����α׷���3
   5���� ��������ü �ǽ� �ҽ�			*/

#include "Timer.h" // ���� ���� �����ϰ� �ִ� ��� ����

#define END_OF_RUN -1 // ���� ����


int main()
{
	AppController* appController;
	appController = AppController_New(); // appController ��ü ����
	AppController_Run(appController); // app ����
	AppController_Delete(appController);// appController ��ü ����
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
	// ����ð��� ������ �ڵ�
	i = 0;
	sum = 0;
	while (i < MAX_NUMBER) {
		sum = sum + i;
		i++;
	}
	Timer_Stop(Time); // Stop Timer
	excutionTime = Timer_Duration(Time); // �ڵ� ���� �ð� ( ����: micro second)
	printf("\n����ð� : %ld(micro seconds)", (long)excutionTime);
	Timer_Delete(Time);
	return 0;
}
*/