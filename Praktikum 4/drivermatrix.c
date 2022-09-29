#include<stdio.h>
#include "matrix.c"

int main(){
    int M, N;
    Matrix matrix;
    int max, min;
    createMatrix(200, 200, &matrix);
    scanf("%d %d", &M, &N);
    readMatrix(&matrix, M, N);
    // printf("%f", AvgCol(matrix, 1));
    // MinMaxCol(matrix, 2, &max, &min);
    // printf("%d %d\n", min, max);
    RotateMat(&matrix);
    for(int i =0; i<M; i++){
        for(int j =0; j<N; j++){
            printf("%d ", ELMT(matrix, i, j));
        }
        printf("\n");
    }
    return 0;
}