#include "AppController.h"

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
Boolean AppController_InputAndStoreStudents(AppController* _this)
{
	int score;
	Boolean StoringAStudentWasSuccessful = TRUE;
	while (StoringAStudentWasSuccessful &&
		AppView_In_DoesContinueToInputNextStudent())
	{
		score = AppView_In_Score();
		if (Ban_ScoreIsValid(score)) {
			StoringAStudentWasSuccessful = Ban_Add((*_this)._ban, score);
		}
		else {
			AppView_Out("[����] 0 ���� �۰ų� 100 ���� Ŀ��, �������� ������ �ƴմϴ�.\n");
		}
	}
	return StoringAStudentWasSuccessful;




}


void AppController_ShowStatistics(AppController* _this)
{
	// �� ������ ���� ó���� ����� Ban ��ü�� ������ �ִ�
	AppView_Out_AverageScore(Ban_AverageScore((*_this)._ban));
	AppView_Out_NumberOfStudentsAboveAverage((*_this)._ban);
	Ban_NumberOfStudentsAboveAverage((*_this)._ban);
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
	AppView_Out("�л����� ������ ����Դϴ�.\n");
	int score;
	char grade;
	for (int order = 0; order < Ban_Size((*_this)._ban); order++) {
		score = Ban_ElementAt((*_this)._ban, order);
		grade = Ban_ScoreToGrade(score);
		AppView_Out_StudentInfo(score, grade);
	}
}

