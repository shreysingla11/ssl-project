#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
vector<long long int> binary(int n)
{
    vector<long long int> temp(5,0);
    int count =4;
    while(n)
    {
        temp[count]=n%2;
        n/=2;
        count --;
    }
    return temp;
}
int main()
{
    int num=0;
    //long long int ar[26][45];
    vector<long long int>temp(5,0);
        vector<long long int> input(26,0);
    for(int i =0;i<26;i++)
    {
        temp=binary(i);
        input[i]=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<9;k++)
            {
                if(temp[4-j]!=0)
                {
                    input[i]+=(long long int)((long long int)1<<(k+9*j));
                }
            }
        }
    }


//    for(int i=0;i<26;i++)
//    {
//        long long int sum=0;
//        for (int j=0;j<45;j++)
//        {
//            sum+=((ar[i][j]*1)<<(long long int)j);
//        }
//        input[i]=sum;
//    }
   // sort(input.begin(),input.end());
//    for(int i=0;i<26;i++)
//    {
//        cout<<input[i]<<endl;
//    }
    unordered_map<long long int,char> map;

    for(int x=0;x<26;x++)
    {
    long long int t=input[x];
    long long int a,b,c,d;
        map[t]=(x+'a');
        for(int i=0;i<45;i++)
        {

            a=t^((long long int)1<<i);
            map[a]=(x+'a');
            for(int j=i+1;j<45;j++)
            {
                b=a^((long long int)1<<j);
                map[b]=(x+'a');
                for(int k=j+1;k<45;k++)
                {
                     c=b^((long long int)1<<k);
                     map[c]=(x+'a');
                    for(int l=k+1;l<45;l++)
                    {
                         d=c^((long long int)1<<l);
                         map[d]=(x+'a');
                    }
                }
            }
        }
    }
    int n;
    long long int nu;
    unordered_map<long long int,char>::iterator got;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&nu);
        got=map.find(nu);
        if(got==map.end())
            printf("?");
        else
            printf("%c",got->second);
             }
    //cout<<endl;
    printf("\n");
}
