#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/

Piezas::Piezas(){
	/*
	for(int i = BOARD_ROWS; i > 0; i--){
		for(int j = 0; j < BOARD_COLS; j++){
			board[i][j]; 
		}	
	}
	*/	
	board[BOARD_ROWS][BOARD_COLS];
	//board[BOARD_ROWS];
	//board2[BOARD_COLS];
	
	turn = X;
};

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset(){
	
	for(int i = BOARD_ROWS; i > 0; i--){
		for(int j = 0; j < BOARD_COLS; j++){
			board[i][j]=Blank;
		}
	}	

};

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column){
	
	int i = 0;
	if(column > 4 || column < 0){
		if(turn == X){
			turn = O;
			return Blank;
		}
		else if(turn == O){
			turn = X;
			return Blank;
		}
	}
	else{	
		do{
			if(board[i][column] == Blank){
				if(turn == X){
					board[i][column] = X;
					turn = O;
					return X;
				}
				else if(turn == O){
					board[i][column] = O;
					turn = X;
					return O;
				}
			}
			else if(board[i][column] != Blank && i < 2){
				i = i+1;
			}
			else{
				return Invalid;
					
			}
		}while(board[i][column] == Blank);
	}			
};

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column){
	if(board[row][column] == X){
		return X;
	}
	else if(board[row][column] == O){
		return O;
	}
	else if(board[row][column] == Blank){
		return Blank;
	}
	else{
		return Invalid;
	}
};
/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState(){
	
	//int X_horizontal;
	//int O_horizontal;
	int X_vert;
	int O_vert;
	int X_score;
	int O_score;
		
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
		
			if(board[i][j] == X){
				X_vert = X_vert + 1;
				if(X_vert > X_score){
					X_score = X_vert;
				}
			}
			else if(board[i][j] == O){
				O_vert = O_vert + 1;
				if(O_vert > O_score){
					O_score = O_vert;
				}
			}
		}
		X_vert = 0;
		O_vert = 0;
	}	
};





