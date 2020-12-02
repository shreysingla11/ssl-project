#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
void findinglines(vector<vector<int> >& red,vector<vector<int> >& blue,int n)
{
    if(n==0)
    {
        return;
    }
    else if(n/2==1)
    {
        cout<<red[0][0]<<","<<red[0][1]<<"->"<<blue[0][0]<<","<<blue[0][1];
         return;
    }
    else
    {
        int i,bl,r;
        int leftbluepoints=0,leftredpoints=0,rightredpoints=0,rightbluepoints=0;
        vector<vector<int> > lred(n/2-1,vector<int>(2));
        vector<vector<int> > lblue(n/2-1,vector<int>(2));
        vector<vector<int> > rred(n/2-1,vector<int>(2));
        vector<vector<int> > rblue(n/2-1,vector<int>(2));
        for( i=0; i<n/2; i++)
        {
            leftbluepoints=0,leftredpoints=0,rightredpoints=0,rightbluepoints=0;
            int a=red[0][1]-blue[i][1],b=blue[i][0]-red[0][0],c=(red[0][1]*b)+(red[0][0]*a);
            //cout<<a<<" "<<b<<" "<<c<<endl;
            bl=0,r=0;
            for(int j=0; j<n/2; j++)
            {
                if(j==i)
                {
                    continue;
                }
                else if((b*blue[j][1]+a*blue[j][0]-c<0))
                {
                    lblue[bl][1]=blue[j][1];
                    lblue[bl][0]=blue[j][0];
                    bl++;
                    leftbluepoints++;
                    //cout<<leftbluepoints<<endl;;
                }
                else
                {
                    rblue[bl][1]=blue[j][1];
                    //cout<<rblue[bl][1]<<endl;
                    rblue[bl][0]=blue[j][0];
                    //cout<<rblue[bl][0]<<endl;
                    bl++;
                    rightbluepoints++;
                    //cout<<rightbluepoints;
                }
            }
            for(int j=1; j<n/2; j++)
            {
                if((b*red[j][1]+a*red[j][0]- c)<0)
                {
                    lred[r][1]=red[j][1];
                    lred[r][0]=red[j][0];
                    r++;
                    leftredpoints++;
                    //cout<<leftredpoints;
                }
                else
                {
                    rred[r][1]=red[j][1];
                    rred[r][0]=red[j][0];
                    r++;
                    rightredpoints++;
                    //cout<<rightredpoints;
                }
            }
            if(leftbluepoints==leftredpoints && rightbluepoints==rightredpoints)
            {
                if(leftbluepoints==0 && rightredpoints==1)
                {
                    break;
                }
                else if(leftbluepoints==1 && rightredpoints==0)
                {
                    break;
                }
                else if(leftbluepoints==0 && rightbluepoints==n/2-1)
                {
                    continue;
                }
                else if(leftbluepoints==n/2-1 && rightbluepoints==0)
                {
                    continue;
                }

                else
                {
                    break;
                }
            }
            else
            {
                continue;
            }
        }
        cout<<red[0][0]<<","<<red[0][1]<<"->"<<blue[i][0]<<","<<blue[i][1]<<endl;;
        cout<<rightbluepoints<<" "<<leftbluepoints<<" "<<leftredpoints<<" "<<rightredpoints<<endl;;
        findinglines(lred,lblue,2*leftbluepoints);
        findinglines(rred,rblue,2*rightbluepoints);
        return;
    }
}
int main()
{
int n;
cin>>n;
    vector<vector<int> > red(n/2,vector<int>(2));
    vector<vector<int> > blue(n/2,vector<int>(2));
    for(int i=0;i<n/2;i++)
    {cin>>red[i][0];
    cin>>red[0][i];
    }
    for(int i=0;i<n/2;i++)
    {cin>>blue[i][0];
    cin>>blue[0][i];
    }


    findinglines(red,blue,n);
    return 0;

}
