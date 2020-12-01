#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter{
        private:
        vector<int> pg_cnt;
        vector<int>::iterator x;

        int n;
        list<int>l1;
        list<int>::iterator k;
        
        list<list<int> > l;
        list<list<int> >::iterator j;
        
        public:
        counter(int c){n=c;
                       for(int i=0;i<n;i++){
					                 pg_cnt.push_back(0);
									 l1.push_back(i);
									 }
                         x=pg_cnt.begin();
						 l.push_back(l1);
                       };
                       
        void increment(int i){
		                  pg_cnt[i]++;
						  }
						  
        void decrement(int i){
		                   pg_cnt[i]--;
						   }
						   
        void reset(int i){
		               pg_cnt[i]=0;
					   }
					   
        int count(int i){
		               return pg_cnt[i];
					   }
        int numMax(){
		             j=l.end();--j;
					 list<int>y=*j;
					 k=y.begin();int h;
				for( h=0;k!=y.end();h++){
				                       ++k;
									   }
					return h;
					}
        void printMax(){
		             j=l.end();--j;
					 list<int>y=*j;
					 k=y.begin();
					 while(k!=y.end()){
					            cout<<*k;++k;
								    }
						cout<<"\n";
						}
		void findMax(){
		               
					   }
        };
