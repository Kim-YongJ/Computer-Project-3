#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef enum { FALSE, TRUE } Boolean;

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define SWAP(TYPE, X, Y) {TYPE temp=X; X=Y; Y=temp;}
#define MAX_STUDENT_ID_LENGTH 9

typedef struct _Student Student;
typedef struct _GradeCounter GradeCounter;
typedef struct _Ban Ban;
typedef struct _AppController AppController;
// 코드 전체를 관리해주는 헤더