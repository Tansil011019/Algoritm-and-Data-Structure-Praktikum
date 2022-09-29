#include <stdio.h>

int main(){
    int M, N;
    int matrix [200][200];
    scanf("%d %d", &M, &N);
    for(int i =0; i<M; i++){
        for(int j =0; j<M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    // for(int i =0; i<M; i++){
    //     for(int j =0; j<M; j++){
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    int r= 0, c= 0, count=0, max=0, max_idx, idx=0;
    for(int k=0; k<M; k++){
        if(k+N-1 < M){
            for(int l=0; l<M; l++){
                if(l+N-1 < M){
                    for(int i =r; i<N+r; i++){
                        for(int j= c; j<N+c; j++){
                            // printf("%d ", matrix[i][j]);
                            if(matrix[i][j] != 0){
                                count++;
                            }
                        }
                        // printf("\n");
                    }
                    idx++;
                }
                if(max<count){
                    max = count;
                    max_idx = idx; 
                }
                // printf("%d\n", idx);
                count =0;
                c++; 
            }
            r++;
            c=0;
        }
    }  
    printf("%d\n", max_idx);
    return 0;
}