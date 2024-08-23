#include <stdio.h>

void delete_a_file(char name[10]){
    if(remove(name) == 0){
        printf("file was deleted succesfully!");
    }
    else{
        printf("nah");
    }
}


int main(){

    FILE *pFile = fopen("test.txt","r");
    //check for existance
    if (pFile==NULL){
        printf("file not exists");
    }
    else{

        //read multiline
        char buffer[255];
        while (fgets(buffer,255,pFile) != NULL){
            printf("%s",buffer);
        }

        fclose(pFile);
    }

    return 0;
}


