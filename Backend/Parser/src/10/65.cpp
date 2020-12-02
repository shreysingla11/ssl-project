#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>

using namespace std;
struct term
{
    int value;
    int position;
};
struct newstruct
{
    vector<int> a;
    vector<int> b;
};

bool compare(term a,term b)
{
    if (b.value>a.value) return true;
    else if(a.value>b.value) return false;
    else
    {
        if(a.position <b.position) return true;
        else return false;
    }
}

class distinct
{
    public:
    vector<int>originalsequence;
    vector<newstruct> lala;
    distinct(vector<int> a)
    {
        vector<term> abcd;
        term temp;

        int si=log2(a.size());
        //lala.resize(si);
        int value=0;
        int iii=0;
        while(iii<a.size())
        {
            temp.value=a[iii];
            temp.position=iii;
            abcd.push_back(temp);
            originalsequence.push_back(-1);
            iii++;
        }
        sort(abcd.begin(),abcd.end(),compare);
        for(int j=0;j<a.size()-1;j++)
        {
            if(abcd[j].value==abcd[j+1].value)
            {
                originalsequence[abcd[j+1].position]=abcd[j].position;
            }
        }
        int jjj=0;
        while(jjj<a.size())
        {
            //cout<<"hiya"<<endl;
            newstruct daa;
            //cout<<"aaaa"<<endl;
            daa.a.resize(a.size());
            daa.b.resize(a.size());
            daa.a[jjj]=abcd[jjj].value;
            daa.b[jjj]=0;
            //cout<<"b";
            lala.push_back(daa);
            jjj++;
        }
        for(int k=0;k<a.size();k++)
        {
            cout<<originalsequence[k]<<" ";
        }
        cout<<endl;
        int kkk=0;
        while(kkk<si)
        {
            int p=-1;
            vector<int> tempo(a.size(),0);
            int q=-1;
            for(int j=0;j<a.size();j++)
            {
                int k=originalsequence[j]*(int(pow(2,kkk))/a.size());
                if(originalsequence[j]>=k*a.size()/int(pow(2,kkk)) + a.size()/int(pow(2,kkk+1)) && originalsequence[j]<(k+1)*a.size()/int(pow(2,kkk)))
                    tempo[k]++;
                lala[kkk].a[j]=tempo[k];

                if(k*a.size()/int(pow(2,kkk)) + a.size()/int(pow(2,kkk+1))<=originalsequence[j] && originalsequence[j]<(k+1)*a.size()/int(pow(2,kkk)))
                {
                    q=j;
                    lala[kkk].b[j]=p;
                }
                else
                {
                    p=j;
                    lala[kkk].b[j]=q;
                }
            }
            kkk++;

        }
        for(int i=0;i<a.size();i++)
        {
            cout<<lala[2].a[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<a.size();i++)
        {
            cout<<lala[2].b[i]<<" ";
        }
        cout<<endl;
    }
};


