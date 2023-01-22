#include<stdio.h>
#include<string.h>


int bin[100];
int sabat[32];
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
if (cnt%2==1)return 1;
return 0;
}

///

int Overflow(int a,int b)
{
///overflow flag
if (a>0&&b>0&&a+b<0)
    return 1;
if (a<0&&b<0&&a+b>0)
    return 1;
return 0;
}

///

void make_vaziat(int n)
{
///parity flag
    vaziat[0]=Number1s_fard(n);
///zero flag
    if(n==0)
        vaziat[1]=0;
    else
        vaziat[1]=0;
///sign flag
    if (n<0)
        vaziat[2]=1;
    else
        vaziat[2]=0;
}


///1.Add

void Add(int c,int b,int a)
{
    sabat[c]=sabat[b]+sabat[a];
    make_vaziat(sabat[c]);
}

///2.Sub

void Sub(int c,int b, int a)
{
    sabat[c]=sabat[b]-sabat[a];
    make_vaziat(sabat[c]);
}

///3.Swp


void Swp(int a, int b)
{
    int tmp=sabat[a];
    sabat[a]=sabat[b];
    sabat[b]=tmp;
}

///4.And

void And(int c, int b, int a)
{
    sabat[c]=sabat[a]&sabat[b];
    make_vaziat(sabat[c]);
}

///5.Xor

void Xor(int c,int b,int a)
{
    sabat[c]=sabat[a]^sabat[b];
    make_vaziat(sabat[c]);
}

///6.Or

void Or(int c, int b, int a)
{
    sabat[c]=sabat[a]|sabat[b];
    make_vaziat(sabat[c]);
}

///7.AddI

void AddI(int c, int b, int imm)
{
    sabat[c]=sabat[b]+imm;
    make_vaziat(sabat[c]);
}

///8.SubI

void SubI(int c, int b, int imm)
{
    sabat[c]=imm-sabat[b];
    make_vaziat(sabat[c]);
}

///9.AndI

void AndI(int c, int b, int imm)
{
    sabat[c]=imm&sabat[b];
    make_vaziat(sabat[c]);
}

///10.XorI

void XorI(int c, int b, int imm)
{
    sabat[c]=imm^sabat[b];
    make_vaziat(sabat[c]);
}

///11.OrI

void OrI(int c, int b, int imm)
{
    sabat[c]=imm|sabat[b];
    make_vaziat(sabat[c]);
}

///12.Mov1 & Mov2

void Mov1(int a, int b)
{
    sabat[a]=sabat[b];
}

void Mov2(int a, int imm)
{
    sabat[a]=imm;
}

///13.Dump

void Dump()
{
    printf("Sabat omumi=> ");
    for (int i=0;i<=31;i++)
        {
        printf("%d, ",sabat[i]);
        }
    printf("/nSabat vaziat=>");
    for(int i=0;i<=7;i++)
        {
        printf("%d, ",vaziat[i]);
        }
}

///14.Dump_F

void Dump_F()
{

FILE *f = fopen("regs.txt", "w");
for (int i=0;i<32;i++)
    {
    fprintf(f,"%d ",sabat[i]);
    }
fprintf(f,"\n");

for (int i=0;i<8;i++)
    {
    fprintf(f,"%d ",vaziat[i]);
    }
fprintf(f,"\n");

fclose(f);

}

int ErrorArg(int a,int b,int c)
{
if (a>31||a<0||b>31||b<0||c<0||c>31)return 1;
return 0;
}

int ErrorArg2(int a,int b)
{
if (a>31||a<0||b>31||b<0)return 1;
return 0;
}


int main()
{
sabat[0]=0;
for (int i=1;i<32;i++)
    {
    sabat[i]=sabat[i-1]+1;
    }

char dastur[100];

int a,b,c,imm,i=1,j;
FILE *file =fopen("input1.txt","r");
while (fscanf(file,"%s ",dastur)!=EOF)
    {
    ///0.Jmp
    if (strcmp(toupper(dastur),"JMP")==0)
        {
        fscanf(file," %d\n",&j);
        rewind(file);
        i=0;
        while (i<=j)
            {
            c=fgetc(file);
            if (c=='\n')
                {
                i++;
                }
            }
        }

    ///1.Add
    else if (strcmp(toupper(dastur),"ADD")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg(a,b,c))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else{
            Add(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///2.Sub
    else if (strcmp(toupper(dastur),"SUB")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg(a,b,c))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            Sub(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///3.And
    else if (strcmp(toupper(dastur),"AND")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg(a,b,c))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            And(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///4.Xor
    else if (strcmp(toupper(dastur),"XOR")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg(a,b,c))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            Xor(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///5.Or
    else if (strcmp(toupper(dastur),"OR")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg(a,b,c))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            Or(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///6.AddI
    else if (strcmp(toupper(dastur),"ADDI")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg2(a,b))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            AddI(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///7.SubI
    else if (strcmp(toupper(dastur),"SUBI")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg2(a,b))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            SubI(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///8.AndI
    else if (strcmp(toupper(dastur),"ANDI")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg2(a,b))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            AndI(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///9.XorI
    else if (strcmp(toupper(dastur),"XORI")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg2(a,b))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            XorI(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///10.OrI
    else if (strcmp(toupper(dastur),"ORI")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        if (ErrorArg2(a,b))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            {
            OrI(c,b,a);
            printf("%d\n",sabat[c]);
            }
        }

    ///11.Mov
    /*else if (strcmp(dastur,"ADDI")==0)
        {
        fscanf(file," S%d, S%d, S%d\n",&c,&b,&a);
        AddI(c,b,a);
        printf("%d\n",sabat[c]);
        }
    */

    ///12.Swp
    else if (strcmp(toupper(dastur),"SWP")==0)
        {
        fscanf(file," S%d, S%d\n",&c,&b);
        if (ErrorArg2(a,b))
            {
            printf("All indexes should be between 0-31 in line %d !\n",i);
            }
        else
            Swp(c,b);
        }

    ///13.DUMP_REGS
    else if (strcmp(toupper(dastur),"DUMP_REGS")==0)
        {
        Dump();
        }

    ///14.DUMP_REGS_F
    else if (strcmp(toupper(dastur),"DUMP_REGS_F")==0)
        {
        Dump_F();
        }

    ///15.Input
    else if (strcmp(toupper(dastur),"INPUT")==0)
        {
            printf("Enter sabat[0]: ");
            scanf("%d",&sabat[0]);
        }

    ///16.OUTPUT
    else if (strcmp(toupper(dastur),"OUTPUT")==0)
        {
            printf("Sabat[0]: %d\n",sabat[0]);
        }
    else if(strcmp(toupper(dastur),"EXIT")==0)
        {
        exit(0);
        }
    else
        {
        printf("%s in line %d is undefined !\n",dastur,i);
        while(c!='\n')
            {
            c=fgetc(file);
            }
        }
    i++;
    }
}

