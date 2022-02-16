#include "AppView.h"

Boolean QuadEquationProblem_SecondOrderTermCoefficientIsZero(QuadEquationProblem* _this) {
	// 가지고 있는 2차방정식의 2 차항이 0 인지를 판단하여 돌려준다

		return FloatValueIsZero(((* _this)._equation)._c2); // ? 를 채우시오
}

Boolean QuadEquationProblem_DeterminantIsNegative(QuadEquationProblem* _this) {
	// 가지고 있는 2차방정식의 판별식의 값이 음수인지를 판단하여 돌려준다

	float determinant = ((*_this)._equation._c1) * ((*_this)._equation._c1) - 4 * ((*_this)._equation._c2) * ((*_this)._equation._c0); // 
	return (determinant < 0);
}

float QuadEquationProblem_Determinant(QuadEquationProblem* _this) {
	// 가지고 있는 2차방정식의 판별식의 값을 계산하여 돌려준다

	float determinant = ((*_this)._equation._c1) * ((*_this)._equation._c1) - 4 * ((*_this)._equation._c2) * ((*_this)._equation._c0); ; // 
	return determinant;
}

Solution QuadEquationProblem_Solve(QuadEquationProblem* _this) {
	// 가지고 있는 2차방정식을 풀어, 그 결과를 돌려준다.

	Solution solution;
	float sqrtOfDeterminant;
		sqrtOfDeterminant = sqrt(QuadEquationProblem_Determinant(_this));

	float determinant = ((*_this)._equation._c1) * ((*_this)._equation._c1) - 4 * ((*_this)._equation._c2) * ((*_this)._equation._c0);
	
	solution._root1 = ((-1) * ((*_this)._equation._c1) + sqrt(determinant)) / 2;
	solution._root2 = ((-1) * ((*_this)._equation._c1) - sqrt(determinant)) / 2;
	
	return solution;
}

void QuadEquationProblem_SetEquation(QuadEquationProblem* _this, QuadEquation anEquation) {
	(*_this)._equation = anEquation;
}