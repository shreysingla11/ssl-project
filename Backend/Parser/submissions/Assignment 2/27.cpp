#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector <int> > r,vector<vector <int> >b,int i,int j)
{
float p,q;
if((b[i][0]-r[i][0])!=0)
{
    float p=(((b[i][1]-r[i][1])/(b[i][0]-r[i][0]))*r[j][0]-r[j][1]+(b[i][0]*r[i][1]-r[i][0]*b[i][1])/(b[i][0]-r[i][0]));
    float q=(((b[i][1]-r[i][1])/(b[i][0]-r[i][0]))*b[j][0]-b[j][1]+(b[i][0]*r[i][1]-r[i][0]*b[i][1])/(b[i][0]-r[i][0]));
    }
    else
    {
    float p=r[j][0]-r[i][0];
    float q=b[j][0]-b[i][0];
    }

    if((p*q)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool inter(vector<vector <int> > r,vector<vector <int> >b,int x,int y)
{
    if((check(r,b,x,y)==true)||(check(r,b,y,x)==true))
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int N;
    cin>>N;

    vector<vector<int> > r(N/2),b(N/2);

    for(int i=0; i<N/2; i++)
    {
        int m,n;
        cin>>m;
        cin>>n;
        r.at(i).push_back(m);
        r.at(i).push_back(n);
        r.at(i).push_back(i);

    }
    for(int j=0; j<N/2; j++)
    {
        int m,n;
        cin>>m;
        cin>>n;
        b.at(j).push_back(m);
        b.at(j).push_back(n);
        b.at(j).push_back(j);
    }
    cout<<endl;
    int l=0;

    while(true)
    {
cout<<"hai";

        for(int i=0; i<N/2; i++)
        {
            for(int j=0; j<N/2; j++)
            {
                if(inter(r,b,i,j)==true)
                {
                    int temp1=b[i][0];
                    int temp2=b[i][1];
                    int temp3=b[i][2];
                    b[i][0]=b[j][0];
                    b[i][1]=b[j][1];
                    b[i][2]=b[j][2];
                    b[j][0]=temp1;
                    b[j][1]=temp2;
                    b[j][2]=temp3;
                    l++;
                }
            }
        }
         if(l==0)
        {
            break;
        }
         else
        {
            l=0;
        }
    }

    for(int i=0;i<N/2;i++)
    {cout<<r[i][2]<<" "<<b[i][2]<<endl;}
}
