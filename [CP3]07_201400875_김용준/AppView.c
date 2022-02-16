#include "Student.h"


/****************** 입력을 위한 함수들 - AppView_in  *********************/
Boolean AppView_In_DoesContinueToInputNextStudent()
{
	printf("성적을 입력하려면 'Y'를 , 입력을 종료하려면 다른 아무 키나 치시오 : \n");
	char answer = GetcharDirectlyFromKeyboard();
	// 다음에 나오는 “Keyboard 에서 직접 문자 입력 받기” 설명을 참고하시오.
	return (answer == 'Y' || answer == 'y');
}

int AppView_In_Score()
{
	int score;
	printf("- 점수를 입력하시오 : ");
	scanf("%d", &score);
	return score;
}


// 키보드에서 입력 받는 문자 바로 인식
char GetcharDirectlyFromKeyboard()
{
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}




/****************** 출력을 위한 함수들 - AppView_out *********************/
void AppView_Out(char* aString)
{
	printf("%s", aString);
}

void AppView_Out_AverageScore(float anAverageScore)
{
	printf("평균점수는 %f입니다. \n", anAverageScore);
	// printf문 - 평균점수는 %f입니다.

}

void AppView_Out_NumberOfStudentsAboveAverage(int aNumber)
{
	printf("평균 이상인 학생은 모두 %d명 입니다. \n", aNumber);
	// printf문 - 평균 이상인 학생은 모두 %d명 입니다.

}

void AppView_Out_MaxScore(int aMaxScore)
{
	printf("최고점은 %d점 입니다. \n", aMaxScore);
	// printf문 - 최고점은 %d 점 입니다.

}

void AppView_Out_MinScore(int aMinScore)
{
	printf("최저점은 %d점 입니다. \n", aMinScore);
	// printf문 - 최저점은 %d 점 입니다.

}

void AppView_Out_GradeCountFor(char aGrade, int aCount)
{
	printf("%c 학점은 %d명 입니다. \n", aGrade, aCount);
	// printf문 - %c 학점은 %d명 입니다.

}

void AppView_Out_StudentInfo(char* aStudentID, int aScore, char aGrade)
{
	// 점수 : %d, 학점
	printf("점수 : %d  ", aScore);

	if (aScore >= 90)
		printf("학점:A\n");
	else if (aScore >= 80)
		printf("학점:B\n");
	else if (aScore >= 70)
		printf("학점:C\n");
	else if (aScore >= 60)
		printf("학점:D\n");
	else
		printf("학점:F\n");
}

void AppView_Out_Msg_InvalidStudentID(char* aStudentID, int maxLength)
{
	printf("[오류] 학번 %s 의 길이가 너무 깁니다. 최대 %d 입니다.\n",
		aStudentID, maxLength);
}
void AppView_In_StudentID(char* aStudentID)
{
	printf("- 학번을 입력하시오: ");
	scanf("%s", aStudentID);
}void AppView_Out_TitleForSortedStudentList(){
	printf("실행합니다");}int AppView_Out_Msg_InvalidScore(int aScore){}