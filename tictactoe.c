#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char XorO;
typedef XorO gameboard[3][3];
typedef struct move{
	int row;
	int col;
}move;

void printBoard(gameboard board){
	printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("--+---+--\n%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("--+---+--\n%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

char checkWinner(gameboard board){
	int countX = 0;
	int countO = 0;

	// check for empty board
	int count = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == 'X' || board[i][j] == 'O'){
				count++;
			}
		}
	}
	if(count == 0){
		return 'e';
	}

	// check for vertical win
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == 'X'){
				countX++;
			}else if(board[i][j] == 'O'){
				countO++;
			}
		}
		if(countX == 3){
			return 'X';
		}else if(countO == 3){
			return 'O';
		}
		countX = 0;
		countO = 0;
	}
	
	// check for horizontal win
	for(int j=0; j<3; j++){
		for(int i=0; i<3; i++){
			if(board[i][j] == 'X'){
				countX++;
			}else if(board[i][j] == 'O'){
				countO++;
			}
		}
		if(countX == 3){
			return 'X';
		}else if(countO == 3){
			return 'O';
		}
		countX = 0;
		countO = 0;
	}

	// check for diagonal win
	if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
		return 'X';
	}else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
		return 'O';
	}else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
		return 'O';
	}else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
		return 'X';
	}

	// check for draw
	count = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == 'X' || board[i][j] == 'O'){
				count++;
			}
		}
	}
	if(count == 9){
		return 'd';
	}

	return 'z';
	
}


void takeTurn(gameboard board, XorO player){

	printf("%c: ", player);
	
	char rown;
	char columnn;
	int temp = scanf(" %c %c", &rown, &columnn);
	int row = (int)(rown) - 48;
	int column = (int)(columnn) - 48;

	// the following checks that your input:
	// 		- is a number and not a letter
	// 		- is within the range of the board
	// 		- is not overwriting a space that was already taken
	if(temp != 2 || row > 2 || row < 0 || column > 2 || column < 0 || board[row][column] != '?'){
		int invalid = 0;
	
		while(invalid == 0){
			printf("invalid move\n%c: ", player);
			temp = scanf(" %c %c", &rown, &columnn);
			row = (int)(rown) - 48;
			column = (int)(columnn) - 48;
			
			if(temp == 2 && row <= 2 && row >= 0 && column <= 2 && column >= 0 && board[row][column] == '?'){
				invalid++;
			}
		}
	}
	
	board[row][column] = player;
}

int minimax(gameboard board, XorO player, int depth){

	if(checkWinner(board) == 'X'){
		return 10-depth;
	}else if(checkWinner(board) == 'O'){
		return -10+depth;
	}else if(checkWinner(board) == 'd'){
		return 0;
	}else{
	
		int score = 0;
	
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(board[i][j] == '?'){				
					board[i][j] = player;
					if(player == 'X'){
						score = minimax(board, 'O', depth+1);
						board[i][j] = '?';
					}else if(player == 'O'){
						score = minimax(board, 'X', depth+1);
						board[i][j] = '?';
					}
				}
			}
		}
		return score;
	}
	
}

move findBest(gameboard board, XorO player){

	printf("%c: ", player);

	int max = minimax(board, player, 0);
	int min = max;
	move tmove = {.row = -1, .col = -1};
	int score;

	int count = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == '?'){
				count++;
			}
		}
	}
	if(count == 9){
		printf("0 0\n");
		board[0][0] = 'O';
		return tmove;
	}

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == '?'){
				board[i][j] = 'O';
				score = minimax(board, 'X', 0);
				board[i][j] = '?';
				if(score<min){
					min = score;
					tmove.row = i;
					tmove.col = j;
				}
				board[i][j] = '?';
			}
		}
	}

	if(tmove.row == -1 && tmove.col == -1){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(board[i][j] == '?'){
					board[i][j] = 'X';
					score = minimax(board, 'O', 0);
					board[i][j] = '?';
					if(score>max){
						max = score;
						tmove.row = i;
						tmove.col = j;
					}
					board[i][j] = '?';
				}
			}
		}
	}
	
	printf("%d %d\n", tmove.row, tmove.col);
	board[tmove.row][tmove.col] = 'O';
}

void endGame(gameboard board){
	if(checkWinner(board) == 'X'){
		printf("X wins\n");
		exit(0);
	}else if(checkWinner(board) == 'O'){
		printf("O wins\n");
		exit(0);
	}else if(checkWinner(board) == 'd'){
		printf("draw\n");
		exit(0);
	}
}


int main(int argc, char **argv){

	gameboard board;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = '?';
		}
	}
			
	if(argc >=  2){
		int input = 1;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(!argv[input]){
					break;
				}
				board[i][j] = argv[input][0];
				input++;
			}
		}
				
		printBoard(board);
		endGame(board);

		findBest(board, 'O');
		
	}else if(argc == 1){		
		int round = 0;
		printBoard(board);
		
		while(round < 9){
			if(round%2==0){ //X turns
				takeTurn(board, 'X');
			}else{ //O turns
				findBest(board, 'O');
			}
			printBoard(board);
			endGame(board);
			round++;
		}
	}
}
