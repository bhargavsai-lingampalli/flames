#include<stdio.h>

int len(char*);
void uniform(char *);
int main()
{
    int i,j,flames_check[6]= {1,1,1,1,1,1};
    int striked=0,del=1,diff=0;
    char name1[100],name2[100];
    char flames[6][15]= {"friends","lovers","attraction","marriage","enemies","siblings"};

    printf("Enter Name1: ");
    scanf("%[^\n]",name1);
    printf("Enter Name2: ");
    scanf("%*c%[^\n]",name2);

    uniform(name1);
    uniform(name2);

    diff=len(name1)+len(name2);
    for(i=0; name1[i]!='\0'; i++)
    {
        for(j=0; name2[j]!='\0'; j++)
        {
            if(name1[i]==name2[j])
            {   diff-=2;
                name2[j]='?'; //striking
                break;
            }
        }
    }

    for(i=0,del=1; striked<5 && diff!=0; i++)
    {
        if(flames_check[i%6]!=0 && del==diff)
        {
            flames_check[i%6]=0;
            del=1;
            striked++;
        }
        if(flames_check[i%6]!=0 && del<diff)
            del+=1;
    }

    for(i=0; i<6; i++)
    {
        if(flames_check[i]!=0)
            printf("%s\n",flames[i]);
    }

    return 0;
}

void uniform(char *name)
{
    int i,j;
    for(i=0; name[i]!='\0'; i++)
    {
        if(name[i]>96)
            name[i]=name[i]-32;
        if(name[i]==' ')
        {
            for(j=i; name[j]!='\0'; j++)
                name[j]=name[j+1];
            i--;
        }
    }
}
int len(char *name)
{
    int c;
    for(c=0; name[c]!='\0'; c++);
    return c;
}
