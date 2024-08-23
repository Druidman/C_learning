#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <time.h>
#include <stdlib.h>

typedef char board[3][3];

enum GameState{Middle,End,Start};
enum Winner{User = 'X',Computer = 'O',Nobody};
enum Winner winner = Nobody;

enum GameState check_game_state(board board);
void handle_user_move(board board);
void make_computer_move(board board);
void print_board(board board);
void buffer_clear();


int main(){
    board board;
    
    printf("\nWelcome to tic tac toe game!\n\nYour character is: X\nComputer character is: O\n");
    enum GameState game_state;
    do{
        
        print_board(board);
        handle_user_move(board);
        game_state = check_game_state(board);
        if (game_state == End){
            break;
        }
        make_computer_move(board);
        game_state = check_game_state(board);
        if (game_state == End){
            break;
        }
        
    }while (game_state != End);

    print_board(board);
    printf("End of the game!\n");
    switch(winner){

        case Computer:
            printf("WINNNER: Computer\n");
            break;
        case User:
            printf("WINNNER: Player\n");
            break;
        case Nobody:
            printf("DRAW\n");
            break;
            
    };
   
    return 0;
}


enum GameState check_game_state(board board){
    //full board
    bool full_board = true;
    for (int i=0; i<3; i++){

        for (int j=0; j<3; j++){
            
            if (board[i][j] == '\0'){
                full_board = false;
                break;
            }
        }
    }
    if (full_board){
        winner = Nobody;
        return End;
    }
    //rows
    for (int row =0; row < 3; row++){
        
        if (board[row][2] != '\0' && board[row][0] == board[row][2] && board[row][1]== board[row][2]){
            winner = board[row][2];
            return End;
        }       
    }
    //columns
    for (int column =0; column < 3; column++){
        
        if (board[2][column] != '\0' && board[0][column] == board[2][column] && board[1][column] == board[2][column]){
            winner = board[2][column];
            return End;
        }       
    }
    //diagonals
    if (board[2][2] != '\0' && board[0][0] == board[2][2] && board[1][1] == board[2][2]){
        winner = board[2][2];
        return End;
    }
    else if (board[2][0] != '\0' && board[0][2] == board[2][0] && board[1][1] == board[2][0]){
        winner = board[2][0];
        return End;
    }
    return Middle;
    
    
}


void print_board(board board){
    for (int i=0; i<3; i++){
        printf("\n");
        for (int j=0; j<3; j++){
            if (board[i][j] == '\0'){
                printf("_  ");
            }
            else{
                printf("%c  ", board[i][j]);
            }
        }
        
    }
    printf("\n\n");
}

void handle_user_move(board board){
    int row;
    int column;
    bool placed;
    do{
        //rows
        printf("Enter on which row you want to place your move: ");
        scanf("%d",&row);
        buffer_clear();
        printf("Enter on which column you want to place your move: ");
        scanf("%d",&column);

        if (board[row-1][column-1] == '\0'){
            board[row-1][column-1] = 'X';
            placed = true;
        }
        else{
            printf("invalid move! \n");
            placed = false;
        }
    }while (!placed);

    

}

void make_computer_move(board board){
    srand(time(0));
    int row;
    int column;

    do{
        row = rand() % 3;
        column = rand() % 3;
    }while(board[row][column] != '\0');

    board[row][column] = 'O';
}

void buffer_clear(){
    char temp;
    scanf("%c",&temp);
}