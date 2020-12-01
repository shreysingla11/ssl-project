#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main()
{
    int first,second,xx,xy;

    cin>>first>>second;

    int i=0,k=0;
  //  vector<int> A,B;
    list<int> A,B,verify2,verify,final1,final2;
    list<int> :: iterator p,a,c,d,e,f,g,h;
    while(k<first)
    {
        cin>>xx;
        A.push_back(xx);
        k++;


    }
    k=0;
    while(k<second)
    {
        cin>>xy;
        B.push_back(xy);

        k++;
    }
    int x=0,temp1=0;
    e=A.begin();
    f=B.begin();
    while(i<first)
    {

        //cout<<"first"<<endl;
        if(*e==*f&&x<second)
        {
            if(x==0)
            {
                temp1=i;
            }
            x++;f++;
            if(x==second)
            {
                verify.push_back(temp1+1);
                verify.push_back(i+1);
                i--;e--;
                x=0;f=B.begin();

            }
        }

        i++;e++;

    }
    i=first;
    x=second;
    g=A.end();
    h=B.end();
    g--;h--;
    while(i>0)
    {

        // cout<<"second"<<endl;
        if(*g==*h&&x>0)
        {
            if(x==second)
            {
                temp1=i;
            }
            x--;h--;
            if(x==0)
            {
                verify2.push_front(temp1);
                verify2.push_front(i);
                i++;g++;
                x=second;h=B.end();h--;

            }
        }

        i--;g--;

    }

 /*  p=verify.begin();
    a=verify2.begin();
    while(p!=verify.end())
    {
    cout<<*p<<endl;
    p++;
    }*/
    a=verify2.begin();
    p=verify.begin();
    i=1;
    while(a!=verify2.end())
    {
        if(*a==*p)
        {
            final1.push_back(*a);
        }
        else
        {
            if(i%2==1)
            {
                final1.push_back(*a);
            }
            else
            {
                final1.push_back(*p);
            }
        }
        a++;
        p++;
        i++;
    }
    d=final1.begin();
    int min=first+1,aa=0,bb=0,index=0;
    while(d!=final1.end())
    {
        aa=*d;
        d++;
        bb=*d;
        d++;
        if(min>bb-aa)
        {

            min=bb-aa;
            index=aa;
        }

    }
    if(verify.begin()==verify.end())
    {
        cout<<"infinity"<<endl;
    }
    else
    {
        cout<<min+1<<" "<<index<<endl;
    }



    return 0;}
