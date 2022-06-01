#define min(a,b) (a<b ? a:b)

typedef struct {
	int num;
	char* name;
} Monkey;

Monkey* CreateMonkeyArray(int n)
{
    Monkey* arr=(Monkey*)calloc(n,sizeof(Monkey));
    for(int i=0;i<n;i++)
        arr[i].name=(char*)calloc(51,sizeof(char));
    return arr;
}

void SetVal(Monkey* arr, int idx, int num, char* name)
{
    arr[idx].num=num;
    strcpy(arr[idx].name,name);
}

int Compare(Monkey* arr, int a, int b)
{
    if(arr[b].num > arr[a].num)
        return 1;
    else if(arr[b].num < arr[a].num)
        return 0;
    int len=min(strlen(arr[a].name),strlen(arr[b].name));
    for(int i=0;i<len;i++)
    {
        if(arr[b].name[i] > arr[a].name[i])
            return 1;
        else if(arr[b].name[i] < arr[a].name[i])
            return 0;
    }
    return strlen(arr[b].name) > strlen(arr[a].name);
}

void Swap(Monkey* arr, int a, int b)
{
    Monkey temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void FreeMonkeyArray(Monkey* arr, int n)
{
    for(int i=0;i<n;i++)
        free(arr[i].name);
    free(arr);
}
