#include "Student.h"

typedef struct _AppController {
	Ban* _ban;
};

/********************** AppController ��ü ������, �Ҹ��� **********************/
AppController* AppController_New(void)
{
	AppController* _this = NewObject(AppController);
	(*_this)._ban = Ban_NewWithCapacity(MAX_NUMBER_OF_STUDENTS);
	return _this;
}

void AppController_Delete(AppController* _this)
{
	Ban_Delete((*_this)._ban);
	free(_this);

}

void AppController_Run(AppController* _this)
{
	AppView_Out("<<< ���� ó���� �����մϴ� >>>\n");
	// (1) ������ �Է� �޴´�
	Boolean InputAndStoreWasSuccessful;
	InputAndStoreWasSuccessful = AppController_InputAndStoreStudents(_this);
	if (InputAndStoreWasSuccessful) {
		if (Ban_IsEmpty((*_this)._ban)) {
			AppView_Out("[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.\n");
		}
		else {
			// (2) ��հ� ��� �̻��� �л���, �ְ���, �������� ����Ѵ�.
			AppController_ShowStatistics(_this);
			// (3) ���������� ����, �׸��� �Է� ���� �л� ������ ����Ѵ�.
			Ban_SortStudentsByScore((*_this)._ban);
			AppController_ShowStudentsSortedByScore(_this);
		}
	}
	else {
		AppView_Out("[����] ������ ���������� ������� �ʾҽ��ϴ�.");
	}
	AppView_Out("\n<<< ���� ó���� �����մϴ� >>>\n");
}

/********************** ���� �Է�, ���, ���� **********************/


void AppController_ShowStatistics(AppController* _this)
{
	// �� ������ ���� ó���� ����� Ban ��ü�� ������ �ִ�
	AppView_Out_AverageScore(Ban_AverageScore((*_this)._ban));
	AppView_Out_NumberOfStudentsAboveAverage(Ban_NumberOfStudentsAboveAverage((*_this)._ban));
	AppView_Out_MaxScore(Ban_MaxScore((*_this)._ban));
	AppView_Out_MinScore(Ban_MinScore((*_this)._ban));
	// ���� �� �л����� Ban ��ü�κ��� GradeCounter ��ü ���·� ��´�
	GradeCounter* GradeCounter = Ban_CountGrades((*_this)._ban);
	AppView_Out_GradeCountFor('A', GradeCounter_NumberOfA(GradeCounter));
	AppView_Out_GradeCountFor('B', GradeCounter_NumberOfB(GradeCounter));
	AppView_Out_GradeCountFor('C', GradeCounter_NumberOfC(GradeCounter));
	AppView_Out_GradeCountFor('D', GradeCounter_NumberOfD(GradeCounter));
	AppView_Out_GradeCountFor('F', GradeCounter_NumberOfF(GradeCounter));
	GradeCounter_Delete(GradeCounter); // �� �̻� �ʿ� �����Ƿ� �Ҹ��Ų��
}

void AppController_ShowStudentsSortedByScore(AppController* _this)
{
	Student* student;
	AppView_Out_TitleForSortedStudentList();
	for (int i = 0; i < Ban_Size((*_this)._ban); i++) {
		student = Ban_ElementAt((*_this)._ban, i);
		int score = Student_Score(student);
		AppView_Out_StudentInfo
		(
			Student_StudentID(student), 
			score, 
			Ban_ScoreToGrade(score)
		);
	}
}

Boolean AppController_InputIsValid(AppController* _this, char* aStudentID, int aScore)
{
	Boolean inputIsValid = TRUE;
	if (!Student_StudentIDIsValid(aStudentID)) {
		AppView_Out_Msg_InvalidStudentID(aStudentID, MAX_STUDENT_ID_LENGTH);
		inputIsValid = FALSE;
	}
	if (!Student_ScoreIsValid(aScore)) {
		AppView_Out_Msg_InvalidScore(aScore);
		inputIsValid = FALSE;
	}
	return inputIsValid;
}

// ����� �Լ�
Boolean AppController_InputAndStoreStudents(AppController* _this)
{
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;
	char studentID[100];
	Student* student;

	while (storingAStudentWasSuccessful &&
		AppView_In_DoesContinueToInputNextStudent())
	{
		AppView_In_StudentID(studentID);
		score = AppView_In_Score();
		if (AppController_InputIsValid(_this, studentID, score)) {
			student = Student_New(studentID, score);
			storingAStudentWasSuccessful = Ban_Add((*_this)._ban, student);
		}
	}
	return storingAStudentWasSuccessful;
}
