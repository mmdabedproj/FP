#include<stdio.h>

int bin[100];
int sobat[32];
int vaziat[8];

void Binary(int n)
{
    int cnt=0,i=1,m=n,tvn=0;;
    while(i<=m)
        {
            i*=2;
            tvn++;
        }
    tvn--;
    i/=2;
    for(int j=tvn;j>=0;j--)
        {
        if (m>=i)
            {
            m-=i;
            bin[j]=1;
            }
        else
            {
            bin[j]=0;
            }
        i/=2;
        }
    }

///

int Number1s_fard(int n)
{
int cnt=0,m=n;
Binary(n);
for(int i=0;i<8;i++)
    {
    if (bin[i])cnt++;
    }
if (cnt%2==1)vaziat[0]=
return cnt%2;
}

///

int Overflow(int n)
{
Binary(n);
if(bin[8]==1)return 1;
return 0;
}

///

void Add(int *c,int *a, int *b)
{
    *c=*b+*a;
}

///

void Sub(int *sub,int *a, int *b)
{
    *sub=*a-*b;
}

///


void swap(int *a, int *b)
{
    int temp;
    temp =*a;
    *a =*b;
    *b =temp;
}

///

void And(int*a, int*b, int*c)
void Or(int*a, int*b, int*c)
void AddI(int*a, int*b, int c)
void SubI(int*a, int*b, int c)
void AndI(int*a, int*b, int c)
void Ori(int*a, int*b, int*c)
///
int main()
{
int a,b,c;
scanf("%d %d",&a,&b);
printf("%d",a);

}
