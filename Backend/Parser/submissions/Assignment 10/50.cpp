#include <iostream>
#include <vector>

using namespace std;
//2^{i-1} = i
/*
*   Note that we are not using A[0][][]
*/
int left(int node){
    return (2*node);
}

int r(int node){
    return ((2*node) + 1);
}

int p(int node){
    return (node / 2);
}

void finding (int i, int j,int n, int node, int &coun, vector<vector<vector<int> > > A, vector<int> l){
//int h,node,coun;
if(i>=j){return;}
if(j>=n/2){
    if(i>=n/2){coun += A[node][0][j] - A[node][0][i]; return;}
    else{coun += A[node][0][j];
        if (A[node][1][j] > 0){
            if (l[A[node][1][j]] <= i){return;}
            else {finding(i,l[A[node][1][j]],n/2,left(node),coun,A,l);}
        }else{finding(i,(n/2)-1,n/2,left(node),coun,A,l);}
    }
}
else{finding(i,j,n/2,left(node),coun,A,l);}
};

struct distinct {
public:
    vector<int> a;
    vector<int> l;
    vector<vector<vector<int> > > A;
    //int A[2*n][2][n];

    void distinctset(vector<int> b){
        vector<vector<int> > lbw;
        a = b;l = b;l[0]=-1;lbw.push_back(a);lbw.push_back(a);
        int n = a.size();
        int p, q;
        for (p = 1 ; p < n ; p++){
            for (q = p-1 ; q >=0 ; q--) {
                if(a[q]==a[p]){break;}
            }
            l[p]=q;
        }
        for (int r = 0 ; r < 2*n ; r++){
            A.push_back(lbw);
        }
int j,k1,k,m;
for (int i = 1 ; i < n ; i *= 2 ){
    for (k = 0 ; k < i ; k++){
        A[i+k][0][0] = 0;A[i+k][1][0]=-1;
        for (j = 1 ; j < n ; j++){
            if(l[j] >= ((k*n) + (n/2))/i  &&  l[j] < (k+1)*n/i){
                A[i+k][0][j]=1;
                //if(kn/2^{i-1} + n/2^i  ((k*n) + (n/2))/i, (k+1)*n/i)
                for (m = j-1 ; m>=0 ; m--){
                    if(l[m] >= k*n/i  &&  l[m] < ((k*n) + (n/2))/i){break;}
                }
                A[i+k][1][j]=m;
            }else{
                A[i+k][0][j] = 0;
                for (m = j-1 ; m>=0 ; m--){
                    if(l[m]>=((k*n) + (n/2))/i  &&  l[m]<(k+1)*n/i){break;}
                }
                A[i+k][1][j]=m;
            }

            A[i+k][0][j] += A[i+k][0][j-1];
        }
    }
    /*
    for (k1 = i ; k1 < 2*i ; k1++){
        for (k = 0 ; k < i ; k++){
            for (s = 0 ; s < n ; s++){
                if(l[s]>=k*n/i  &&  l[s]<(k+1)*n/i){

                }
            }
        }
    }*/
}
    }

    int num_distinct(int i1, int j1){
        int k = 0;
        int coun = 0;int n = a.size();
        finding(i1,j1,n,1,coun,A,l);
        k = coun;
        return j1-i1+1-k;
    }
};
/*
int main (){

    vector<int> b;
    b.push_back(1);b.push_back(2);b.push_back(1);b.push_back(3);
    b.push_back(2);b.push_back(1);b.push_back(1);b.push_back(3);
    distinct W;
    W.distinctset(b);
    for (int i = 0 ; i < 8 ; i++){
        cout<<W.A[3][0][i];
    }

    return 0;
}*/
/*
int l(int node){
    return ((2*node) + 1);
}

int r(int node){
    return ((2*node) + 2);
}

int p(int node){
    return ((node-1) / 2);
}

void build (int node, int total, int sum, int &a[][]){

    return;
}

int main(){

    int n, val, sum=0;
    cin >> n;
    int m[n], a[4*(n-1)][3];
    for (int i = 0 ; i < n ; i++){
        m[i]=i;sum += m[i];
    }
    build(0,n,sum,a);

    return 0;
}*/
