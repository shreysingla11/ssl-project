#include <iostream>
using namespace std;
struct boolno{
              int a,b;
              bool c;
              };

boolno squarefree(string a,int l,int n){
                                       boolno e;
                                       e.a=0;
                                       e.b=0;
                                       e.c=true;
                                       int z=0;
                                       for(int x=1;x*(n/l)<n;x++){int n=x;int y=(x)*l;
                                                        for(int i=0;y<x*l+4*l-2 && i<l;i++){
                                                                         if(a[y+i]!=a[(x-1)*l+i])
                                                                         {int y=y+i;z=0;i=0;continue;}
                                                                          z++;
                                                                          if(z==l)break;
                                                                            }
                                                        if(z!=l){x++;continue;}int r=0;int f;
                                                        for( f=y-1;f>(x-1)*l+l-1;f--){r++;
                                                                                     if(a[f]!=a[(x-1)*l-y+f])break;
                                                                                     }
                                                                                     if(2*r+2*l<=8*l-2){e.c=false;e.b=f;e.a=2*(r+l);}
                                            for( f=x*l;f<y;f--){r++;
                                                                                     if(a[f]!=a[(x-1)*l-y+f])break;
                                                                                     }
                                                                                     if(2*r+2*l<=8*l-2){e.c=false;e.b=f;e.a=2*(r+l);}


                                                                }

                                       return e;
                                       }
int main(){
           string a;
           getline(cin,a);
           //cout<<a<<endl;
           int n;
           for(n=0;a[n]!='\0';n++){}

           int l=1;
           boolno d;
           d.a=0;d.b=0;d.c=true;
           for(l=1;2*l-1<n;l=2*l)
                            {
                            int m=2*l-1;
                            int n=2*m;

                            d=squarefree(a,l,n);
                            if(d.c==true)continue;
                            if(d.c==false)break;
                            }
           cout<<d.a<<" "<<d.b;
           }
