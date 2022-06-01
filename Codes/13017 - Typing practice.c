#include<stdio.h>
#include<string.h>
char x[500005];
char inp[5];
int len=0;
int ctr=0;
int flag=1;
int main()
{
    fgets(x,500005,stdin);
    while(fgets(inp,5,stdin))
    {
        if(inp[0]=='\\')
        {
            if(len>0)
            {
                if(flag==1)
                {
                    len--;
                    ctr--;
                }
                else
                    len--;
                if(ctr==len)
                    flag=1;
            }
        }
        else if(flag==0)
            len++;
        else if(flag==1)
        {
            len++;
            if(inp[0]!='\n')
            {
                if(inp[0]==x[ctr])
                    ctr++;
                else
                    flag=0;
            }
            else if(inp[0]=='\n')
            {
                if(x[ctr]==' ')
                    ctr++;
                else
                    flag=0;
            }
        }
        printf("%d\n",flag);
    }
    if(flag && len>0)
        printf("Correct\n");
    else
        printf("Incorrect\n");
}
