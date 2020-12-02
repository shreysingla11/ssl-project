#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class distinct
{
    int *seq;
    int *l;
    int numOfLevels;
    vector < pair<int, int> > mymap;
    void createL();
    void createArr();
    vector <vector<int> > Cvect;
    vector <vector<int> > IVect;
public:
    distinct(vector<int> v);
    int num_distinct(int S,int E);
};
distinct:: distinct(vector<int> v)
{
    seq=new int[v.size()];
    l=new int[v.size()];
    for(int i=0; i<v.size(); i++)
    {
        seq[i]=v[i];
        mymap.push_back(pair <int, int> (v[i],i));
    }
    int a=v.size(),Count=0;
    while(a>=1)
    {
        a=a/2;
        Count++;
    }
    numOfLevels=Count;
    createL();
    createArr();
}
void distinct::createL()
{
    sort(mymap.begin(),mymap.end(),[](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool
    {
        if(lhs.first==rhs.first)
        {
            if(lhs.second<rhs.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(lhs.first<rhs.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    });
    for(int i=mymap.size()-1; i>0; i--)
    {
        if(mymap[i].first==mymap[i-1].first)
        {
            l[mymap[i].second]=mymap[i-1].second;
            //cout<<l[mymap[i-1].second]<<endl;
        }
        else
        {
            l[mymap[i].second]=-1;
        }
    }
    l[mymap[0].second]=-1;
    return;
}
void create(int start,int End,int l[],vector <vector<int> > Cvect,vector <vector<int> > Ivect)
{
    int C=0;
    for(int i=start;i<End;i++)
    {
        if((l[i]>=(start+End-1)/2)&&(l[i]<End))
        {
            C=C+1;
            //Cvect.push_back(C);
        }
        else
        {

        }
    }
}
void ArrayCreation(int level,int l[],vector <vector<int> > Cvect,vector <vector<int> > Ivect,int numOfLevels)
{
    for(int p=0;p<level;p++)
    {
        int start=p*2^(numOfLevels-level);
        int End=(p+1)*2^(numOfLevels-level);
        //create(start,End,l,Cvect,Ivect);
    }
}
void distinct::createArr()
{
    for(int i=1;i<=numOfLevels;i++)
    {
    ArrayCreation(i,l,Cvect,IVect,numOfLevels);
    }
}
int distinct::num_distinct(int S,int E)
{

}
