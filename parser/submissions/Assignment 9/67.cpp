#include <iostream>
using namespace std;

class boolfunc {
    int node;
    int value=0;
    boolfunc* Tl=nullptr;
    boolfunc* Tr=nullptr;
    int numofterms;

    void makechildren () {

    }

  public:

    boolfunc() {;}      // constructor that does nothing

    ~boolfunc() {       // destructor that should free all allocated memory
        ****
    }

    boolfunc( boolfunc const &) {    // copy constructor

    }

    void operator+=(boolfunc const & fxn) {   // or operator
        if(node == fxn.node) {
            if(fxn.Tl != nullptr) {Tl+=fxn.Tl;}
            if(fxn.Tr != nullptr) {Tr+=fxn.Tr;}
            if(value != 0 && value != fxn.value) {value = 0;}
        }
        else if(node > fxn.node) {
            if(value = -1) {Tr=fxn; value=0; Tl.node=-1;}
            else if(value = 1) {Tl=fxn; value=0; Tr.node=-1;}
            else {
            if(Tl == nullptr) {Tl=fxn; Tr+=(fxn);}
            else if(Tr == nullptr) {Tr=fxn; Tl+=(fxn);}
            else {Tr+=(fxn); Tl+=(fxn);}
            }
        }
        else {
            boolfunc* T1,T2 = fxn;
            T1.node = node;
            T1.Tl = Tl; T1.Tr = Tr;
            T2.Tl+=T; T2.Tr+=T;
            node = fxn.node;
            Tl = T2.Tl; Tr = T2.Tr;
        }
    }

    void operator*=(boolfunc const & fxn) {  // and operator
        if(node == fxn.node){
            if(fxn.Tl != nullptr) {Tl*=fxn.Tl;}
            if(fxn.Tr != nullptr) {Tr*=fxn.Tr;}
            if(fxn.value != 0 && value != fxn.valu) {
                if(value == 0) {value=fxn.value;}
                if(value != 0) {node=0;}
            }
        }
        else if(node > fxn.node) {
            if(value = -1) {Tl=fxn; value=0; Tr.node=0;}
            else if(value = 1) {Tr=fxn; value=0; Tl.node=0;}
            else {
            if(Tl == nullptr) {Tr*=(fxn);}
            else if(Tr == nullptr) {Tl*=(fxn);}
            else {Tr*=(fxn); Tl*=(fxn);}
            }
        }
        else {
            boolfunc* T1,T2 = fxn;
            T1.node = node;
            T1.Tl = Tl; T1.Tr = Tr;
            T2.Tl*=T; T2.Tr*=T;
            node = fxn.node;
            Tl = T2.Tl; Tr = T2.Tr;
        }
    }

    void operator~() {  // not operation
        boolfunc* T,T1=(~Tl),T2=(~Tr);
        T*=T1; T*=T2;
        Tl=T2; Tl+=T;
        Tl=T1; Tl+=T;
    }

    bool operator==(boolfunc const & fxn) {     // check for equality.
        if(value==fxn.value && Tl==fxn.Tl && Tr==fxn.Tr) {return true;}
    }

    void read() {
        int numofliterals;
        cin>>numofterms;
        for(int i=0; i<numofterms; i++) {
            cin>>numofliterals;
            cin>>node;
            if(node < 0) {
                for(int j=1; j<numofliterals; j++){}
            }
        }
    }

    void print() {

    }

    void subst(int i, bool v) {

    }
}












