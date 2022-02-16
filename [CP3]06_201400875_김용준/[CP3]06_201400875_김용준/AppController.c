#include "AppController.h"

typedef struct _AppController {
	Ban* _ban;
};

/********************** AppController 객체 생성자, 소멸자 **********************/
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
	AppView_Out("<<< 성적 처리를 시작합니다 >>>\n");
	// (1) 성적을 입력 받는다
	Boolean InputAndStoreWasSuccessful;
	InputAndStoreWasSuccessful = AppController_InputAndStoreStudents(_this);
	if (InputAndStoreWasSuccessful) {
		if (Ban_IsEmpty((*_this)._ban)) {
			AppView_Out("[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
		}
		else {
			// (2) 평균과 평균 이상인 학생수, 최고점, 최저점을 출력한다.
			AppController_ShowStatistics(_this);
			// (3) 성적순으로 정렬, 그리고 입력 받은 학생 정보를 출력한다.
			Ban_SortStudentsByScore((*_this)._ban);
			AppController_ShowStudentsSortedByScore(_this);
		}
	}
	else {
		AppView_Out("[오류] 성적이 정상적으로 저장되지 않았습니다.");
	}
	AppView_Out("\n<<< 성적 처리를 종료합니다 >>>\n");
}


/********************** 점수 입력, 출력, 정렬 **********************/
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
			AppView_Out("[오류] 0 보다 작거나 100 보다 커서, 정상적인 점수가 아닙니다.\n");
		}
	}
	return StoringAStudentWasSuccessful;




}


void AppController_ShowStatistics(AppController* _this)
{
	// 이 시점에 성적 처리된 결과를 Ban 객체가 가지고 있다
	AppView_Out_AverageScore(Ban_AverageScore((*_this)._ban));
	AppView_Out_NumberOfStudentsAboveAverage((*_this)._ban);
	Ban_NumberOfStudentsAboveAverage((*_this)._ban);
	AppView_Out_MaxScore(Ban_MaxScore((*_this)._ban));
	AppView_Out_MinScore(Ban_MinScore((*_this)._ban));
	// 학점 별 학생수는 Ban 객체로부터 GradeCounter 객체 형태로 얻는다
	GradeCounter* GradeCounter = Ban_CountGrades((*_this)._ban);
	AppView_Out_GradeCountFor('A', GradeCounter_NumberOfA(GradeCounter));
	AppView_Out_GradeCountFor('B', GradeCounter_NumberOfB(GradeCounter));
	AppView_Out_GradeCountFor('C', GradeCounter_NumberOfC(GradeCounter));
	AppView_Out_GradeCountFor('D', GradeCounter_NumberOfD(GradeCounter));
	AppView_Out_GradeCountFor('F', GradeCounter_NumberOfF(GradeCounter));
	GradeCounter_Delete(GradeCounter); // 더 이상 필요 없으므로 소멸시킨다





}

void AppController_ShowStudentsSortedByScore(AppController* _this)
{
	AppView_Out("학생들의 성적순 목록입니다.\n");
	int score;
	char grade;
	for (int order = 0; order < Ban_Size((*_this)._ban); order++) {
		score = Ban_ElementAt((*_this)._ban, order);
		grade = Ban_ScoreToGrade(score);
		AppView_Out_StudentInfo(score, grade);
	}
}

