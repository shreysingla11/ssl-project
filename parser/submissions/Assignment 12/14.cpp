#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Person
{
public:
    int index;
    int t;
    int n;

    bool marked ;
    vector< int > friends;
    list < Person * > friends_inverse;
    Person(int t_index,int ti, int ni)
    {
        marked=false;
        index= t_index;
        t=ti;
        n=ni;
        friends.resize(ni);

    }
};

class answer
{
public:
    int def_going;
    int def_not_going;
    answer()
    {
        def_going=0;
        def_not_going=0;
    }
};



void DFS(Person * node , answer * A)
{   bool goin = false;
    if(node->t==0)
    {
    //cout<<A->def_going<<endl;
    A->def_going++;
    node->marked=true;
    goin=true;
    }
    else
    {
        if((node->t)>(node->n))
        {
        A->def_not_going++;
        node->marked=true;
        goin = false;
        }
        else
        {
            return ;
        }



    }
    list < Person * > :: iterator iter;
        for (iter=(node->friends_inverse).begin();iter!=((node->friends_inverse).end());++iter){
       //cout<< (*iter)->marked <<endl;
            if((*iter)->marked==false){
            //cout<<"joke"<<endl;
            (*iter)->n =(*iter)->n -1;
                if(goin){
                if((*iter)->t!=0){


                     (*iter)->t = (*iter)->t - 1;}
                    //cout<<(*iter)->t<<endl;
                }
                else{

                }
                DFS((*iter) , A);
            }

        };
    return;
}







int main()
{
    int N;
    cin>>N;
    int temp_t;
    int temp_n;
    int temp_j;
    vector < Person * > persons(N);
    for(int i=0; i<N; i++)
    {
        cin>>temp_t;
        cin>>temp_n;
        persons[i] = new Person(i,temp_t,temp_n);

        for(int j=0; j<temp_n; j++)
        {
            cin>>temp_j;
            (persons[i]->friends)[j]=(temp_j);
        }

    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<persons[i]->n; j++)
        {//cout<<"jop"<<endl;
            (persons[(persons[i]->friends)[j]]->friends_inverse).push_back(persons[i]);
            //cout<<(persons[j]->friends_inverse).size()<<endl;
        }
    }

    ///main outer loop


    answer * A = new answer;

    for(int i=0; i<N; i++)
    {
        if(persons[i]->marked==false){
        DFS(persons[i],A);}

    }

    cout<< A->def_going <<" "<< (N - A->def_not_going) <<endl;


    return 0;
}



