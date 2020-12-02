#include <iostream>
#include <unordered_map>
#include <bitset>
using namespace std;

int main()
{
    int n,p;
    char c;
    long long t;
    cin>>n;
    bitset<45> *bits= new bitset<45>[n];
    for(int i=0;i<n;i++)
    {
        cin>>t;
        bitset<45> k(t);
        bits[i]=k;
    }
    unordered_map<bitset<45>,char> mymap;
    for(int i=0;i<26;i++)
    {
        c=(char)(i+97);
        bitset<5> b(i);
        bitset<45> s;
        p=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<9;k++)
            {
                s.set(p,b[j]);
                p++;
            }
        }
        mymap[s]=c;
        for(int j=0;j<45;j++)
        {
            s.flip(j);
            mymap[s]=c;
            for(int k=j+1;k<45;k++)
            {   
                s.flip(k);
                mymap[s]=c;
                for(int l=k+1;l<45;l++)
                {
                    s.flip(l);
                    mymap[s]=c;
                    for(int m=l+1;m<45;m++)
                    {
                        s.flip(m);
                        mymap[s]=c;
                        s.flip(m);
                    } 
                    s.flip(l);  
                }
                s.flip(k);
            }
            s.flip(j);
        }
    }
    unordered_map<bitset<45>,char>::iterator it=mymap.begin();
    for(int i=0;i<n;i++)
    {
        it=mymap.begin();
        it=mymap.find(bits[i]);
        if(it!=mymap.end())cout<<it->second;
        else cout<<"?";
    }
    cout<<endl;
    return 0;
}
