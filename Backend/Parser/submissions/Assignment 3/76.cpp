#include<iostream>
#include<list>
#include <limits>
#include<vector>
using namespace std;
int n,m;
vector<int> a,b;
int minim=2000000, position=0;

int main(){
cin>>n>>m;
a.resize(n);
b.resize(m);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<m;i++){
    cin>>b[i];
}
vector<int> c(m);
for(int i=0; i<m;i++){
    c[i]=0;
}
//iterating row wise instaed of collummn wise
for(int i=n-1;i>=0;i--)
    {
        for(int y=0;y<=i && y<m;y++)
        {
            if(y==(m-1))
            {
                if(i==(n-1))
                {
                    if(a[i]==b[y]) c[y]=1;
                    else c[y]=2000000;
                }
                else
                {
                    if(a[i]==b[y]) c[y]=1;
                    else c[y]=1+c[y];
                }
            }

            else if(y!=(m-1) && i==(n-1))
            {
                c[y]=2000000;
            }

            else if (a[i]==b[y]) c[y]=1+c[y+1];
            else c[y]=1+c[y];

        }
        //cout<<"c zero"<<c[0]<<endl;
        //cout<<minim<<endl;
        if(minim>c[0])
        {   //just checking for each 1st row element= basically checking for first horizontalcollumn
            minim=c[0];
            position=i+1;

        }
    }

cout<<minim<<" "<<position<<endl;

}
