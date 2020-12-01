#include <iostream>
#include <set>
#include <vector>

using namespace std;

int mod(int x) {
    if(x>=0){return x;}
    else{return (-1*x);}
};

/*
class node {
public:
    bool x;
    int num;
    node *left, *right;
};
*/
class boolfunc {
    //boolfunc *root;
    int x;
    int num;
    boolfunc *left, *right;
    vector<vector<int> > A;
    vector<vector<int> > Al;
    vector<vector<int> > Ar;

public:
    bool getbool(){
        return x;
    }

    void setnum(int n) {
        num = n;
    }

    void setleft( boolfunc *b) {
        left = b;
    }

    void setright( boolfunc *b) {
        right = b;
    }

    boolfunc() {
        left = NULL;
        right = NULL;
    }

    ~boolfunc() {

    }

    boolfunc (boolfunc &a){

    }

    boolfunc create (vector<vector<int> > A, int s, int mini, int coun) {
        int minl = 0;
        int minr = 0;
        int countr = 0;
        int countl = 0;
        vector<vector<int> > Ar;
        vector<vector<int> > Al;
        boolfunc var;
        boolfunc *var12;
        if(coun == 0){var.setnum(-1);return var;}
        //var.setnum(mini);
        for (int c = 0 ; c < coun ; c++) {
            if(A[c].size() == s){var.setnum(-1);return var;}
            //if(A[i][s] == mini)
            if(A[c][s] == mini){
                Ar.push_back(A[c]);
                if(A[c][s+1]<=minr){minr=mod(A[c][s+1]);}
                countr++;
            }
            else{
                if(A[c][0] == (-1 * num)){
                    Al.push_back(A[c]);
                    if(A[c][1]<=minl){minl=mod(A[c][1]);}
                    countl++;
                }
                else{
                    Ar.push_back(A[c]);
                    countr++;
                    if(A[c][1]<=minr){minr=mod(A[c][1]);}
                    Al.push_back(A[c]);
                    countl++;
                    if(A[c][1]<=minl){minl=mod(A[c][1]);}
                }
            }
        }
        var12= &create(Al,s+1,minl,countl);
        var.setleft(var12);
        var12= &create(Ar,s+1,minr,countr);
        var.setright(var12);
    };
    void operator+= (boolfunc &a) {

    }

    void operator*= (boolfunc &a) {

    }

    void operator~() {

    }

    bool operator== (boolfunc &a) {
        if(x == a.getbool()){return true;}
        else{return false;}
    }

    void read() {
        //set<int> aleft;
        //set<int> aright;
        int minl = 0;
        int minr = 0;
        int countr = 0;
        int countl = 0;
        vector<int> b;
        /*node *tempr;
        tempr = new node;
        node *temp;
        temp = new node;*/
        int n,m,k,pr=0;cin>>n;
        for (int i = 0 ; i < n ; i++){
            cin>>m;
            for (int j = 0 ; j < m ; j++){
                cin>>k;
                b.push_back(k);
                //all.insert(mod(k));
            }
            A.push_back(b);
            b.clear();
        }
        num = mod(A[0][0]);//*all.begin();
        //boolfunc *tempr;
        //tempr = new boolfunc;
        for (int c = 0; c < n; c++){
            if(A[c][0] == num){
                Ar.push_back(A[c]);
                if(A[c].size() != 1){if(A[c][1]<=minr){minr=mod(A[c][1]);}}
                countr++;
            }
            else{
                if(A[c][0] == (-1 * num)){
                    Al.push_back(A[c]);
                    if(A[c].size() != 1){if(A[c][1]<=minl){minl=mod(A[c][1]);}}
                    countl++;
                }
                else{
                    Ar.push_back(A[c]);
                    countr++;
                    if(A[c].size() != 1){if(A[c][1]<=minr){minr=mod(A[c][1]);}}
                    Al.push_back(A[c]);
                    countl++;
                    if(A[c].size() != 1){if(A[c][1]<=minl){minl=mod(A[c][1]);}}
                }
            }
        }
        left = &create(Al,1,minl,countl);
        right = &create(Ar,1,minr,countr);
        boolfunc *tempr;
        tempr = new boolfunc;
    }

                /*
                if(k<0){pr=-1;}
                else{pr=1;}
                temp->num = mod(k);
                temp->left = NULL;
                temp->right = NULL;
                if(j==0){
                    root = temp;
                    //if(k<0){pr=-1;}
                    //else{pr=1;}
                }
                else{

                }
                tempr = temp;*/

    void print () {

    }

    void subst (int i, bool v) {

    }
};

boolfunc create (vector<vector<int> > A, int s, int mini, int coun) {
    int minl = 0;
    int minr = 0;
    int countr = 0;
    int countl = 0;
    boolfunc var;
    //var.setnum(mini);
    for (int i = 0 ; i < coun ; i++) {
        if(A[i].size() == s){var.setnum(-1);return var;}
    }
};
