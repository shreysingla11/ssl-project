#include<stdio.h>
#include<set>
#include<map>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){

	int n, w, u, v, t1, t2;
	char dir;
    cin>>n>>w>>u>>v>>t1>>t2;
    //cout<<n<<" "<<w<<" "<<u<<" "<<v<<" "<<t1<<" "<<t2;
    /*
	scanf("%d",&n);
	scanf("%d",&w);
	scanf("%d",&u);
	scanf("%d",&v);
	scanf("%d",&t1);
	scanf("%d",&t2);*/
	vector<set<int> > pos;
	vector<map<int, int> > len;

    set<double> pos_f;
    map<double, int> len_f;
    //cout<<n<<endl;
	for(int i=0; i<n;i++)
	{
		//cout<<i<<endl;
		int m=1;
		cin>>dir;  //fun
		cin>>m;
		//cout<<m<<endl;
		set<int> temp_p;
		map<int, int> temp_l;

		for(int j=0;j<m;j++)
		{
			int p,l;
			scanf("%d",&l);
			scanf("%d",&p);
			p=abs(p);
			//cout<<p<<endl;
			temp_p.insert(p);
            temp_l.insert(pair<int,int>(p,l));
		}
		pos.push_back(temp_p);
		len.push_back(temp_l);
        //cout<<"a"<<endl;
        if(!pos[i].empty())
        {
		 for(set<int>::iterator it=pos[i].begin();it!=pos[i].end();it++)
		 {
            double position=(double)(*it)-(double)(w*i*u)/(double)(v);

           // cout<<(double)(w*i*u)/(double)(v)<<" "<<position<<endl;
            //int length=
            set<double>::iterator found=pos_f.find(position);
            if(found!=pos_f.end())
            {
                if(len_f[position]<len[i][*it])
                    len_f[position]=len[i][*it];
                //cout<<"found"<<endl;
            }
            else
            {
                len_f.insert(pair<double, int>(position,len[i][*it]));
                pos_f.insert(position);
                //cout<<"new"<<endl;
            }
//            cout<<"b"<<i<<endl;
          }
         }

	}

// for(set<int>::iterator it=pos_f.begin(); it!=pos_f.end();it++)
 //  cout<<*it<<endl;

    //algo
    double start_max=t1, end_max=t1, s=0;
    double del_t=0, t1_f=0, t2_f=0;
    {
        set<double>::iterator it=pos_f.begin();
        if(*it>0){
            del_t=(*it)/(double)(u)  ;
            end_max=max(*it+len_f[*it],(double)t1);
            //cout<<"Hello "<<del_t<<endl;        //
        }                           //
    }
    set<double>::iterator it=pos_f.begin();
    for(it=pos_f.begin(); it!=pos_f.end();it++)
    {
        //del_t
        int length_i=len_f[*it];
        double start_i= *it + length_i;
        start_max=max(start_max,start_i);
        //cout<<start_max<<endl;
        t1_f=start_max/(double)(u);
        //cout<<start_max<<endl;
        if(t1_f>=t1&&t1_f<=t2)
        {
            it++;
            double end_i=*it;
            end_max=max(end_i,(double)(t1));
            it--;
            double delta_t=(end_i-start_max)/(double)(u);
            //cout<<delta_t<<" "<<del_t<<endl;
            if(del_t<delta_t)//&&delta_t>0)
            {
                s=t1_f;
                del_t=delta_t;
                //cout<<delta_t<<endl;
            }
        }
        else if(t1_f>t2)
                break;
    }
    it--;
    {
        double delta_t=(t2-*it-len_f[*it])/(double)u;
        if(del_t<delta_t)//&&delta_t>0)
        {
                s=(*it+len_f[*it])/(double)(u);
                del_t=delta_t;
               //cout<<delta_t<<endl;
        }
    }
    //cout<<del_t<<" "<<(double)(w)/(double)(v)<<endl;
    double d=min(del_t-(double)(w)/(double)(v), (t2-s-(double)(w)/(double)(v)>0)?t2-s:0);
    printf("%.6f",d);
    //cout<<d<<endl;
}
