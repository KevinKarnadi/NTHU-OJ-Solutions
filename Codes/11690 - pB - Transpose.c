#include <stdlib.h>
#include "function.h"

void Transpose(int* row, int* col, int matrix[][500]){
    int temp = *row;
    *row = *col;
    *col = temp;
    int big;
    if(*row > *col)
        big = *row;
    else
        big = *col;
    for(int i = 0; i < big; i++){
        for(int j = i+1; j < big; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
