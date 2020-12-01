#include<iostream>
#include<vector>
using namespace std;

class boolfunc{


    vector<int> v1;
public:
    boolfunc *leftc,*rightc;
int x;
    boolfunc(){
        x = -1;
        leftc = NULL;
        rightc = NULL;
    }
    ~boolfunc(){
        if(this->leftc!=NULL){delete this->leftc;}
        if(this->rightc!=NULL){delete this->rightc;}
        delete leftc;
        delete rightc;
    }

    boolfunc( boolfunc const &fin){//finput
        x = fin.x;
        leftc = new boolfunc(*(fin.leftc));
        rightc = new boolfunc(*(fin.rightc));
    }
    void operator+=(boolfunc const &){return;}
    void operator*=(boolfunc const &){return;}
    void operator~(){return;}
    bool operator==(boolfunc const &){return true;}

    void read(){
        int nterm;
        cin >>nterm;
        v1.push_back(nterm);
        v1.push_back(-1000000);
        for(int i=0;i<nterm;i++){
            int nlit;
            cin>>nlit;
            v1.push_back(nlit);
            v1.push_back(-1000000);
            for(int j=0;j<nlit;j++){
                int value;
                cin >> value;
                v1.push_back(value);
            }
            v1.push_back(-1000000);
        }
        return;
    }

    void print(){
        cout<<"printing"<<endl;
        int l = v1.size();
        for(int i=0;i<l;i++){
            if(v1[i]==-1000000){cout<<endl;}
            else{cout<<v1[i]<<" ";}
        }
        return;
    }

    void subst(int i, bool v){return;};


};
