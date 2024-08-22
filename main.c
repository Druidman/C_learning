#include <stdio.h>
#include <string.h>


typedef struct{
    char name[20];
    double salary;
} Worker;


int main(){

    Worker worker1 = {"Mateusz",41.25};
    Worker worker2 = {"Kuba",35.9};
    Worker worker3 = {"Kamil",23.49};
    Worker worker4 = {"Kacper",33.75};

    Worker workers[] = {worker1,worker2,worker3,worker4};
    int length = sizeof(workers)/sizeof(workers[0]);

    for (int i=0; i< length; i++){
        printf("%s\n",workers[i].name);
        printf("%.2lf\n\n",workers[i].salary);
    }
    



    return 0;
}