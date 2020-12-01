#include <iostream>
#include <functional>
#include <string>
#include<unordered_map>
#include<cmath>

using namespace std;
long long int countSetBits(long long int n);
long long int con(long long int bin);

long long int convert(char A);

struct func
{
	long long operator()(long long const i) const
	{
        for(char alpha='a';alpha<='z';alpha++)
        {
        long long int res=convert(alpha);
        long long int result=(res)^(i);
        long long int diff=countSetBits(result);
        if(diff<=4)
            return res;
        else
            continue;
        }
        /*if(diff>4)
            {
                return hash());
            }*/


	}
};

long long int countSetBits(long long int n)
{
    long long int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
long long int con(long long int bin)
    {
    long long int rem,dec,base,num;
    num=bin;base=1;dec=0;
       while (num > 0)
    {
        rem = num % 10;
        dec = dec + rem * base;
        base = base * 2;
        num = num / 10;
    }
    return dec;
    }

long long int convert(char A)
    {
        //cout<<(int)A;
        //A=(int)A-97;
        //cout<<"orig a"<<A<<endl;
        A=(long long int)A;
        //cout<<"a value"<<A<<endl;
        long long int result=0;
        long long int temp=111111111;
        if(A&1)
            {
                result=result|con(temp);
                //cout<<result<<"1";
            }
        A>>=1;
        if(A&1)
            {
                result=result|con(temp*pow(10,9));
                 //cout<<result<<"2";
            }
        A>>=1;
        if(A&1)
            {
                result=result|con(temp*pow(10,18));
                 //cout<<result<<"3";
            }
        A>>=1;
        if(A&1)
            {
                result=result|con(temp*pow(10,27));
                 //cout<<result<<"4";
            }
        A>>=1;
        if(A&1)
            {
                result=result|con(temp*pow(10,36));
                 //cout<<result<<"5";
            }
        A>>=1;
        return result;

    }
 unordered_map <long long int,char, func> mymap;
int main()
{
    //cout<<convert('e');
   unordered_map < long long int,char, func >::const_iterator it=mymap.begin();
    for( char i='a';i<='z';i++)
        {
            //cout<<i<<"\n";
            //cout<<convert(i)<<"convert"<<endl;
            pair<long long int,char>toinsert(convert(i),i);
            mymap.insert(toinsert);

        }

    /*for( unordered_map < long long int,char, func >::const_iterator it = mymap.begin(); it != mymap.end(); ++it )
        cout << it->first << it->second<<"\n";*/

   long long int totalsize;
    cin>>totalsize;
    for(long long int i=0;i<totalsize;i++)
        {
            long long int input;
            cin>>input;
            unordered_map <long long int , char , func >::const_iterator got = mymap.find (input);

            if ( got == mymap.end() )
                cout << "?";
            else
                cout << got->second;

        }
}
