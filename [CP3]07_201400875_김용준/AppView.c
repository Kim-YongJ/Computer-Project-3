#include "Student.h"


/****************** �Է��� ���� �Լ��� - AppView_in  *********************/
Boolean AppView_In_DoesContinueToInputNextStudent()
{
	printf("������ �Է��Ϸ��� 'Y'�� , �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ� : \n");
	char answer = GetcharDirectlyFromKeyboard();
	// ������ ������ ��Keyboard ���� ���� ���� �Է� �ޱ⡱ ������ �����Ͻÿ�.
	return (answer == 'Y' || answer == 'y');
}

int AppView_In_Score()
{
	int score;
	printf("- ������ �Է��Ͻÿ� : ");
	scanf("%d", &score);
	return score;
}


// Ű���忡�� �Է� �޴� ���� �ٷ� �ν�
char GetcharDirectlyFromKeyboard()
{
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}




/****************** ����� ���� �Լ��� - AppView_out *********************/
void AppView_Out(char* aString)
{
	printf("%s", aString);
}

void AppView_Out_AverageScore(float anAverageScore)
{
	printf("��������� %f�Դϴ�. \n", anAverageScore);
	// printf�� - ��������� %f�Դϴ�.

}

void AppView_Out_NumberOfStudentsAboveAverage(int aNumber)
{
	printf("��� �̻��� �л��� ��� %d�� �Դϴ�. \n", aNumber);
	// printf�� - ��� �̻��� �л��� ��� %d�� �Դϴ�.

}

void AppView_Out_MaxScore(int aMaxScore)
{
	printf("�ְ����� %d�� �Դϴ�. \n", aMaxScore);
	// printf�� - �ְ����� %d �� �Դϴ�.

}

void AppView_Out_MinScore(int aMinScore)
{
	printf("�������� %d�� �Դϴ�. \n", aMinScore);
	// printf�� - �������� %d �� �Դϴ�.

}

void AppView_Out_GradeCountFor(char aGrade, int aCount)
{
	printf("%c ������ %d�� �Դϴ�. \n", aGrade, aCount);
	// printf�� - %c ������ %d�� �Դϴ�.

}

void AppView_Out_StudentInfo(char* aStudentID, int aScore, char aGrade)
{
	// ���� : %d, ����
	printf("���� : %d  ", aScore);

	if (aScore >= 90)
		printf("����:A\n");
	else if (aScore >= 80)
		printf("����:B\n");
	else if (aScore >= 70)
		printf("����:C\n");
	else if (aScore >= 60)
		printf("����:D\n");
	else
		printf("����:F\n");
}

void AppView_Out_Msg_InvalidStudentID(char* aStudentID, int maxLength)
{
	printf("[����] �й� %s �� ���̰� �ʹ� ��ϴ�. �ִ� %d �Դϴ�.\n",
		aStudentID, maxLength);
}
void AppView_In_StudentID(char* aStudentID)
{
	printf("- �й��� �Է��Ͻÿ�: ");
	scanf("%s", aStudentID);
}void AppView_Out_TitleForSortedStudentList(){
	printf("�����մϴ�");}int AppView_Out_Msg_InvalidScore(int aScore){}