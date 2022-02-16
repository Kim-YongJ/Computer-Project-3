#include "Student.h"

typedef struct _Ban {
	int _capacity;
	int _size;
	Student** _elements;
	GradeCounter* _gradeCounter;
};

/******************  생성자, 소멸자, 속성 정보 *********************/

Ban* Ban_New()
{
	Ban* _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban))
	(*_this)._capacity = DEFAULT_CAPACITY; // 최대 학생 수 설정
	(*_this)._size = 0; // 객체를 생성한 직후의 학생수는 0 명
	(*_this)._elements = NewVector(Student*, (*_this)._capacity); // 성적을 저장할 배열
	return _this;
}

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
	free((*_this)._elements); // 객체 삭제
	free(_this);
}

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
	return ((*_this)._size == 0);
}

Boolean Ban_IsFull(Ban* _this)
{
	return ((*_this)._size >= (*_this)._capacity);
}

Boolean Ban_Add(Ban* _this, Student* aStudent)
{
	// 성적을 배열에 저장
	if (Ban_IsFull(_this)) {
		return FALSE; // 저장 공간이 부족
	}
	else {
		// 배열의 맨 마지막 위치에 넣는다.
		(*_this)._elements[(*_this)._size] = aStudent;
		(*_this)._size++;
		return TRUE;
	}

}

Student* Ban_ElementAt(Ban* _this, int anOrder)
{
	if (anOrder >= (*_this)._size) {
		// 주어진 위치에 원소가 존재하지 않는다
		return NULL; // 음수로 존재하지 않음을 표시하기로 한다
	}
	else {
		// 원소가 정상적으로 존재한다
		return ((*_this)._elements[anOrder]);
	}
}



/****************** 학생 정보 정렬 (퀵 정렬) *********************/

void Ban_SortStudentsByScore(Ban* _this)
{
	Ban_QuickSort(_this);
}
void Ban_QuickSort(Ban* _this)
{
	int size = (*_this)._size;
	// 정렬할 데이터는 (*_this)._elements[0] 부터 (*_this)._elements[size-1] 까지 이다
	// 퀵 정렬을 실행한다
	if (size >= 2) { // 개수가 2 이상이면
	// 최소값의 위치를 찾는다
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (Student_Score((*_this)._elements[i]) < Student_Score((*_this)._elements[minPosition]))
			{
				minPosition = i;
			}
		}
		// 최소값을 원소 구간의 맨 끝으로 옮긴다.
		SWAP(Student*, (*_this)._elements[minPosition], (*_this)._elements[size - 1]);
		// 정렬을 시작한다
		Ban_QuickSortRecursively(_this, 0, size - 2);
	}
}


void Ban_QuickSortRecursively(Ban* _this, int left, int right)
{
	if (left < right) { // 구간의 크기가 2이면
		int mid = Ban_Partition(_this, left, right); // mid 값을 설정해주고
		Ban_QuickSortRecursively(_this, left, mid - 1); 
		Ban_QuickSortRecursively(_this, mid + 1, right); // 값을 정렬해준다
	}
}



int Ban_Partition(Ban* _this, int left, int right)
{
	int pivot = left; // 시작은 왼쪽 끝
	int pivotScore = Student_Score((*_this)._elements[pivot]); // 값은 해당 pivot값
	int toLeft = right + 1;
	int toRight = left;; // 오른쪽으로 한칸씩 이동
	do {
		do { toRight++; } while (Student_Score((*_this)._elements[toRight]) > pivotScore);
		do { toLeft--; } while (Student_Score((*_this)._elements[toLeft]) < pivotScore); // 구간을 좁혀간다
		if (toRight < toLeft) { // 구간이 2이상 벌어졌으면
			SWAP(Student*, (*_this)._elements[toRight], (*_this)._elements[toLeft]); // 좌우를 바꾼다 (정렬)
		}
	} while (toRight < toLeft);
	SWAP(Student*, (*_this)._elements[pivot], (*_this)._elements[toLeft]);
	return toLeft;
}



/**************** 평균점, 최소점, 최대점 구하기 (재귀 이용) **********************/

float Ban_AverageScore(Ban* _this)
{
	// 평균을 계산하여 return 값으로 돌려준다.
	float sumOfScores = (float)Ban_SumOfScoresRecursively(_this, 0, (*_this)._size - 1);
	float average = sumOfScores / (float)(*_this)._size;
	return average;
}


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
	if (left > right) 
	{
		return 0;
	}
	else 
	{
		return (Student_Score((*_this)._elements[left]) + Ban_SumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_MaxScoreRecursively(Ban* _this, int left, int right)
{
	// 최고점을 찾아서 return 값으로 돌려준다.
	
		int maxOfSubPart;
		if (left == right)
			return Student_Score((*_this)._elements[left]);
		else {
			maxOfSubPart = Ban_MaxScoreRecursively(_this, left + 1, right);
			if (Student_Score((*_this)._elements[left]) >= maxOfSubPart) {
				return Student_Score((*_this)._elements[left]);
			}
			else {
				return maxOfSubPart;
			}
		}
}


int Ban_MinScoreRecursively(Ban* _this, int left, int right)
{
	// 최저점을 찾아서 return 값으로 돌려준다.

	int minOfSubPart;
	if (left == right)
		return Student_Score((*_this)._elements[left]);
	else {
		minOfSubPart = Ban_MinScoreRecursively(_this, left + 1, right);
		if (Student_Score((*_this)._elements[left]) <= minOfSubPart) {
			return Student_Score((*_this)._elements[left]);
		}
		else {
			return minOfSubPart;
		}
	}
}

/**************** 평균이상 학생수, 학점별 학생수 세기 **********************/
int Ban_NumberOfStudentsAboveAverage(Ban* _this)
{
	float average = Ban_AverageScore(_this);
	int numberOfStudentsAboveAverage = 0;
	for (int i = 0; i < (*_this)._size; i++) {
		if ((float)(Student_Score((*_this)._elements[i])) >= average) {
			numberOfStudentsAboveAverage = numberOfStudentsAboveAverage + 1;
		}
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_CountGrades(Ban* _this)
{
	char currentGrade;
	int score;
	GradeCounter* gradeCounter = GradeCounter_New();
	for (int i = 0; i < (*_this)._size; i++) {
		score = Student_Score((*_this)._elements[i]);
		currentGrade = Ban_ScoreToGrade(score);
		GradeCounter_Count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}

/**************** 점수 유효한지 확인, 점수에 따른 학점 반환 **********************/

Boolean Ban_ScoreIsValid(int aScore) {
	return (aScore >= 0 && aScore <= 100);
}


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





