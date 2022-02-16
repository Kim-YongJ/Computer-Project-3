#pragma once
#include "Common.h"

// ��QuadEquationProblem�� �� ����� �Լ���

void QuadEquationProblem_SetEquation (QuadEquationProblem* _this, QuadEquation anEquation);
// 

Boolean QuadEquationProblem_SecondOrderTermCoefficientIsZero(QuadEquationProblem* _this);
// ������ �ִ� 2���������� 2 ������ 0 ������ �Ǵ��Ѵ�

Boolean QuadEquationProblem_DeterminantIsNegative(QuadEquationProblem* _this);
// ������ �ִ� 2���������� �Ǻ����� ���� ���������� �Ǵ��Ѵ�.

float QuadEquationProblem_Determinant(QuadEquationProblem* _this);
// ������ �ִ� 2���������� �Ǻ����� ���� ��´�.

Solution QuadEquationProblem_Solve(QuadEquationProblem* _this);
// ������ �ִ� 2���������� Ǯ�� �Ͽ�, �ظ� ��´�.