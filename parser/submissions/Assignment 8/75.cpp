# include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct interval
{
    float s,e;
    interval()
    {

    }
    interval(float s1,float e1)
    {
        s=s1;
        e=e1;
    }

    void print()
    {
        cout<<"["<<s<<","<<e<<"]"<<endl;
        return;
    }

};

bool sortinterval(interval a,interval b)
{
    return a.s<b.s;
}


struct ship
{
    float l,p;
    char d;
    ship(float len,float pos,char dir)
    {
        l=len;
        p=pos;
        d=dir;
    }
};




int main()
{
    //complement intervals are stored
    int n ;
    float w,u,v,t1,t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    //time for ferry to cross,st is dis travelled by ship in which
    //ferry crosses
    float ft=w/v,st=w/u,sdis=ft*u;

    float ns,l,p;
    char dir;
    vector< vector<interval> > intervals(n,vector<interval>() );
    vector <interval> all;
    for(int i=0; i<n; i++)
    {
        //i*t will be the time lag
        cin>>dir>>ns;
        //ns is no of ships

        while(ns--)
        {
            cin>>l>>p;
            //cout<<l<<p<<endl;
            interval iv;
            if(dir=='E')
            {
            	if(i>0){
                iv.s=(0-p)/u -(i)*w/v ;

                iv.e= iv.s + l/u +w/v ;
                // cout<<w/v<<endl;
                	}
                	else{
						iv.s=(0-p)/u;
						iv.e= iv.s + l/u;
                	}
            }
            else
            {

            	if(i>0){
                iv.s=(p)/u -(i)*w/v ;

                iv.e= iv.s + l/u +w/v ;
                // cout<<w/v<<endl;
                	}
                	else{
						iv.s=(p)/u;
						iv.e= iv.s + l/u;
                	}


                //cout<<l<<endl;
            }
           // iv.print();
            intervals[i].push_back(iv);
            all.push_back(iv);
        }
    }
    // now find the intervals
    //for()
    //find comlement
    sort(all.begin(),all.end(),sortinterval);
    //vector< vector<interval> > cintervals(n,vector<interval>(0) );
    std::vector<interval> ::iterator nit=all.begin();
    //while(nit!=all.end())
    //{
    //    (*nit).print();
    //    nit++;
   // }

    //now find gaps
   // cout<<"size of compleents is "<<all.size()<<endl;
    std::vector<interval> ::iterator it=all.begin();
    vector<interval> uni;
    float max;
    if((*it).s>t1)
    {
        max=(*it).s-t1;
    }
    else{
    	max=0;
    }
    //it--;
    float f1,f2,e1;
    while(it!=all.end())
    {
    	//(*it).print();
    	f1=(*it).s;
    	f2=(*(++it)).s;
		it--;
		e1=(*it).e;
        if(f1<f2)
        {
            //cout<<(*it).s<<((*(++it))).s<<endl;it--;

            if(e1<f2)
            {
            	//cout<<f2-e1<<max<<endl;	
                //cout<<(*it).e<<((*(++it)).s)<<endl;it--;
                max= (f2-e1>max) ? f2-e1:max;


            }
        }
        else
        {

        }
        it++;

    }
    if((*(--all.end())).e < t2){
    uni.push_back(interval((*(--all.end())).e,t2));
    }

    //sort(uni.begin(),uni.end(),sortinterval);


    printf("%.8f\n",max);

        return 0;

}
