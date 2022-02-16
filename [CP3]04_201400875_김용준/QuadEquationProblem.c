#include "AppView.h"

Boolean QuadEquationProblem_SecondOrderTermCoefficientIsZero(QuadEquationProblem* _this) {
	// ������ �ִ� 2���������� 2 ������ 0 ������ �Ǵ��Ͽ� �����ش�

		return FloatValueIsZero(((* _this)._equation)._c2); // ? �� ä��ÿ�
}

Boolean QuadEquationProblem_DeterminantIsNegative(QuadEquationProblem* _this) {
	// ������ �ִ� 2���������� �Ǻ����� ���� ���������� �Ǵ��Ͽ� �����ش�

	float determinant = ((*_this)._equation._c1) * ((*_this)._equation._c1) - 4 * ((*_this)._equation._c2) * ((*_this)._equation._c0); // 
	return (determinant < 0);
}

float QuadEquationProblem_Determinant(QuadEquationProblem* _this) {
	// ������ �ִ� 2���������� �Ǻ����� ���� ����Ͽ� �����ش�

	float determinant = ((*_this)._equation._c1) * ((*_this)._equation._c1) - 4 * ((*_this)._equation._c2) * ((*_this)._equation._c0); ; // 
	return determinant;
}

Solution QuadEquationProblem_Solve(QuadEquationProblem* _this) {
	// ������ �ִ� 2���������� Ǯ��, �� ����� �����ش�.

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