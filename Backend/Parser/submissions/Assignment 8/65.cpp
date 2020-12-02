#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<algorithm>
#include<cstdio>
#include<cmath>

struct positions
{
    double a;
    int b;
};


vector<positions> finalarray;

bool compare(positions m, positions n){
    if (m.a < n.a) return true;
    if (m.a > n.a) return false;
    else
    {
        if (m.b >n.b) return true ;
        else return false ;
}
    }


int main(){
int lanes;
double width,uship,uferry;
double t1ferry,t2ferry;
cin>>lanes>>width>>uship>>uferry>>t1ferry>>t2ferry;
int numberinserted=0;
for(int i=0;i<lanes;i++)
{
    //cout<<"hi"<<endl;
    char direction;
    cin>>direction;
    int sign=1;
    if(direction=='W')
    {
      sign=-1;
    }
    int shipnumber;
    cin>>shipnumber;
    for(int j=0; j<shipnumber;j++)
    {
        double lengthtemp;
        double positiontemp;
        cin>>lengthtemp>>positiontemp;
        positiontemp= double(sign*positiontemp);

        //positiontemp+= (double((i+1)*width)/uferry)*uship;
        double inittime,finaltime;
        inittime=(-positiontemp-(double)(i+1)*((double)width/uferry)*uship)/uship;
        finaltime=(-positiontemp +lengthtemp-(double)(i)*((double)width/uferry)*uship)/uship;
        if(inittime<=t1ferry)
        {
            inittime=t1ferry;
        }
        if(finaltime>=t2ferry)
        {
            finaltime=t2ferry;
        }
        positions temp;
        temp.a=inittime;
        temp.b=1;
        finalarray.push_back(temp);
        positions temp2;
        temp2.a=finaltime;
        temp2.b=0;
        finalarray.push_back(temp2);
        numberinserted++;
    }

}

/*for(int i=0;i<numberinserted;i++)
{
    positions temp;
    temp.a=ships[i].a;
    temp.b=1;
    finalarray.push_back(temp);
    temp.a=ships[i].b;
    temp.b=0;
    finalarray.push_back(temp);

}*/
//cout<<"bla"<<endl;

sort(finalarray.begin(),finalarray.end(),compare);

//cout<<"gggg"<<endl;
int num=0;
double maxtime=-100;
if(finalarray[0].a>=t1ferry)
{
    if(finalarray[0].a>=t2ferry)
    {
        maxtime=t2ferry-t1ferry ;
    }
    else
    {
        maxtime=finalarray[0].a-t1ferry ;
    }
}
int i=0;

for(; i<finalarray.size()-1;i++)
{
    //cout<<finalarray[i].a<<" "<<finalarray[i].b<<endl;
    if(finalarray[i].b==1) num++;
    else num--;
    //cout<<num<<endl;
    if (num==0)
    {
        double t1,t2;
        t2=finalarray[i+1].a;
        t1=finalarray[i].a;
        double currenttime;
        //if(t1>=t1ferry && t2 <=t2ferry)
        //{
            currenttime=(t2-t1);
            if(currenttime>maxtime) maxtime=currenttime;

        //}
        /*else if(t1<t1ferry && t2 <t2ferry)
        {
            currenttime=(t2-t1ferry);
            if(currenttime>maxtime) maxtime=currenttime;
        }
        else if(t1>t1ferry && t2 >t2ferry)
        {
            currenttime=(t2ferry-t1)y;
            if(currenttime>maxtime) maxtime=currenttime;
        }
        else if(t1<t1ferry && t2 >t2ferry)
        {
            currenttime=(t2ferry-t1ferry);
            if(currenttime>maxtime) maxtime=currenttime;
        }*/
    }
}


//cout<<i<<endl;
double currenttime;
//i--;
if(finalarray[i].a<=t2ferry)
{
    if(finalarray[i].a <=t1ferry)
    {
        currenttime=t2ferry-t1ferry;
    }
    else
    {
        currenttime=t2ferry-finalarray[i].a;
    }
    if(currenttime>maxtime) maxtime=currenttime;
}

//cout<<maxtime<<endl;
printf("%.8lf \n",maxtime);

return 0;
}
