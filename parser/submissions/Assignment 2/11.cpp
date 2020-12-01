#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{int n,i,j,x,y,r=0,b=0;
cout<<"give the total no. of points : ";
cin>>n;
vector<vector<int> > red;
vector<vector<int> > blue;
vector<vector<int> > rp;
vector<vector<int> > bp;
rp.resize(0);
bp.resize(0);
vector<int> v;
vector<int> w;
cout<<"give the coordinates of red points : "<< endl;
for(i=0;i<n/2;i++)
    {
        v.resize(0);
        cin>>x;
        cin>>y;
        v.push_back(x);
        v.push_back(y);
        red.push_back(v);
    }
cout<<"give the coordinates of blue points : "<<endl;
for(i=0;i<n/2;i++)
    {
        v.resize(0);
        cin>>x;
        cin>>y;
        v.push_back(x);
        v.push_back(y);
        blue.push_back(v);
    }

for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            for(int k=0;k<n/2;k++)
                    {
                    if(k!=i && k!=j){
                           if((red[k][0]-red[i][0])*(blue[j][1]-red[i][1])-(red[k][1]-red[i][1])*(blue[j][0]-red[i][0])>0)
                               {
                                r++;
                                }
                           else
                                if((blue[k][0]-red[i][0])*(blue[j][1]-red[i][1])-(blue[k][1]-red[i][1])*(blue[j][0]-red[i][0])>0)
                                {
                                b++;
                                }
                                if(rp==bp&&(rp.size()==0)&&(bp.size()==0)){cout<<i<<" "<<j<<endl;}

             if(rp==bp&&(rp.size()==0)&&(bp.size()==0))
             {
                v.resize(0);
                v.push_back(red[i][0]);
                v.push_back(red[i][1]);
                rp.push_back(v);
                w.resize(0);
                w.push_back(blue[j][0]);
                w.push_back(blue[j][1]);
                bp.push_back(w);

            for(int l=0;l<rp.size();l++)
        {
        if(((rp[l][0]-red[i][0])*(blue[j][1]-red[i][1])-(rp[l][1]-red[i][1])*(blue[j][0]-red[i][0])>0)&&((bp[l][0]-red[i][0])*(blue[j][1]-red[i][1])-(bp[l][1]-red[i][1])*(blue[j][0]-red[i][0])>0))
                                {cout<<i<<" "<<j<<endl;}
        if(((rp[l][0]-red[i][0])*(blue[j][1]-red[i][1])-(rp[l][1]-red[i][1])*(blue[j][0]-red[i][0])<0)&&((bp[l][0]-red[i][0])*(blue[j][1]-red[i][1])-(bp[l][1]-red[i][1])*(blue[j][0]-red[i][0])<0))
            {cout<<i<<" "<<j<<endl;
            }
        }
    }
    ;}
    }
    }
    }


return 0;

}
