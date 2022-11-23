#include <iostream>

using namespace std;

void Queens(int N);
void printBoard(int **queenBoard, int N);
void QueenHelp(int **queenBoard, int N, int count);
bool isGoodMove(int **queenBoard, int N, int row, int column);

void Queens(int N) {
	int **queenBoard;
	queenBoard = new int *[N];
	cout << "Create Board" << endl;
	for(int i = 0; i < N; ++i) {
		queenBoard[i] = new int[N];
	}
	
	cout << "Setting Board" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			queenBoard[i][j] = 0;
		}
	}
	
	printBoard(queenBoard, N);
	
	cout << "Setting Board" << endl;
	
	QueenHelp(queenBoard, N, 0);
	
	printBoard(queenBoard, N);
	cout << "Delete Board" << endl;
	for (int i = 0; i < N; ++i) {
		delete[] queenBoard[i];
	}
	delete[] queenBoard;
}

void printBoard(int **queenBoard, int N) {
	cout << "Print Board" << endl;
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
	cout << "Start" << endl;
	int column = count;
	for (int r = 0; r < N; ++r) {
		if(isGoodMove(queenBoard, N, r, column)) {
			queenBoard[r][column] = 1;
			cout << "Good Move" << endl;
		}
		else if (column == N - 1) {
			printBoard(queenBoard, N);
			cout << "Done" << endl;
			exit(1);
		}
		else {
		cout << "Recursive" << endl;
		QueenHelp(queenBoard, N, column + 1);
		queenBoard[r][column] = 0;
		}
	}
}

bool isGoodMove(int **queenBoard, int N, int row, int column) {
	for (int i = 0; i < column; ++i) {
		if (queenBoard[row][i] == 1) {
			cout << "In column" << endl;
			return false;
		}
	}
	
	for (int i = row; i > 0; --i) {
		for (int j = column; j > 0; --j) {
			if(queenBoard[i][j] == 1) {
				cout << "Bottom left" << endl;
				return false;
			}							
		}
	}
	
	for (int i = row; i < N; ++i) {
		for (int j = column; j > 0; --j) {
			if(queenBoard[i][j] == 1) {
				cout << "Bottom right" << endl;
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	int N;
	cout << "Welcome to the queens problem solver" << endl;
	cout << "Please input the number N: ";
	cin >> N;
	cout << N << endl;
	Queens(N);
}
