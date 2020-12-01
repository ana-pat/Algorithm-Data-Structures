import java.util.*;


public class MatrixMultiplication{
    
    public static int[][] add(int[][] A, int[][] B){
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }

    public static void split(int[][] P, int[][] C, int iB, int jB){
        for(int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for(int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                C[i1][j1] = P[i2][j2];
    }

    
    public static void join(int[][] C, int[][] P, int iB, int jB){
        for(int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for(int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
    }
    public static int[][] matrixMult(int[][] A,int[][] B)
    {
        int n = A[0].length;
        int[][] R = new int[n][n];
        if(n == 1)
        {
            R[0][0] = A[0][0]*B[0][0];
        } 
        else
        {
            int[][] A11 = new int[n/2][n/2];
            int[][] A12 = new int[n/2][n/2];
            int[][] A21 = new int[n/2][n/2];
            int[][] A22 = new int[n/2][n/2];
            int[][] B11 = new int[n/2][n/2];
            int[][] B12 = new int[n/2][n/2];
            int[][] B21 = new int[n/2][n/2];
            int[][] B22 = new int[n/2][n/2];

            split(A, A11, 0 , 0);
            split(A, A12, 0 , n/2);
            split(A, A21, n/2, 0);
            split(A, A22, n/2, n/2);
            
            
            split(B, B11, 0 , 0);
            split(B, B12, 0 , n/2);
            split(B, B21, n/2, 0);
            split(B, B22, n/2, n/2);


            int [][] C11 = add(matrixMult(A11,B11),matrixMult(A12,B21));
            int [][] C12 = add(matrixMult(A11,B12),matrixMult(A12,B22));
            int [][] C21 = add(matrixMult(A21,B11),matrixMult(A22,B21));
            int [][] C22 = add(matrixMult(A21,B12),matrixMult(A22,B22));

            join(C11, R, 0 , 0);
            join(C12, R, 0 , n/2);
            join(C21, R, n/2, 0);
            join(C22, R, n/2, n/2);
        }
        return R;
    }



    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        
        System.out.println("!!CAUTION!!\nEnter n in the form of 2^n");
        System.out.println("Enter the size of array:");       
        int n = input.nextInt();

        int[][] a = new int[n][n];
        int[][] b = new int[n][n];
        int[][] c = new int[n][n];

        System.out.println("Enter the elements of the first matrix:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print("a["+ i + "][" + j + "] = ");
                a[i][j] = input.nextInt();
            }
        }
        
        System.out.println("Enter the elements of the second matrix:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print("b[" + i + "][" + j + "] = ");
                b[i][j] = input.nextInt();
            }
        }

        c = matrixMult(a,b);
        System.out.println("\nProduct of matrices A and  B : ");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                System.out.print(c[i][j] +" ");
            System.out.println();
        }
        input.close();
    }

    
   
    


}
