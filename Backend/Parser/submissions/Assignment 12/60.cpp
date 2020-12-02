#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int pakka_going=0;
int pakka_not_going=0;


void print_adjacency_list(vector<vector<int> > v)
{
    for(int i=0; i< v.size(); i++)
    {
        for(int j=0; j< v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

class node
{
public:
    //Status = 1 for going, -1 for not going, 0 for undecided
    int name;
    int status;
    int number_of_friends;
    int number_required;
    node() {}
    node(int ni, int ti)
    {
        number_of_friends = ni;
        number_required = ti;

        if(number_required == 0)
        {
            pakka_going++;
            status = 1;
        }
        else if(number_required > number_of_friends)
        {
            pakka_not_going++;
            status = -1;
        }
        else status = 0;

    }
};

vector<node> people;
queue<int> going;
queue<int> not_going;
vector<vector<int> > predecessors;

int main()
{
    int no;
    scanf("%d",&no);
    people.resize(no);
    predecessors.resize(no);
    for(int i=0; i<no; i++)
    {
        int ti, ni;
        scanf("%d",&ti);
        scanf("%d",&ni);
        people[i] = node(ni, ti);
        if(( people[i].status) == 1 ) going.push(i);
        else if(( people[i].status) == -1 ) not_going.push(i);
        for(int j=0; j<ni; j++)
        {
            int temp;
            scanf("%d",&temp);
            predecessors[temp].push_back(i);
        }
    }

    while(!not_going.empty())
    {
        int person_name = not_going.front();
        for(int i=0; i< predecessors[person_name].size(); i++)
        {
            int num = predecessors[person_name][i];
            if((people[num].status) == 0)
            {
                //node pred;
                //pred = people[predecessors[person_name][i]];
                people[num].number_of_friends--;
                if(people[num].number_required > people[num].number_of_friends)
                {
                    people[num].status = -1;
                    pakka_not_going++;
                    not_going.push(predecessors[person_name][i]);
                }
            }
        }
        not_going.pop();
        //cout<<"Yo1"<<endl;
    }

    while(!going.empty())
    {
        int person_name = going.front();
        for(int i=0; i< predecessors[person_name].size(); i++)
        {
            int num = predecessors[person_name][i];
            if((people[num].status) == 0)
            {
                //node pred = people[predecessors[person_name][i]];
                people[num].number_of_friends--;
                people[num].number_required--;
                if(people[num].number_required == 0)
                {
                    people[num].status = 1;
                    pakka_going++;
                    going.push(predecessors[person_name][i]);
                }
            }
        }
        going.pop();
        //cout<<"Yo"<<endl;
    }


//print_adjacency_list(predecessors);
    printf("%d %d",pakka_going,no-pakka_not_going);
    return 0;
}
