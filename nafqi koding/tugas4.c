#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kali( int (*a)[4], int (*b)[1], int n ){
    int l = 0;
    for(int j = 0; j< 4; j++){
            l += a[n][j] * b[j][0]; 
    }
    return l;
}

int main(){
    srand(time(0));
    int n = 0;
    int mtrks_A[4][4];
    int mtrks_B[4][1];
    int mtrks_C[4][1];

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            mtrks_A[i][j] = (rand() % 100) + 1;
        }
    }
    for(int i = 0; i<4; i++){
        for(int j = 0; j<1; j++){
            mtrks_B[i][j] = (rand() % 100) + 1;
        }
    }

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            printf(" %d", mtrks_A[i][j]);
        }
        printf("     %d\n", mtrks_B[i][0]);
    }
    
    for(int i = 0; i<4; i++){
        for(int j = 0; j<1; j++){
            mtrks_C[i][j] = kali(mtrks_A, mtrks_B, n);
        }
        n = n + 1;
    }
    printf("\n");
    for(int i = 0; i<4; i++){
        for(int j = 0; j<1; j++){
            printf(" %d", mtrks_C[i][j]);
        }
        printf("\n");
    }
}
