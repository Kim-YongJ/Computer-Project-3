#pragma once
#include "Common.h"
#include "UnsortedLinkedList.h"
#include "SortedLinkedList.h"




typedef struct _AppController AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void AppController_generateTestDataByRandomNumbers(AppController* _this);

void AppController_showResults(AppController* _this, int aTestSize, double aTimeforMin, double aTimeForAdd, double aTimeForRemoveMax);

void AppController_initPerformanceMeasurement(AppController* _this);


/*********************** 정렬 안된 리스트 ***********************/
double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize);


/*********************** 정렬된 리스트 ***********************/
double AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* aList, int aTestSize);
double AppController_timeForSortedLinkedList_min(AppController* _this, SortedLinkedList* aList, int aTestSize);
double AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* aList, int aTestSize);
