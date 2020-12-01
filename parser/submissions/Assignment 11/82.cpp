#include <iostream>
#include <unordered_map>
#include <vector>
#include<cstdio>
using namespace std;
long long int todecimal(vector<int> v)
{
    long long int sum=0;
    long long int mul=1;
    for(int i=0; i<45; i++)
    {
        sum+=v[i]*mul;
        mul=mul*2;
    }
    return sum;
}
int change(int a)
{
    if(a==1)
    {
        return 0;
    }
    else return 1;
}
void formvec(vector<int> &v,int r)
{
    for(int i=0; i<5; i++)
    {
        for(int j=9*i; j<9*(i+1); j++)
        {
            v[j]=r%2;
        }
        r=r/2;
    }
}
int main()
{
    int n;
    cin>>n;
    unordered_map<long long int , char> mymap;
    vector<int> v(45);
    vector<int> m(45);
    long long int num;
    m[0]=1;
    for(int i=1;i<45;i++)
    {
      m[i]=2*m[i-1];
    }
    for(int r =0;r<26; r++)
    {
        formvec(v,r);
        char ch = r+97;
        num=todecimal(v);
        mymap[num]=ch;
        for(int i=0; i<45; i++)
        {
            v[i] =  change(v[i]);
            if(v[i]==1){ num+=m[i];}
            else {num-=m[i];}
           for(int j=i+1; j<45; j++)
            {
                v[j]=change(v[j]);
                if(v[j]==1){ num+=m[j];}
                 else {num-=m[j];}
                for(int k=j+1; k<45; k++)
                {
                    v[k]=change(v[k]);
                    if(v[k]==1){ num+=m[k];}
                     else {num-=m[k];}
                    for(int l=k+1; l<45; l++)
                    {
                        v[l]=change(v[l]);
                        if(v[l]==1){ num+=m[l];}
                        else {num-=m[l];}
                        //num = todecimal(v);
                        mymap[num]=ch;
                        v[l]=change(v[l]);
                        if(v[l]==1){ num+=m[l];}
                        else {num-=m[l];}

                    }
                    //num=todecimal(v);
                    mymap[num]= ch;
                    v[k]=change(v[k]);
                    if(v[k]==1){ num+=m[k];}
                     else {num-=m[k];}
                }
                //num=todecimal(v);
                mymap[num]= ch;
                v[j]=change(v[j]);
                if(v[j]==1){ num+=m[j];}
                 else {num-=m[j];}
            }
            //num=todecimal(v);

            mymap[num]= ch;
            v[i]=change(v[i]);
            if(v[i]==1){ num+=m[i];}
            else {num-=m[i];}
        }
    }
     for(int i=0; i<n; i++)
    {
        long long int val;
        cin>>val;
        unordered_map<long long int ,char>::const_iterator got = mymap.find (val);
        if(got!=mymap.end())
        {
        //cout<<mymap[val];
        printf("%c",mymap[val]);
        }
        else
        //cout<<"?";
        printf("?");
    }
    cout<<endl;
}
