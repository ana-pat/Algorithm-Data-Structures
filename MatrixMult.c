/*
Matrix Multiplication using naive method.
*/
#include <stdio.h>

void input(int n, int m[][n]){
    int i, j;
	printf("\nEnter elements of matrix:\n");
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			printf("Enter elements a%d%d: ", i + 1, j + 1);
			scanf("%d", &m[i][j]);
		}
	}
}

void multiplyMatrices(int n, int m1[][n], int m2[][n], int r[][n]){
    int i, j, k;

	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			r[i][j] = 0;
		}
	}

	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			for(k=0; k<n; ++k)
			{
				r[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void display(int n,int r[][n]){

    int i, j;
	printf("\nOutput :\n");
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			printf("%d  ", r[i][j]);
			if(j == n - 1)
				printf("\n\n");
		}
	}
}

int main()
{

    int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);

    int m1[n][n], m2[n][n], r[n][n], i, j, k;

        input(n, m1);
        input(n, m2);


        multiplyMatrices(n, m1, m2, r);


        display(n, r);

	return 0;
}







