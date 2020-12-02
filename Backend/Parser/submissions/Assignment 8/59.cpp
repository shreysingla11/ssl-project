#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector<pair<double,bool> > times;
int main()
{
    //Input
    int n, w, u, v, t1, t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    char ch;
    int lane_num, ship_length, ship_pos;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        cin>>lane_num;
        if(ch=='E')
        {
            for(int j=0;j<lane_num;j++)
            {
                cin>>ship_length>>ship_pos;
                pair<double,bool> new_pair1 = make_pair((double)(-(double)ship_pos/u) - double((i+1)*(double)w/v), false);
                pair<double,bool> new_pair2 = make_pair(double((double)(-ship_pos+ship_length)/u) - double(i*(double)w/v), true);
                if(new_pair1.first<t1)
                    new_pair1.first=t1;
                if(new_pair2.first>t2)
                    new_pair2.first=t2;
                times.push_back(new_pair1);
                times.push_back(new_pair2);
            }
        }
        else
        {
            for(int j=0;j<lane_num;j++)
            {
                cin>>ship_length>>ship_pos;
                pair<double,bool> new_pair1 = make_pair(double((double)ship_pos/u) - double((i+1)*(double)w/v), false);
                pair<double,bool> new_pair2 = make_pair(double((double)(ship_pos+ship_length)/u) - double(i*(double)w/v), true);
                if(new_pair1.first<t1)
                    new_pair1.first=t1;
                if(new_pair2.first>t2)
                    new_pair2.first=t2;
                times.push_back(new_pair1);
                times.push_back(new_pair2);
            }
        }
    }

    //Process
    sort(times.begin(),times.end());
    double max_d=times[0].first-t1;
    //double in_d=0,out_d=0;
    int tcount=0;
    //bool in=false,out=false;
    vector<pair<double,bool> > ::iterator it=times.begin();
    while(it!=times.end())
    {
        //if(it->first >=t1 && it->first<=t2)
        {
            /*if(!in)
            {
                in=true;
                if(tcount==0)
                    in_d=it->first -t1;
            }*/

            if(it->second)
                tcount--;
            else tcount++;
            //cout<<"tcount is "<<tcount<<endl;

            if(tcount==0)
            {
                if(it!=times.end())
                {
                    vector<pair<double,bool> > ::iterator temp_it=it;
                    it++;
                    double temp_max=it->first - temp_it->first;
                    if(temp_max >max_d)
                        max_d=temp_max;
                    it=temp_it;
                }
            }
            it++;
        }
        //else it++;
        /*if(it!=times.end())
        {
            if(it-> first >t2 && !out)
            {
                out=true;
                if(tcount==0)
                {
                    vector<pair<double,bool> > ::iterator temp_it1=it;
                    it--;
                    out_d=t2-it->first;
                    it=temp_it1;
                }
            }
        }
        */
    }
    //cout<<"in "<<in_d<<" "<<out_d<<endl;
    /*if(max_d<in_d)
        max_d=in_d;
    if(max_d<out_d)
        max_d=out_d;*/
    if(t2-times[times.size()-1].first>max_d)
        max_d=t2-times[times.size()-1].first;
    double result=max_d;

    //Output
    /*vector<pair<double,bool> > ::iterator it1=times.begin();
    while(it1!=times.end())
    {
        cout<<it1->first<<" "<<it1->second<<endl;
        it1++;
    }*/
   // cout<<"Max d is "<<result<<endl;
    printf("%.8lf\n",result);
    return 0;
}
