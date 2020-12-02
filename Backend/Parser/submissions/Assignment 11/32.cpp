#include <iostream>
#include <bitset>
#include <unordered_map>
using namespace std;

void cons_map(unordered_map<long long int,char> &mymap,int alp,char alph)
{
    bitset<5> alpb(alp);
    bitset<45> calpb;
    for(int i=0,j=-1;i<45;i++)
    {
        if(i%9==0)j++;
        calpb[i]=alpb[j];
    }

    //0 err
    mymap[calpb.to_ullong()]=alph;

    //1err
    for(int i=0;i<45;i++)
    {
        calpb[i]=!calpb[i];
        mymap[calpb.to_ullong()]=alph;
        calpb[i]=!calpb[i];
    }

    //2err
    for(int i=0;i<45;i++)
    {
        calpb[i]=!calpb[i];
        for(int j=i+1;j<45;j++)
        {
            calpb[j]=!calpb[j];
            mymap[calpb.to_ullong()]=alph;
            calpb[j]=!calpb[j];
        }
        calpb[i]=!calpb[i];
    }


    //3err
    for(int i=0;i<45;i++)
    {
        calpb[i]=!calpb[i];
        for(int j=i+1;j<45;j++)
        {
            calpb[j]=!calpb[j];
            for(int k=j+1;k<45;k++)
            {
                calpb[k]=!calpb[k];
                mymap[calpb.to_ullong()]=alph;
                calpb[k]=!calpb[k];
            }
            calpb[j]=!calpb[j];
        }
        calpb[i]=!calpb[i];
    }

    //4err
    for(int i=0;i<45;i++)
    {
        calpb[i]=!calpb[i];
        for(int j=i+1;j<45;j++)
        {
            calpb[j]=!calpb[j];
            for(int k=j+1;k<45;k++)
            {
                calpb[k]=!calpb[k];
                for(int l=k+1;l<45;l++)
                {
                    calpb[l]=!calpb[l];
                    mymap[calpb.to_ullong()]=alph;
                    calpb[l]=!calpb[l];
                }
                calpb[k]=!calpb[k];
            }
            calpb[j]=!calpb[j];
        }
        calpb[i]=!calpb[i];
    }

    return;
}

int main()
{
    unordered_map<long long int,char> mymap;
    unordered_map<long long int,char>::iterator it;

    char alph='a';
    for(int alp=0;alp<26;alp++,alph++)cons_map(mymap,alp,alph);

    int n;
    long long int cw;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>cw;
        it=mymap.find(cw);
        if(it==mymap.end())
        {
            cout<<"?";
            continue;
        }
        cout<<it->second;
    }
    return 0;
}
