#include "AppView.h"

void AppView_Out_Msg_StartSolvingQuadEquation() {
	printf("<<< 2�������� Ǯ�̸� �����մϴ�. >>> \n"); // 1�������� Ǯ���� ������ �˸��� ���� ����ϴ� �Լ� �� ��� �޼���
}

void AppView_Out_Msg_EndSolvingQuadEquation() {
	printf("<<< 2�������� Ǯ�̸� �����մϴ�. >>>"); // 1�������� Ǯ���� ���� �˸��� ���� ����ϴ� �Լ� �� ��� �޼���
}


void AppView_Out_QuadEquation(float c0, float c1, float c2) {
	
	Boolean aNonZeroTermDoesExist = FALSE;

	if (!FloatValueIsZero(c2)) { // ����� 0 �� ���� ������� �ʴ´�.
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x * x", c2);
	}
	if (!FloatValueIsZero(c1)) { // ����� 0 �� ���� ������� �ʴ´�.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x", c1);
	}
	if (!FloatValueIsZero(c0)) { // ����� 0 �� ���� ������� �ʴ´�.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)", c0);
	}
	if (!aNonZeroTermDoesExist) {
		printf("0"); // ��� ���� ����� 0 �̾, ��µ� ���� ����.
	}
	printf(" = 0\n");
}

void AppView_Out_Solution(float root1, float root2)
{
	printf("�־��� �������� �� x1 = %f x2 = %f\n", root1, root2); // ����� ������ �ظ� ����ϴ� �Լ� �� ��� �޼���
}
void AppView_Out_Msg_SecondOrderTermCoefficientIsZero() {
	printf("2������ ����� 0�Դϴ�. ����� �Է��� �ּ���. \n"); // 2������ ����� 0���� �Է� ���� ��, �˷��ִ� �Լ� �� ��� �޼���
}

Boolean AppView_In_SolvingIsRequested() {
	char answer;
	printf("������Ǯ�̸� �����Ϸ��� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ� : \n"); // ������Ǯ�̸� �����ϰ� �ϴ� �Լ� �� ��� �޼���
	
	char InputLine[255]; // 255���� �迭 ����
	scanf("%s", InputLine); 
	answer = InputLine[0]; // ���ڿ��� ù��° ���� �Է°����� �޴´�
	return(answer == 'y'); // %s�� �Էµ� ��Ʈ������(���ڿ�) 'return' �޴´�
}
void AppView_In_QuadEquation(float* p_c0, float* p_c1, float* p_c2) // �������� Ǯ�� ���� �ʿ��� ������� �Է¹ް� �ϴ� �Լ� �� ��� �޼���
{
	printf("2������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c2); // %f�� float���� �Է¹޴´�
	printf("1������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c1); // %f�� float���� �Է¹޴´�
	printf("������� ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c0); // %f�� float���� �Է¹޴´�
}

void AppView_Out_Msg_DeterminantIsNegative(float* _this) {
	printf("�Ǻ����� ���� 0���� �۽��ϴ�");
}


