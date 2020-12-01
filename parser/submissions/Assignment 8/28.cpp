#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

bool vare = 0;
bool varw = 0;
int storee,stores;

struct laneship
{
    char dir;
    int num;
    vector<double> lij;
    vector<double> pij;
    vector<double> time;
    /*void print()
    {
        cout<<dir<<num<<" "<<lij[0]<<" "<<lij[1];
    }*/
};

int main()
{
    multimap<double,int> vari;
    multimap<double,int>::iterator ti;
    int nl,ll,u,v,uE,uW;
    double t1,t2;
    cin>>nl>>ll>>u>>v>>t1>>t2;

    double temp1,temp2;

    double tf = ll/v;
    uE = v;
    uW = -v;

    laneship lanes[nl];

    for(int i=0; i<nl; i++)
    {
        cin>>lanes[i].dir>>lanes[i].num;
        for(int j=0; j<lanes[i].num; j++)
        {
            cin>>temp1>>temp2;
            /*if(lanes[i].dir=='E')
            {
                temp2 = temp2 + (u*i*tf);
            }
            if(lanes[i].dir=='W')
            {
                temp2 = temp2 - (u*i*tf);
            }*/
            //cout<<"hai"<<endl;
            lanes[i].lij.push_back(temp1);
            lanes[i].pij.push_back(temp2);
        }
    }
    //lanes[0].print();



    for(int i=0; i<nl; i++)
    {
        //cout<<lanes[i].dir<<endl;
        //lanes[i].time.push_back(t1);
        if(lanes[i].dir=='W')
        {
            for(int j=0; j<lanes[i].num; j++)
            {
                double time1,time2;
                time1 = ((lanes[i].pij[j]*u)-((i+1)*ll*v))/(v*u*1.0);
                time2 = (((lanes[i].pij[j]+lanes[i].lij[j])*u)-(i*ll*v))/(v*u*1.0);
                if(time2>=t1&&time1<=t2)
                {
                    if(time1<t1)
                    {
                        time1=t1;
                    }
                    if(time2>t2)
                    {
                        time2=t2;
                    }
                    //cout<<time1<<" "<<time2<<endl;
                    multimap<double,int>::iterator it = vari.end();
                    vari.insert (it,pair<double,int>(time1,1));
                    vari.insert (it,pair<double,int>(time2,-1));
                }



            }


        }
        if(lanes[i].dir=='E')
        {
            for(int j=(lanes[i].num)-1; j>=0; j--)
            {
                double time1,time2;
                lanes[i].pij[j] = -lanes[i].pij[j];
                time1 = ((lanes[i].pij[j]*u)-((i+1)*ll*v))/(v*u*1.0);
                time2 = (((lanes[i].pij[j]+lanes[i].lij[j])*u)-(i*ll*v))/(v*u*1.0);
                if(time2>=t1&&time1<=t2)
                {
                    if(time1<t1)
                    {
                        time1=t1;
                    }
                    if(time2>t2)
                    {
                        time2=t2;
                    }
                    //cout<<time1<<" "<<time2<<endl;
                    multimap<double,int>::iterator it = vari.end();
                    vari.insert (it,pair<double,int>(time1,1));
                    vari.insert (it,pair<double,int>(time2,-1));
                }

            }
        }
    }




    multimap<double,int>::iterator ite = vari.begin();
    double out=(ite->first)-t1,temp;
    int count=0;
    for(ite = vari.begin(); ite!=vari.end(); ite++)
    {
        ti = ite;
        ti++;
        if(ti == vari.end())
        {
            temp = t2-(ite->first);
        }
        else
        {
            count  = count + (ite->second);
            if(count == 0)
            {
                temp = (ti->first)-(ite->first);
            }

        }
        if(temp > out)
        {
            out = temp;
        }
    }

    printf("%.8f\n", out);


    return 0;
}

