#define swap(a, b){a^=b^=a^=b;}

void array2d_sort(int row, int col, long long arr[][500])
{
    for(int x = 0; x < col; x++)
        sort(0, x, min(col-x, row), arr);
    for(int y = 1; y < row; y++)
        sort(y, 0, min(row-y, col), arr);
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void sort(int y, int x, int len, long long arr[][500])
{
    for(int i = 0; i < len-1; i++)
        for(int j = i+1; j < len; j++)
            if(arr[y+i][x+i] > arr[y+j][x+j])
                swap(arr[y+i][x+i], arr[y+j][x+j])
}
