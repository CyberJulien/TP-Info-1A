#include <stdio.h>

int fact(int a){
    if (a == 1) {
        return(1);
        }

    return(a*fact(a-1));

}
 void main(){
    int a = 0;
    int b = 0;

    scanf("%d", &a);

    printf(" %d \n",fact(a));


 }