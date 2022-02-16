#include "AppView.h"

void AppView_Out_Msg_StartSolvingQuadEquation() {
	printf("<<< 2차방정식 풀이를 시작합니다. >>> \n"); // 1차방정식 풀이의 시작을 알리는 문장 출력하는 함수 및 출력 메세지
}

void AppView_Out_Msg_EndSolvingQuadEquation() {
	printf("<<< 2차방정식 풀이를 종료합니다. >>>"); // 1차방정식 풀이의 끝을 알리는 문장 출력하는 함수 및 출력 메세지
}


void AppView_Out_QuadEquation(float c0, float c1, float c2) {
	
	Boolean aNonZeroTermDoesExist = FALSE;

	if (!FloatValueIsZero(c2)) { // 계수가 0 인 항은 출력하지 않는다.
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x * x", c2);
	}
	if (!FloatValueIsZero(c1)) { // 계수가 0 인 항은 출력하지 않는다.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x", c1);
	}
	if (!FloatValueIsZero(c0)) { // 계수가 0 인 항은 출력하지 않는다.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)", c0);
	}
	if (!aNonZeroTermDoesExist) {
		printf("0"); // 모든 항의 계수가 0 이어서, 출력된 항이 없다.
	}
	printf(" = 0\n");
}

void AppView_Out_Solution(float root1, float root2)
{
	printf("주어진 방정식의 해 x1 = %f x2 = %f\n", root1, root2); // 계산을 끝내고 해를 출력하는 함수 및 출력 메세지
}
void AppView_Out_Msg_SecondOrderTermCoefficientIsZero() {
	printf("2차항의 계수가 0입니다. 제대로 입력해 주세요. \n"); // 2차항의 계수가 0으로 입력 됐을 때, 알려주는 함수 및 출력 메세지
}

Boolean AppView_In_SolvingIsRequested() {
	char answer;
	printf("방정식풀이를 시작하려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오 : \n"); // 방정식풀이를 시작하게 하는 함수 및 출력 메세지
	
	char InputLine[255]; // 255개의 배열 생성
	scanf("%s", InputLine); 
	answer = InputLine[0]; // 문자열의 첫번째 값을 입력값으로 받는다
	return(answer == 'y'); // %s로 입력된 스트링값을(문자열) 'return' 받는다
}
void AppView_In_QuadEquation(float* p_c0, float* p_c1, float* p_c2) // 방정식을 풀기 위해 필요한 계수들을 입력받게 하는 함수 및 출력 메세지
{
	printf("2차항의 계수를 입력하시오: ");
	scanf("%f", p_c2); // %f로 float값을 입력받는다
	printf("1차항의 계수를 입력하시오: ");
	scanf("%f", p_c1); // %f로 float값을 입력받는다
	printf("상수항의 계수를 입력하시오: ");
	scanf("%f", p_c0); // %f로 float값을 입력받는다
}

void AppView_Out_Msg_DeterminantIsNegative(float* _this) {
	printf("판별식의 값이 0보다 작습니다");
}


