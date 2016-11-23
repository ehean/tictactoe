
/*********************************************************************
** Author:			Erik Heaney
** Date:			11/23/16
** Description:		This is the class implementation file for the 
					TicTacToe class. It also includes the main function,
					which queries the user for the first user and initializes
					a TicTacToe instance and calls the play member function.
*********************************************************************/

#include "Board.hpp"
#include "TicTacToe.hpp"
#include <iostream>

/*********************************************************************
** main():
** The main function queries the user for the first player (x or o),
** initializes a TicTacToe object, and calls the play() member function.
*********************************************************************/
int main() {
	char first;

	std::cout << "Who goes first?" << std::endl;
	std::cin >> first;

	TicTacToe game(first);
	game.play();
}

/*********************************************************************
** TicTacToe(char):
** This is the constructor. It takes a char as the argument and
** initializes the currentPlayer variable.
*********************************************************************/
TicTacToe::TicTacToe(char first) {
	currentPlayer = first;
}

/*********************************************************************
** play():
** This is a member function of the TicTacToe class. It asks the current
** player to enter their move, validates their move, and checks for a 
** win condition (x wins, o wins, or draw).
*********************************************************************/
void TicTacToe::play() {

	// do while game is in unfinished state
	do {
		int row, col;

		// ask current player to move	
		std::cout << "Player " << currentPlayer << ": please enter your move.\n";
		std::cin >> row >> col;

		// if move is valid, switch players
		if (m_board.makeMove(row, col, currentPlayer)) {
			if (currentPlayer == 'o') {
				currentPlayer = 'x';
			}
			else
				currentPlayer = 'o';
		}
		m_board.print();
	} while (m_board.gameState() == UNFINISHED);

	// check game outcome to see if x won, o own, or draw
	if (m_board.gameState() == X_WON) {
		std::cout << "x won" << std::endl;
	}
	else if (m_board.gameState() == O_WON) {
		std::cout << "o won" << std::endl;
	}
	else
		std::cout << "Draw" << std::endl;
}