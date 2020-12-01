#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class node{
  public:
    long long int t;
    long long int n;
    vector<long long int> v;
    vector<long long int> pre;
    bool b;
    long long int ng;
    long long int nn;
    node(){
        b=false;
        ng=0;
        nn=0;
    }
};

int main(){
    long long int num;
    long long int min=0,max=0;
    cin>>num;
    node* nodes=new node[num];
    stack<long long int> sg,sn;
    long long int su=0;
    for(long long int j=0;j<num;j++){
        cin>>nodes[j].t;
        cin>>nodes[j].n;
        nodes[j].v.resize(nodes[j].n);
        for(long long int k=0;k<nodes[j].n;k++){
            cin>>nodes[j].v[k];
            nodes[nodes[j].v[k]].pre.push_back(j);
        }
    }
    for(long long int i=0;i<num;i++){
        if(nodes[i].t==0){sg.push(i);}
        else if(nodes[i].t>nodes[i].n){sn.push(i);}
        else{nodes[i].b=true;su++;}
    }
    long long int index;
    while((!sg.empty())||(!sn.empty())){
        if(!sg.empty()){
            index = sg.top();
            min++;max++;
            sg.pop();
            long long int pi;
            for(long long int j=0;j<nodes[index].pre.size();j++){
                pi = nodes[index].pre[j];
                if(nodes[pi].b){
                    nodes[pi].ng++;
                    if(nodes[pi].ng>=nodes[pi].t){
                        nodes[pi].b=false;
                        su--;
                        sg.push(pi);
                    }
                }
            }
        }
        else{
            index = sn.top();
            sn.pop();
            long long int pi;
            for(long long int j=0;j<nodes[index].pre.size();j++){
                pi = nodes[index].pre[j];
                if(nodes[pi].b){
                    nodes[pi].nn++;
                    if(nodes[pi].n-nodes[pi].nn<nodes[pi].t){
                        nodes[pi].b=false;
                        sn.push(pi);
                        su--;
                    }
                }
            }
        }
    }
    max = max+su;
    cout<<min<<" "<<max<<endl;
return 0;
}

