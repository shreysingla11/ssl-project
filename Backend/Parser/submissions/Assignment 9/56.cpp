#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*struct node {
    int var;
    node* parent;
    node* lchild;
    node* rchild;

    node() {var =0; parent = NULL; lchild = NULL; rchild = NULL;}
}*/

class boolfunc {

int var;
//boolfunc* parent;
boolfunc* lchild;
boolfunc* rchild;

public:

boolfunc() {
    var = 0;
    lchild = NULL;
    rchild = NULL;
}

~boolfunc() {

}

boolfunc(boolfunc const& a) {

    var = a.var;
    if(a.lchild != NULL) {
        *lchild = *a.lchild;
    }
    if(a.rchild != NULL) {
        *rchild = *a.rchild;
    }
    if(a.rchild == NULL) {
        rchild = NULL;
    }
    if(a.lchild == NULL) {
        lchild = NULL;
    }
//    if(parent != NULL) {
//        *parent = *a.parent;
//    }
}

boolfunc operator+(boolfunc const& a) {

    boolfunc b;

    if(var == -1 || a.var == -1) {
        b.var = -1;
        b.lchild = NULL;
        b.rchild = NULL;
    }
    else if (var == 0) {
        b = a;
    }
    else if (a.var == 0) {
        b = *this;
    }
    else {
    if(var == a.var) {
        b.var = var;
        *b.lchild = *lchild + *a.lchild;
        *b.rchild = *rchild + *a.rchild;
    }
    else if(var < a.var) {
        b.var = var;
        *b.lchild = *lchild + a;
        *b.rchild = *rchild + a;
    }
    else {
        b.var = a.var;
        *b.lchild = *a.lchild + *this;
        *b.rchild = *a.rchild + *this;
    }
    }
    return b;
}

void operator+=(boolfunc const& a) {
    *this = *this + a;
}

boolfunc operator*(boolfunc const& a) {

    boolfunc b;

    if(var == 0 || a.var == 0) {
        b.var = 0;
        b.lchild = NULL;
        b.rchild = NULL;

    }
    else if (var == -1) {
        b = a;

    }
    else if (a.var == -1) {
        b = *this;

    }
    else {
    if(var == a.var) {
        b.var = var;
        *b.lchild = *lchild * *(a.lchild);
        *b.rchild = *rchild * *(a.rchild);

    }
    else if(var > a.var) {
        b.var = a.var;
        *(b.lchild) = *(a.lchild) * (*this);
        *(b.rchild) = *(a.rchild) * (*this);

    }
    else {
        b.var = a.var;
        *(b.lchild) = *(lchild) * (a);
        *(b.rchild) = *(rchild) * (a);

    }
    }
    return b;
}

void operator*=(boolfunc const& a) {
    *this = *this * a;
}

void operator~() {

    if(var == -1) {
    var = 0;
    return;
    }

    else if(var == 0) {
    var = -1;
    return;
    }

    else {
        ~(*lchild);
        ~(*rchild);
        return;
    }
}

bool operator==(boolfunc const& a) {

    if (var == a.var) {
        return (*lchild == *a.lchild && *rchild == *a.rchild);
    }
    else return 0;
};

void read() {

    int noOfTerms;
    cin>>noOfTerms;

    boolfunc func;

    while(noOfTerms) {
        int noOfVar;
        cin>>noOfVar;

        boolfunc *Term = new boolfunc;
        Term->var = -1;

        while(noOfVar) {

            int val;
            cin>>val;

            boolfunc *Var = new boolfunc;
            Var->lchild = new boolfunc;
            Var->rchild = new boolfunc;

            Var->var = abs(val);
            Var->lchild->var = 0;
            Var->rchild->var = -1;

            if(val<0) ~(*Var);

            *Term *= (*Var);
            noOfVar--;
        }
        *this = *this + *Term;
        noOfTerms--;
    }
};

void print() {



}

};

int main() {

boolfunc b;
boolfunc a(b);
b.read();

return 0;
}
