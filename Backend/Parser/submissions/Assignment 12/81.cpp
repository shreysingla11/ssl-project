#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int i;
    int t;
    int f;
    int *x;
    int notgoing;
    bool de;
    node(int d,int a,int b,int *c)
    {
        t=a;
        f=b;
        x=c;
        i=d;
        notgoing=0;
        de=false;
    }
};
int main()
{
    int mini=0;
    int maxi=0;
    int n;
    cin>>n;
    vector<node> fren,fre;
    vector<int> stac,add,stak;
    vector<vector<int> > lis(n);
    for(int i=0;i<n;i++)
    {
        add.push_back(i);
    }
    for(int i=0; i<n; i++)
    {
        int a,b,*c;
        cin>>a;
        cin>>b;
        c=new int[b];
        for(int j=0; j<b; j++)
        {
            cin>>c[j];
            (lis[c[j]]).push_back(i);
        }

        node temp(i,a,b,c);
        fren.push_back(temp);
        fre.push_back(temp);
    }

    for(int i=0; i<n; i++)
    {
        if((fren[i]).t==0)
        {
            stac.push_back(i);
            mini++;
        }
    }


    while(true)
    {
    if(stac.size()>0)
    {
        int index=stac[stac.size()-1];
        stac.pop_back();
        fren[index].t=n;
        for(int i=0; i<(lis[index]).size(); i++)
        {
            fren[lis[index][i]].t--;
            if(fren[lis[index][i]].t==0)
            {
                stac.push_back(lis[index][i]);
                mini++;
            }
        }

    }
    else
    {
        cout<<mini<<" ";
        break;
    }
    }



    for(int i=0; i<n; i++)
    {
        if((fre[i]).t>(fre[i]).f)
        {
            stak.push_back(i);
            fre[i].de=true;
            maxi++;
        }
    }



    while(true)
    {
    if(stak.size()>0)
    {
        int index=stak[stak.size()-1];
        stak.pop_back();
        fre[index].f=0;
        for(int i=0; i<(lis[index]).size(); i++)
        {
            fre[lis[index][i]].notgoing++;
            if( (fre[lis[index][i]].t)-1==(fre[lis[index][i]].f-fre[lis[index][i]].notgoing))
            {
                if(!fre[lis[index][i]].de)
                {
                stak.push_back(lis[index][i]);
                fre[lis[index][i]].de=true;
                maxi++;
                }
            }
        }

    }
    else
    {
        cout<<n-maxi;
        break;
    }
    }
    return 0;

}
