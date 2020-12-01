#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

void mymerge(vector<double> &leftA,vector<double> &rightA,vector<double> &A,int &n)
{
    int i=0, j=0, k=0;
    int a=leftA.size();
    int b=rightA.size();
    int flag=0;
    while(k<n)
    {
        if(flag==1) break;
        else if(i==a)
        {
            flag=1;
            while(k<n) { A[k]=rightA[j];k++;j++;}
        }
        else if(j==b)
        {
            flag=1;
            while(k<n) { A[k]=leftA[i];k++;i++;}
        }
        else if(leftA[i]<=rightA[j])
        {
            A[k]=leftA[i]; i++;
        }
        else if(leftA[i]>rightA[j])
        {
            A[k]=rightA[j]; j++;
        }
        k++;
    }
    return;
}
void mergesort(vector<double> &A, int& n)
{
        if(n==1) return;
        vector<double> leftA;
        vector<double> rightA;
        int i,j;
        for(i=0;i<(n/2);i++) {leftA.push_back(A[i]);}
        for(;i<n;i++) {rightA.push_back(A[i]);}
        int m=n/2;
        int t=n-m;
        mergesort(leftA,m);
        mergesort(rightA,t);
        mymerge(leftA,rightA,A,n);
        leftA.clear();
        rightA.clear();
        return;
}
int main()
{
    int n, w, u, v, t1, t2, i, m, j, l, p,count2=0;
    double t3, t4, t, et, st;
    char c;
    scanf("%d%d%d%d%d%d",&n,&w,&u,&v,&t1,&t2);
    vector <double> start, ender;
    for(i=0;i<n;i++)
    {
        cin>>c;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&l,&p);
            if(c=='E')
            {   t3=(-p)/u-(i*w+w)/v; t4=(-p+l)/u-(i*w)/v;}
            else if(c=='W')
            {   t3=(p)/u-(i*w+w)/v; t4=(p+l)/u-(i*w)/v;}
            if(t3<0) t3=0;
            if(t4<0) t4=0;
            start.push_back(t3);
            ender.push_back(t4);
            count2++;
        }
    }
    mergesort(start,count2);
    mergesort(ender,count2);
    int count=0;
    vector <double> :: iterator it,il;
    it=start.begin();
    il=ender.begin();
    double max=0;t=*it;
    if((*it)-t1>max) max=(*it)-t1;
    while(t<=t2)
    {
        if((*it)>(*il)) {count--; t=*il;il++;}
        else{count++; t=*it;it++;}
        if(count==0&&t>=t1){    et=(*it); if(et-t>max) max=et-t;}
        if(il==(--ender.end())) {count-- ;break;}
    }
    if(count==0&&t2-(*(--ender.end()))>max) max=t2-(*(--ender.end()));
    printf("%f",max);
    return 0;
}
