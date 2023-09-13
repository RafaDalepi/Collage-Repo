#include <stdio.h>
#include <stdlib.h>

#define BoardSize 8

typedef struct movements{
    int xf;
    int yf;
    int xt;
    int yt;
}MOVES;


int RookMovement(int board[BoardSize][BoardSize], MOVES move){
    if(move.xf == move.xt || move.yf == move.yt){
        if(move.xf < move.xt || move.yf < move.yt){
            for(int i = move.xf; i <= move.xt; i++){
                if(board[i][move.yf] == 0){
                    return(1);
                }else{
                    printf("\nPieces on the way\n");
                    return(0);
                }               
            }        
            for(int i = move.yf; i <= move.yt; i++){
                if(board[move.xf][i] == 0){
                    return(1);
                }else{
                    printf("\nPieces on the way\n");
                    return(0);
                }
            }
        }else{
            for(int i = move.xf; i >= move.xt; i--){
                if(board[i][move.yf] == 0){
                    return(1);
                }else{
                    printf("\nPieces on the way\n");
                    return(0);
                }               
            }        
            for(int i = move.yf; i >= move.yt; i--){
                if(board[move.xf][i] == 0){
                    return(1);
                }else{
                    printf("\nPieces on the way\n");
                    return(0);
                }
            }
        }
    }else{
        printf("\nIllegal Move\n");
        return(0);
    }
}

int HorseMovement(int board[BoardSize][BoardSize], MOVES move){
    int moveSum = BoardSize - (move.xt + move.yt);

    if(moveSum <= 4 && moveSum >= 0){
        if(board[move.xt][move.yt] == 0){
            return(1);
        }else{
            printf("\nPieces on the way\n");
            return(0);
        }
    }else{
        printf("\nIllegal Move\n");
        return(0);
    }    
}

int BishopMovement(int board[BoardSize][BoardSize], MOVES move){
    
    if(move.xf > move.yf){
        for(int i = move.xf; i <= move.xt; i++){
            for (int j = 0; j >= move.yt; j--){
                if(board[i][j] == 0){
                    return(1);
                }else{
                    printf("\nPieces on the way\n");
                    return(0);
                }   
            }            
        }
    }else{
        for(int i = move.xf; i >= move.xt; i--){
            for (int j = 0; j <= move.yt; j++){
                if(board[i][j] == 0){
                    return(1);
                }else{
                    printf("\nPieces on the way");
                    return(0);
                }   
            }            
        }
    }
}

int ValidMovement(int board[BoardSize][BoardSize],MOVES move){
    int isValid = 1;

    if(board[move.xf][move.yf] == 10 || board[move.xf][move.yf] == 11){       
        isValid = RookMovement(board, move);
    }else if(board[move.xf][move.yf] == 20 || board[move.xf][move.yf] == 21){
        isValid = HorseMovement(board, move);
    }else if(board[move.xf][move.yf] == 30 || board[move.xf][move.yf] == 31){
        isValid = BishopMovement(board, move);
    }
    
    return isValid;
}

void pieceMovement(int board[BoardSize][BoardSize], MOVES move){
    if(ValidMovement(board, move)){
        board[move.xt][move.yt] = board[move.xf][move.yf];
        board[move.xf][move.yf] = 0;
    }
}

void printBoard(int board[BoardSize][BoardSize]){
    printf("\n");
    for (int i = 0; i < BoardSize; i++){
        for (int j = 0; j < BoardSize; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");        
    }    
}

int main(){
    int gameOver = 0;
    MOVES move;
    int board[BoardSize][BoardSize] = {{10, 20, 30, 40, 50, 30, 20, 10},
                                       {8,  8,  8,  8,  8,  8,  8,  8},
                                       {0,  0,  0,  0,  0,  0,  0,  0},
                                       {0,  0,  0,  0,  0,  0,  0,  0},
                                       {0,  0,  0,  0,  0,  0,  0,  0},
                                       {0,  0,  0,  0,  0,  0,  0,  0},
                                       {9,  9,  9,  9,  9,  9,  9,  9},
                                       {11, 21, 31, 41, 51, 31, 21, 11}};
    while(!gameOver){
        printBoard(board);

        printf("\nFrom X Y: ");
        scanf("%d %d", &move.xf, &move.yf);

        printf("To X Y: ");
        scanf("%d %d", &move.xt, &move.yt);

        pieceMovement(board, move);  
        
        // system("clear");
    }    
}