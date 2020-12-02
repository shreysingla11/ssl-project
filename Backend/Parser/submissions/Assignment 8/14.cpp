#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
bool mysort(const vector<double> &u,const vector<double> &v)
{
    if(u[0]<v[0])
    {
        return true;
    }
    else if (u[0]>v[0])
    {
        return false;
    }
    //else if(u[0]==v[0])
    //{
     //   if(u[1]<=v[1])
      //  {
      //      return true;
      //  }
      //  else if (u[1]>v[1])
       // {
       //     return false;
       // }
    }
//}
int main()
{
    int n,w,u,v,t1,t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    vector<vector<double> > sinterval;
    for(int i=0; i<n; i++)
    {
        char d;
        cin>>d;
        int m;
        cin>>m;
        vector<double> temp;
        for(int j=0; j<m; j++)
        {
            //vector<vector<int> >shiplp(m);//ship length and position
            int l;
            cin>>l;
            //shiplp[j].push_back(l);
            int p;
            cin>>p;
            //shiplp[j].push_back(p);
            double tw=i*(w*1.0)/v;  // time for ferry
            double in1,in2;
            if(d=='E')
            { // boat is eastbound
                p=-1*p;
                in1=((p*1.0)/u)-tw-(w*1.0/v);
                in2=(((p+l)*1.0)/u)-tw;
            }
            else if(d=='W')
            { // boat is westbound
                in1=((p*1.0)/u)-tw-(w*1.0/v);
                in2=(((p+l)*1.0)/u)-tw;
            }
            // pushing valid time intervals into sinterval
            if(in1>=t1 && in2<=t2)
            {
                temp.push_back(in1);
                temp.push_back(in2);
                sinterval.push_back(temp);
                temp.clear();
            }
            else if(in1<=t1 && in2<=t2 && in2>t1)
            {
                temp.push_back(t1);
                temp.push_back(in2);
                sinterval.push_back(temp);
                temp.clear();
            }
            else if(in1>=t1 && in1<t2 && in2>=t2)
            {
                temp.push_back(in1);
                temp.push_back(t2);
                sinterval.push_back(temp);
                temp.clear();
            }
            //else if(in1<=t1 && in2>=t2)
            //{
              //  temp.push_back(t1);
             //   temp.push_back(t2);
            //    sinterval.push_back(temp);
           // }
        }
    }
    if(sinterval.empty()){ // if the sintervel is empty..
    vector<double> temp;
    temp.push_back(t1);
    temp.push_back(t1);
    vector<double> temp1;
    temp1.push_back(t1);
    temp1.push_back(t1);
    sinterval.push_back(temp);
    sinterval.push_back(temp1);
    }
    sort (sinterval.begin(), sinterval.end(), mysort); // sorting the intervals in sinterval
    int len=sinterval.size();
    double maxallowed=0;
    if(maxallowed<(sinterval[0][0]-t1))
    {
        maxallowed=sinterval[0][0]-t1;
    }
    for(int i=0; i<len-1; i++)
    {
        if(maxallowed<(sinterval[i+1][0]-sinterval[i][1]))
        {
            maxallowed=(sinterval[i+1][0]-sinterval[i][1]);
        }
    }
    if(maxallowed<(t2-sinterval[len-1][1]))
    {
        maxallowed=(t2-sinterval[len-1][1]);
    }
    printf("%0.8f",maxallowed);
    //cout<<maxallowed;
//for(int m=0;m<s;m++){
//cout<<"("<<sinterval[m][0]<<","<<sinterval[m][1]<<" ";}
}
