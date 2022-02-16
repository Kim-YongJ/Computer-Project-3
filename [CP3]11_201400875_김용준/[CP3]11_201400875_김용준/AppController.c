#pragma once
#include "AppController.h"
#include "AppView.h"
#include "Message.h"
#include "ParameterSet.h"
#include "Time.h"
#include <stdio.h>



struct _AppController {
	ParameterSet* _parameterSet;
	int* _testData;
	Timer* _timer;
};


AppController* AppController_new(void)
{
	AppController* _this = NewObject(AppController);

	//_this->_parameterSet = ParameterSet_new();

	return _this;
}


void AppController_delete(AppController* _this)
{
	free(_this);

}

void AppController_run(AppController* _this)
{
	AppView_out(MSG_StartPerformanceMeasuring);
	AppController_initPerformanceMeasurement(_this);

	int numberOfTests = ParameterSet_numberOfTests(_this->_parameterSet);
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);
	int intervalSize = ParameterSet_intervalSize(_this->_parameterSet);


	AppView_out(MSG_TitleForUnsortedLinkedList);

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnsortedLinkedList* listForTest = UnsortedLinkedList_new(maxTestSize);
		double timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeForUnsortedLinkedList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		UnsortedLinkedList_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out(MSG_TitleForSortedLinkedList);
	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortedLinkedList* listForTest = SortedLinkedList_new(maxTestSize);
		double timeForAdd = AppController_timeForSortedLinkedList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeForSortedLinkedList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForSortedLinkedList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		SortedLinkedList_delete(listForTest);
		testSize += intervalSize;
	}
	AppView_out(MSG_EndPerformanceMeasuring);


}


void AppController_generateTestDataByRandomNumbers(AppController* _this)
{
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);
	srand((unsigned)time(NULL));

	for (int i = 0; i < maxTestSize; i++) {
		_this->_testData[i] = rand();
	}
}


/*********************** 정렬 안된 리스트(삽입, 최소값, 삭제) ***********************/
double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isFull(aList)) {
			UnsortedLinkedList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize)
{
	Element min;
	double duration = 0;
	Timer* timer = Timer_new();
	for (int i = 0; i < aTestSize; i++) {
		// 이곳의 측정에서는 리스트의 내용이 변하지 않은 상태에서 동일한 행위를 반복한다
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) {
			min = UnsortedLinkedList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;

}


double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize)
{
	Element max;
	double duration = 0;
	Timer* timer = Timer_new();
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) {
			max = UnsortedLinkedList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


/*********************** 정렬된 리스트(삽입, 최소값, 삭제) ***********************/
double AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedList_isFull(aList)) {
			SortedLinkedList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedList_min(AppController* _this, SortedLinkedList* aList, int aTestSize)
{
	Element min;
	double duration = 0;
	Timer* timer = Timer_new();
	for (int i = 0; i < aTestSize; i++) {
		// 이곳의 측정에서는 리스트의 내용이 변하지 않은 상태에서 동일한 행위를 반복한다
		Timer_start(timer);
		if (!SortedLinkedList_isEmpty(aList)) {
			min = SortedLinkedList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;

}

double AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* aList, int aTestSize)
{
	Element max;
	double duration = 0;
	Timer* timer = Timer_new();
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedList_isEmpty(aList)) {
			max = SortedLinkedList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}



void AppController_showResults(AppController* _this, int aTestSize, double aTimeforMin, double aTimeForAdd, double aTimeForRemoveMax)
{
	char results[255];
	sprintf(results, "크기: %4d, 삽입: %6ld, 최소값얻기: %7ld, 최대값삭제: %7ld\n", aTestSize, (long)aTimeforMin, (long)aTimeForAdd, (long)aTimeForRemoveMax);
	AppView_out(results);
}


// [08-2] 에서 추가
void AppController_initPerformanceMeasurement(AppController* _this) {
	_this->_parameterSet = ParameterSet_new();
	ParameterSet_setMinTestSize(_this->_parameterSet, MIN_TEST_SIZE);
	ParameterSet_setIntervalSize(_this->_parameterSet, INTERVAL_SIZE);
	ParameterSet_setNumberOfTests(_this->_parameterSet, NUMBER_OF_TESTS);
	_this->_testData = NewVector(int, ParameterSet_maxTestSize(_this->_parameterSet));
	// 유의: 사용을 종료한 후, 이것을 소멸시킬 위치는?
	AppController_generateTestDataByRandomNumbers(_this);
}
