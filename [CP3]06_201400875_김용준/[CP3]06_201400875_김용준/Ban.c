#include "AppController.h"

typedef struct _Ban {
	// 슬라이드 162 에는 다르지만 이렇게 할 것.
	int _capacity;
	int _size;
	int* _elements;
};


/******************  생성자, 소멸자, 속성 정보 *********************/

Ban* Ban_New()
{
	Ban* _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban))
	(*_this)._capacity = DEFAULT_CAPACITY; // 최대 학생 수 설정
	(*_this)._size = 0; // 객체를 생성한 직후의 학생수는 0 명
	(*_this)._elements = NewVector(int, (*_this)._capacity); // 성적을 저장할 배열
	return _this;}

Ban* Ban_NewWithCapacity(int givenCapacity)
{
	Ban* _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban))
	(*_this)._capacity = givenCapacity; // 최대 학생 수 설정
	(*_this)._size = 0; // 객체를 생성한 직후의 학생수는 0 명
	(*_this)._elements = NewVector(int, (*_this)._capacity); // 성적을 저장할 배열
	return _this;
}

void Ban_Delete(Ban* _this)
{
	free((*_this)._elements);
	free(_this);}

int Ban_Capacity(Ban* _this)
{
	return ((*_this)._capacity);

}

int Ban_Size(Ban* _this)
{
	return ((*_this)._size);
}

Boolean Ban_IsEmpty(Ban* _this)
{
	return ((*_this)._size == 0);}

Boolean Ban_IsFull(Ban* _this)
{
	return ((*_this)._size >= (*_this)._capacity);
}

Boolean Ban_Add(Ban* _this, int aScore)
{
	// 성적을 배열에 저장
	if (Ban_IsFull(_this)) {
		return FALSE; // 저장 공간이 부족
	}
	else {
		// 배열의 맨 마지막 위치에 넣는다.
		(*_this)._elements[(*_this)._size] = aScore;
		(*_this)._size++;
		return TRUE;
	}
}

int Ban_ElementAt(Ban* _this, int anOrder)
{
	if (anOrder >= (*_this)._size) {
		// 주어진 위치에 원소가 존재하지 않는다
		return -1; // 음수로 존재하지 않음을 표시하기로 한다
	}
	else {
		// 원소가 정상적으로 존재한다
		return ((*_this)._elements[anOrder]);
	}}



/****************** 학생 정보 정렬 (퀵 정렬) *********************/

void Ban_SortStudentsByScore(Ban* _this)
{
	int size = (*_this)._size;
	// 정렬할 데이터는 (*_this)._elements[0] 부터 (*_this)._elements[size-1] 까지 이다
	// 퀵 정렬을 실행한다
	if (size >= 2) { // 개수가 2 이상이면
	// 최소값의 위치를 찾는다
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if ((*_this)._elements[i] < (*_this)._elements[minPosition]) {
				minPosition = i;
			}
		}
		// 최소값을 원소 구간의 맨 끝으로 옮긴다.
		SWAP(int, (*_this)._elements[minPosition], (*_this)._elements[size - 1]);
		// 정렬을 시작한다
		Ban_QuickSortRecursively(_this, 0, size - 2);
	}
}


void Ban_QuickSortRecursively(Ban* _this, int left, int right)
{
	if (left < right) {
		int mid = Ban_Partition(_this, left, right);
		Ban_QuickSortRecursively(_this, left, mid - 1);
		Ban_QuickSortRecursively(_this, mid + 1, right);
	}
}



int Ban_Partition(Ban* _this, int left, int right)
{
	int pivot = left;
	int pivotScore = (*_this)._elements[pivot];
	right++;
	do {
		do { left++; } while ((*_this)._elements[left] > pivotScore);
		do { right--; } while ((*_this)._elements[right] < pivotScore);
		if (left < right) {
			SWAP(int, (*_this)._elements[left], (*_this)._elements[right]);
		}
	} while (left < right);
	SWAP(int, (*_this)._elements[pivot], (*_this)._elements[right]);
	return right;}



/**************** 평균점, 최소점, 최대점 구하기 (재귀 이용) **********************/

float Ban_AverageScore(Ban* _this)
{
	// 평균을 계산하여 return 값으로 돌려준다.
	float sumOfScores = (float)Ban_SumOfScoresRecursively(_this, 0, (*_this)._size - 1);
	float average = sumOfScores / (float)(*_this)._size;
	return average;}


int Ban_MaxScore(Ban* _this)
{
	// 최고점을 찾아서 return 값으로 돌려준다.
	return Ban_MaxScoreRecursively(_this, 0, (*_this)._size - 1);
}



int Ban_MinScore(Ban* _this)
{
	// 최저점을 찾아서 return 값으로 돌려준다.
	return Ban_MinScoreRecursively(_this, 0, (*_this)._size - 1);
}



int Ban_SumOfScoresRecursively(Ban* _this, int left, int right)
{
	// 성적 합계를 계산하여 return 값으로 돌려준다.
// 크기를 (N-1)로 줄이는 재귀함수로 작성하시오.
	if (left > right) {
		return 0;
	}
	else {
		return ((*_this)._elements[left] + Ban_SumOfScoresRecursively(_this, left + 1, right));
	}}

int Ban_MaxScoreRecursively(Ban* _this, int left, int right)
{
	// 슬라이드 172 참고하여 구현
	// 최고점을 찾아서 return 값으로 돌려준다.
	// 여기를 채우시오. 두 개의 구간으로 나누는 재귀함수로 작성하시오.


	// 알고리즘은 슬라이드 45 p 참고

}

int Ban_MinScoreRecursively(Ban* _this, int left, int right)
{
	// 슬라이드 172 참고하여 구현
	// 최저점을 찾아서 return 값으로 돌려준다.
	// 여기를 채우시오. 크기를 (N-1)로 줄이는 재귀함수로 작성하시오.


	// 알고리즘은 슬라이드 45 p 참고 - max 알고리즘에서 부등호 방향만 바꾸면됨.

}

/**************** 평균이상 학생수, 학점별 학생수 세기 **********************/
int Ban_NumberOfStudentsAboveAverage(Ban* _this)
{
	float average = Ban_AverageScore(_this);
	int numberOfStudentsAboveAverage = 0;
	for (int i = 0; i < (*_this)._size; i++) {
		if (((float)(*_this)._elements[i]) >= average) {
			numberOfStudentsAboveAverage++;
		}
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_CountGrades(Ban* _this)
{
	char currentGrade;
	GradeCounter* gradeCounter = GradeCounter_New();
	for (int i = 0; i < (*_this)._size; i++) {
		currentGrade = Ban_ScoreToGrade((*_this)._elements[i]);
		GradeCounter_Count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}

/**************** 점수 유효한지 확인, 점수에 따른 학점 반환 **********************/

Boolean Ban_ScoreIsValid(int aScore) {
	return (aScore >= 0 && aScore <= 100);}


char Ban_ScoreToGrade(int aScore) {
	if (aScore >= 90) {
		return 'A';
	}
	else if (aScore >= 80) {
		return 'B';
	}
	else if (aScore >= 70) {
		return 'C';
	}
	else if (aScore >= 60) {
		return 'D';
	}
	else
	{
		return 'F';
	}
}





