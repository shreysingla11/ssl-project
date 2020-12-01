#include<iostream>
#include<vector>

using namespace std;

class social_network
{
public:
    int b;
    vector<vector<int> > friends;
    vector<int> *predecessor;
    vector<int> must_see;
    vector<int> never_see;
    vector<int> n_f_g;
    vector<int> n_f_n_g;
    vector<bool> going;
    vector<bool> not_going;
    void increment(vector<int> v)
    {
        int size=v.size();
        for(int i=0;i<v.size();i++)
        {
            if(going[v[i]])continue;

            else
            {
                n_f_g[v[i]]++;
                if(n_f_g[v[i]]>=friends[v[i]][0])
                {
                    going[v[i]]=true;
                    must_see.push_back(v[i]);
                }
            }
        }
    }

    void decrement(vector<int> v)
    {
        int size=v.size();
        for(int i=0;i<size;i++)
        {
            if(not_going[v[i]])continue;

            else
            {
                n_f_n_g[v[i]]++;
                if(friends[v[i]][1]-n_f_n_g[v[i]]<friends[v[i]][0])
                {
                    not_going[v[i]]=true;
                    never_see.push_back(v[i]);
                }
            }
        }
    }

    void DFS()
    {
        int size1=must_see.size();
        for(int i=0;i<size1;i++)
        {
            increment(predecessor[must_see[i]]);
            size1=must_see.size();
        }

        int size2=never_see.size();
        for(int i=0;i<size2;i++)
        {
            decrement(predecessor[never_see[i]]);
            size2=never_see.size();
        }

        size2=never_see.size();
        cout<<size1<<" "<<(b-size2);
    }

    social_network(int n)
        {
            b=n;
            predecessor=new vector<int>[n];
            going.assign(n,false);
            not_going.assign(n,false);
            n_f_g.assign(n,0);
            n_f_n_g.assign(n,0);
            for(int i=0;i<n;i++)
            {
                vector<int> temp;
                int t,f;
                cin>>t>>f;

                temp.push_back(t);
                temp.push_back(f);

                if(t==0) must_see.push_back(i);
                if(t>f) never_see.push_back(i);

                for(int j=0;j<f;j++)
                {
                    int p;
                    cin>>p;
                    temp.push_back(p);
                    predecessor[p].push_back(i);
                }
                friends.push_back(temp);

            }

            for(int i=0;i<must_see.size();i++)
            {
                going[must_see[i]]=true;
            }

            for(int i=0;i<never_see.size();i++)
            {
                not_going[never_see[i]]=true;
            }

        }

};

int main()
{
    int n;
    cin>>n;
    social_network s(n);

    s.DFS();

}


