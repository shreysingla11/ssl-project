#include<iostream>
using namespace std;

 int red_x[2500],red_y[2500],blue_x[2500], blue_y[2500];


 float line(int i,int j,int X,int Y)
        {float result;
        if (((red_y[i]-blue_y[j])*(X-red_x[i]))==0){
        result=0;}
        else{
          result=(Y-red_y[i])*(red_x[i]-blue_x[j])/((red_y[i]-blue_y[j])*(X-red_x[i]));
          }return result;
          }


bool f(int n,int i)
{ int j=0,k,a=0,b=0;
  bool t;
  bool ccl;

 if(i==n-1){
 ccl=true;
 cout<<i<<" "<<j<<endl;
 return ccl;}
 else{

 for(j=0;j<n;j++)
    {
     for(k=0;k<n;k++)
     { if( line(i,j,red_x[k],red_y[k])<0)
        {a++;


        }


        else{}

        }


     for(k=0;k<n;k++)
     { if( line(i,j,blue_x[k],blue_y[k])<0)
        {b++;
        }

        else{}

        }

        if(a==b){
         t=f(n,i+1);


         if(t==true)

         {
          cout<<i<<" "<<j<<endl;
         ccl=true;
         return ccl;}
         else{return ccl=false;
         }
         }
         else{}
        }
        }

        }


    int main()
    {
    for (int c=0;c<2500;c++)
    {red_x[c]=red_y[c]=blue_x[c]= blue_y[c]=0;}

     int N,n,g;
    bool s;
    cout<<"enter the total number of points(has to be an even no.)"<<endl;
    cin>>N;
    n=N/2;

    cout<<"enter the red points followed by blue points"<<endl;

    for(g=0;g<n;g++){
    cin>>red_x[g]>>red_y[g];
    }
    for(g=0;g<n;g++){
    cin>>blue_x[g]>>blue_y[g];
    }
       cout<<"output:"<<endl;
      s=f(n,0);
      return 0;
    }
