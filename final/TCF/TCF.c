#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check[51][51];

int area;

typedef struct
{
    char personName[51];
    char name[51];
    int age;
    char phoneNumber[21];
    int bestFriend;
    int bestFriendID;
} data;

typedef struct
{
    data people[11];
    int population;
} total;

typedef struct
{
    total origin[11];
    char personName[51];
} city;

int main()
{
    memset(check, false, sizeof(check));
    char personName[51][51];
    scanf("%d", &area);
    city ID;
    int i, j, k, l, m;
    for (i = 0; i < area; i++){
        scanf("%s", personName[i]);
        int n;
        scanf("%d", &n);
        ID.origin[i].population = n;
        for (j = 0; j < n; j++){
            strcpy(ID.origin[i].people[j].personName, personName[i]);
            scanf("%s %d %s", ID.origin[i].people[j].name, &ID.origin[i].people[j].age, ID.origin[i].people[j].phoneNumber);
        }
    }

    int entry;
    scanf("%d", &entry);
    for (i = 0; i < entry; i++){
        char x[51], y[51];
        scanf("%s %s", x, y);
        for (j = 0; j < area; j++){
            for (k = 0; k < ID.origin[j].population; k++){
                if (strcmp(x, ID.origin[j].people[k].name) == 0){
                    int p = 1;
                    for (l = 0; l < area && p == 1; l++){
                        for (m = 0; m < ID.origin[l].population && p == 1; m++){
                            if (strcmp(y, ID.origin[l].people[m].name) == 0){
                                ID.origin[j].people[k].bestFriend = l;
                                ID.origin[j].people[k].bestFriendID = m;
                                check[j][k] = true;
                                break;
                                p = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < area; i++)
    {
        printf("%s\n", personName[i]);
        for (j = 0; j < ID.origin[i].population; j++)
        {
            printf("Name: %s\n", ID.origin[i].people[j].name);
            printf("Age: %d\n", ID.origin[i].people[j].age);
            printf("Phone Number:%s\n", ID.origin[i].people[j].phoneNumber);
            if (check[i][j])
            {
                printf("His/Her bestie is: %s\n", ID.origin[ID.origin[i].people[j].bestFriend].people[ID.origin[i].people[j].bestFriendID].name);
                printf("His/Her contact info is as follows\n");
                printf("Name: %s\n", ID.origin[ID.origin[i].people[j].bestFriend].people[ID.origin[i].people[j].bestFriendID].name);
                printf("Age: %d\n", ID.origin[ID.origin[i].people[j].bestFriend].people[ID.origin[i].people[j].bestFriendID].age);
                printf("Phone Number:%s\n", ID.origin[ID.origin[i].people[j].bestFriend].people[ID.origin[i].people[j].bestFriendID].phoneNumber);
            }
            else
            {
                printf("His/Her bestie is: No one\n");
            }
        }
    }
}
