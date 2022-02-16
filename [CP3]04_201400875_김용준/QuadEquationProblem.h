#pragma once
#include "Common.h"

// “QuadEquationProblem” 와 직결된 함수들

void QuadEquationProblem_SetEquation (QuadEquationProblem* _this, QuadEquation anEquation);
// 

Boolean QuadEquationProblem_SecondOrderTermCoefficientIsZero(QuadEquationProblem* _this);
// 가지고 있는 2차방정식의 2 차항이 0 인지를 판단한다

Boolean QuadEquationProblem_DeterminantIsNegative(QuadEquationProblem* _this);
// 가지고 있는 2차방정식의 판별식의 값이 음수인지를 판단한다.

float QuadEquationProblem_Determinant(QuadEquationProblem* _this);
// 가지고 있는 2차방정식의 판별식의 값을 얻는다.

Solution QuadEquationProblem_Solve(QuadEquationProblem* _this);
// 가지고 있는 2차방정식을 풀게 하여, 해를 얻는다.