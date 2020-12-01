#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;


class person{

public:

int tbool;
int thresh;
int num_friends;
int num_go;
int num_notgo;
//vector<int> friends;
vector<int> whose;
person()
{
    tbool=-1;
    num_notgo=0;
    num_go=0;
}

void check()
{
    if(thresh<=num_go)
    {
    tbool=1;
    }
    else if(thresh>num_notgo)
    {
    tbool=0;
    }

}
};

int main()
{

int num=0;
scanf("%d",&num);
person* persons=new person[num];
vector<int> def_go;
vector<int> def_notgo;
for(int i=0;i<num;i++)
{
    int temp;
    scanf("%d",&temp);
    persons[i].thresh=temp;
    scanf("%d",&temp);
    persons[i].num_friends=temp;
    persons[i].num_notgo=persons[i].num_friends;
    persons[i].check();
    if(persons[i].tbool==0)
    {
        def_notgo.push_back(i);
    }
    else if(persons[i].tbool==1)
    {
        def_go.push_back(i);
    }
    for(int j=0;j<persons[i].num_friends;j++)
    {
        scanf("%d",&temp);
        //persons[i].friends.push_back(temp);
        persons[temp].whose.push_back(i);
    }

}

for(int i=0;i<def_notgo.size();i++)
{
    int temp=def_notgo[i];
    if(!persons[temp].whose.empty())
    {
        for(int j=0;j<persons[temp].whose.size();j++)
        {
            int x=persons[temp].whose[j];
            if(persons[x].tbool==-1)
            {
                persons[x].num_notgo--;
                persons[x].check();
                if(persons[x].tbool==0)
                {
                    def_notgo.push_back(x);
                }
                else if(persons[x].tbool==1)
                {
                    def_go.push_back(x);
                }
            }
        }
    }

}


for(int i=0;i<def_go.size();i++)
{
    int temp=def_go[i];
    if(!persons[temp].whose.empty())
    {
        for(int j=0;j<persons[temp].whose.size();j++)
        {
            int x=persons[temp].whose[j];
            if(persons[x].tbool==-1)
            {
                persons[x].num_go++;
                persons[x].check();
                if(persons[x].tbool==0)
                {
                    def_notgo.push_back(x);
                }
                else if(persons[x].tbool==1)
                {
                    def_go.push_back(x);
                }
            }
        }
    }
}

cout<<def_go.size()<<" "<<num-(def_notgo.size());

return 0;
}
