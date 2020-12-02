#include <iostream>
//#include <string>
#include <unordered_map>
using namespace std;
/*union ConversionUnion
{
    long long numericValue;
    char byteValues[sizeof(long long)];
};*/
long long int inttobinary(int n)
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
/*
 string longinttobinary(long long int n, int s){
string ans;
ans.resize(s);
long long int temp;
for(int i=0;i<s;i++){
temp=n%2;
ans[s-i-1]='0'+temp;
n=n/2;
}
return ans;
 }
*/
int main()
{
   long long int n;
    cin>>n;
    long long int temp;
    //ConversionUnion converter;
    //map <int,string> refer;
    long long int refer[26];
    unordered_map < long long int , char > data;
    char c = 'a';
    long long int twopower[45];
    twopower[0]=1;
    for(int i=1;i<45;i++){
    twopower[i]=2*twopower[i-1];
    };
    for(int i=0; i<26; i++)
    {
        refer[i]=inttobinary(i);
        //cout<<refer[i]<<endl;
        data[refer[i]]= c;

        for(int p=0;p<45;p++){
            data[(refer[i]^twopower[p])] = c;
        }
        for(int p=0;p<45;p++){
        for(int q=0;q<p;q++){

            data[((refer[i]^twopower[p])^twopower[q])] = c;

        }
        }
        for(int p=0;p<45;p++){
        for(int q=0;q<p;q++){
        for(int r=0;r<q;r++){
            data[(((refer[i]^twopower[p])^twopower[q])^twopower[r])] = c;

        }
        }
        }
         for(int p=0;p<45;p++){
        for(int q=0;q<p;q++){
        for(int r=0;r<q;r++){
        for(int s=0;s<q;s++){
            data[(((refer[i]^twopower[p])^twopower[q])^twopower[r])^twopower[s]] = c;

        }
        }
        }
        }
        c=c+1;
    }
for(long long int i=0;i<n;i++){
cin>>temp;
unordered_map<long long int,char>::iterator got = data.find (temp);
if ( got == data.end() ){
    cout << "?";}
  else{
    cout  << got->second;
}
}
    /*

        int count;
        for(int i=0; i<n; i++)
        {
            cin>> temp;
            //converter.numericValue = temp;
            //std::string bytes(converter.byteValues, converter.byteValues + sizeof(long long));
           string bytes = longinttobinary(temp,45);
           //cout<< bytes <<endl;

           bool found = false;
            for(int j=0;j<26;j++){
             //cout<< refer[j]<<endl;
            count=0;
            for(int k=0;k<45;k++){

            if(refer[j][k]!=bytes[k]){
            count++;
            }
            }
            //cout<<count<<endl;
            if(count>4){
            }
            else{
            char newchar = 'a';
            newchar=newchar+j;
            cout<<newchar;
            found = true;
            break;
            }
            }
            if(!found){
            cout<<"?";
            }
        }*/
    return 0;
}

