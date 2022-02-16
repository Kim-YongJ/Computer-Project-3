#pragma once

#define C1_LinearEquation_Common_h
#define MAXFLOAT 1.0E+100 // only for Windows
#define EPSILON 1.0E-6 // EPSILON값 정의
#define FloatValueIsZero(NUMBER)  (fabsf(NUMBER) < EPSILON)

#include <math.h>
#include <stdio.h>
typedef enum { FALSE, TRUE } Boolean; // 논리값 정의하는 과정

typedef struct {
	float _c0;
	float _c1;
	float _c2;
} QuadEquation;

typedef struct {
	float _root1;
	float _root2;
} Solution;


// QuadEquationProblem 의 자료형 정의
typedef struct {
	QuadEquation _equation;
} QuadEquationProblem;


