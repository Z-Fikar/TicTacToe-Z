#ifndef TTTZ_H
#define TTTZ_H
#include <iostream.h>
#include <stdlib.h>

int count;

char itoc(int number){
	if ((number == -1) || (number == -3))
		return 'X';
	else if((number == 1)||(number == 3))
		return 'O';
	else
		return '_';
}

void display(int board[9]){
	system("cls");
	cout << "\n\t  \t1\t \t2\t \t3\t \n";
	cout << "\t +--------------+---------------+---------------+\n";
	for (int i = 0 ; i < 3 ; i++){
		cout << "\t |\t \t|\t \t|\t \t|\n\t |\t \t|\t \t|\t \t|\n";
		cout << "\t" << i + 1 << "|";
		for (int j = 0; j < 3; j++)
			cout << "\t" << itoc(board[i*3 + j]) << "\t|";
		cout<<"\n\t |\t \t|\t \t|\t \t|\n\t |\t \t|\t \t|\t \t|\n";
		cout<<"\t +--------------+---------------+---------------+\n";
	}
}

void initial(int board[9]){
	count = 0;
	for (int i = 0; i < 9; i++)
		board[i] = 0;
	display(board);
}

void player(int symbol, int board[9]){
	int row, col;
	cout << "row\t: ";
	cin >> row;
	cout << "col\t: ";
	cin >> col;
	if ((board[3*row+col-4] == 0) && (row<=3) && (col<=3) && (row>0) && (col>0)){
		board[3*row+col-4] = symbol;
		count = count + 1;
		cout << " " << count << endl;
	}
	else{
		cout << "Position (" << row << "," << col << " is not available\n";
		system("pause");
		display(board);
		player(symbol, board);
	}
}

void comMove(int symbol, int board[9]){
	bool done = false, loop = true, empty = false;
	int a;
	while (loop){
		for (int i=0; i<9; i+=2){
			if (board[i] == 0){
				empty = true;
				break;
			}
		}
		a = rand() % 5;
		if (empty){
			if (board[2*a] == 0){
				board[2*a] = symbol; 
				loop = false; 
				done = true;
			}
		}
		else{
			loop = false;
		}
	}
	if (!done || !empty){
		for (int i = 1; i<8; i+=2){
			if (board[i] == 0){
				board[i] = symbol;
				break;
			}
		}
	}
}

void comFirst(int symbol, int board[9]){
	bool done = false, loop = true, empty = false;
	int a;
	do{
		a = rand() % 5;
	} while (a == 2);
	while (loop){
		for (int i=0; i<9; i+=2){
			if (i == 4) i+=2;
			if(board[i] == 0){
				empty = true;
				break;
			}
		}
		if (empty && (board[2*a] == 0)){
			board[2*a] = symbol; 
			loop = false; 
			done = true;
		}
		else
			loop = false;
	}
	if (!done || !empty)
		comMove(symbol, board);
}

void comSecond(int symbol, int board[9]){
	bool done = false, loop = true, empty = false;
	int a = rand() % 4;
	if (board[4] == 0){
		board[4] = symbol;
		done = true;
		empty = true;
	}
	while (loop && !done){
		for (int i=1; i<8; i+=2)
			if(board[i] == 0){
				empty = true;
				break;
			}
		if (empty && (board[2*a+1] == 0)){
			board[2*a+1] = symbol; 
			loop = false; 
			done = true;
		}
		else
			loop = false;
	}
	if (!done || !empty)
		comMove(symbol, board);
}

void comTactic(int symbol, int board[9], int tactic = 1){
	int row[3], col[3], diag[2], i;
	
	row[1] = board[0] + board[1] + board[2];
	row[2] = board[3] + board[4] + board[5];
	row[3] = board[6] + board[7] + board[8];
	
	col[1] = board[0] + board[3] + board[6];
	col[2] = board[1] + board[4] + board[7];
	col[3] = board[2] + board[5] + board[8];
	
	diag[1] = board[0] + board[4] + board[8];
	diag[2] = board[2] + board[4] + board[6];
	
	if (row[1] == 2*symbol*tactic){
		for (i=0; i<3; i++)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (row[2] == 2*symbol*tactic){
		for (i=3; i<6; i++)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (row[3] == 2*symbol*tactic){
		for (i=6; i<9; i++)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (col[1] == 2*symbol*tactic){
		for (i=0; i<7; i+=3)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (col[2] == 2*symbol*tactic){
		for (i=1; i<8; i+=3)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (col[3] == 2*symbol*tactic){
		for (i=2; i<9; i+=3)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (diag[1] == 2*symbol*tactic){
		for (i=0; i<9; i+=4)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else if (diag[2] == 2*symbol*tactic){
		for (i=2; i<7; i+=2)
			if (board[i] == 0)
				board[i] = symbol;
	}
	else{
		if (tactic == -1){
			if (symbol == 1) comFirst(symbol, board);
			else if (symbol == -1) comSecond(symbol, board);
			else comMove(symbol, board);
		}
		else
			comTactic(symbol, board, -tactic);
	}
}

void com(int symbol, int board[9]){
	_sleep(1000);
	comTactic(symbol, board);
	count++;
}

void pcMove(int symbol, int board[9], int poc){
	if (poc == 1){
		player(symbol, board);
	}
	else{
		com(symbol, board);
	}
}

bool checkWin(int board[9]){
	int row[3] = {0,0,0};
	int col[3] = {0,0,0};
	int diag[2];
	bool rows, cols, diags;
	
	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			row[i] += board[j+3*i];
			col[i] += board[j*3+i];
		}
	}
	diag[1] = board[0] + board[4] + board[8];
	diag[2] = board[2] + board[4] + board[6];
	
	rows = (abs(row[0]) == 3) || (abs(row[1]) == 3) || (abs(row[2]) == 3);
	cols = (abs(col[0]) == 3) || (abs(col[1]) == 3) || (abs(col[2]) == 3);
	diags = (abs(diag[1]) == 3) || (abs(diag[2]) == 3);
	
	if (rows || cols || diags)
		return true;
	else
		return false;
}

#endif
