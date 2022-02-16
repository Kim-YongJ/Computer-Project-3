#include "AppController.h"
#include "Postfix.h"
#include "AppView.h"
#include "Stack.h"

#define MAX_NUMBER_OF_TOKENS 200


struct _AppController
{
	char _expression[MAX_NUMBER_OF_TOKENS];
	Postfix* _postfix;
};

AppController* AppController_New(void)
{
	AppController* _this = NewObject(AppController);
	(*_this)._postfix = Postfix_New(MAX_NUMBER_OF_TOKENS);

	return _this;
}

void AppController_Delete(AppController* _this)
{
	free(_this);

}


void AppController_Run(AppController* _this)
{
	Boolean expressionIsAvailable, noErrorIsInEvaluation;
	PostfixError evaluationError;
	AppView_Out_StartingMessage();

	(*_this)._postfix = Postfix_New(MAX_NUMBER_OF_TOKENS);
	expressionIsAvailable = AppView_In_PostfixExpression((*_this)._expression);

	while (expressionIsAvailable) {
		Postfix_SetExpression((*_this)._postfix, (*_this)._expression);
		evaluationError = Postfix_Evaluate((*_this)._expression);
	if (evaluationError == PostfixError_None) {
		AppView_Out_EvaluatedValue(Postfix_EvaluatedValue((*_this)._postfix));
	}
	else {
		AppView_Out_PostfixEvaluationErrorMessage(evaluationError);
	}
		expressionIsAvailable = AppView_In_PostfixExpression((*_this)._expression);
	}
	Postfix_Delete((*_this)._postfix);
	AppView_Out_EndingMessage();
}
