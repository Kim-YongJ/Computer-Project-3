#include <math.h>
#include "AppView.h"


void main()
{

	QuadEquationProblem qeProblem; // 객체 qeProblem 생성
	QuadEquation equation; // 갯체 equation 생성
	Solution solution; // 객체 solution 생성


	AppView_Out_Msg_StartSolvingQuadEquation(); // 시작 메시지 출력함수 호출
		
	while (AppView_In_SolvingIsRequested()) { // SolvingIsRequested 값이 true이면, 
		AppView_In_QuadEquation(&equation._c0, &equation._c1, &equation._c2); // 2차방정식을 풀기 위한 계수를 입력 받고 (3개)
		QuadEquationProblem_SetEquation(&qeProblem, equation); // 객체와 부가정보를 제공
		AppView_Out_QuadEquation(equation._c0, equation._c1, equation._c2); // 입력받은 2차방정식을 화면에 보여준다.
		
		if (QuadEquationProblem_SecondOrderTermCoefficientIsZero(&qeProblem)) { // 2차항의 계수를 판단하는 함수
			AppView_Out_Msg_SecondOrderTermCoefficientIsZero(); // 2차항의 계수가 0일때 오류라고 알려주는 메세지 출력
		}
		else {
			if (QuadEquationProblem_DeterminantIsNegative(&qeProblem)) { // 판별식의 값을 판단하는 함수
				float determinant = QuadEquationProblem_Determinant(&qeProblem); // 판별식의 값의 오류 여부를 저장
				AppView_Out_Msg_DeterminantIsNegative(determinant); // 판별식의 값이 음수이면 오류라고 알려주는 메세지 출력
			}
			else {
				solution = QuadEquationProblem_Solve(&qeProblem); // solution이라는 객체에 2차방정식 풀이의 답을 저장
				AppView_Out_Solution(solution._root1, solution._root2); // 2차방정식의 근 2개 출력
			}
		}
	}
	AppView_Out_Msg_EndSolvingQuadEquation(); // 종료 메세지 출력함수 호출
}
