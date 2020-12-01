#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int *mapp,*app;
    mapp=new int[512];
    app=new int[512];
    int five;
    long long int a=0,temp=0;
    int zero=0,first=0,i=0;
    for(int y=0; y<512; y++)
    {
        i=y;
        temp=i%2;
        zero=0;
        first=0;
        for(int j=0; j<9; j++)
        {
            if(temp==1)
            {
                first++;
            }
            i=i/2;
            temp=i%2;
        }
        if(first>4)
        {
            app[y]=9-first;
            mapp[y]=1;
        }
        else
        {
            app[y]=first;
            mapp[y]=0;
        }

        //mapp[y]=first;
    }
    int N,err=0,x=1,ab=0,p=1;
    long long int bit,temp1;
    scanf("%d",&N);
    while(N>0)
    {
        //scanf("%d",&bit);
        cin>>bit;
        err=0;
        ab=0;
        p=1;

        for(int i=0; i<5; i++)
        {
            x=1;
            five =0;
            for(int u=0;u<9;u++)
            {
                five+=(bit%2)*x;
                x=x*2;
                bit=bit/2;
            }
            //five=bit%512;
            err+=app[five];
            if(mapp[five]==1)
            {
                ab+=p;
                p=p*2;
            }
            else
            {
                p=p*2;
            }
            //bit=bit/512;
        }
        if(err>4)
        {
            printf("?");
        }
        else
        {
            if(ab>25)
            {
                printf("?");
            }
            else
            {
                printf("%c",char(97+ab));
            }
        }
        N--;
    }
    return 0;
}
