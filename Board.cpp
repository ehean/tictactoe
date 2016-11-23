/*********************************************************************
** Author:			Erik Heaney
** Date:			11/23/16
** Description:		This is the class implementation file for the Board
					class. 
*********************************************************************/
#include "Board.hpp"
#include "TicTacToe.hpp"
#include <iostream>

/*********************************************************************
** Board():
** This is the constructor function. It creates an empty board by
** ititializing every element of currentBoard[][] with '.'
*********************************************************************/
Board::Board() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			currentBoard[i][j] = '.';
		}
	}
}

/*********************************************************************
** makeMove(int, int, char):
** This function takes in the board coordinates and current player as
** arguments. If the move is valid the board is updated and return true. 
** If not, print validation message and return false.
*********************************************************************/
bool Board::makeMove(int x, int y, char player) {
	// check to see if move is on the board
	if (x <= 2 && y <= 2) {
		// check to see if space is taken
		if (currentBoard[x][y] == '.') {
			currentBoard[x][y] = player;
			return true;
		}
		else {
			std::cout << "That space is taken. Choose another." << std::endl;
			return false;
		}
	}
	else {
		std::cout << "That is not a valid move." << std::endl;
		return false;
	}
}

/*********************************************************************
** gameState():
** This function tests for three different game states: x won, o won,
** or unfinished. If it's none of things, return draw.
*********************************************************************/
state Board::gameState() {


	// check if there's a win condition
	if (checkRowOrColWin('x') || checkDiagonalWin('x')) {
		return X_WON;
	}
	else if (checkRowOrColWin('o') || checkDiagonalWin('o')) {
		return O_WON;
	}

	// check to see if the game is unfinished
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (currentBoard[i][j] == '.')
				return UNFINISHED;
		}
	}

	// if none of the above, return draw
	return DRAW;
}

/*********************************************************************
** checkRowOrColWin(char):
** This function takes a char (player) as the function and checks for
** a row win or a column win.
*********************************************************************/
bool Board::checkRowOrColWin(char player) {
	// check for a column win
	for (int i = 0; i <= 2; i++) {
		if ((currentBoard[i][0] != '.') &&
			(currentBoard[i][0] == currentBoard[i][1]) &&
			(currentBoard[i][0] == currentBoard[i][2])) {
			if (currentBoard[i][0] == player) 
				return true;
		}
		// check for a row win
		else if ((currentBoard[0][i] != '.') &&
			(currentBoard[0][i] == currentBoard[1][i]) &&
			(currentBoard[0][i] == currentBoard[2][i])) {
			if (currentBoard[0][i] == player)
				return true;
		}
	}

	return false;
}

/*********************************************************************
** checkDiagonalWin(char):
** This function takes the player char as an argument and checks for a
** diagonal win.
*********************************************************************/
bool Board::checkDiagonalWin(char player) {

	// check for SW to NE (upward) diagonal win
	if ((currentBoard[1][1] != '.') &&
		(((currentBoard[0][0] == currentBoard[1][1]) &&
		(currentBoard[0][0] == currentBoard[2][2])) ||
			// check for NW to SE (downward) diagonal win
			((currentBoard[2][0] == currentBoard[1][1]) &&
			(currentBoard[2][0] == currentBoard[0][2])))) {
		if (currentBoard[1][1] == player)
			return true;
	}

	return false;
}

/*********************************************************************
** print():
** This function prints the board in the console. 
*********************************************************************/
void Board::print() {

	std::cout << "   0  1  2\n\n";
	for (int row = 0; row <= 2; row++) {
		std::cout << row << "  ";
		for (int col = 0; col <= 2; col++) {
			std::cout << currentBoard[row][col] << "  ";
		}
		std::cout << std::endl << std::endl;
	};
}