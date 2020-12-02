#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
using namespace std;

int flip(int value)
{
    if(value==0)return 1;
    else return 0;
}

long long int conversion(vector <int> B)
{
    long long int k=1,j=0;
    for(int i=44;i>=0;i--)
    {
        j+=(k*B[i]);
        k*=2;
    }
    return j;
}

int main(){
	int n,j,p,q,r,s;
	long long int num,input;
	cin>>n;
	vector <int> B(45);
	bitset<5> A;
	char temp;

    unordered_map<long long int,char> mymap;
    unordered_map<long long int,char>::const_iterator got;

    for(int i=0;i<26;i++)
    {
        temp=i+97;
        A=i;
        //for(int i=0;i<5;i++)cout<<A[i];
        //cout<<endl;


        for(p=0;p<45;p++)
        {
            B[p]=A[4-p/9];
            //cout<<B[p];
        }
        //cout<<endl;
        num=conversion(B);
        mymap[num]=temp;

    for(p=0;p<45;p++)
        {
            B[p]=flip(B[p]);
            for(q=p+1;q<45;q++)
            {
                B[q]=flip(B[q]);
                for(r=q+1;r<45;r++)
                {
                    B[r]=flip(B[r]);
                    for(s=r+1;s<45;s++)
                    {
                        B[s]=flip(B[s]);
                        num=conversion(B);
                        mymap[num]=temp;
                        B[s]=flip(B[s]);
                    }

                    num=conversion(B);
                    mymap[num]=temp;
                    B[r]=flip(B[r]);
                }
                num=conversion(B);
                mymap[num]=temp;
                B[q]=flip(B[q]);
            }
            num=conversion(B);
            mymap[num]=temp;
            B[p]=flip(B[p]);
        }

    }
    for(int z=0;z<n;z++)
    {
        cin>>input;
        got=mymap.find(input);
        if(got!=mymap.end())cout<<mymap[input];
        else cout<<"?";
    }
    //cout<<endl;
    //cout<<"hi";
return 0;
}
