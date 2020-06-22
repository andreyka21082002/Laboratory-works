//#pragma once
#ifndef XO_H
#define XO_H

namespace XO {
	enum Status {
		PLAY,
		USER_WIN,
		BOT_WIN,
		NOT_WIN
	};

	struct Game {
		char board[3][3] = {};
		bool isUserTurn;
		char userChar;
		char botChar;
		int playerScore = 0;
		int botScore = 0;
		Status status;
	};
}

	XO::Game initGame(char);
	void updateDisplay(const XO::Game);
	bool updateGame(XO::Game*);

#endif