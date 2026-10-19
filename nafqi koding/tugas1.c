#include<stdio.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("argumen yang dibutuhkan kurang misal %s %s %s\n", argv[0], "baso", "becce");
        return -1;
    }
    printf("argumen 1: %s\n", argv[0]);
    printf("argumen 2: %s\n", argv[1]);
    printf("argumen 3: %s\n", argv[2]);
    
    return 0;
}