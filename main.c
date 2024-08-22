#include <stdio.h>
#include <string.h>

struct Player{
    char name[12];
    int score;
};

int main(){

    

    struct Player player1;
    struct Player player2;

    strcpy(player1.name,"Mateusz");
    strcpy(player2.name,"Krzychu");

    printf("Player 1 name %s, PLayer 2 name %s",player1.name,player2.name);

  

    return 0;
}