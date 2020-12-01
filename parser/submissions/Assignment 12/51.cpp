#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{

    int n,min_friends=0,max_friends=0,not_friends=0;

    cin>>n;

    vector<int> friends,stac;

    vector<vector<int > > A,pred;
    stack<int> definetly_will_go,definetly_will_not_go;
    vector<int>::iterator it;

    A.resize(n);
    stac.resize(n);
    pred.resize(n);

    friends.resize(n);

    for (int i=0; i<n; i++)
    {
        A[i].resize(2);
        stac[i]=0;
        cin>>A[i][0]>>A[i][1];
        A[i].resize(2+A[i][1]);

        for (int j=0; j<A[i][1]; j++)
        {
            cin>>A[i][j+2];
            pred[A[i][j+2]].push_back(i);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(A[i][0]==0)
        {
            definetly_will_go.push(i);
            stac[i]=1;
            min_friends++;
        }
        else if(A[i][0]>A[i][1])
        {
            definetly_will_not_go.push(i);
            stac[i]=1;
            not_friends++;
        }
    }

    while(!definetly_will_go.empty())
    {

        int i=definetly_will_go.top();
        definetly_will_go.pop();
        //cout<<i<<endl;
        it=pred[i].begin();
        //cout<<*it<<endl;
        for (it; it!=pred[i].end(); it++)
        {
            friends[*it]++;
            if(A[*it][0]<=friends[*it]&&A[*it][0]!=0&&stac[*it]==0)
            {
                definetly_will_go.push(*it);
                stac[*it]=1;
                min_friends++;
            }
        }
    }
    for(int i=0;i<n;i++){
    friends[i]=A[i].size()-2;
    //cout<<friends[i];
    }
    while(!definetly_will_not_go.empty())
    {

        int i=definetly_will_not_go.top();
        definetly_will_not_go.pop();
        //cout<<i<<endl;
        it=pred[i].begin();
        //cout<<*it<<endl;
        for (it; it!=pred[i].end(); it++)
        {
            //cout<<*it<<" "<<i<<' ';
            //cout<<A[*it][0]<<' '<<friends[*it]<<" \n"<<stac[*it];
            friends[*it]--;
            if(A[*it][0]>friends[*it]&&stac[*it]==0)
            {
                definetly_will_not_go.push(*it);
                stac[*it]=1;
                not_friends++;
            }
        }
    }
    max_friends=n-not_friends;


    cout<<min_friends<<" "<<max_friends<<endl;
    return 0;
}
