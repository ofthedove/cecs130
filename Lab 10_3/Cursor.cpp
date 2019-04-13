#include "Cursor.h"

Cursor::Cursor()
{
	x = 1;
	y = 1;
	z = 1;
}

void Cursor::overlayPointer(char board[3][3][3])
{
	if(board[x][y][z] == ' ') {
		board[x][y][z] = 43; }
	else {
		board[x][y][z] = 249; }
}

void Cursor::moveCursor(int dx, int dy, int dz)
{
	x += dx;
	y += dy;
	z += dz;
	
	if (x > 2) { x = 2; }
	if (x < 0) { x = 0; }
	
	if (y > 2) { y = 2; }
	if (y < 0) { y = 0; }
	
	if (z > 2) { z = 2; }
	if (z < 0) { z = 0; }
}

void Cursor::returnCursorPos(int *px, int *py, int *pz)
{
	*px = x;
	*py = y;
	*pz = z;
}
