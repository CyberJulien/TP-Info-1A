#include <stdio.h>
#include <assert.h>

double power_n(double x, int n){
    int compt = 0;
    double r=1;
    while (compt < n){
        r=r*x;
        compt=compt+1;
    }
    return(r);
}
int fact(int a){
    if (a == 1) {
        return(1);
        }

    return(a*fact(a-1));
}

double my_sin(double x,int n){
    int compt = 0;
    double sin = 0;
    while (compt<n) {
        sin = sin + (power_n(-1,compt))*((power_n(x,(2*compt+1)))/(fact((2*compt+1))));
        compt=compt+1;
    }
    assert(sin>-1);
    assert(sin<1);
    return(sin);


}




 void main(){
    double x = 0;
    int n = 0;

    scanf("%lf %d", &x, &n);

    printf("%lf \n",my_sin(x,n));


 }