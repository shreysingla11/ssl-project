#include <iostream>
#include <string.h>
using namespace std;

int main()  {
    string str;
    cin>>str;

    int n=str.length();                             //cout<<"n="<<n<<endl;
    int m_max=n/2;
    int length=0,position=0;

    for(int l=1;l<=m_max;l=2*l){
                                                    //cout<<"l="<<l<<endl;
        for( int i=0 ; i<(n/l) ; i=i+1 ) {
            int p=i*l,q=i*l+(2*l-2),firstpos=0;     //cout<<"..block "<<i<<endl;

            while (firstpos<=i*l+(4*l-3))   {       //cout<<"...p="<<p<<".."<<str[p]<<endl;
                                                    //cout<<"...q="<<q<<".."<<str[q]<<endl;
                if (str[p]==str[q] && p!=q) {
                    if (p == (i*l)+(l-1)) {firstpos;break;}
                    else    {p++;q++;}
                }
                else {p=i*l;q++;firstpos=q;}
            }

            if (p == (i*l)+(l-1))   {
                int pre1=i*l, pre2=firstpos;
                while ( pre1>=0 && pre2>(i*l)+(l-1) )   {   //cout<<"....pre1="<<pre1<<".."<<str[pre1]<<endl;
                                                            //cout<<"....pre2="<<pre2<<".."<<str[pre2]<<endl;
                    if(str[pre1]==str[pre2]) {pre1--;pre2--;}
                    else    {break;}
                }
                pre1++;pre2++;                      //cout<<"....pre1="<<pre1<<".."<<str[pre1]<<endl;
                                                    //cout<<"....pre2="<<pre2<<".."<<str[pre2]<<endl;
                int post1=p, post2=firstpos+(l-1);
                while ( post1<pre2 && post2<=n-1 )  {       //cout<<"....post1="<<post1<<".."<<str[post1]<<endl;
                                                            //cout<<"....post2="<<post2<<".."<<str[post2]<<endl;
                     if(str[post1]==str[post2]) {post1++;post2++;}
                     else   {break;}
                }
                post1--;post2--;
                                                    //cout<<"....post1="<<post1<<endl;
                                                    //cout<<"....post2="<<post2<<endl;
                if ( (pre2-post1)==1 )  {
                                                    //cout<<"***"<<endl;
                    length = (post1-pre1+1);
                    position = pre1;
                    break;
                }
            }
        }
        if (length != 0) {break;}

    }

    cout<<length<<" "<<position<<endl;
    return 1;
}
