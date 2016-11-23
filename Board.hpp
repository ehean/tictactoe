/*********************************************************************
** Author:			Erik Heaney
** Date:			11/23/16
** Description:		This is the class definition file for the Board class.
					The Board class includes a default constructor, makeMove,
					print, and gameState functions and the currentBoard array.			 
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

// enum of game conditions
enum state {X_WON, O_WON, DRAW, UNFINISHED};

class Board {
public:
	Board();
	bool makeMove(int x, int y, char player);
	state gameState();
	void print();
	bool checkRowOrColWin(char player);
	bool checkDiagonalWin(char player);
private:
	char currentBoard[3][3];
};

#endif // !
