#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cmath>

struct larr
    {
        int l;
        int i;
    };
bool mysort(larr a,larr b)
    {
        if(a.l!=b.l)
            return (a.l<b.l);
        else
            return (a.i<b.i);
    }
struct mainvec
    {
        vector <int> arr1;
        vector <int> arr2;
    };

class distinct
{
vector <mainvec> main;
int size;
public:
    distinct(vector<int> v)
        {
            size=v.size();
            vector <larr> initial;
            initial.resize(v.size());
            for(int i=0;i<v.size();i++)
                {
                    initial[i].l=v[i];
                    initial[i].i=i;
                }
            sort(initial.begin(),initial.end(),mysort);
            vector <int> l;
            l.resize(v.size());
            l[0]=-1;
            for(int i=1;i<l.size();i++)
                {
                    if(initial[i].l==initial[i-1].l)
                        l[initial[i].i]=initial[i-1].i;
                    else
                        l[initial[i].i]=-1;
                }
            int n=l.size();
            //Root node
            vector <int> arr1,arr2;
                    int totn=0;
                    int tot1=0;int tot2=0;
                    int minind1=-1;int minind2=-1;
                    int i=0;
                    while(pow(2,i)<n)
                    {
                    for(int j=0;j<n;j++)
                        {
                            vector <int> tot(pow(2,i-1));
                            for(int k=0;k<pow(2,i-1);k++)
                            {
                            if(l[j]<(k*(n/pow(2,i-1)))&&l[j]<((k+1)*n/(pow(2,i-1))))
                            {
                             if(l[j]<(k*(n/pow(2,i-1))+(n/pow(2,i)))&&l[j]<=((k+1)*n/(pow(2,i-1))))
                                        {
                                            tot[k]++;
                                            arr2[j]=minind1;

                                        }
                            else
                                        {
                                            arr2[j]=minind2;
                                        }
                            arr1[j]=tot[k];
                            if(l[i]<((k+1)*n/pow(2,i-1))&&l[i]>=(k*n)/pow(2,i-1)+n/pow(2,i)) minind2=j;
                            if(l[i]>=((k)*n/pow(2,i-1))&&l[i]<(k*n)/pow(2,i-1)+n/pow(2,i)) minind1=j;
                            }
                            }
                        }
                        mainvec topush;
                        topush.arr1=arr1; topush.arr2=arr2;
                        main.push_back(topush);
                        i++;
            }
    }
    int num_distinct(int a,int b)
        {
            static int i=1;
            int finalcount=0;
            if(a==size/(pow(2,i)))
                {
                    vector <int> toret=main[i].arr1;
                    finalcount+=(toret[b]);
                }
            else if(a<size/(pow(2,i)))
                {
                    i++;
                    vector <int> toret1=main[i].arr1;
                    vector <int> toret2=main[i].arr2;
                    finalcount+= (toret1[b]+num_distinct(a,toret2[b]));
                }
            else if(a>size/pow(2,i))
                {
                    i++;
                    vector <int> toret=main[i].arr1;
                    finalcount+= (num_distinct(a,toret[b]));
                }
                return (b-a+1-finalcount);
        }
};
/*int main()
    {
        int num;
        cin>>num;
        vector <int> v(num);
        for(int i=0;i<num;i++)
            {
                cin>>v[i];
            }
        distinct myarr(v);
    }*/
