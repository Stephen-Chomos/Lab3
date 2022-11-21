#include <iostream>

using namespace std;

void Queens(int N);
void printBoard(int **queenBoard, int N);
void QueenHelp(int **queenBoard, int N, int count);
bool isGoodMove(int **queenBoard, int N, int row, int column);

void Queens(int N) {
	int **queenBoard;
	queenBoard = new int *[N];
	for(int i = 0; i < N; ++i) {
		queenBoard[i] = new int[N];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			queenBoard[i][j] = 0;
		}
	}

	QueenHelp(queenBoard, N, 0);
	for (int i = 0; i < N; ++i) {
		delete[] queenBoard[i];
	}
	delete[] queenBoard;
}

void printBoard(int **queenBoard, int N) {
	int push;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			push = queenBoard[i][j];
			cout << push << " ";
		}
		cout << endl;
	}
}

void QueenHelp(int **queenBoard, int N, int count) {
	int column = count;
	for(int r = 0; r < N; ++r) {
		queenBoard[column][r] = 1;
		if (!isGoodMove(queenBoard, N, r, column)) {
			queenBoard[r][column] = 0;
		}
		else if (column == N - 1) {
			printBoard(queenBoard, N);
			exit(1);
		}
		else {
			QueenHelp(queenBoard, N, column + 1);
			queenBoard[r][column] = 0;
		}
	}
}

bool isGoodMove(int **queenBoard, int N, int row, int column) {
	if(queenBoard[row - 1][column] == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cout << "Welcome to the queens problem solver" << endl;
	cout << "Please input the number N: ";
	cin >> N;
	Queens(N);
}
