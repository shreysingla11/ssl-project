#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>

using namespace std;

int main(){
stack<int> go;
stack<int> wontgo,prob;
int gocount=0,notgocount=0;
int n;
cin>>n;
vector<vector<int> > m;
vector<vector<int> > pred(n);
vector<int> a(n); //for the number of friends of ith member who will definitely go
vector<int> b(n);// for the number of friends of ith member who will definitely not go
int numoffrnds[n],th[n];

for(int i=0;i<n;i++){
    a[i]=0;
    b[i]=0;
}

for(int i=0;i<n;i++){
    scanf("%d %d ",&th[i],&numoffrnds[i]);

    vector<int> temp;
    int num[numoffrnds[i]];
    for(int j=0;j<numoffrnds[i];j++){
        cin>>num[j];
        pred[num[j]].push_back(i);
        temp.push_back(num[j]);
    }
    m.push_back(temp);
    if(th[i]>numoffrnds[i]){
        wontgo.push(i);
         notgocount++;
        b[i]++;

    }
    else if(th[i]==0){
        go.push(i);
        gocount++;
        a[i];
    }
    else if(th[i]==numoffrnds[i]){
        for(int j=0;j<m[i].size();j++){
            go.push(m[i][j]);
            gocount++;
            a[i]++;
        }
    }

}



while(!go.empty()){
    for(int i=0;i<pred[go.top()].size();i++){
        a[pred[go.top()][i]]++;
        if(a[pred[go.top()][i]]>=th[pred[go.top()][i]]){
            go.pop();
            go.push(pred[go.top()][i]);
            gocount++;
        }
    }
}

while(!wontgo.empty()){
    for(int i=0;i<pred[wontgo.top()].size();i++){
        b[pred[wontgo.top()][i]]++;
        if(th[pred[wontgo.top()][i]]>(numoffrnds[pred[wontgo.top()][i]]-b[pred[wontgo.top()][i]])){
            wontgo.pop();
            wontgo.push(th[pred[wontgo.top()][i]]);
            notgocount++;
        }
    }
}

cout<<gocount<<' '<<(n-notgocount)<<endl;

return 0;
}









