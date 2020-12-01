#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string input;
    cin>>input;
    //cout<<input.length();
    int curr=0,check=1,i=0,j=0,l=1,countj=0,count=0;
    for(l=1; l <= ((input.length()+2)/4) ; l*=2)
    {
        for(j = 0; j<=(input.length()); j+=l)
        {
            //cout<<"gherlh"<<endl;
            countj = j;
            count=0;
            for(i = j + l; /*(i - j) <= (3*l-2)*/; )
            {
                if(((i - countj) > ( 4*l - 2)) || (i >= (input.length())) )
                {
                    break;
                    //cout<<"gherlh"<<endl;
                }


                if(input[countj] != input[i])
                {
                    if(countj == j)
                    {
                        i++;
                        //count++;
                    }
                    countj = j;
                    count=0;
                    //i++;
                }
                else
                {
                    //cout<<"gherlh"<<endl;
                    //if( ( (countj) >= (2*l - 3)) && ( (countj) <= (4*l - 3)) )
                    //if( ( (countj-j) >= (2*l - 1)) && ( (countj-j) <= (4*l - 2)) )
                    if(countj == (i-count-1))
                    {
                        cout/*<<"TRUE "*/<<countj-j+1<<" "<<countj-count<<endl;
                        return 0;
                        //break;
                    }
                    countj++;
                    i++;
                    count++;
                }

                /*if(((i - countj) > ( 4*l - 2)) || (i >= (input.length()-1)) )
                {
                    break;
                    //cout<<"gherlh"<<endl;
                }*/
            }
        }
    }
    cout<<0<<" "<<0<<endl;
    return 0;
}


