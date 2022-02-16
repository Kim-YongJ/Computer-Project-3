#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef enum { FALSE, TRUE } Boolean;

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define SWAP(TYPE, X, Y) {TYPE temp=X; X=Y; Y=temp;}