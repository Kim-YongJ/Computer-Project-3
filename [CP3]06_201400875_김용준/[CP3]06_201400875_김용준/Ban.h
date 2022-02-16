#pragma once
#include "GradeCounter.h"

#define DEFAULT_CAPACITY 100

typedef struct _Ban Ban;

/******************  ������, �Ҹ���, �Ӽ� ���� *********************/
Ban* Ban_New(void);
Ban* Ban_NewWithCapacity(int givenCapacity);
void Ban_Delete(Ban* _this);
int Ban_Capacity(Ban* _this);
int Ban_Size(Ban* _this);
Boolean Ban_IsEmpty(Ban* _this);
Boolean Ban_IsFull(Ban* _this);
Boolean Ban_Add(Ban* _this, int aScore);
int Ban_ElementAt(Ban* _this, int anOrder);


/****************** �л� ���� ���� (�� ����) *********************/
void Ban_SortStudentsByScore(Ban* _this);
void Ban_QuickSortRecursively(Ban* _this, int left, int right);
int Ban_Partition(Ban* _this, int left, int right);


/**************** �����, �ּ���, �ִ��� ���ϱ� (��� �̿�) **********************/
float Ban_AverageScore(Ban* _this);
int Ban_MaxScore(Ban* _this);
int Ban_MinScore(Ban* _this);

int Ban_SumOfScoresRecursively(Ban* _this, int left, int right);
int Ban_MaxScoreRecursively(Ban* _this, int left, int right);
int Ban_MinScoreRecursively(Ban* _this, int left, int right);


/**************** ����̻� �л���, ������ �л��� ���� **********************/
int Ban_NumberOfStudentsAboveAverage(Ban* _this);
GradeCounter* Ban_CountGrades(Ban* _this);



/**************** ���� ��ȿ���� Ȯ��, ������ ���� ���� ��ȯ **********************/
Boolean Ban_ScoreIsValid(int aScore);
char Ban_ScoreToGrade(int aScore);