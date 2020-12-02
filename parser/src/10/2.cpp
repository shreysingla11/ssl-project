#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class object{
public:
    int value;
    int index;
              };

void arraycreate(int s,int e,int N,int l[],vector<int[]> &v){

int A[N],count;
 for(int i=0;i<N;i++){
     if((l[i]>= s)&&(l[i]<e)){count = count + 1;}
      A[i] = count;
                       }
    v.insert(A);
     arraycreate()



                                                                         }

  //overloading the operator
  bool operator< (const object a, const object b)
{
    if(a.value == b.value){return (a.index < b.index);}
    else{return (a.value<b.value);}
}



class distinct{
public:

distinct(vector<int> v){

    //getting l out of v

    int N = v.size();
vector<object> v1;
                for(int i=0;i<N;i++){
                             object o;
                        o.value = v[i];
                        o.index = i;
                                       }

sort(v1.begin(),v1.end());
vector<object> :: iterator j;
int l[N];
l[0]= -1;
l[v1[0].index] = -1;
for(int i = 1;i<N;i++){
       if (v1[i].value == v1[i-1].value) {l[v1[i].index] = v1[i-1].index;}
       else{ l[v1[i].index] = -1;}
                        }

             // l has extracted;
//=====================================================================
           //create arrays recursively
vector<int[]> v;
arraycreate(N/2,N,N,l,v);

           //arrays created

                                }


                 };

int main(){




return 0;
                  }





