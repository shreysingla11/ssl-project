#include<iostream>
#include <unordered_map>
#include<cmath>
using namespace std;
int main()
{
    unordered_map<long long int,char> mymap;
    long long alpha;
    long long p_2_9=pow(2,9);
    long long p_2_18=p_2_9*p_2_9;
    long long p_2_27=p_2_18*p_2_9;
    long long p_2_36=p_2_18*p_2_18;
    bool a[5];
    long long alphatem1;
    long long alphatem2;
    long long alphatem3;
    for(int i=0; i<26; i++)
    {
        char present=97+i;
        int temp=i;
        a[4]=i%2;
        temp=temp/2;
        a[3]=(temp)%2;
        temp=temp/2;
        a[2]=(temp)%2;
        temp=temp/2;
        a[1]=(temp)%2;
        temp=temp/2;
        a[0]=(temp)%2;
        alpha=(p_2_9-1)*(a[0]*p_2_36+a[1]*p_2_27+a[2]*p_2_18+a[3]*p_2_9+a[4]);
        mymap[alpha]=present;
        long long first=1;
        for(int j=0; j<45; j++,first*=2)
        {
            int index=j/9;
            if(a[4-index])
            {
                alphatem1=alpha-first;
            }
            else
            {
                alphatem1=alpha+first;
            }
            mymap[alphatem1]=present;
            long long second=1;
            for(int k=0; k<j; k++,second*=2)
            {
                index=k/9;
                if(a[4-index])
                {
                    alphatem2=alphatem1-second;
                }
                else
                {
                    alphatem2=alphatem1+second;
                }
                mymap[alphatem2]=present;
                long long third=1;
                for(int l=0; l<k; l++,third*=2)
                {
                    index=l/9;
                    if(a[4-index])
                    {
                        alphatem3=alphatem2-third;
                    }
                    else
                    {
                        alphatem3=alphatem2+third;
                    }
                    mymap[alphatem3]=present;
                    long long fourth=1;
                    for(int m=0; m<l; m++,fourth*=2)
                    {
                        index=m/9;
                        if(a[4-index])
                        {
                            mymap[alphatem3-fourth]=present;
                        }
                        else
                        {
                            mymap[alphatem3+fourth]=present;
                        }
                    }
                }
            }
        }
    }
    int n=0;
    long long int present;
    cin>>n;
    //cout<<mymap.bucket_count()<<endl;
    //cout<<mymap.size();
    while(n!=0)
    {
        scanf("%lld",&present);
        if(mymap.count(present)>0)
        {
            printf("%c",mymap[present]);
        }
        else
        {
            printf("?");
        }
        n--;
    }
}
