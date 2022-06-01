int** s(int* ptr,int len)
{
    int sz=sqrt(len);
    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(ptr[i]>ptr[j])
            {
                int temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
        }
    }
    int k=-1;
    int m=0;
    int **res=(int**)malloc(sz*sizeof(int*));
    for(int i=0;i<len;i++)
    {
        if(i%sz==0)
        {
            k++;
            res[k]=(int*)malloc(sz*sizeof(int));
            m=0;
        }
        res[k][m]=ptr[i];
        m++;
    }
    return res;
}
