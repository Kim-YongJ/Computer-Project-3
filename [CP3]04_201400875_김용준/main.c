#include <math.h>
#include "AppView.h"


void main()
{

	QuadEquationProblem qeProblem; // ��ü qeProblem ����
	QuadEquation equation; // ��ü equation ����
	Solution solution; // ��ü solution ����


	AppView_Out_Msg_StartSolvingQuadEquation(); // ���� �޽��� ����Լ� ȣ��
		
	while (AppView_In_SolvingIsRequested()) { // SolvingIsRequested ���� true�̸�, 
		AppView_In_QuadEquation(&equation._c0, &equation._c1, &equation._c2); // 2���������� Ǯ�� ���� ����� �Է� �ް� (3��)
		QuadEquationProblem_SetEquation(&qeProblem, equation); // ��ü�� �ΰ������� ����
		AppView_Out_QuadEquation(equation._c0, equation._c1, equation._c2); // �Է¹��� 2���������� ȭ�鿡 �����ش�.
		
		if (QuadEquationProblem_SecondOrderTermCoefficientIsZero(&qeProblem)) { // 2������ ����� �Ǵ��ϴ� �Լ�
			AppView_Out_Msg_SecondOrderTermCoefficientIsZero(); // 2������ ����� 0�϶� ������� �˷��ִ� �޼��� ���
		}
		else {
			if (QuadEquationProblem_DeterminantIsNegative(&qeProblem)) { // �Ǻ����� ���� �Ǵ��ϴ� �Լ�
				float determinant = QuadEquationProblem_Determinant(&qeProblem); // �Ǻ����� ���� ���� ���θ� ����
				AppView_Out_Msg_DeterminantIsNegative(determinant); // �Ǻ����� ���� �����̸� ������� �˷��ִ� �޼��� ���
			}
			else {
				solution = QuadEquationProblem_Solve(&qeProblem); // solution�̶�� ��ü�� 2�������� Ǯ���� ���� ����
				AppView_Out_Solution(solution._root1, solution._root2); // 2���������� �� 2�� ���
			}
		}
	}
	AppView_Out_Msg_EndSolvingQuadEquation(); // ���� �޼��� ����Լ� ȣ��
}
