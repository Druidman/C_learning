#include <stdio.h>
#include <string.h>
#include <stdbool.h>


enum Result{Passed = true,Failed = false};
typedef struct{
    char question[100];
    char options[4][100];
    char answer;

} Question;

void print_question(int index);
void print_options(int index);
void print_answer(int index);
enum Result ask_question(int index);

int score = 0;
Question questions[] = {
    {"1. What year did the C language debut?:",{"A. 1969","B. 1972", "C. 1975", "D. 1999"},'B'},
    {"2. Who is credited with creating C?:",{"A. Dennis Ritchie", "B. Nikola Tesla","C. John Carmack", "D. Elon Musk"},'A'},
    {"3. What is the predecessor of C?",{"A. Objective C","B. B","C. C++","D. C#"},'B'}
    };

int main(){

    

    int number_of_questions = sizeof( questions ) / sizeof(questions[0]);


    for (int i =0; i < number_of_questions; i++){
   
        enum Result result = ask_question(i);

        switch(result){
            case Passed:
                score++;
                
                break;
        }
    }

    printf("Result of an quiz are: %d / %d\n",score,number_of_questions);

    return 0;
}

void print_question(int index){

    printf("\n%s\n",questions[index].question);
}

void print_options(int index){
    int length = sizeof(questions[index].options) / sizeof(questions[index].options[0]);
    for (int i=0; i< length; i++){
        printf("    %s\n",questions[index].options[i]);
    }
    printf("Option: ");
    
}

void print_answer(int index){
    printf("Correct answer is: %c\n",questions[index].answer);
}

enum Result ask_question(int index){
  
    char user_answer;
    

    print_question(index);
    print_options(index);
    
    scanf("%c",&user_answer);

    //buffer clearance
    char temp;
    scanf("%c",&temp); 
    //buffer cleared

    if (user_answer==questions[index].answer){
        printf("Correct!\n");
        return Passed;

    }
    else{
        printf("! WRONG !\n");
        return Failed;
    }
}

