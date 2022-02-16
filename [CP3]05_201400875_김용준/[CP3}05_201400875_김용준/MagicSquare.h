#pragma once
#include "AppView.h"





MagicSquare* MagicSquare_New();

void MagicSquare_SetOrder(MagicSquare* aMagicSquare, int newOrder); // aMagicSquare가 소유하고 있는 마방진 객체의 차수를 newOrder의 값으로 설정한다.
int MagicSquare_Order(MagicSquare* aMagicSquare); // aMagicSquare가 소유하고 있는 마방진 객체의 차수를 얻는다
Boolean MagicSquare_OrderIsValid(MagicSquare* aMagicSquare); // aMagicSquare가 소유하고 있는 마방진 객체의 차수가 유효하면 TRUE, 아니면 FALSE를 얻는다.
void MagicSquare_Solve(MagicSquare* aMagicSquare); // aMagicSquare가 소유하고 있는 마방진 객체의 차수의 마방진을 계산한다.


int MagicSquare_Cell(MagicSquare* aMagicSquare, int aRow, int aCol);
void MagicSquare_Delete(MagicSquare* aMagicSquare);