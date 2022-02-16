#include "AppView.h"
#include <stdio.h>


Boolean AppView_In_PostfixExpression(char* s)
{
	printf("> Postfix 수식을 입력하시오 : ");
	scanf("%s", s);

	if (s[0] == '@')
		return FALSE;
	else
		return TRUE;
}

void AppView_Out_StartingMessage()
{
	printf("<<< Postfix 수식 계산을 시작합니다 >>>\n\n");

}

void AppView_Out_ErrorInExpression()
{
	printf("> 수식에 오류가 있습니다.\n");
}

void AppView_Out_EvaluatedValue(int result)
{
	printf("계산값 : %d\n\n", result);
}

void AppView_Out_EndingMessage()
{
	printf("\n<<< Postfix 수식 계산을 종료합니다 >>>\n");
}



/**************** void Postfix_showTokenAndStack 함수에서 사용하는 출력문(따로 만들었음) ***************/
void AppView_Out_CurrentTokenAndBottom(char currentToken)
{
	printf(" %c : Stack <Bottom> ", currentToken);
}

void AppView_Out_StackElement(int anElement)
{
	printf("%d ", anElement);
}

void AppView_Out_Top()
{
	printf("<Top>\n");
}

void AppView_Out_PostfixEvaluationErrorMessage(PostfixError aPostfixError)
{
	if (aPostfixError == PostfixError_ExpressionTooLong) {
		printf(ErrorMsg_ExpressionTooLong);
	}
	else if (aPostfixError == PostfixError_OperandsTooMany) {
		printf(ErrorMsg_OperandsTooMany);
	}
	else if (aPostfixError == PostfixError_OperandsTooFew) {
		printf(ErrorMsg_OperandsTooFew);
	}
	else if (aPostfixError == PostfixError_UnknownOperator) {
		printf(ErrorMsg_UndefinedOperator);
	}
	else if (aPostfixError == PostfixError_DivideByZero) {
		printf(ErrorMsg_DivideByZero);
	}
}