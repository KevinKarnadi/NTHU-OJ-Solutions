#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _AccountData {

	char* name;

	int money;

} AccountData;

AccountData* createData(char* name, int money)
{
    AccountData* temp = (AccountData*)malloc(sizeof(AccountData));
    temp->name = (char*)malloc(strlen(name)*sizeof(char));
    strcpy(temp->name, name);
    temp->money = money;
    return temp;
}

AccountData* userQuery(AccountData* data)
{
    AccountData* temp = (AccountData*)malloc(sizeof(AccountData));
    return temp;
}
