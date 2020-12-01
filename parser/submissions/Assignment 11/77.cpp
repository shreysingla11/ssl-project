#include<iostream>
#include <unordered_map>
#include <bitset>
using namespace std;
int main()
{
    unordered_map<bitset<45>,char> u;
    unordered_map<bitset<45> ,char>::iterator ui;

    char c;
    int p=0,q=0,r=0,s=0,n=0;
    long long int l=0;
    bitset<45> tmp;
    cin>>n;

    for(int i=0; i<26; i++)
    {

        bitset<5> t(i);

        for(int j=0; j<5; j++)
        {
            for(int k=9*j; k<9*j+9; k++)
            {
                tmp.set(k,t[j]);
            }
        }
        c=(char)(i+97);
        u[tmp]=c;
        for(p=0; p<45; p++)
        {
            tmp.flip(p);
            u[tmp]=c;
            for(q=p+1; q<45; q++)
            {
                tmp.flip(q);
                u[tmp]=c;
                for(r=q+1; r<45; r++)
                {
                    tmp.flip(r);
                    u[tmp]=c;
                    for(s=r+1; s<45; s++)
                    {
                        tmp.flip(s);
                        u[tmp]=c;
                        tmp.flip(s);
                    }
                    tmp.flip(r);
                }
                tmp.flip(q);
            }
            tmp.flip(p);
        }

    }
ui=u.begin();

    for(int i=0; i<n; i++)
    {
        cin>>l;
        bitset<45> b(l);
        ui=u.find(b);
        if(ui!=u.end())
        {
            cout<<ui->second;
        }
        else
        {
            cout<<"?";
        }
    }
cout<<endl;
    return 0;
}
