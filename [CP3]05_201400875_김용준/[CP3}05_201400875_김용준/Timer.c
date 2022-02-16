#include "Timer.h"
#include <Windows.h> // �ӵ� ������ ���� Header

struct _Timer{
	LARGE_INTEGER _Frequency;
	LARGE_INTEGER _StartCounter;
	LARGE_INTEGER _StopCounter;
};


Timer* Timer_New() {
	Timer* Time = NewObject(Timer);
	QueryPerformanceFrequency(&((* Time)._Frequency)); // ���ļ�( 1�ʴ� �����Ǵ� ī��Ʈ ��)�� ���Ѵ�.
	return Time;
}
void Timer_Delete(Timer* Time) {
	free(Time);
}
void Timer_Start(Timer* Time) {
	QueryPerformanceCounter(&((* Time)._StartCounter)); // ���� �� ī��Ʈ�� ���Ѵ�.
}
void Timer_Stop(Timer* Time) {
	QueryPerformanceCounter(&((* Time)._StopCounter)); // ���� �� ī��Ʈ�� ���Ѵ�.
}
double Timer_Duration(Timer* Time) {
	double elapsed = (double)((* Time)._StopCounter.QuadPart - (* Time)._StartCounter.QuadPart);
	return (elapsed * 1000000.0 / ((double)(* Time)._Frequency.QuadPart));
	// ���� �ð��� ����ũ�� �� (micro second) �� ��ȯ�Ѵ�.
}