#include "tttz.h"

int main(){
	int command;
	int board[9];
	do {
		system("cls");
		cout<<"\n--------------------------------------------\n";
		cout<<"\tTicTacToe created by Z-Fikar\n";
		cout<<"============================================\n";
		cout<<" 1. Player O vs Player X\n";
		cout<<" 2. Player O vs Com X\n";
		cout<<" 3. Com O vs Player X\n";
		cout<<" 4. Com O vs Com X\n";
		cout<<" 0. Exit\n";
		cout<<"--------------------------------------------\n";
		cout<<"Command: ";
		cin >> command;
		if ((command != 0) && (command >= 1) && (command <= 4)){
			initial(board);
			int symbol = -1;
			int poc;
			if ((command == 1) || (command == 3)) poc = 1;
			else if ((command == 2) ||(command == 4)) poc = -1;
			while ((count < 9) && !checkWin(board)){
				display(board);
				symbol = -symbol;
				cout<<" "<<itoc(symbol)<<"'s Turn\n";
				switch (command){
					case 1: pcMove(symbol, board, poc); break;
					case 2: poc = -poc; pcMove(symbol, board, poc); break;
					case 3: poc = -poc; pcMove(symbol, board, poc); break;	
					case 4:	pcMove(symbol, board, poc); break;
				}
			}
			display(board);
			cout<<endl;
			if (checkWin(board))
				cout<<itoc(symbol)<<"'s WIN!";
			else if (count == 9)
				cout<<"XO DRAW OX";
			cout<<endl;
			system("pause");
			main();
		}
		else if (command == 0) exit(1);
		else{
			cout<<"Invalid Input (0-4)\n";
			system("pause");
			main();
		}
	} while (command != 0);
	return 0;
}
