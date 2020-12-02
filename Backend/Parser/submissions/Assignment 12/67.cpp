#include<iostream>
#include<vector>
#include<stack>
#include<list>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector< vector<int> > P(n);
    vector<int> th(n);
    vector<int> nf(n);
    vector<bool> complete(n);
    stack<int> DG;
    stack<int> DNG;
    int ans1=0,ans2=0;
    vector<int> FG(n,0 );
    vector<int> FNG(n,0);
    vector< list<int> > R(n);
    for(int i=0; i<n; i++)
    {
        int input;
        cin>>input;
        th[i]=input;
        cin>> input;
        nf[i]=input;
        if(th[i]==0){
            DG.push(i);
            ans1++;
            complete[i]==true;
        }
        else if(th[i]>nf[i]){
            DNG.push(i);
            ans2++;
            complete[i]==true;
        }
        else{
        complete[i]==false;
        }
        P[i].resize(nf[i]);
        for(int j=0; j<nf[i]; j++)
        {
            cin>>P[i][j];
            R[P[i][j]].push_back(i);
        }
    }
    /*for(long i=0; i<n; i++)
    {
        for(list<long>::iterator it=rev[i].begin(); it != rev[i].end(); ++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }*/
    while (!DG.empty())
  {
    int temp =DG.top();
    DG.pop();

    for(list<int>::iterator it=R[temp].begin(); it != R[temp].end(); ++it)
        {
            if(complete[*it]==false){
            FG[*it]++;
            }
            else{continue;}
            if((th[*it]- FG[*it])<=0){
            DG.push(*it);
            ans1++;
            complete[*it]==true;
        }

        }
  }
  while (!DNG.empty())
  {
  int temp =DNG.top();
    DNG.pop();
    for(list<int>::iterator it=R[temp].begin(); it != R[temp].end(); ++it)
        {
            if(complete[*it]==false){
            FNG[*it]++;
            }
            else{continue;}
            if((nf[*it]- FNG[*it]<th[*it])){
            DNG.push(*it);
            ans2++;
            complete[*it]==true;
        }

        }
  }
  cout << ans1 <<" "<< n-ans2;

    return 0;
}
