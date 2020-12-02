#include<iostream>
#include<vector>
#include<list>
using namespace std;

class counter{

    int n;
    vector< list< list< int> >::iterator > Ba;
    vector< list< int>::iterator > Bb;
    vector< int> Bint;

    list< list< int> > A;
    list< list< int> >::iterator a;
    list< list< int> >::iterator aaaa;
    list< int>::iterator b;

public:
    //Max Count of Objects
    int findMax(){
        a=A.end();
        a--;
        if((a==aaaa)&&((*aaaa).size() ==0)){--a;}
            int i= *((*a).begin());
            return Bint[i];
    };

    //Increment Function
    void increment(int i){
        a=Ba[i];
        list< list< int> >::iterator aaa=Ba[i];
        b=Bb[i];
        int maxele=findMax();
        (*a).erase(b);



            if(Bint[i]== maxele ){
                a++;
                //cout<<"assfSF";
                if(a != aaaa){
                        //cout<<"sdg";
                    list< int > dummy;
                    dummy.push_back(i);
                    A.push_back(dummy);
                    a=A.end();
                    a--;
                }

                else{
                        //cout<<"sdgj";
                    (*aaaa).push_back(i);
                    a=aaaa;
                }

            }

            else{


                if(a==aaaa){(*a).push_back(i);a=aaaa;}
                else{int test=*((*a).begin());

                //cout<<test<<Bint[test]<<Bint[i];

                if((Bint[test]==Bint[i]+1)){
                    (*a).push_back(i);
                }
                else{
                    list< int> dummy;
                    dummy.push_back(i);
                    A.insert(a,dummy);
                    --a;

                }
                }

            }

            Ba[i]=a;
            b=(*a).end();
            b--;
            Bb[i]=b;
            Bint[i]++;
            if(((*aaa).size() ==0)&&(aaa !=aaaa)){
                    A.erase(aaa);
            }


    };

    //Decrement Function
    void decrement(int i){
        a=Ba[i];
        list< list< int> >::iterator aaa=Ba[i];
        b=Bb[i];
        (*a).erase(b);

        if(a != A.begin()){
            --a;int checki=0;;
            if(a!= aaaa){checki= *((*a).begin());}

            if((Bint[checki]+1 == Bint[i])||(a == aaaa)){

                (*a).push_back(i);
            }

            else{

                a++;
                list< int> dummy;
                dummy.push_back(i);
                A.insert(a,dummy);
                a--;
            }

        }

        else{
            list< int> dummy;
            dummy.push_back(i);
            A.insert(a,dummy);
            a--;
        }

        Ba[i]=a;
        b=(*a).end();
        b--;
        Bb[i]=b;
        Bint[i]--;


        if(((*aaa).size() ==0)&&(aaa !=aaaa)){

            A.erase(aaa);
        }
    return;
    };

    //Reset Function
    void reset(int i){
        list< list< int> >::iterator aaa=Ba[i];
        b=Bb[i];
        (*aaa).erase(b);

        (*aaaa).push_back(i);

            Ba[i]=aaaa;
            b=(*aaaa).end();
            b--;
            Bb[i]=b;
            Bint[i]=0;

            if((*aaa).size() == 0){
                A.erase(aaa);
                //cout<<"gjsbfs";
            }


            return;
    };

    //Count Function
    int count(int i){
        return Bint[i];
    }

    //numMax Function
    int numMax(){
        a=A.end();
        a--;
        if((a==aaaa)&&((*aaaa).size() ==0)){--a;}
        return (*a).size();
    }

    //printMax Function
    void printMax(){
        a=A.end();
        a--;
        if((a==aaaa)&&((*aaaa).size() ==0)){--a;}
        b=(*a).begin();
        for(b;b != (*a).end();++b){

            if(b==(*a).begin()){cout<< *b;}
            else{cout<<" "<< *b;}
        }
    return ;}

    //Constuctor function
    counter(int input){
        n=input;
        list<int> dubby;
        for(int i=0;i<n;i++){
            dubby.push_back(i);
        }
        A.push_back(dubby);
        aaaa=A.begin();
        a=A.begin();
        b=(*a).begin();
        for(int i=0;i<n;i++){
            int j=0;
            Ba.push_back(a);
            Bb.push_back(b);
            Bint.push_back(j);
            b++;
        }
    };
};
