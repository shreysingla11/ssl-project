#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<climits>
using namespace std;

struct in
{
    double T1;
    bool point;
};
bool compare(in a,in b)
{
    if(a.T1<b.T1)
        return true;
    else if(a.T1==b.T1)
    {
        if(a.point<b.point)
            return true;
        else
            return false;
    }
    else

    {
        return false;
    }
}
vector<in>input;
int main()
{
    double n,w,u,v,t1,t2;input.clear();
    int count=0;
    scanf("%lf %lf %lf %lf %lf %lf",&n,&w,&u,&v,&t1,&t2);
    while(n--)
    {
    int s;
        double x,l;in temp;
        char ch;
        cin>>ch;
        scanf("%d",&s);
        if(ch=='E'){
        for(int i=0;i<s;i++)
        {
            scanf("%lf %lf",&l,&x);
            temp.T1=(-x-(double)(count+1)*(w/v)*u)/u;
            temp.point=false;
             if(temp.T1<=t1)
                temp.T1=t1;
            input.push_back(temp);
            temp.T1=(-x+l-(double)count*(w/v)*u)/u;
            temp.point=true;
            if(temp.T1>=t2)
                temp.T1=t2;
            input.push_back(temp);

        }
        }
        else
        {
            for(int i=0;i<s;i++)
            {
                 scanf("%lf %lf",&l,&x);
                 temp.T1=(x-(double)(count+1)*(w/v)*u)/u;
                 temp.point= false;
                 if(temp.T1<=t1)
                    temp.T1=t1;
                 input.push_back(temp);
                 temp.T1=(x+l-(double)count*(w/v)*u)/u;
                 temp.point=true;
                 if(temp.T1>=t2)
                    temp.T1=t2;
                 input.push_back(temp);
            }
        }

        count++;
    }
    sort(input.begin(),input.end(),compare);
//    for(int i=0;i<input.size();i++)
//    {
//        cout<<input[i].T1<<"   "<<input[i].point<<endl;
//    }
    int count_inter=0;
    double max=-1000000.0,diff;
    if(input[0].T1>=t1)
    {
        if(input[0].T1>=t2)
        {
            diff = t2-t1;
        }
        else
        {
            diff=input[0].T1-t1;
        }
        if(diff>max)
            {
                max=diff;
            }

    }

    for(int i=0;i<input.size()-1;i++)
    {
        if(input[i].point==false)
        {
            count_inter++;
        }
        else
        {
            count_inter--;
        }
        if(count_inter==0&&input[i].T1>=t1&&input[i+1].T1<=t2)
        {
            diff=input[i+1].T1-input[i].T1;
            if(diff>max)
            {
                max=diff;
            }
        }
//        else if(count_inter==0&&input[i].T1<=t1&&input[i+1].T1<=t2&&input[i+1].T1>t1)
//        {
//             diff=input[i+1].T1-t1-w/v;
//            if(diff>max)
//            {
//                max=diff;
//            }
//        }
//        else if(count_inter==0&&input[i].T1<=t1&&input[i+1].T1>=t2)
//        {
//             diff=t2-t1-w/v;
//            if(diff>max)
//            {
//                max=diff;
//            }
//        }
//        else if(count_inter==0&&input[i].T1>=t1&&input[i+1].T1>=t2&&input[i].T1<=t2)
//        {
//             diff=t2-input[i].T1-w/v;
//            if(diff>max)
//            {
//                max=diff;
//            }
//        }

    }
    if(input[input.size()-1].T1<=t2)
    {
        if(input[input.size()-1].T1<=t1)
        {
            diff=t2-t1;
            if(diff>max)
            {
                max=diff;
            }
        }
        else
        {
            diff=t2-input[input.size()-1].T1;
            if(diff>max)
            {
                max=diff;
            }
        }
    }
    printf("%.8lf\n",max);

}
