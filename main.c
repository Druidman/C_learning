#include <stdio.h>
#include <string.h>

typedef int name[25];

typedef struct {
    char name[20];
    int id;
    long long password;
} Player;



int main(){

    Player player1 = {"Mateusz",1,123454354353453453};

    printf("NAME: %s\nID: %d\nPASSWORD: %lld\n",player1.name,player1.id,player1.password);

    name names = {1,2,3,4,6,8};
    
    for (int i =0; i<sizeof(names)/4; i++){
        printf("%d",names[i]);
    }

    return 0;
}