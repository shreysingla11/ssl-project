#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
double n,w,u,v,tf1,tf2;
scanf("%lf %lf %lf %lf %lf %lf",&n,&w,&u,&v,&tf1,&tf2);
char d;
vector<double> t1(100000);
vector<double> t2(100000);


int count =0;

for(int i =0;i<n;i++)
{
    cin>>d;

    if(d=='E')
    {
        int num;
        scanf("%d",&num);
        for(int k =0;k<num;k++)
        {
         double l,p;

        scanf("%lf %lf",&l,&p);
        if(p-l<=0){

        t1[count]=-p/u - (w*i)/v;

        if(t1[count]<0)t1[count]=0;

        t2[count]=(-p+l)/u - (w*i)/v ;



        count++;
            }

        }


    }
    else if(d=='W') {

    int num;
        scanf("%d",&num);
        for(int k =0;k<num;k++)
        {
        double l,p;

        scanf("%lf %lf",&l,&p);

        if(p-l>=0){
        t1[count]=p/u - (w*i)/v;

        if(t1[count]<0)t1[count]=0;

        t2[count]=(p+l)/u -(w*i)/v;




        count++;
            }

        }




    }


}

//input;

sort(t1.begin(),t1.begin()+count);
sort(t2.begin(),t2.begin()+count);
//max interval;
int count1=0;
int i=0,j=0;
double current=0.0;


for(;i<count;)
{

if(t1[i]<t2[j])
{

count1++;
i++;
}
else if(t1[i]==t2[j])
{
i++;
j++;

}
else {

count1--;
j++;
}
if(count1==0)
{
if(t1[i]>tf2)
{
if(current<tf2-t2[j-1])
current = tf2-t2[j-1];
break;
}
else if(tf1>t2[j-1])
{
if(current<t1[i]-tf1)
current = t1[i]-tf1;

}
else if(current<t1[i]-t2[j-1])
current = t1[i]-t2[j-1];
}


}
current =current - w/v;

printf("%.8lf\n", current);


}
