#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> strt;
    vector<int > end;
    int n;
    int w;
    int u;
    int v;
    int t1;
    int t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    char dir;
    int numship;
    int start;
    int len;
    int t2dis;
    int t1dis;
    int mininf =-1000000;
    int maxinf =1000000;
    for(int i=0; i<n; i++)
    {
        cin>>dir;
        if(dir=='E')
        {

            cin>>numship;
            end.push_back(mininf/((-1)*u));
            strt.push_back(maxinf/((-1)*u));
            for(int i=0; i<numship; i++)
            {
                cin>>len>>start;
                end.push_back(start/((-1)*u));
                strt.push_back((start-len)/((-1)*u));

            }

        }
        else
        {
            cin>>numship;
            strt.push_back(mininf/((1)*u));
            end.push_back(maxinf/((1)*u));
            for(int i=0; i<numship; i++)
            {
                cin>>len>>start;
                strt.push_back((start+len)/((1)*u));
                end.push_back((start)/((1)*u));

            }

        }

    }
    sort(strt.begin(),strt.end());
    sort(end.begin(),end.end());
    vector<int>::iterator i=strt.begin();
    vector<int>::iterator j=end.begin();
    /*
    for(; i<strt.end(); i++)
    {
        cout<<(*i)<<endl;
    }
    for(; j<end.end(); j++)
    {
        cout<<(*j)<<endl;
    }
    */
    i=strt.begin();
    j=end.begin();
    int count=0;
    int max=0;
    int minin;
    int maxin;
    int tmp;
    while(i!=strt.end()&&j!=end.end())
    {
        if((*i)<(*j))
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        if(count==n)
        {
            count=0;
            if(!(((*(--i))>t2)||((*(j))<t1)))
            {
                if((*(i))<t1)
                {
                    minin=t1;
                }
                else
                {
                    minin=(*i);
                }
                if((*(j))>t2)
                {
                    maxin=t2;
                }
                else
                {
                    maxin=(*j);
                }
                tmp=maxin-minin;
                if(tmp>max)
                {
                    max=tmp;
                }
            }
        }
    }


    cout<<max;
}
