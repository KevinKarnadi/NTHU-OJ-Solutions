#include<stdio.h>
typedef struct cell
{
    int val;
    struct cell* d[4];
}cell;
int q, m, dir, val;
int rdir[4]={2,3,0,1};
cell* create(cell* prev, int dir, int val)
{
    cell* temp = (cell*)malloc(sizeof(cell));
    temp->val = val;
    temp->d[dir] = prev;
    return temp;
}
int main()
{
    cell* now = create(NULL, NULL, 0);
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &m);
        if(m == 1)
        {
            scanf("%d %d", &dir, &val);
            if(now->d[dir] == NULL)
                now->d[dir] = create(now, rdir[dir], val);
            else
                printf("Invalid\n");
        }
        else if(m == 2)
        {
            scanf("%d", &dir);
            if(now->d[dir] == NULL)
                printf("Invalid\n");
            else
                now = now->d[dir];
        }
        else if(m == 3)
        {
            scanf("%d", &val);
            now->val = val;
        }
        else if(m == 4)
            printf("%d\n", now->val);
    }
}
