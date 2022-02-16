#include "AppView.h"
#include <stdio.h>


Boolean AppView_In_PostfixExpression(char* s)
{
	printf("> Postfix ������ �Է��Ͻÿ� : ");
	scanf("%s", s);

	if (s[0] == '@')
		return FALSE;
	else
		return TRUE;
}

void AppView_Out_StartingMessage()
{
	printf("<<< Postfix ���� ����� �����մϴ� >>>\n\n");

}

void AppView_Out_ErrorInExpression()
{
	printf("> ���Ŀ� ������ �ֽ��ϴ�.\n");
}

void AppView_Out_EvaluatedValue(int result)
{
	printf("��갪 : %d\n\n", result);
}

void AppView_Out_EndingMessage()
{
	printf("\n<<< Postfix ���� ����� �����մϴ� >>>\n");
}



/**************** void Postfix_showTokenAndStack �Լ����� ����ϴ� ��¹�(���� �������) ***************/
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