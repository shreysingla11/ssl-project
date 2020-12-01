# include <iostream>
#include <queue>
#include <cstdio>
using namespace std;



int main()
{
//take the data as input and store it in vector of vectors
    int n,f,temp;
    //cin>>n;
    scanf("%d",&n);
    vector<vector<int> > pred(n,vector<int>(0));
    int mingoing=0,maxgoing=n;
    vector<int> t(n);//t
    vector<int> frnd(n);//no of friends
    vector<bool> minqueue(n,false);//in queue .??
    vector<bool> maxqueue(n,false);//in queue .??
    vector<int> frendgoing(n);//no of friends going
    vector<int> frendnotgoing(n);
    std::queue<int> going;
    std::queue<int> notgoing;
    for(int i=0; i<n; i++)
    {
        //  cout<<"21"<<endl;
       // cin>>t[i];
        scanf("%d",&t[i]);
        if(t[i]==0)
        {
            going.push(i);
            mingoing++;
            minqueue[i]=true;
        }
        //cin>>f;
        scanf("%d",&f);
        if(t[i]>f)
        {
            notgoing.push(i);
            maxgoing--;
            maxqueue[i]=true;

        }
        frnd[i]=f;
        for(int j=0; j<f; j++)
        {
            //cin>>temp;
            scanf("%d",&temp);
            pred[temp].push_back(i);
        }
    }
    //maintain a queue

    vector<int>::iterator it;
    while(!going.empty())
    {
        // cout<<"43"<<endl;
        it=pred[going.front()].begin();
        while(it!=pred[going.front()].end())
        {
            //   cout<<47<<endl;
            if(!minqueue[*it])
            {
                frendgoing[*it]++;
                if(frendgoing[*it]==t[*it])
                {
                    going.push(*it);
                    mingoing++;
                    minqueue[*it]=true;
                }
            }
            it++;
        }
        going.pop();
    }

    cout<<mingoing;
    while(!notgoing.empty())
    {
        it=pred[notgoing.front()].begin();
        while(it!=pred[notgoing.front()].end())
        {
            if(!maxqueue[*it]){
                frendnotgoing[*it]++;
                if(frendnotgoing[*it]>frnd[*it]-t[*it]){
                    notgoing.push(*it);
                    maxgoing--;
                    maxqueue[*it]=true;
                }
            }
            it++;
           }
           notgoing.pop();

    }
    cout<<" "<<maxgoing<<endl;

    return 0;
}
