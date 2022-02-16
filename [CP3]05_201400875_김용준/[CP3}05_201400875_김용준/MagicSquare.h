#pragma once
#include "AppView.h"





MagicSquare* MagicSquare_New();

void MagicSquare_SetOrder(MagicSquare* aMagicSquare, int newOrder); // aMagicSquare�� �����ϰ� �ִ� ������ ��ü�� ������ newOrder�� ������ �����Ѵ�.
int MagicSquare_Order(MagicSquare* aMagicSquare); // aMagicSquare�� �����ϰ� �ִ� ������ ��ü�� ������ ��´�
Boolean MagicSquare_OrderIsValid(MagicSquare* aMagicSquare); // aMagicSquare�� �����ϰ� �ִ� ������ ��ü�� ������ ��ȿ�ϸ� TRUE, �ƴϸ� FALSE�� ��´�.
void MagicSquare_Solve(MagicSquare* aMagicSquare); // aMagicSquare�� �����ϰ� �ִ� ������ ��ü�� ������ �������� ����Ѵ�.


int MagicSquare_Cell(MagicSquare* aMagicSquare, int aRow, int aCol);
void MagicSquare_Delete(MagicSquare* aMagicSquare);