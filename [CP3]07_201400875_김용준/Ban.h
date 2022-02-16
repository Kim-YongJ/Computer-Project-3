#pragma once
#include "GradeCounter.h"

#define DEFAULT_CAPACITY 100

typedef struct _Ban Ban;

/******************  생성자, 소멸자, 속성 정보 *********************/
Ban* Ban_New(void);
Ban* Ban_NewWithCapacity(int givenCapacity);
void Ban_Delete(Ban* _this);
int Ban_Capacity(Ban* _this);
int Ban_Size(Ban* _this);
Boolean Ban_IsEmpty(Ban* _this);
Boolean Ban_IsFull(Ban* _this);
Boolean Ban_Add(Ban* _this, Student* aStudent);
Student* Ban_ElementAt(Ban* _this, int anOrder);

/****************** 학생 정보 정렬 (퀵 정렬) *********************/
void Ban_SortStudentsByScore(Ban* _this);
void Ban_QuickSortRecursively(Ban* _this, int left, int right);
int Ban_Partition(Ban* _this, int left, int right);
void Ban_QuickSort(Ban* _this);

/**************** 평균점, 최소점, 최대점 구하기 (재귀 이용) **********************/
float Ban_AverageScore(Ban* _this);
int Ban_MaxScore(Ban* _this);
int Ban_MinScore(Ban* _this);

int Ban_SumOfScoresRecursively(Ban* _this, int left, int right);
int Ban_MaxScoreRecursively(Ban* _this, int left, int right);
int Ban_MinScoreRecursively(Ban* _this, int left, int right);


/**************** 평균이상 학생수, 학점별 학생수 세기 **********************/
int Ban_NumberOfStudentsAboveAverage(Ban* _this);
GradeCounter* Ban_CountGrades(Ban* _this);




/**************** 점수 유효한지 확인, 점수에 따른 학점 반환 **********************/
Boolean Ban_ScoreIsValid(int aScore);
char Ban_ScoreToGrade(int aScore);

// 학생의 성적을 받으면, 그거를 최고점과 최저점, 평균 등 학생 성적의 전체적인 관리를 해주는 헤더