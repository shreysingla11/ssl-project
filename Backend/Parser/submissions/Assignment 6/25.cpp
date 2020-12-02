#include<string>
#include<iostream>
using namespace std;
int main()
{
string input;
cin>>input;
size_t length=input.length();
//cout<<input;
//cout<<"length="<<length;
int l=1;
int j;
bool flag=false;
int wordlength=0;
int wordbegin=0;
int n=length;
while(n/l!=1)
{
    int offset=l;
    //cout<<"n= and l="<<n<<" "<<l<<endl;
    //cout<<"n/l="<<(n/l)<<endl;
    for(int i=0;i<n-n%l;i++)
    {

//string test1=input.substr(i,n/l);

//string test2=input.substr(i+(n/l));
        int count=1;

        offset=l;
        //cout<<"offset="<<offset<<endl;
        //cout<<"i="<<i;
        j=i;
        while(offset<=3*l-2)
        {
            count++;
            //cout<<"j<=i+3*l-2 loop j="<<j<<endl;
            j=i;
            //cout<<"comparing "<<input[j]<<" &"<<input[offset+j]<<endl;
            //cout<<"at indices<<"<<j<<" "<<offset+j<<endl;
            while(input[j]==input[offset+j]&&j!=i+l&&offset<=3*l-2)
                {
                    j++;
                }
            if(j!=i+l)
                {
                    //cout<<"j!=i+l"<<endl;
                    offset=j+offset+1;
                    continue;
                }
            else if(input[j-1]==input[offset+j-1])
                {
                    j--;
                    //cout<<"found match at j= and offset ="<<j<<" "<<offset<<endl;
                    int k=0;
                    while(input[j+k]==input[offset+j+k])
                    {
                        k++;
                    }
                    int testin=j+k-1;
                    //cout<<"testin"<<testin<<endl;
                    int leadend=k-1;
                    k=0;
                    j=i;
                    while(input[j-k]==input[offset+j-k])
                    {
                        k--;
                    }
                    int lagend=0-k-1;
                    int testout=offset+j+k+1;
                    wordbegin=j+k+2;
                    //cout<<"testout"<<testout<<endl;

            wordlength=l+leadend+lagend-1;
            //int testin=j+k;
            if(testin==testout)
            {
                flag=true;
                break;
            }
        }
        }
if(flag==true)
break;

    }
if(flag==true)
break;
else
{

l*=2;
//cout<<"l sublength="<<l<<endl;
}
}
//if(flag==true)
//{

//}
cout<<wordlength<<" "<<wordbegin<<endl;


}
