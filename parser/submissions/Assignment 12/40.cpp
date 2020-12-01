#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    //cout<<"poo"<<endl;
    vector< int > t(n);
    //vector<vector<int> > suc(n);
    vector<vector<int> > pre(n);
    //int * frds = new int[n];
    int frdstemp;

    int present;
    vector< bool > maxbool(n,false);
    vector<int > countmax(n);

    //cout<<"sjdhj"<<endl;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&t[i]);
        scanf("%d",&frdstemp);
        for(int j = 0;j<frdstemp;j++)
        {
            scanf("%d",&present);
            countmax[i] = frdstemp;
            //suc[i].push_back(present);
            pre[present].push_back(i);
        }
    }
    queue< int > yes;//for min
    queue< int > no;//for maxima
    vector<int > countmin(n,0);
    vector< bool > minbool(n,false);
    for(int i = 0;i<n;i++)
    {
        if(t[i]==0)
        {
            minbool[i] = true;
            yes.push(i);
        }
    }
    int mini = 0;
    while(!(yes.empty()))
    {
        int currsize = (pre[yes.front()]).size();
        int currindex;
        for(int i = 0;i<currsize;i++)
        {
            currindex = pre[yes.front()][i];
            countmin[currindex]++;
            if(countmin[currindex]>=t[currindex])
            {
                //cout<<"pooka"<<endl;
                if(!minbool[currindex])
                {
                        minbool[currindex] = true;

                yes.push(currindex);
                }
            }
            else
            {
               // cout<<"jsdhjsd"<<endl;
                //skip
            }
        }
        //cout<<yes.front()<<endl;
        yes.pop();
        mini++;
    }




    int maxi = 0;

    for(int i = 0;i<n;i++)
    {
        if(t[i]>countmax[i])
        {
            maxbool[i] = true;
            no.push(i);
        }
    }
    while(!(no.empty()))
    {
        int currsize = (pre[no.front()]).size();
        int currindex;
        for(int i = 0;i<currsize;i++)
        {
            currindex = pre[no.front()][i];
            countmax[currindex]--;
            if(countmax[currindex]<t[currindex])
            {
                //cout<<"pooka"<<endl;
                if(!maxbool[currindex])
                {
                    maxbool[currindex] = true;
                    no.push(currindex);
                }
            }
            else
            {
                //cout<<"jsdhjsd"<<endl;
                //skip
            }
        }
        //cout<<no.front()<<endl;
        no.pop();
        maxi++;
    }




    cout<<mini<<" "<<n-maxi<<endl;
}
