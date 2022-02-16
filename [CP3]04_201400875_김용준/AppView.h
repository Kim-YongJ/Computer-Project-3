#pragma once
#include "QuadEquationProblem.h"

//����Լ� ����
void AppView_Out_Msg_StartSolvingQuadEquation();
void AppView_Out_Msg_EndSolvingQuadEquation();
void AppView_Out_QuadEquation(float c0, float c1, float c2);
void AppView_Out_Solution(float root1, float root2);
void AppView_Out_Msg_SecondOrderTermCoefficientIsZero();
void AppView_Out_Msg_DeterminantIsNegative(float aDeterminant);


//�Է��Լ� ����
Boolean AppView_In_SolvingIsRequested();
void AppView_In_QuadEquation(float* p_c0, float* p_c1, float* p_c2);