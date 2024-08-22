#include <stdio.h>
#include <string.h>
#include <stdbool.h>


enum Bools{Yes=true,no=false};
    


int main(){

    enum Bools work_today = no;

    if (work_today){
        printf("working today");
    }
    else{
        printf("not working today");
    }

  

    return 0;
}