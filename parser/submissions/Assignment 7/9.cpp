#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    map<string, int> A;
    map<int, set<string> > B;

    char input1;
    string part1;
    int num1,num2,mistakes=0;
    char input;
    map<int, set<string> >::iterator itB;
    set< string >::iterator itA;


    while(input!='E')
    {
        cin>>input;
        switch(input)
        {
        case 'O':
        {
            cin>>part1;
            if(A.count(part1)!=0)
            {
                mistakes++;
            }
            else
            {
                A[part1]=0;
                B[A[part1]].insert(part1);
            }
        }
        break;
        case 'C':
        {
            cin>>part1;
            if(A.count(part1)==0)
            {
                mistakes++;
            }
            else
            {
                if(A[part1]!=0)
                {
                    mistakes++;
                }
                else
                {
                    B[A[part1]].erase(part1);
                    if(B[A[part1]].size()==0)
                    {
                        B.erase(A[part1]);
                    }
                    A.erase(part1);
                }
            }
        }
        break;
        case 'D':
        {
            cin>>part1>>num1;
            if(A.count(part1)==0)
            {
                mistakes++;
            }
            else
            {
                B[A[part1]].erase(part1);
                if(B[A[part1]].size()==0)
                {
                    B.erase(A[part1]);
                }
                A[part1]=A[part1]+num1;
                B[A[part1]].insert(part1);
            }


        }
        break;
        case 'W':
        {
            cin>>part1>>num1;
            if(A.count(part1)==0)
            {
                mistakes++;
            }
            else
            {
                if(A[part1]<num1)
                {
                    mistakes++;
                }
                else
                {
                    B[A[part1]].erase(part1);
                    if(B[A[part1]].size()==0)
                    {
                        B.erase(A[part1]);
                    }
                    A[part1]=A[part1]-num1;
                    B[A[part1]].insert(part1);
                }
            }
        }
        break;
        case 'P':
        {
            cin>>num1>>num2;
            for(itB=B.begin(); itB!=B.end(); itB++)
            {
                if((itB -> first <=num2)&&(itB -> first >=num1))
                {
                    cout<<itB->first;
                    for(itA=itB->second.begin(); itA != itB->second.end(); itA++)
                    {
                        cout<<" "<< *itA;
                    }
                    cout<<endl;
                }
            }
            break;

        }
        }
    }
    cout<<mistakes<<endl;
    return 0;
}
