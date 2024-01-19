 #include <stdio.h>




int sum_two_num(int a,int b) {
    
    return(a+b);

}
 
 void main(){
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);
    

    printf( "%d \n", sum_two_num(a,b));

 }