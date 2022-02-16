#include "Timer.h"
#include <Windows.h> // 속도 측정을 위한 Header

struct _Timer{
	LARGE_INTEGER _Frequency;
	LARGE_INTEGER _StartCounter;
	LARGE_INTEGER _StopCounter;
};


Timer* Timer_New() {
	Timer* Time = NewObject(Timer);
	QueryPerformanceFrequency(&((* Time)._Frequency)); // 주파수( 1초당 증가되는 카운트 수)를 구한다.
	return Time;
}
void Timer_Delete(Timer* Time) {
	free(Time);
}
void Timer_Start(Timer* Time) {
	QueryPerformanceCounter(&((* Time)._StartCounter)); // 실행 전 카운트를 구한다.
}
void Timer_Stop(Timer* Time) {
	QueryPerformanceCounter(&((* Time)._StopCounter)); // 실행 후 카운트를 구한다.
}
double Timer_Duration(Timer* Time) {
	double elapsed = (double)((* Time)._StopCounter.QuadPart - (* Time)._StartCounter.QuadPart);
	return (elapsed * 1000000.0 / ((double)(* Time)._Frequency.QuadPart));
	// 실행 시간을 마이크로 초 (micro second) 로 변환한다.
}