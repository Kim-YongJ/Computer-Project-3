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
		AppView_Out("오류 : 입력한 차수가 너무 작습니다. 3보다 크거나 같은 값을 입력하여 주시길 바랍니다. \n"); // 오더가 최소 3이상이 되게 알려주는 출력문
		return FALSE;
	}

	else if ((* aMagicSquare)._order > MAX_ORDER) {
		char MessageBuffer[255];
		sprintf(MessageBuffer, "오류 : 입력한 차수가 너무 큽니다. %d 보다 작은 값을 입력하여 주시길 바랍니다.\n ", MAX_ORDER); // 오더가 100이상이 되면 알려주는 출력문
		AppView_Out(MessageBuffer);
		return FALSE;
	}

	else if (((* aMagicSquare)._order % 2) == 0) {
		AppView_Out("오류 : 입력한 차수가 짝수입니다. 홀수를 입력하여 주시길 바랍니다. \n"); // 오더가 홀수여야 한다고 알려주는 출력문
		return FALSE;
	}

	else {
		return TRUE;
	}
}

void MagicSquare_Solve(MagicSquare* aMagicSquare) { // 초기화!
	for (int row = 0; row < (* aMagicSquare)._order; row++) {
		for (int col = 0; col < (* aMagicSquare)._order; col++) {
			(* aMagicSquare)._board[row][col] = EMPTY_CELL;
		}
	}

	CurrentLoc._row = 0; // 0행부터 시작
	CurrentLoc._col = ((* aMagicSquare)._order / 2); // 시작열 설정
	int CellValue = 1; // 값 입력 1부터
	(* aMagicSquare)._board[CurrentLoc._row][CurrentLoc._col] = CellValue; // 현재 위치에 1입력
	int LastCellValue = (* aMagicSquare)._order * (* aMagicSquare)._order; // 값 입력 Order^2까지 (5라면 25까지)


	for (CellValue = 2; CellValue <= LastCellValue; CellValue++) { // 2부터 시작하여 하나씩 증가시키면서 입력하는 함수

		NextLoc._row = CurrentLoc._row - 1; // 오른쪽 위로 가기 때문에 행은 항상 1씩 감소 
		NextLoc._col = CurrentLoc._col + 1; // 열은 오른쪽으로 한칸 이동

		if (NextLoc._row < 0) { // 행이 0행보다 위일 경우
			NextLoc._row = (* aMagicSquare)._order - 1; // 다음 행은 맨 밑줄로 간다.
		}
		else
		{
			NextLoc._row = NextLoc._row;
		}

		if (NextLoc._col >= (* aMagicSquare)._order) { // 열이 맨 오른쪽을 벗어날 경우
			NextLoc._col = 0; // 0열로 복귀
		}
		else
		{
			NextLoc._col = NextLoc._col;
		}
		if ((* aMagicSquare)._board[NextLoc._row][NextLoc._col] != EMPTY_CELL) // 다음행, 열이 차있는경우
		{
			NextLoc._row = CurrentLoc._row + 1; // 행은 1추가하여 밑으로이동
			NextLoc._col = CurrentLoc._col; // 열은 그대로 유지
		}
		else
		{
			NextLoc._row = NextLoc._row;
			NextLoc._col = NextLoc._col;
		}
		CurrentLoc._row = NextLoc._row; // 현재 값을 저장시키고
		CurrentLoc._col = NextLoc._col;

		(* aMagicSquare)._board[CurrentLoc._row][CurrentLoc._col] = CellValue; // CellValue값을 입력!
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
	{ // 위치가 정상
		return (* aMagicSquare)._board[aRow][aCol];
	}
	else { // 위치가 정상 범위를 벗어났음
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