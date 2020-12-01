/*
Maximun and minimum element in an array using divide and conquer.
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>



/*
    a -> array
    s -> start
    e -> end
    m -> mid
*/

int findMax(int *a, int s, int e){

    static int max = INT_MIN;

    if(s != e) {
        int m = (s + e)/2;

        findMax(a, s, m);
        findMax(a, m + 1, e);

        return max;
    }
    else {

        if(*(a + s) > max) {
            max = *(a + s);
        }
        else {
            return 0;
        }
    }
}
int findMin(int *a, int s, int e){
    static int min = INT_MAX;

    if(s != e) {
        int m = (s + e)/2;


        findMin(a, s, m);
        findMin(a, m + 1, e);


        return min;
    }
    else {

        if(*(a + s) < min) {
            min = *(a + s);
        }
        else {
            return 0;
        }
    }
}

int main(){

    int *a, n;

    printf("Enter the size of the array: ");
    scanf(" %d", &n);

    a = (int *)malloc(sizeof(int) * n);

    printf("Enter the array elements\n");
    for(int i = 0; i < n; i++) {                                                                          //taking inout of the array
        scanf(" %d", a + i);
    }


    printf("\nThe Maximum element in the array is : %d", findMax(a, 0, n - 1));

    printf("\nThe Minimum element in the array is : %d", findMin(a, 0, n - 1));

    return 0;
}

