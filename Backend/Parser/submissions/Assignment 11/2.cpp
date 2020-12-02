#include<iostream>
#include <bitset>
#include<string>
#include<unordered_map>
using namespace std;
bitset<45> get_string(int k){
bitset<45> p;
bitset<5> q(k);
int i = 4 ;

int j=44,l,m;
while(i != -1){
  m = q[i]; 
if(m == 0){
     for(l= 1;l<=9;l++){p.set(j,0);j--;}
                                               }
if(m == 1)     {
     for(l= 1;l<=9;l++){p.set(j,1);j--;}
           }


 i =i-1;
               }
return p;
                          }


int main()                 {
//initialising map
unordered_map<bitset<45>,char > map1;
bitset<45> s;

int k;
char c ;
for(c = 'a',k = 0  ; k != 26 ;k++ ){
s = get_string(k);
//cout<< k << "    "<< s<<endl;
map1[s] = c;
           //collecting all flips
   int i,j,r,l;
   for(i =0 ;i<45;i++){
            s.flip(i); map1[s] = c;
               for(j = i+1 ;j<45;j++){
                   s.flip(j);map1[s] = c;
                       for(r = j+1 ;r<45;r++){
                                s.flip(r);map1[s] = c;
                                    for(l = r+1 ;l<45;l++){
                                              s.flip(l);map1[s] = c;
                                              s.flip(l);
                                                           }
                                s.flip(r);
                                             }
                    s.flip(j);
                         }
            s.flip(i);             
                     }
           //collected
                         c++;

                                }  


  //taking input
 int N;
 cin>>N;
 string result,s1;
 long long int y;
 bitset<45> *bits = new bitset<45>[N] ;
 for(int x = 0 ;x<N;x++){
      cin>>y;
     bitset<45> b(y);
     bits[x] = b ; 
                         }
 unordered_map<bitset<45>,char>::const_iterator ite;
 for(int x = 0 ;x<N;x++){
      
    ite = map1.find(bits[x]);
    if(ite == map1.end()) {cout<<"?";}
    else { cout<< ite->second;}
                           }  

cout<<endl;


return 0;
              }
