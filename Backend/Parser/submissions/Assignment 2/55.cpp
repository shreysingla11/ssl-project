#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void pdivide(vector<vector<int> > &red, vector<vector<int> > &blue, int &n, vector<vector<int> > &pairs, int &q)
{
    if(n==0) return;
    vector<int> u(2);
    if(n==1)
    {
        u[0]=red[0][2];u[1]=blue[0][2];pairs.push_back(u); q=pairs.size(); return;
    }
    vector<vector<int> > red1, red2, blue1, blue2;
    int a,c,i=0;
    while(i<red.size())
    {
        red1.resize(0); blue1.resize(0); red2.resize(0); blue2.resize(0);
        int j, r=0, b=0;
        for(j=0; j<red.size(); j++)
        {

            if((red[j][1]-red[0][1])*(blue[i][0]-red[0][0])>(blue[i][1]-red[0][1])*(red[j][0]-red[0][0]))
            {
                r++; red1.push_back(red[j]);
            }
            if((blue[j][1]-red[0][1])*(blue[i][0]-red[0][0])>(blue[i][1]-red[0][1])*(blue[j][0]-red[0][0]))
            {
                b++; blue1.push_back(blue[j]);
            }
            if((red[j][1]-red[0][1])*(blue[i][0]-red[0][0])<(blue[i][1]-red[0][1])*(red[j][0]-red[0][0]))
            {
                red2.push_back(red[j]);
            }
            if((blue[j][1]-red[0][1])*(blue[i][0]-red[0][0])<(blue[i][1]-red[0][1])*(blue[j][0]-red[0][0]))
            {
                blue2.push_back(blue[j]);
            }

        }
        if(b==r) {a=red1.size(); c=red2.size(); break;}
        i++;
    }
    u[0]=red[0][2];u[1]=blue[i][2];pairs.push_back(u); q=pairs.size();
    pdivide(red1, blue1, a, pairs, q);
    pdivide(red2, blue2, c, pairs, q);
    return;
}

int main()
{
    int n, i;
    scanf("%d",&n);
    vector<vector<int> > red;
    vector<vector<int> > blue;
    vector<int> v(3);
    for(i=0; i<(n/2); i++)
    {
        cin>>v[0]>>v[1];
        v[2]=i;
        red.push_back(v);
    }
    for(i=0; i<(n/2); i++)
    {
        cin>>v[0]>>v[1];
        v[2]=i;
        blue.push_back(v);
    }
    int q=0, m=n/2;
    vector<vector<int> > pairs;
    pdivide(red, blue, m, pairs, q);
    for(i=0; i<pairs.size(); i++)
        cout<<pairs[i][0]<<"\t"<<pairs[i][1]<<endl;
    return 0;
}
