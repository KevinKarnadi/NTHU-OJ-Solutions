#include<stdlib.h>
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
{
    unsigned ***p3=(unsigned***)malloc(n*sizeof(unsigned**));
    unsigned **p2=(unsigned**)malloc(n*m*sizeof(unsigned*));
    unsigned *p1=(unsigned*)malloc(n*m*k*sizeof(unsigned));

    for(int i=0;i<n;i++)
    {
        *(p3+i)=p2+i*m;
        for(int j=0;j<m;j++)
        {
            *(p2+i*m+j)=p1+i*m*k+j*k;
        }
    }
    return p3;
}
void delete_3d_array(unsigned ***arr)
{
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
