#include <stdio.h>
#include <string.h>


void sort(int array[], int length){

    int state = length;
    char userinput[25];
    int countt;

    for (int count = 0; count < state; count++){
        
        int temp;
        for (int i = 0; i< length-1; i++){
            if (array[i+1] < array[i]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                
            }
            countt++;
            
        }
        length-=1;
    
        
    }
    for (int i=0; i<state;i++){
        printf("%d\n",array[i]);
    }
    printf("\n This sort took %d list iterations",countt);
    
}


int main(){

    int array[] = {6,8,4,9,5,7,1,2,3,45,23,87,123,0,34};
    int length = sizeof(array) / sizeof(array[0]);


    sort(array,length);

    
    return 0;
}

