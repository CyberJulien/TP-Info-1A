#include <stdio.h>

double power_n(double x, int n){
    int compt = 0;
    double r=1;
    while (compt < n){
        r=r*x;
        compt=compt+1;
    }
    return(r);
}
 void main(){
    double a = 0;
    int b = 0;

    scanf("%lf %d", &a, &b);

    printf(" %lf \n",power_n(a,b));


 }