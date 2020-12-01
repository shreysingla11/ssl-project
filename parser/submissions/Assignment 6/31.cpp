#include <iostream>
#include <string>

using namespace std;

int main()
{
    //char A[10];
    //char A[];
    string A;
    cin>>A;



  int n=A.length();

    int first=n;
    int length=1;
    bool sq=false;//it is sq free at intialization


    int l=1;



   while(l<=(n/2)){
    for(int i=n-1;i>=(l-1);)
        {
            int c=0;
            for(int j=l-1;j>=0;j--)
            {

                if( !(A[i-j]==A[i-l-j]) )
                {
                c=1;


                }


            }
            if(c == 0)
            {

                first=i-2*l+1;
                length=l;
                sq = true ;
            }

            i=i-l;


        }

        l=l+1;
        }
    if( sq ){ cout<<length<<" "<<first<<endl; }
    else{ cout<<"0 0"<<endl; }




    return 0;
}

