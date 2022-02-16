#include "AppController.h"

typedef struct _Ban {
	// �����̵� 162 ���� �ٸ����� �̷��� �� ��.
	int _capacity;
	int _size;
	int* _elements;
};


/******************  ������, �Ҹ���, �Ӽ� ���� *********************/

Ban* Ban_New()
{
	Ban* _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban))
	(*_this)._capacity = DEFAULT_CAPACITY; // �ִ� �л� �� ����
	(*_this)._size = 0; // ��ü�� ������ ������ �л����� 0 ��
	(*_this)._elements = NewVector(int, (*_this)._capacity); // ������ ������ �迭
	return _this;}

Ban* Ban_NewWithCapacity(int givenCapacity)
{
	Ban* _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban))
	(*_this)._capacity = givenCapacity; // �ִ� �л� �� ����
	(*_this)._size = 0; // ��ü�� ������ ������ �л����� 0 ��
	(*_this)._elements = NewVector(int, (*_this)._capacity); // ������ ������ �迭
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
	// ������ �迭�� ����
	if (Ban_IsFull(_this)) {
		return FALSE; // ���� ������ ����
	}
	else {
		// �迭�� �� ������ ��ġ�� �ִ´�.
		(*_this)._elements[(*_this)._size] = aScore;
		(*_this)._size++;
		return TRUE;
	}
}

int Ban_ElementAt(Ban* _this, int anOrder)
{
	if (anOrder >= (*_this)._size) {
		// �־��� ��ġ�� ���Ұ� �������� �ʴ´�
		return -1; // ������ �������� ������ ǥ���ϱ�� �Ѵ�
	}
	else {
		// ���Ұ� ���������� �����Ѵ�
		return ((*_this)._elements[anOrder]);
	}}



/****************** �л� ���� ���� (�� ����) *********************/

void Ban_SortStudentsByScore(Ban* _this)
{
	int size = (*_this)._size;
	// ������ �����ʹ� (*_this)._elements[0] ���� (*_this)._elements[size-1] ���� �̴�
	// �� ������ �����Ѵ�
	if (size >= 2) { // ������ 2 �̻��̸�
	// �ּҰ��� ��ġ�� ã�´�
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if ((*_this)._elements[i] < (*_this)._elements[minPosition]) {
				minPosition = i;
			}
		}
		// �ּҰ��� ���� ������ �� ������ �ű��.
		SWAP(int, (*_this)._elements[minPosition], (*_this)._elements[size - 1]);
		// ������ �����Ѵ�
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



/**************** �����, �ּ���, �ִ��� ���ϱ� (��� �̿�) **********************/

float Ban_AverageScore(Ban* _this)
{
	// ����� ����Ͽ� return ������ �����ش�.
	float sumOfScores = (float)Ban_SumOfScoresRecursively(_this, 0, (*_this)._size - 1);
	float average = sumOfScores / (float)(*_this)._size;
	return average;}


int Ban_MaxScore(Ban* _this)
{
	// �ְ����� ã�Ƽ� return ������ �����ش�.
	return Ban_MaxScoreRecursively(_this, 0, (*_this)._size - 1);
}



int Ban_MinScore(Ban* _this)
{
	// �������� ã�Ƽ� return ������ �����ش�.
	return Ban_MinScoreRecursively(_this, 0, (*_this)._size - 1);
}



int Ban_SumOfScoresRecursively(Ban* _this, int left, int right)
{
	// ���� �հ踦 ����Ͽ� return ������ �����ش�.
// ũ�⸦ (N-1)�� ���̴� ����Լ��� �ۼ��Ͻÿ�.
	if (left > right) {
		return 0;
	}
	else {
		return ((*_this)._elements[left] + Ban_SumOfScoresRecursively(_this, left + 1, right));
	}}

int Ban_MaxScoreRecursively(Ban* _this, int left, int right)
{
	// �����̵� 172 �����Ͽ� ����
	// �ְ����� ã�Ƽ� return ������ �����ش�.
	// ���⸦ ä��ÿ�. �� ���� �������� ������ ����Լ��� �ۼ��Ͻÿ�.


	// �˰����� �����̵� 45 p ����

}

int Ban_MinScoreRecursively(Ban* _this, int left, int right)
{
	// �����̵� 172 �����Ͽ� ����
	// �������� ã�Ƽ� return ������ �����ش�.
	// ���⸦ ä��ÿ�. ũ�⸦ (N-1)�� ���̴� ����Լ��� �ۼ��Ͻÿ�.


	// �˰����� �����̵� 45 p ���� - max �˰��򿡼� �ε�ȣ ���⸸ �ٲٸ��.

}

/**************** ����̻� �л���, ������ �л��� ���� **********************/
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

/**************** ���� ��ȿ���� Ȯ��, ������ ���� ���� ��ȯ **********************/

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





