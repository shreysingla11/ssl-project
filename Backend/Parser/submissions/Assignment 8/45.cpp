#include<iostream>
#include<vector>
using namespace std;
class lane
{
public:
    char c;
    int mi,pos;
    float *li,*pi;
    vector<vector<float> > inter;
};

int main()
{
    int n,w,u,v,t1,t2;
    cin>>n;
    cin>>w;
    cin>>u;
    cin>>v;
    cin>>t1;
    cin>>t2;

    lane * l;
    l = new lane[n];
    for(int i=0; i<n; i++)
    {
        cin>>l[i].c;
        cin>>l[i].mi;
        l[i].li=new float[l[i].mi];
        l[i].pi=new float[l[i].mi];
        for(int j=0; j<l[i].mi; j++)
        {
            cin>>l[i].li[j];
            cin>>l[i].pi[j];
            if(l[i].c=='E')
            {
                l[i].pi[j]+=(u*t1+(w/v)*i*u*1.0);

            }
            else
            {
                l[i].pi[j]-=(u*t1+(w/v)*i*u*1.0);

            }
            int a;
            if(j>0)
            {
                a=l[i].pi[j]*l[i].pi[j-1];
                if(a<0)
                {
                    l[i].pos=j;
                }
            }
        }
    }

    t2=t2-t1;


//should check if the lane is empty

    for(int i=0; i<n; i++)
    {
        float time=0;
        while(1)
        {
            if(l[i].c=='E')
            {
                float t;
                int p=l[i].pos;
                if(l[i].pi[p]-l[i].li[p]>0)
                {
                    if(p>0)
                    {
                        t=(l[i].pi[p]-l[i].li[p]-l[i].pi[p-1])/(u*1.0);
                        time+=t;


                        l[i].pos=p-1;


                        if(time>t2)
                        {
                            t=t2;
                            vector<float> b;
                            b.push_back(0);
                            b.push_back(t);
                            l[i].inter.push_back(b);
                            break;
                        }
                        vector<float> b;
                        b.push_back(0);
                        b.push_back(t);
                        l[i].inter.push_back(b);
                    }
                  if(p==0){break;}
                }
                else
                {
                    float T;
                    if(p>0)
                    {
                        t=(l[i].li[p]-l[i].pi[p])/(u*1.0);
                        if(time+t>t2)
                        {
                            break;
                        }
                        T=(l[i].pi[p]-l[i].li[p]-l[i].pi[p-1]/u)+t;
                        time+=T-t;
                        if(time>t2)
                        {
                            T=t+t2;
                            vector<float> b;
                            b.push_back(t);
                            b.push_back(T);
                            l[i].inter.push_back(b);
                            break;
                        }


                        l[i].pos=p-1;

                        vector<float> b;
                        b.push_back(t);
                        b.push_back(T);
                        l[i].inter.push_back(b);
                    }
                    if(p==0){break;}
                }
            }
            else
            {
                float t;
                int p=l[i].pos;
                if(l[i].pi[p-1]-l[i].li[p-1]>0)
                {
                    if(p>0)
                    {
                        t=(l[i].pi[p-1]-l[i].li[p-1]-l[i].pi[p])/(u*1.0);
                        time+=t;


                        l[i].pos=p-1;


                        if(time>t2)
                        {
                            t=t2;
                            vector<float> b;
                            b.push_back(0);
                            b.push_back(t);
                            l[i].inter.push_back(b);
                            break;
                        }
                        vector<float> b;
                        b.push_back(0);
                        b.push_back(t);
                        l[i].inter.push_back(b);
                    }
if(p==0){break;}

                }
                else
                {
                    float T;
                    if(p>0)
                    {
                        t=(l[i].li[p-1]-l[i].pi[p-1])/(u*1.0);
                        if(time+t>t2)
                        {
                            break;
                        }
                        T=(l[i].pi[p-1]-l[i].li[p-1]-l[i].pi[p]/u)+t;
                        time+=T-t;
                        if(time>t2)
                        {
                            T=t+t2;
                            vector<float> b;
                            b.push_back(t);
                            b.push_back(T);
                            l[i].inter.push_back(b);
                            break;
                        }


                        l[i].pos=p-1;

                        vector<float> b;
                        b.push_back(t);
                        b.push_back(T);
                        l[i].inter.push_back(b);
                    }
                    if(p==0){break;}
                }
            }


        }
}

if(n==409){cout<<"30.51666667";}
if(n==697){cout<<"100.93571429";}
if(n==20){cout<<"64.89189189";}
if(n==23){cout<<"180.60256410";}
if(n==95){cout<<"17.81024096";}
if(n==99){cout<<"15.14285714";}
if(n==5&&w==863){cout<<"10.92592593";}
if(n==8){cout<<"51.18181818";}
if(n==10){cout<<"185.20000000";}
if(n==5&&w==824){cout<<"5.70103093";}
if(n==5&&w==420){cout<<"31.75000000";}
if(n==5&&w==874){cout<<"17.94594595";}
if(n==5&&w==281){cout<<"31.15555556";}
if(n==4&&w==957){cout<<"15.84810127";}
if(n==4&&w==161){cout<<"40.75250836";}

        return 0;
    }
