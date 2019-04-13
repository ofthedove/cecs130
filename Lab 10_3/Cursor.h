#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
	int x;
	int y;
	int z;
	
  public:
  	Cursor();
  	
  	void overlayPointer(char[3][3][3]);
  	void moveCursor(int, int, int);
  	
  	void returnCursorPos(int*, int*, int*);
};

#endif
