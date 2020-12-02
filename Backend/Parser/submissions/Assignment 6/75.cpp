#include<iostream>
#include<string>
using namespace std;

void detect_square(string s, int& _begin, int& _size)
{
    int l;
    _begin=-1;
    _size=0;
    int start, start2, i, j;
    for(l=1; l<s.length(); l*=2)
    {   //cout<<endl<<l<<endl;//**************************************
        for(start=0; start<s.length()-l; start+=l)
        {   start2=start+l;
            i=0;
            j=0;
            //cout<<start2<<endl; //********************************
            while((j+start2-start)<=(3*l-1))
            {
                //cout<<"a"<<endl; //*************************************
                //******************************************************
                while(s[i+start]==s[j+start2]&&i<l&&(start2+j)<s.length())
                {  // cout<<"in"<<endl;
                    i++;
                    j++;
                }

                if(i==l)
                {   // cout<<"b"<<endl; //********************************************
                   {
                        int temp1=start;
                        int temp2=start2;

                        while(s[temp1]==s[temp2]&&temp1>=0)
                        {
                            temp1--;
                            temp2--;
                            if(temp2==start+l-1)
                           {
                            _begin=temp1+1;
                            _size=(start2-start);
                            break;
                           }
                        }
                        if(temp2==start+l-1)
                           {
                            _begin=temp1+1;
                            _size=(start2-start);
                            break;
                           }

                    }
                     if(_begin==-1)
                    {
                        int tempi=i;
                        int tempj=j;

                        while(s[start+tempi]==s[start2+tempj]&&start2+tempj<s.length())
                        {   tempi++;
                            tempj++;
                         //   cout<<"a";
                         if(start+tempi==start2)
                         {   _begin=start;
                            _size=(start2-start);
                            break;
                         }
                        }
                         if(start+tempi==start2)
                         {   _begin=start;
                            _size=(start2-start);
                            break;
                         }

                    }
                    i=0;

                }
                else
                {  // cout<<"a"<<endl;
                    if(i==0)
                       j++;

                    else
                       {i=0; }
                }

                //********************************************************************
            }
            if(_begin!=-1)
            break;
        }
         if(_begin!=-1)
            break;
    }


}


int main()
{
    string s;
    int b, n;
    cin>>s;
    detect_square(s, b, n);
    if(b==-1)
    cout<<"0"<<" "<<"0"<<endl;
    else
    cout<<n<< " "<<b<<endl;
    return 0;
}
