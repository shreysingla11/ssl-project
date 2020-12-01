#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;

class mypair{
public:
    int v=0,i=0;
};

int main(){
    int n;
    scanf("%d",&n);
    vector<long long> B(n);
    vector<bool> E(n);
    vector<vector<long long> > C(n,B);
    vector<vector<long long> > A((4*n)+1,B);
    vector<vector<bool> > S((4*n)+1,E);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&C[i][j]);
            A[i][j] = 10000000000000;
            A[i][j+n] = 10000000000000;
            A[i][j+(2*n)] = 10000000000000;
            A[i][j+(3*n)] = 10000000000000;
            S[i][j] = false;
            S[i][j+n] = false;
            S[i][j+(2*n)] = false;
            S[i][j+(3*n)] = false;
        }
        A[i][(4*n)] = 1000000000000;
        S[i][(4*n)] = false;
    }
     queue<mypair> q;
    for(int t=0;t<=2*n;t++){
        A[0][t] = 0;
          mypair p;
    p.v = 0;
    p.i = t;
    S[0][t]=true;
    q.push(p);
    }


    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    mypair p;
    p.v = 0;
    p.g = 0;
    queue<mypair> q;
    q.push(p);
    while(!q.empty()){
        mypair temp;
        temp = q.front();
        q.pop();cout<<"a"<<endl;
        S[temp.v][temp.g] = false;
        for(int i=0;i<n;i++){cout<<"b"<<endl;
            if(C[temp.v][i]<0){//good edge
                long long templ = (A[temp.v][temp.g] + (-1)*C[temp.v][i]);
                int index = temp.g;
                if(index>(n+1)){index--;}
                if(index==(n+1)){index=0;}
                if(index==n){cout<<"infinity"<<endl;}

                if(A[i][index]>templ){
                    A[i][index] = templ;
                    if(S[i][index]==false){
                        mypair tempp;
                        tempp.v = i;
                        tempp.g = index;
                        q.push(tempp);
                        S[i][index]=true;
                    }
                }
            }
            else{//bad edge
                long long templ = (A[temp.v][temp.g] + C[temp.v][i]);
                int index = temp.g -1;
                if(index<0){index=((-1)*index)+n;}
                if(A[i][index]>templ){
                    A[i][index] = templ;
                    if(S[i][index]==false){
                        mypair tempp;
                        tempp.v = i;
                        tempp.g = index;
                        q.push(tempp);cout<<"p"<<endl;
                        S[i][index]=true;
                    }
                }

            }
        }
    }
    */

    while(!q.empty()){
        mypair temppair = q.front();
        q.pop();
        S[temppair.v][temppair.i]=false;
        for(int t=0;t<n;t++){
            if(C[temppair.v][t]<0){//good
                int index = temppair.i;
                if(index==(4*n)){continue;}
               else{index++;}
                long long temp = A[temppair.v][temppair.i] + (-1)*C[temppair.v][t];
                if(A[t][index]>temp){
                    A[t][index] = temp;
                    if(S[t][index]==false){
                        mypair pair1;
                        pair1.v = t;
                        pair1.i = index;
                        q.push(pair1);
                        S[t][index] = true;
                    }
                }
            }
            else{//bad
                int index = temppair.i;
                if(index==(0)){continue;}
                else{index--;}
                long long temp = A[temppair.v][temppair.i] + C[temppair.v][t];
                if(A[t][index]>temp){
                    A[t][index] = temp;
                    if(S[t][index]==false){
                        mypair pair1;
                        pair1.v = t;
                        pair1.i = index;
                        q.push(pair1);
                        S[t][index] = true;
                    }
                }
            }
        }
    }



    for(int i=0;i<n;i++){
        cout<<A[i][2*n]<<endl;
    }



}
