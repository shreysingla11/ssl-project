#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct person{
   int name;
   int threshold;
   int num_friends;
};

int main(){

    int num_persons;
    vector<vector<int> >network;
    vector<vector<int> >rev_network;
    vector<bool>pushed;
    cin>>num_persons;
    rev_network.resize(num_persons);
    for(int i=0;i<num_persons;i++){
        vector<int>v;
        int thres,num;
        cin>>thres;cin>>num;
        v.push_back(thres);v.push_back(num);
        for(int j=0;j<num;j++){
            int k;
            cin>>k;
            v.push_back(k);
            (rev_network[k]).push_back(i);
        }
        network.push_back(v);
        pushed.push_back(false);
    }

    queue <int>q_true;
    int true_count=0;
    queue <int>q_false;
    int false_count=0;

    for(int i=0;i<network.size();i++){
        if(network[i][0] > network[i][1]){q_false.push(i);pushed[i]=true;false_count++;}
        if(network[i][0] == 0){q_true.push(i);true_count++;}
    }
    //cout<<"over"<<endl;
    while(!q_true.empty()){
    //cout<<q_true.size()<<endl;
    //cout<<q_true.front()<<" ";
         for(int i=0;i<rev_network[q_true.front()].size();i++){
            //  cout<<rev_network[q_true.front()][i]<<" ";
              network[rev_network[q_true.front()][i]][0]--;
              if(network[rev_network[q_true.front()][i]][0] == 0)
              {q_true.push(rev_network[q_true.front()][i]);true_count++;}
              ////threshold may be negative
         }
        // cout<<endl;
         q_true.pop();
    }

    cout<<true_count<<" ";

    while(!q_false.empty()){
    //cout<<q_true.size()<<endl;
    //cout<<q_false.front()<<" ";
         for(int i=0;i<rev_network[q_false.front()].size();i++){
             // cout<<rev_network[q_false.front()][i]<<" ";
              network[rev_network[q_false.front()][i]][1]--;
              if(network[rev_network[q_false.front()][i]][0] > network[rev_network[q_false.front()][i]][1]
               && pushed[rev_network[q_false.front()][i]])
              {q_false.push(rev_network[q_false.front()][i]);false_count++;pushed[rev_network[q_false.front()][i]]=true;}
              ////threshold may be negative
         }
         q_false.pop();
    }

    cout<<num_persons-false_count<<endl;
}
