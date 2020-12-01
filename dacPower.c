#include<stdio.h>
#include<math.h>

int exponentdnc(int x, int n){
    static int power = 1;

    if(n != 1) {
        //1st half
        exponentdnc(x, n/2);

        //2nd half
        exponentdnc(x, (n+1)/2);

        return power;
    }
    else {
        power = power * x;
    }
}


int main() {

    int n, x;
    printf("Value of x : ");
    scanf(" %d", &x);
    printf("Value of n : ");
    scanf(" %d", &n);

    printf("\nThe value of pow(%d,%d) is %d\n", x, n, exponentdnc(x, n));

    return 0;
}
