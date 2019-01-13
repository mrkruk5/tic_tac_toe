#include <iostream>
bool quit = false;
char b[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
bool p1 = true; // true = p1, false = p2
int p1_input;
int p2_input;

void printBoard() {
	for (int i = 0; i < 9; i++) {
		if ((i + 1) != 9 && (i + 1) % 3 == 0) {
			std::cout << ::b[i] << std::endl;
			for (int j = 0; j < 3; j++) {
				std::cout << "- ";
			}
			std::cout << std::endl;
		} else {
			if (i != 8) {
				std::cout << ::b[i] << "|";
			} else {
				std::cout << ::b[i];
			}

		}
	}
	std::cout << std::endl;
}

bool win() {
	if (::b[0] != ' ' && ::b[1] != ' ' && ::b[2] != ' ' && ::b[0] == ::b[1] && ::b[1] == ::b[2]) {
		return true;
	} else if (::b[3] != ' ' && ::b[4] != ' ' && ::b[5] != ' ' && ::b[3] == ::b[4] && ::b[4] == ::b[5]) {
		return true;
	} else if (::b[6] != ' ' && ::b[7] != ' ' && ::b[8] != ' ' && ::b[6] == ::b[7] && ::b[7] == ::b[8]) {
		return true;
	} else if (::b[0] != ' ' && ::b[3] != ' ' && ::b[6] != ' ' && ::b[0] == ::b[3] && ::b[3] == ::b[6]) {
		return true;
	} else if (::b[1] != ' ' && ::b[4] != ' ' && ::b[7] != ' ' && ::b[1] == ::b[4] && ::b[4] == ::b[7]) {
		return true;
	} else if (::b[2] != ' ' && ::b[5] != ' ' && ::b[8] != ' ' && ::b[2] == ::b[5] && ::b[5] == ::b[8]) {
		return true;
	} else if (::b[0] != ' ' && ::b[4] != ' ' && ::b[8] != ' ' && ::b[0] == ::b[4] && ::b[4] == ::b[8]) {
		return true;
	} else if (::b[2] != ' ' && ::b[4] != ' ' && ::b[6] != ' ' && ::b[2] == ::b[4] && ::b[4] == ::b[6]) {
		return true;
	} else {
		return false;
	}
}

bool full() {
	for (int i = 0; i < 9; i++) {
		if (::b[i] == ' ') {
			return false;
		}
	}
	return true;
}

bool validMove(int i) {
	if (0 <= i && i < 9) {
		if (::b[i] == ' ') {
			return true;
		} else {
			std::cout << "There's already an " << ::b[i] << " there!" << std::endl;
			return false;
		}
	} else {
		std::cout << "Enter a number between 0 and 8 (inclusive)" << std::endl;
		return false;
	}

}

void userInput() {
	if (::p1) {
		std::cout << "Player 1: Where do you want to place your x on the board?";
		std::cin >> ::p1_input;
	} else {
		std::cout << "Player 2: Where do you want to place your o on the board?";
		std::cin >> p2_input;
	}
}

void simulate() {
	if (p1) {
		if (validMove(::p1_input)) {
			::b[::p1_input] = 'x';
			::p1 = false;
			if (win()) {
				std::cout << "Congratulations, Player 1 wins!" << std::endl;
				printBoard();
				::quit = true;
			}
		}
	} else {
		if (validMove(::p2_input)) {
			::b[::p2_input] = 'o';
			::p1 = true;
			if (win()) {
				std::cout << "Congratulations, Player 2 wins!" << std::endl;
				printBoard();
				::quit = true;
			}
		}
	}
	if (!win() && full()) {
		std::cout << "Game Over, the board is full and nobody won." << std::endl;
		printBoard();
		::quit = true;
	}
}

int main() {
	while (!quit) {
		printBoard();
		userInput();
		simulate();
	}
}