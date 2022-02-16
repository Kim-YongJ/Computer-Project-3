#pragma once
#include <stdlib.h>
#include <conio.h>
#include <string.h>



typedef enum { FALSE, TRUE } Boolean;


#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)