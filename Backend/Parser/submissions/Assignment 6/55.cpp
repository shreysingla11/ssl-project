#include<iostream>
#include<string>
using namespace std;
bool compare(string a,int &start,int i,int &occ2,int &len,int l)
      {

      int end1=(i*l)-1;
        int end2=occ2+l;
        if(start==0)
        {
           while(end1!=occ2-1)
             {
               if(a[end1+1]!=a[end2+1])
                   { return false;}
                else{end1++;
                      end2++;
                      continue;}
                }


             }
    else{
           while(end1!=occ2-1)
               {
                  if(a[end1+1]==a[end2=1])
                    {
                      end1++;
                      end2++;
                      continue;}
                    if(start!=0)
                       {
                         if(a[start-1]==a[occ2-1])
                           {
                             start--;
                             occ2--;
                            continue;}
                        }
                        else{return false;}

                      }
            }
            len=end1-start;

            return false;}
bool isequal(string a,int i,int k,int f,int &occ2,int l)
     {

     int j=(i-1)*l;
     int j1=j;
        while(k<f&&j<i*l)
          {if(a[j]!=a[k])
                {
                  j=j1;
                  k++;}
            else{j++;
                 k++;}
                  }
          if(j==i*l){occ2=k-l;
                     return true;}
          return false;
            }
bool square(string a,int i,int &start,int &len,int n,int l)
    {
      int j,k,f;
      int occ2;
         k=i*l;
         f=k+(3*l)-2;

                start=(i-1)*l;
                 if(isequal(a,i,k,f,occ2,l))
                   {
                     if(compare(a,start,i,occ2,len,l))
                     { return true;}
                     }

         return false;

      }


int main()
{
 string a;
 int n,l=1,i=0,len=0,start=0;
 cin>>a;
 n=a.size();
while((2*l)-1<=n/2)
 { for(i=1;i<=n/l;i++)
      {
         if(square(a,i,start,len,n,l))
             {
                cout<<len<<' '<<start;
                return 0;
              }
        }
    l=2*l;
    }
    cout<<0<<' '<<0;
 return 0;}
