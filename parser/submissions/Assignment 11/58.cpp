
#include <iostream>
#include <unordered_map>
using namespace std;
long long int binary(int n)
{
    long long int temp[5];

    for(int i=0; i<5; i++)
    {
        temp[i]=n%2;
        n=n/2;
    }
    long long int finl=0;
    long long int k=1;
    long long int m = 1;
    for(int j=0; j<9; j++)
    {m=1;
        for(int i=0; i<5; i++)
        {
            if(temp[i]==1)
            {
                finl+=k*m;
            }
            m*=512;
        }
        k*=2;
    }
    return finl;
}
int main()
{
   long long int n;
    cin>>n;
    long long int temp;
    long long int alphabet[26];
    unordered_map < long long int , char > error;
    char c = 'a';
    long long int exp[45];
    exp[0]=1;
    for(int i=1;i<45;i++){
    exp[i]=2*exp[i-1];
    };
    for(int i=0; i<26; i++)
    {
        alphabet[i]=binary(i);
        error[alphabet[i]]= c;

            for(int p=0;p<45;p++){
            error[(alphabet[i]^exp[p])] = c;
            }
            for(int p=0;p<45;p++){
            for(int q=0;q<p;q++){
            error[((alphabet[i]^exp[p])^exp[q])] = c;

            }
            }
            for(int p=0;p<45;p++){
            for(int q=0;q<p;q++){
            for(int r=0;r<q;r++){
            error[(((alphabet[i]^exp[p])^exp[q])^exp[r])] = c;
            }
            }
            }
             for(int p=0;p<45;p++){
            for(int q=0;q<p;q++){
            for(int r=0;r<q;r++){
            for(int s=0;s<q;s++){
            error[(((alphabet[i]^exp[p])^exp[q])^exp[r])^exp[s]] = c;
            }
            }
            }
            }
        c=c+1;
    }
for(long long int i=0;i<n;i++){
cin>>temp;
unordered_map<long long int,char>::iterator found = error.find (temp);
if ( found == error.end() ){
    cout << "?";}
  else{
    cout  << found->second;
}
}
    return 0;
}

