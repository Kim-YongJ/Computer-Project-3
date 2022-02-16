#include "Timer.h"

typedef struct {
	int _row;
	int _col;
} CellLocation;

CellLocation CurrentLoc;
CellLocation NextLoc;




Boolean MagicSquare_OrderIsValid(MagicSquare* aMagicSquare)
{

	if ((* aMagicSquare)._order < 3) {
		AppView_Out("���� : �Է��� ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���� ���� �Է��Ͽ� �ֽñ� �ٶ��ϴ�. \n"); // ������ �ּ� 3�̻��� �ǰ� �˷��ִ� ��¹�
		return FALSE;
	}

	else if ((* aMagicSquare)._order > MAX_ORDER) {
		char MessageBuffer[255];
		sprintf(MessageBuffer, "���� : �Է��� ������ �ʹ� Ů�ϴ�. %d ���� ���� ���� �Է��Ͽ� �ֽñ� �ٶ��ϴ�.\n ", MAX_ORDER); // ������ 100�̻��� �Ǹ� �˷��ִ� ��¹�
		AppView_Out(MessageBuffer);
		return FALSE;
	}

	else if (((* aMagicSquare)._order % 2) == 0) {
		AppView_Out("���� : �Է��� ������ ¦���Դϴ�. Ȧ���� �Է��Ͽ� �ֽñ� �ٶ��ϴ�. \n"); // ������ Ȧ������ �Ѵٰ� �˷��ִ� ��¹�
		return FALSE;
	}

	else {
		return TRUE;
	}
}

void MagicSquare_Solve(MagicSquare* aMagicSquare) { // �ʱ�ȭ!
	for (int row = 0; row < (* aMagicSquare)._order; row++) {
		for (int col = 0; col < (* aMagicSquare)._order; col++) {
			(* aMagicSquare)._board[row][col] = EMPTY_CELL;
		}
	}

	CurrentLoc._row = 0; // 0����� ����
	CurrentLoc._col = ((* aMagicSquare)._order / 2); // ���ۿ� ����
	int CellValue = 1; // �� �Է� 1����
	(* aMagicSquare)._board[CurrentLoc._row][CurrentLoc._col] = CellValue; // ���� ��ġ�� 1�Է�
	int LastCellValue = (* aMagicSquare)._order * (* aMagicSquare)._order; // �� �Է� Order^2���� (5��� 25����)


	for (CellValue = 2; CellValue <= LastCellValue; CellValue++) { // 2���� �����Ͽ� �ϳ��� ������Ű�鼭 �Է��ϴ� �Լ�

		NextLoc._row = CurrentLoc._row - 1; // ������ ���� ���� ������ ���� �׻� 1�� ���� 
		NextLoc._col = CurrentLoc._col + 1; // ���� ���������� ��ĭ �̵�

		if (NextLoc._row < 0) { // ���� 0�ຸ�� ���� ���
			NextLoc._row = (* aMagicSquare)._order - 1; // ���� ���� �� ���ٷ� ����.
		}
		else
		{
			NextLoc._row = NextLoc._row;
		}

		if (NextLoc._col >= (* aMagicSquare)._order) { // ���� �� �������� ��� ���
			NextLoc._col = 0; // 0���� ����
		}
		else
		{
			NextLoc._col = NextLoc._col;
		}
		if ((* aMagicSquare)._board[NextLoc._row][NextLoc._col] != EMPTY_CELL) // ������, ���� ���ִ°��
		{
			NextLoc._row = CurrentLoc._row + 1; // ���� 1�߰��Ͽ� �������̵�
			NextLoc._col = CurrentLoc._col; // ���� �״�� ����
		}
		else
		{
			NextLoc._row = NextLoc._row;
			NextLoc._col = NextLoc._col;
		}
		CurrentLoc._row = NextLoc._row; // ���� ���� �����Ű��
		CurrentLoc._col = NextLoc._col;

		(* aMagicSquare)._board[CurrentLoc._row][CurrentLoc._col] = CellValue; // CellValue���� �Է�!
	}
}

void MagicSquare_SetOrder(MagicSquare* aMagicSquare, int newOrder)
{
	(* aMagicSquare)._order = newOrder;
}


int MagicSquare_Order(MagicSquare* aMagicSquare)
{
	return (* aMagicSquare)._order;
}


int MagicSquare_Cell(MagicSquare* aMagicSquare, int aRow, int aCol)
{
	if ((0 <= aRow && aRow < (* aMagicSquare)._order) &&
		(0 <= aCol && aCol < (* aMagicSquare)._order))
	{ // ��ġ�� ����
		return (* aMagicSquare)._board[aRow][aCol];
	}
	else { // ��ġ�� ���� ������ �����
		return -1;
	}
}

void MagicSquare_Delete(MagicSquare* aMagicSquare)
{
	free(aMagicSquare);
}

MagicSquare* MagicSquare_New()
{
	MagicSquare* aMagicSquare;
	aMagicSquare = NewObject(MagicSquare);
	return aMagicSquare;
}