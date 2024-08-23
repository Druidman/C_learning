#include <stdio.h>

void printA(int a){

}


int main(){

    char a = 'x';
    char *pA = &a;

    

    printf("address of a: %p\n",pA);
    printf("value of a: %c\n",a);
    printf("value at address %c\n",*pA);

    return 0;
}


