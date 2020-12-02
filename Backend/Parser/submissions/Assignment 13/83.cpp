#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <map>
//#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <limits>
#include <stdio.h>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)
# define ll long long int
# define frl(i,n) for(ll i=0;i<n;i++)
# define frl1(i,n) for(ll i=1;i<=n;i++)

using namespace std;

class node{
public:
bool in_q;
bool in_r;
ll th,def_go,def_no;
ll n_frs;
queue <node*> prs;

};


int main(){
/**DECLARATIONS**/
ll n,g;
//ll** c;
cin>>n;
ll s[2*n+1][n];
ll infi=numeric_limits<ll>::max();
ll c[n][n];
//s=new ll*[2*n+1];

frl(i,n){
//    c[i]=new ll[n];
    frl(j,n){
    cin>>c[i][j];
    //cout<<c[i][j]<<" ";
    }
    //cout<<endl;
}

// frl(j,2*n+1){
//     s[j]=new ll[n];
// }


/**initializations**/
frl(v,n){
frl(j,2*n+1){
s[j][v]=infi;
////cout<<numeric_limits<ll>::max()<<endl;
}
}
s[n][0]=0;

////cout<<abs(-10.6)<<endl;
/**main iterations**/
frl(i,n*n){
        frl(u,n){
            //s[j][v]=infi;
/**for all predecesors of v**/
            frl(v,n){
            	for(int j=-n;j<n+1;j++){
                if(c[u][v]<0){
                	if(s[j+n][u]!=infi){
                		s[j+1+n][v]=min(s[j+1+n][v],s[j+n][u]+abs(c[u][v]));
          
                	}
                }

                else{
                	if(s[j+n][u]!=infi){
                		s[j+n-1][v]=min(s[j+n-1][v],s[j+n][u]+abs(c[u][v]));
          
                	}
                }
                



                }

        }
    }
}

ll m=infi;
frl(v,n){
	m=infi;
    for(ll j=n	;j<2*n+1;j++){
    	m=min(m,s[j][v]);
    	////cout<<s[j][v]<<" ";
    }
////cout<<endl;

if(m==infi){cout<<"infinity"<<endl;}
else{
    cout<<m<<endl;
}
}

return 0;
}

