#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDER 99
#define END_OF_RUN -1
#define EMPTY_CELL -1
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))



typedef enum { FALSE, TRUE } Boolean;

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
} MagicSquare;
MagicSquare* aMagicSquare;