    #include <iostream>
    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <list>
    #include <string>
    #include <map>
    #include <unordered_map>
    #include <set>
    #include <stack>
    #include <algorithm>
    # define fr(i,n) for(int i=0;i<n;i++)
    # define fr1(i,n) for(int i=1;i<=n;i++)
    # define ll long long int
    # define frl(i,n) for(ll i=0;i<n;i++)
    # define frl1(i,n) for(ll i=1;i<=n;i++)

    using namespace std;


    int main()
    {
    char c;
    int temp;
    ll n,b_str,sum;
    ll five_l[26][5];
    ll* two_p=new ll[45];
    ll* codewords=new ll[26];
    unordered_map<ll,char> decode;
    unordered_map<ll,char> ::iterator it;

    /**array of 2 powers**/
    two_p[0]=1;
    frl1(i,44){
    two_p[i]=two_p[i-1]*2;
    //cout<<two_p[i]<<" ";
    }

    /**finding 5 lenght lls for a-z**/
    fr(i,26){
    temp=i;
    fr(j,5){
    five_l[i][j]=temp%2;
    temp/=2;
    ////cout<<temp;
    ////cout<<five_l[i][j];
    }
    ////cout<<endl;
    }

    /**finding 45 lenght lls (codewords) for a-z**/
    fr(i,26){
    sum=0;
    fr1(j,5){
    sum+=five_l[i][j-1]*((two_p[9]-1)*(two_p[9*(j-1)]));
    }
    codewords[i]=sum;
    //cout<<sum<<endl;
    }


    /**finding error b_strs and insertin unordered set**/
    /**case 1 45c1**/
    c='a';
  
   fr(i,26){
   /**for each letter**/
   	decode.insert({codewords[i],c});
   fr(j,45){
   sum=codewords[i]^two_p[j];
   //cout<<sum<<" "<<c<<endl;
   decode.insert({sum,c});
}


fr(j,45){

for(int k=j+1;k<45;k++){

sum=(codewords[i]^two_p[j])^two_p[k];
decode.insert({sum,c});
}
}

fr(j,45){

for(int k=j+1;k<45;k++){

for(int l=k+1;l<45;l++){

sum=((codewords[i]^two_p[j])^two_p[k])^two_p[l];
decode.insert({sum,c});
}
}
}


fr(j,45){

for(int k=j+1;k<45;k++){

for(int l=k+1;l<45;l++){
for(int m=l+1;m<45;m++){
sum=(((codewords[i]^two_p[j])^two_p[k])^two_p[l])^two_p[m];
decode.insert({sum,c});
}
}
}
}
	c=c+1;
   }


    cin>>n;
    frl(i,n){
    cin>>b_str;
    it=decode.find(b_str);
    if(it!=decode.end()){
    	cout<<(*it).second;
    }
    else{
		cout<<"?";

    }
    }
cout<<endl;



        return 0;
    }

