#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main()
{
    //number of nodes N
    int N;
    cin>>N;
    //threshold values T[]
    int T[N];
    int T2[N];
    //no of friends to ith person = F[i]
    int F[N];
    int p=0;
    //vecor of persons with Joker attitude
    list<int> Jok;
    int counts=0;
    list<int> Nogo;
    int counts2=0;
    //vectors of vectors
    vector<vector<int> > Inf2(N);
    vector<vector<int> > Inf(N);
    for(int i=0;i<N;i++)
    {
        cin>>T[i]>>F[i];
        for(int j=0;j<F[i];j++)
        {
            cin>>p;
            Inf2[p].push_back(i);
            Inf[p].push_back(i);
        }
        T2[i]=T[i];
        if(T[i]==0)
        {
            Jok.push_back(i);
            counts++;
        }
        if(T2[i]>F[i])
        {
            Nogo.push_back(i);
            counts2++;
        }
    }


    list<int>::iterator iter;
    vector<int>::iterator iter2;
    iter=Jok.begin();
    int num;
    int num2;
    for(iter=Jok.begin();iter!=Jok.end();iter++)
    {
    num2=*iter;
        iter2=Inf[num2].begin();
        for(iter2=Inf[num2].begin();iter2!=Inf[num2].end();iter2++)
        {
            num=*iter2;
            T[num]=T[num]-1;
            if(T[num]==0)
            {
                Jok.push_back(num);
                counts++;
            }
        }
    }
cout<<counts<<" ";

    list<int>::iterator iter3;
    vector<int>::iterator iter4;
    iter3=Nogo.begin();
    int num3;
    int num4;
    for(iter3=Nogo.begin();iter3!=Nogo.end();iter3++)
    {
        num4=*iter3;
        iter4=Inf2[num4].begin();
        for(iter4=Inf2[num4].begin();iter4!=Inf2[num4].end();iter4++)
        {
            num3=*iter4;
            T2[num3]=T2[num3]+1;
            if(T2[num3]-F[num3]==1)
            {
                Nogo.push_back(num3);
                counts2++;
            }
        }
    }
cout<<N-counts2<<endl;

return 0;
}

