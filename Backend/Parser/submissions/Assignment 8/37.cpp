#include<iostream>
#include<algorithm>
#include<map>
#include<iomanip>

using namespace std;
int main()
{
    int n,w,t1,t2;
    double u,v;
    cin>>n>>w>>u>>v>>t1>>t2;
    multimap <double,int> risk;//int stores whether it is the start or the end time
    for(int i = 0; i<n; i++)
    {
        char direction;
        int ships;
        cin>>direction>>ships;
        for(int j = 0; j<ships; j++)
        {
            int length,start;
            cin>>length>>start;
            double x1,x2;
            if(direction == 'E')
            {
                start = -start;
                x1 = (start/u)-(((i+1)*w)/v);
                x2 = ((start+length)/u)-((i*w)/v);
                start = -start;
                //cout<<x1<<x2<<endl;
            }
            else
            {
                x1 = (start/u)-(((i+1)*w)/v);
                x2 = ((start+length)/u)-((i*w)/v);
                //cout<<x1<<x2<<endl;
            }
            if(x2>=t1&&x1<=t2)
            {
                if(x1<t1)
                {
                    x1 = t1;
                }
                if(x2>t2)
                {
                    x2 = t2;
                }
                //cout<<x1<<x2<<endl;
                risk.insert(pair<double,int>(x1,1));
                risk.insert(pair<double,int>(x2,-1));
            }
        }
        int safety =0;
        multimap<double,int>::iterator ite = risk.begin();
        multimap<double,int>::iterator temp = risk.begin();
        multimap<double,int>::iterator endite = risk.end();
        double d = ite->first-t1;
        if(ite == endite)
        {
            d = t2-t1;
        }
        for(; ite!=endite; ite++)
        {
            safety = safety+ite->second;
            if(safety == 0)
            {
                temp = ite;
                temp++;
                if(temp!=endite)
                {
                    if(d<temp->first-ite->first)
                    {
                        d = temp->first-ite->first;
                    }
                }
                else
                {
                    if(d<t2-ite->first)
                    {
                        d = t2-ite->first;
                    }
                }
            }
        }
        cout << fixed;
        cout << setprecision(8);
        cout<<d<<endl;
        //cout<<i<<endl;
    }
    return 0;
}
