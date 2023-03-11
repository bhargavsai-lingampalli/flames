#include<stdio.h>
#include<string.h>
void uniform(char a[],int size);
int main()
{
    int i,j,flames_check[6]= {1,1,1,1,1,1};
    int limit=5,del=1,diff,result;
    char name1[100],name2[100];
    char flames[6][15]= {"friends","lovers","attraction"
                         ,"marriage","enemies","siblings"
                        };
    printf("Enter Name1: ");
    gets(name1);
    printf("Enter Name2: ");
    gets(name2);
    uniform(name1,strlen(name1));
    uniform(name2,strlen(name2));
    diff=strlen(name1)+strlen(name2);
    for(i=0; i<strlen(name1); i++)
    {
        for(j=0; j<strlen(name2); j++)
        {
            if(name1[i]==name2[j])
            {   diff=diff-2;
                name2[j]='?'; //striking
                break;
            }
        }
    }

    for(i=0,del=1; limit>0 && diff!=0; i++)
    {
        if(flames_check[i%6]!=0 && del==diff)
        {
            flames_check[i%6]=0;
            del=1;
            limit--;
        }
        if(flames_check[i%6]!=0 && del<diff)
            del+=1;
    }

    for(i=0; i<6; i++)
    {
        if(flames_check[i]!=0)
            result=i;
    }
    printf("%s\n",flames[result]);

    return 0;
}

void uniform(char a[],int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        if(a[i]>96)
            a[i]=a[i]-32;
        if(a[i]==' ')
        {
            for(j=i; j<size; j++)
                a[j]=a[j+1];
        }
    }

}
