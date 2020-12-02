#include <iostream>
#include <list>
using namespace std;

class node
{
public:
    int threshold;
    int nfriends;
    list < node*> pf;
    bool defgoin=false;
    bool defnotgoin=false;
    int index;
};


int main()
{
    //cout<<"What"<<endl;
    int n;
    int m;
    cin>>n;
    node L[n];
    int t_v;
    int n_v;
    for(int i=0; i<n; i++)
    {
        //cout<<"1"<<endl;
        cin>>t_v;
        cin>>n_v;
        if(t_v==0)
        {
            L[i].defgoin=true;
        }
        if(n_v<t_v)
        {
            L[i].defnotgoin=true;
        }
        L[i].threshold=t_v;
        L[i].nfriends=n_v;
        L[i].index=i;
        for(int j=0; j<n_v; j++)
        {
            cin>>m;
            L[m].pf.push_back(&L[i]);
        }
    }
    //cout<<"done"<<endl;
    list <int> q;
    int min=0;
    int count=0;
    int count2=0;
        int q_nodes[n];
    for(int i=0; i<n; i++)
    {
        q_nodes[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        if(L[i].defgoin)
        {
            q.push_back(i);
            count++;
            q_nodes[i]=1;
            //cout<<i<<endl;
        }
                if(L[i].defnotgoin)
        {
            //q.push_back(i);
            count2++;
            //cout<<i<<endl;
        }
    }
    min=count+1;
    if(min==0)
    {
    cout<<n<<" "<<n;return 0;
    }
        if(count2==n)
    {
    cout<<"0"<<" "<<"0";return 0;
    }
    int max = n- count2;
    //list<int>::iterator i = q.begin();
      //  while(i!=q.end())
        //{

        //cout<<(*i)<<endl;
        //i++;
        //}

    while(!q.empty())
    {
        int v = *(q.begin());
        //cout<<v<<endl;
        q.pop_front();
        list<node*>::iterator i = L[v].pf.begin();
        while(i!=L[v].pf.end())
        {
        //cout<<"done";
            if(!q_nodes[(*i)->index])
            {

                if((*i)->defgoin)
                {
                    i++;continue;
                }
                if((*i)->defnotgoin)
                {
                    i++;continue;
                }
                (*i)->threshold--;
                if((*i)->threshold==0)
                {
                    //cout<<q_nodes[(*i)->index]<<endl;

                    q.push_back((*i)->index);
                    q_nodes[(*i)->index]=1;
                    count++;
                }
            }
            i++;
            //cout<<"done"<<endl;
        }



    //cout<<v<<endl;
}
    /*  for(int i=0;i<n;i++)
      {
              list<node*>::iterator j = L[i].pf.begin();
          while(j!=L[i].pf.end())
          {
          cout<<(*j)->index<<" ";
          j++;
    }
    cout<<endl;
    }
    */
    cout<<count<<" "<<min;
}
