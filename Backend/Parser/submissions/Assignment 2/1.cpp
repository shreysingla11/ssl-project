#include<iostream>
using namespace std;
class point{
public:
        int x;
        int y;
        int index;
            };
class line{
public:
        point a;

        point b;


          } ;
bool  are_intersecting(line &l,line &m) {
    //part 1
    double val1,val2;
    val1=(l.b.y-l.a.y)*m.a.x-(l.b.x-l.a.x)*m.a.y+l.a.y*l.b.x-l.b.y*l.a.x;
    val2=(l.b.y-l.a.y)*m.b.x-(l.b.x-l.a.x)*m.b.y+l.a.y*l.b.x-l.b.y*l.a.x;
    if(val1*val2>0) return 0;
    //part  2
    val1= (m.b.y-m.a.y)*l.a.x-(m.b.x-m.a.x)*l.a.y+m.a.y*m.b.x-m.b.y*m.a.x;
    val2= (m.b.y-m.a.y)*l.b.x-(m.b.x-m.a.x)*l.b.y+m.a.y*m.b.x-m.b.y*m.a.x;
    if(val1*val2>0) return 0;
    else return 1;
                                      }
void display(line &l){
            cout<<l.a.index-1<<" "<<l.b.index-1<<endl;

           return;

                      }
   //function to check equal division in recursive method;
/*bool is_division_equal(line &l,int N){
       //check for red dots
       int i,val,s1,s2;
       s1=0;s2=0;
       for(i=1;i<=N/2;i++){
          if(i!=l.a.index)  {
         val=(l.b.y-l.a.y)*R[i].x-(l.b.x-l.a.x)*R[i].y+l.a.y*l.b.x-l.b.y*l.a.x;
            if(val>0) s1=s1+1;
            else s2=s2+1  ;
                             }
                           }
       //check for blue dots

       int p1,p2;p1=0;p2=0;
          for(i=1;i<=N/2;i++){
          if(i!=l.b.index)  {
         val=(l.b.y-l.a.y)*B[i].x-(l.b.x-l.a.x)*B[i].y+l.a.y*l.b.x-l.b.y*l.a.x;
            if(val>0) p1=p1+1;
            else p2=p2+1 ;
                             }
                           }

      if((s1==s2)&&(p1==p2)) return 1;
      else return 0;
                                }  */


int main(){
int N,i,j,p,tem,k;
p=0;
cin>>N;
k=N/2;
point R[k];
point B[k];
point temp;
line  L[k];
for(i=1;i<=k;i++){
                    cin>>R[i].x>>R[i].y;R[i].index=i;
                  }

for(i=1;i<=k;i++) {
                     cin>>B[i].x>>B[i].y;B[i].index=i;
                         }

for(i=1;i<=k;i++){
              L[i].a=R[i];L[i].b=B[i];
                   }

while(p!=(k*k)){
p=0;
for(i=1;i<=k;i++){
                 for(j=0;j<=k;j++){
                       if(are_intersecting(L[i],L[j])){

                                  temp=L[i].b;
                                  L[i].b=L[j].b;
                                  L[j].b=temp;
                                  tem=L[i].b.index;
                                  L[i].b.index=L[j].b.index;
                                  L[j].b.index=tem;
                                                      }

                        else p=p+1;

                                    }
                    }
              cout<<"value of p is "<<p<<endl;
               }

for(i=1;i<=k;i++){
               display(L[i]);
                    }
cout<<endl;

return 0;

          }
