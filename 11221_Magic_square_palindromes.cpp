#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<ctype.h>
using namespace std;

string s,str;
char g[110][110];
int sz;
void print()
{
    int i,j;
    for(i=0;i<sz;i++)
    {
        for(j=0;j<sz;j++)
        printf("%c",g[i][j]);
        printf("\n");
    }
}
bool is_palindrom()
{
    int i,j;
    for(i=0,j=sz*sz-1;i<=j;i++,j--)
    if(str[i]!=str[j])
    return false;

    return true;
}
bool p1()
{
    int i,j;
    str="";
    for(i=0;i<sz;i++)
    for(j=0;j<sz;j++)
    str+=g[i][j];

    if(is_palindrom())
    return true;
    else
    return false;

}

bool p2()
{
    int i,j;
    str="";
    for(i=0;i<sz;i++)
    for(j=0;j<sz;j++)
    str+=g[j][i];

    if(is_palindrom())
    return true;
    else
    return false;

}

bool p3()
{
    int i,j;
    str="";
    for(i=sz-1;i>=0;i--)
    for(j=sz-1;j>=0;j--)
    str+=g[i][j];

    if(is_palindrom())
    return true;
    else
    return false;

}

bool p4()
{
    int i,j;
    str="";
    for(i=sz-1;i>=0;i--)
    for(j=sz-1;j>=0;j--)
    str+=g[j][i];

    if(is_palindrom())
    return true;
    else
    return false;

}
bool is_magic_squre()
{
    int i,j,k;

    k=0;
    for(i=0;i<sz;i++)
    for(j=0;j<sz;j++)
    g[i][j]=s[k++];

    //print(sz);

    if(p1() && p2() && p3() && p4())
    return true;
    else
    return false;
}
int main()
{
    int tc,i,t=1,l;
    char x[10010];
    scanf("%d",&tc);
    gets(x);
    while(tc--)
    {
        gets(x);
        s="";
        for(i=0;x[i];i++)
        if(isalpha(x[i]))
        s+=x[i];
        l=s.size();
        sz=sqrt(l);
        printf("Case #%d:\n",t++);
        if(sqrt(l)==sz)
        {
            if(is_magic_squre())
            printf("%d\n",sz);
            else
            printf("No magic :(\n");
        }
        else
        printf("No magic :(\n");
    }
    return 0;
}
