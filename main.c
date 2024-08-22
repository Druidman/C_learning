#include <stdio.h>
#include <string.h>

typedef struct{
    char question[100];
    char options[4][100];
    char answer;

} Question;

void print_question(Question questions[],int index);
void print_options(Question questions[],int index);
void print_answer(Question questions[], int index);


int main(){

    Question questions[] = {
        {"1. What year did the C language debut?:",{"A. 1969","B. 1972", "C. 1975", "D. 1999"},'B'},
        {"2. Who is credited with creating C?:",{"A. Dennis Ritchie", "B. Nikola Tesla","C. John Carmack", "D. Elon Musk"},'A'},
        {"3. What is the predecessor of C?",{"A. Objective C","B. B","C. C++","D. C#"},'B'}
        };

    int number_of_questions = sizeof( questions ) / sizeof(questions[0]);
    int score = 0;
    print_question(questions,0);
    print_options(questions,0);
    print_answer(questions,0);

    
    

    

   

    

    return 0;
}

void print_question(Question questions[],int index){

    printf("%s\n",questions[index].question);
}

void print_options(Question questions[],int index){
    int length = sizeof(questions[index].options) / sizeof(questions[index].options[0]);
    for (int i=0; i< length; i++){
        printf("    %s\n",questions[index].options[i]);
    }
    
}

void print_answer(Question questions[], int index){
    printf("Correct answer is: %c\n",questions[index].answer);
}



