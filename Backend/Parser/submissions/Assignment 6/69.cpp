#include <iostream>
#include <string>
using namespace std;


int main ()
{
    string str;
    cin>>str;
    int bre=0;
    for(int length=1;length<str.length()/2;length++)
    {
        for(int i=0;i<str.length()+1-length;i++)
        {
            string temp1=str.substr(i,length);
            string temp2=str.substr(i+length,length);
            if(temp1.compare(temp2)==0)
            {
                bre=1;
                cout<<length<<" "<<i<<endl;
                break;
            }
        }
        if(bre==1)
        {
            break;
        }
    }
    return 0;
}
