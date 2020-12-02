#include <iostream>
#include <vector>

using namespace std;

struct point{
  int x;
  int y;
  int in;
  bool color;// true is red , false is blue
};

struct line{
   int a,b,c;

   void set(point p1,point p2){

     a=(p1.y-p2.y);
     b=(-1)*(p1.x-p2.x);
     c=(p1.x)*(p2.y)-(p1.y)*(p2.x);
     return;
   }

   bool check(point p){
     int x=p.x;
     int y=p.y;
     if(a*x+b*y+c<0){
       return true;
     }
     else{
       return false;
     }
   }
};

void arrange(vector<point> &R,vector<point> &B,int start,int end){

   if (start>=end){
     return;
   }

   int inb=-1 ;
   int min=50000;
   int inr=(start+end)/2;
   int inr2;

   line l;
   for(int i=start;i<=end;i++){
      l.set(R[inr],B[i]);

      int numr,numb;
      numr=0; numb=0;

      for(int j=start;j<=end;j++){
        if(j!=inr){
           if(l.check(R[j])){
              numr++;
           }
        }
      }

      for(int j=start;j<=end;j++){
        if(j!=i){
           if(l.check(B[j])){
              numb++;
           }
        }
      }

      if(numr==numb){
         if(numr<end-start-numr){
           numr=end-start-numr;
           numb=end-start-numb;
         }
         if(numr<min){
            min=numr;
            inb=i;
         }
      }

   }

   if(inb<0){
      inr2=-1;
      for(int i=start;i<=end;i++){
        if(i!=inr){
         l.set(R[inr],R[i]);
         int numr,numb;
         numr=0; numb=0;

         for(int j=start;j<=end;j++){
           if(j!=inr&&j!=i){
            if(l.check(R[j])){
              numr++;
            }
           }
         }

         for(int j=start;j<=end;j++){
            if(l.check(B[j])){
                numb++;
            }
         }

         if((numr==numb)&&(numr!=0)||(numb==numr+2)&&(numb+numr+2!=end-start+1)){
           inr2=i;
         }

        }

      }

   }


   vector<point> tmpR1;
   vector<point> tmpB1;
   vector<point> tmpR2;
   vector<point> tmpB2;

   if(inb>=0){

     l.set(R[inr],B[inb]);

      for(int j=start;j<=end;j++){
        if(j!=inr){
           if(l.check(R[j])){
              tmpR1.push_back(R[j]);
           }
           else{
              tmpR2.push_back(R[j]);
           }
        }
      }

      for(int j=start;j<=end;j++){
        if(j!=inb){
           if(l.check(B[j])){
              tmpB1.push_back(B[j]);
           }
           else{
              tmpB2.push_back(B[j]);
           }
        }
      }

     if(tmpR1.size()!=tmpB1.size())cout<<"sizeeww"<<endl;
     if(tmpR2.size()!=tmpB2.size())cout<<"sizeeww"<<endl;

     arrange(tmpR1,tmpB1,0,tmpR1.size()-1);
     arrange(tmpR2,tmpB2,0,tmpR2.size()-1);

     R[start]=R[inr];
     B[start]=B[inb];
     int k=start+1;
     for(int i=0;i<tmpR1.size();i++){
       R[k]=tmpR1[i];
       B[k]=tmpB1[i];
       k++;
     }
     for(int i=0;i<tmpR2.size();i++){
       R[k]=tmpR2[i];
       B[k]=tmpB2[i];
       k++;
     }



   }
   else{
     l.set(R[inr],R[inr2]);
     for(int i=start;i<=end;i++){
        if(l.check(B[i])){
          tmpB1.push_back(B[i]);
        }
        else{
          tmpB2.push_back(B[i]);
        }
     }

     for(int i=start;i<=end;i++){
        if(i!=inr&&i!=inr2){
          if(l.check(R[i])){
            tmpR1.push_back(R[i]);
          }
          else{
            tmpR2.push_back(R[i]);
          }
        }
     }

     if(tmpR1.size()==tmpB1.size()){
       tmpR2.push_back(R[inr]);
       tmpR2.push_back(R[inr2]);
     }
     else{
       tmpR1.push_back(R[inr]);
       tmpR1.push_back(R[inr2]);
     }

     arrange(tmpR1,tmpB1,0,tmpR1.size()-1);
     arrange(tmpR2,tmpB2,0,tmpR2.size()-1);

     int k=start;
     for(int i=0;i<tmpR1.size();i++){
       R[k]=tmpR1[i];
       B[k]=tmpB1[i];
       k++;
     }
     for(int i=0;i<tmpR2.size();i++){
       R[k]=tmpR2[i];
       B[k]=tmpB2[i];
       k++;
     }


    }


   return ;
}

int main(){

   int n;
   cin>>n;
   n=n/2;

   vector<point> redpts(n);
   vector<point> bluepts(n);

   for (int i=0;i<n;i++){
        int x,y;
        cin>>x;
        cin>>y;
        redpts[i].x=x;
        redpts[i].y=y;
        redpts[i].color=true;
        redpts[i].in=i;
   }

   for (int i=0;i<n;i++){
        int x,y;
        cin>>x;
        cin>>y;
        bluepts[i].x=x;
        bluepts[i].y=y;
        bluepts[i].color=false;
        bluepts[i].in=i;
   }

   arrange(redpts,bluepts,0,n-1);

   for(int i=0;i<n;i++){
     cout<<redpts[i].in<<" "<<bluepts[i].in<<endl;
   }

   return 0;

}
