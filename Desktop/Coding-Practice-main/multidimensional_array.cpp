#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[3][4]){
     for(int i=0; i<3; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m = 3; int n = 4;
    int** arr = (int**)malloc(sizeof(int*) * m);
    for(int i=0; i<m; ++i)
        arr[i] = (int*)malloc(sizeof(int)* n);

    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            arr[i][j] = 1;
    
    printArray(arr);
}