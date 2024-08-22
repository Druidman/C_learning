#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>



enum Guess{lower=0,higher=1,equal=2};

enum Guess check_guess(int guess, int answer);

int random_num(int min,int max);

    
int main(){
    
    const int MIN = 1;
    const int MAX = 100;
    int answer = random_num(MIN,MAX);

    int guess;
    int guesses;
    bool game = true;

    do{
        printf("Take a guess: ");
        scanf("%d",&guess);
        enum Guess check = check_guess(guess,answer);
        guesses++;

        switch(check){
            case lower:
                printf("Too low...\n");
                break;
            case higher:
                printf("Too high...\n");
                break;
            case equal:
                printf("Answer is %d\n",answer);
                printf("Congrats!\n");
                printf("it took %d guesses\n",guesses);
                game = false;
                break;
            default:
                game = false;
        };
    }while(game);

    return 0;
}

int random_num(int min,int max){

    srand(time(0));

    return (rand() % max) + min;

}

enum Guess check_guess(int guess,int answer){
    
    if (guess> answer){
        
        return higher;
    }
    else if(guess < answer){
        
        return lower;
    }
    else{
       
        return equal;
    }
}