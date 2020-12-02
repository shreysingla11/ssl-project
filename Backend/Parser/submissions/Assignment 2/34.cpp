#include <iostream>
#include <vector>
using namespace std;

void getpairs(vector<vector <int> > &red,vector<vector <int> > &blue,vector<vector <int> > &pairs,int n,int &index)
{
    if(n==1)
    {
        pairs[index][0]=red[0][2];pairs[index][1]=blue[0][2];
        index++;
        return;
    }
    int np_r,np_b,np_op=0,i_op,k_op;
    for(int k=0;k<n;k++)
    {
        for(int i=0; i<n; i++)
        {
            np_r=0;
            np_b=0;
            for(int j=0; j<n; j++)
            {
                if(j==k)continue;
                if(((blue[i][0]-red[k][0])*(red[j][1]-red[k][1])-(blue[i][1]-red[k][1])*(red[j][0]-red[k][0]))>0)np_r++;
            }
            for(int j=0; j<n; j++)
            {
                if(j==i)continue;
                if(((blue[i][0]-red[k][0])*(blue[j][1]-red[k][1])-(blue[i][1]-red[k][1])*(blue[j][0]-red[k][0]))>0)np_b++;
            }
            if(np_r==np_b)
            {
                np_op=np_r;
                i_op=i;
                k_op=k;
            }
        }
    }
    pairs[index][0]=red[k_op][2];
    pairs[index][1]=blue[i_op][2];
    index++;
    vector<vector <int> > red1,blue1,red2,blue2;
    red1.resize(np_op,vector<int>(3,0));
    blue1.resize(np_op,vector<int>(3,0));
    red2.resize(n-1-np_op,vector<int>(3,0));
    blue2.resize(n-1-np_op,vector<int>(3,0));
    int idx1=0,idx2=0;
    for(int j=0; j<n; j++)
    {
        if(j==k_op)continue;
        if(((blue[i_op][0]-red[k_op][0])*(red[j][1]-red[k_op][1])-(blue[i_op][1]-red[k_op][1])*(red[j][0]-red[k_op][0]))>0)
        {
            red1[idx1][0]=red[j][0];red1[idx1][1]=red[j][1];red1[idx1][2]=red[j][2];
            idx1++;
        }
        else
        {
            red2[idx2][0]=red[j][0];red2[idx2][1]=red[j][1];red2[idx2][2]=red[j][2];
            idx2++;
        }
    }
    idx1=0;idx2=0;
    for(int j=0; j<n; j++)
    {
        if(j==i_op)continue;
        if(((blue[i_op][0]-red[k_op][0])*(red[j][1]-red[k_op][1])-(blue[i_op][1]-red[k_op][1])*(red[j][0]-red[k_op][0]))>0)
        {
            blue1[idx1][0]=blue[j][0];blue1[idx1][1]=blue[j][1];blue1[idx1][2]=blue[j][2];
            idx1++;
        }
        else
        {
            blue2[idx2][0]=blue[j][0];blue2[idx2][1]=blue[j][1];blue2[idx2][2]=blue[j][2];
            idx2++;
        }
    }
    red.resize(0);
    blue.resize(0);
    if(np_op!=0)getpairs(red1,blue1,pairs,np_op,index);
    if(n-1-np_op!=0)getpairs(red2,blue2,pairs,n-1-np_op,index);
    return;
}

int main()
{
    vector<vector <int> > red,blue,pairs;
    int n,n2,index=0;
    cin>>n2;
    n=n2/2;
    red.resize(n,vector<int>(3,0));
    blue.resize(n,vector<int>(3,0));
    pairs.resize(n,vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
        cin>>red[i][0]>>red[i][1];
        red[i][2]=i;
    }
    for(int j=0;j<n;j++)
    {
        cin>>blue[j][0]>>blue[j][1];
        blue[j][2]=j;
    }
    getpairs(red,blue,pairs,n,index);
    for(int i=n-1;i>=0;i--)
    {
        cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
    }
    return 0;
}
