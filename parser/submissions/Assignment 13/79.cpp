# include <iostream>
# include <limits.h>
using namespace std;

bool relax(int i,int j,int** W,int**A,int v) {
    bool changed;
    changed = false;
    int u = (2*v)+1;
    if (W[i][j] > 0) {
        for(int gj=1; gj<u; gj++) {
            //cout<<gj<<j<<i;
            if(A[gj][j] > A[gj-1][i] + W[i][j]) {
                A[gj][j] = A[gj-1][i] + W[i][j];
                //cout<<A[gj-1][i];
                //cout<<A[gj-1][i] + W[i][j];
                //cout<<A[gj][j]<<endl;
                changed = true;
            }
         }
    }
    else {
        for(int gj=0; gj<u-1; gj++) {
            //cout<<gj<<j;
            if(A[gj][j] > A[gj+1][i] - W[i][j]) {
                A[gj][j] = A[gj+1][i] - W[i][j];
                //cout<<A[gj][j]<<endl;
                changed = true;
            }
         }
    }
    //cout<<i<<" "<<j<<endl;
    return changed;
}
int main() {
    int v;cin>>v;
    int** W = new int*[v];
    for(int i = 0; i < v; i++) {
        W[i] = new int[v];
    }
    //example begin
    for(int i=0; i < v; i++) {
        for(int j=0; j < v; j++) {
            cin>>W[i][j];
        }
    }
    //example end
    //Min array
    int u = (2*v)+1;
    //cout<<u<<endl;
    int** A = new int*[u];
    for(int i = 0; i < u; i++) {
        A[i] = new int[v];
    }
    //Inistiallisation
    for(int i=0; i<2*v-1; i++) {
        for(int j=0; j<v; j++) {
            A[i][j] = 100000;
        }
    }
    A[v-1][0] = 0;
    /*for(int i=0; i<2*v-1; i++) {
        for(int j=0; j<v; j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }*/

    bool stop=true;
    bool changed = true;
    int x=0;
    while(stop) {
        stop = false;
        for(int i=0; i < v; i++) {
            for(int j=0; j < v; j++) {
                changed = relax(i,j,W,A,v);
                if(changed) {
                    stop = true;
                }
            }
        }
        x++;
        if(x == 2) {stop = false;}
    }
    int min_cost;
    for(int i=0; i<v; i++) {
        min_cost = 100000;
        for(int j=0; j<v; j++) {
            if(A[j][i] < min_cost) {min_cost = A[j][i];}
        }
        cout<<min_cost<<endl;
    }
    /*for(int i=0; i<u; i++) {
        for(int j=0; j<v; j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
