#include<iostream>
#include<vector>
using namespace std;
void red_left(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int&A,vector<int>&B,vector<int>&C,int index)
{
    int a = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(a>0)
    {
        A++;
        B.push_back(index);
    }
    else if(a<0)
    {
        C.push_back(index);
    }
    else
    {
    ;
    }
    return;
}
void blue_left(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int&A,vector<int>&B,vector<int>&C,int index)
{
    int a = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(a>0)
    {
        A--;
        B.push_back(index);
    }
    else if(a<0)
    {
        C.push_back(index);
    }
    else
    {
    ;
    }
    return;
}
void pairing(vector<int>&rx,vector<int>&ry,vector<int>&bx,vector<int>&by,int A[],int B,vector<int>X,vector<int>Y,int n)
{
    if(X.size()==0)
    {
        return;
    }
    if(X.size()==1)
    {
        A[X[0]]=Y[0];
        return;
    }
    else
    {
        vector<int>C;
        vector<int>D;
        vector<int>E;
        vector<int>F;
        int i=X[0];
        int j=1;
        int k=0;
        while(k!=n)
        {
            j=1;
            B=0;
            while(j!=n)
            {
                red_left(rx[i],ry[i],bx[Y[k]],by[Y[k]],rx[X[j]],ry[X[j]],B,C,E,X[j]);
                j++;
            }
            j=0;
            while(j!=n)
            {
                blue_left(rx[i],ry[i],bx[Y[k]],by[Y[k]],bx[Y[j]],by[Y[j]],B,D,F,Y[j]);
                j++;
            }
            if(B==0)
            {
                A[i]=Y[k];
                break;
            }
            else
            {
                k++;
            }
        }
        pairing(rx,ry,bx,by,A,B,C,D,C.size());
        pairing(rx,ry,bx,by,A,B,E,F,E.size());
    }
}
int main()
{
    int t;
    cin>>t;
    int i;
    i=0;
    int *A = new int[t/2];
    int B=0;
    while(i!=t/2)
    {
        A[i]=i;
        i++;
    }
    vector<int>rx(t/2);
    vector<int>ry(t/2);
    vector<int>bx(t/2);
    vector<int>by(t/2);
    vector<int>X(t/2);
    vector<int>Y(t/2);
    i=0;
    while(i!=t/2)
    {
        cin>>rx[i];
        cin>>ry[i];
        X[i]=i;
        Y[i]=i;
        i++;
    }
    i=0;
    while(i!=t/2)
    {
        cin>>bx[i];
        cin>>by[i];
        i++;
    }
    pairing(rx,ry,bx,by,A,B,X,Y,t/2);
    i=0;
    while(i!=t/2)
    {
        cout<<i<<" "<<A[i]<<endl;
        i++;
    }
    return 0;
}
