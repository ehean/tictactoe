/*********************************************************************
** Author:			Erik Heaney
** Date:			11/23/16
** Description:		This is the class definition file for the TicTacToe
					class. TicTacToe contains a nested Board object.
					TicTacToe also includes the play member function,
					and the current player variable.
*********************************************************************/
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe {
public:
	TicTacToe(char firstPlayer);
	void play();
	char currentPlayer;
private:
	Board m_board;
};

#endif 
#pragma once
