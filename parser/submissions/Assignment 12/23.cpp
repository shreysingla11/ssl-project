#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class person
    {
        public:
        int t;
        int n;
        list <int> friends;
        list <int> pred;

    };
int main()
{
    int totalnum;
    vector <person> graph;
    cin>>totalnum;
    graph.resize(totalnum);
    for(int i=0;i<totalnum;i++)
        {
            person p;
            cin>>p.t>>p.n;
            for(int j=0;j<p.n;j++)
                {
                    int next;
                    cin>>next;
                    (p.friends).push_back(next);
                    (graph[next].pred).push_back(i);
                    //cout<<"pushing back i="<<i<<" and new list front for "<<next<<" is i"<<(graph[next].pred).back();
                }
            graph[i].t=p.t;
            graph[i].n=p.n;
            graph[i].friends=p.friends;
        }
   /* for(int i=0;i<totalnum;i++)
        {
            //cout<<"person="<<i<<endl;
            person p=graph[i];
            //cout<<"t="<<p.t<<"n= "<<p.n;
            //cout<<" friends=";
            for (list<int>::iterator it=(p.friends).begin(); it != (p.friends).end(); ++it)
                    //cout << ' ' << *it;
            //cout<<" preds= ";
            for (list<int>::iterator it=(p.pred).begin(); it != (p.pred).end(); ++it)
                    //cout << ' ' << *it;
            //cout<<endl;

        }*/
    queue <int> s,q;
    int yes=0;
    int no=0;
    vector <int> visited(totalnum);
    for(int i=0;i<totalnum;i++)
        {
            person p=graph[i];
            if(p.t>p.n)
                {
                    s.push(i);
                    no++;
                    visited[i]=1;
                }
            if(p.t==0)
                {
                    s.push(i);
                    yes++;
                    visited[i]=1;
                }

        }
    q=s;
    while(!q.empty())
        {
            //cout<<q.front();
            q.pop();
        }
        while(!s.empty())
            {
                int top=s.front();
                person p=graph[top];
                //cout<<"examining person in stack"<<top<<endl;
                for (list<int>::iterator it=(p.pred).begin(); it != (p.pred).end(); ++it)
                    {
                        //cout<<"preds "<<(*it)<<endl;
                        if(visited[*it]==0)
                        {
                        //cout<<"not visited\n";
                        if(p.t>p.n)
                            {
                                graph[*it].n--;
                                //no++;
                                //visited[*it]++;
                               // cout<<"no\n";
                            }
                        if(p.t==0)
                            {
                                graph[*it].n--;
                                graph[*it].t--;
                                //yes++;
                                //visited[*it]++;
                               //cout<<"yes";
                            }
                        person test=graph[*it];
                        if(test.t>test.n)// || test.t==0)
                            {
                                //cout<<"pushed no\n";
                                s.push(*it);
                                visited[*it]++;
                                no++;
                            }
                        if(test.t==0)
                            {
                                //cout<<"pushed yes\n";
                                s.push(*it);
                                visited[*it]++;
                                yes++;
                            }
                            }
                    }
                    //cout<<"popping "<<s.front()<<endl;
                s.pop();

            }

            cout<<yes<<" "<<(totalnum-no)<<endl;
}
