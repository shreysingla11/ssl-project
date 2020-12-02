#include <iostream>
#include <vector>
//#include <unordered_map>
#include <algorithm>
#include <stdlib.h>
#include <bitset>

using namespace std;

char decoder(long long int x)
{
    string binx=bitset<45>(x).to_string();
    int orig[5];
    int numone=0, numzero=0, num=0;
    for(int i=0;i<5;i++)
    {
        numone=0;
        numzero=0;
        for(int j=0;j<9;j++)
        {
            if(binx[9*i+j]=='0')
            {
                numzero++;
            }
            else if(binx[9*i+j]=='1')
            {
                numone++;
            }
        }
        if(numzero>numone)
        {
            orig[i]=0;
        }
        else
        {
            orig[i]=1;
        }
        if(numzero!=9 && numone!=9)
        {

            if (numzero>4)
            {
                num=num+numone;//corrupted bits in x
            }
            if (numone>4)
            {
                num=num+numzero;//corrupted bits in x
            }
        }
    }
    int orignum;
    orignum=orig[4]+2*orig[3]+4*orig[2]+8*orig[1]+16*orig[0];
    char result;
    if (orignum>=0&&orignum<=25&&num<=4)
    {
        result=orignum+97;
        //result=mapof[orignum];
    }
    else
    {
        result='?';
    }

    return result;
}

int main()
{
    /*int x;
    cin>>x;
    string binary = bitset<45>(x).to_string(); //to binary
    cout<<binary<<"\n";
    long long int p=34841965625839;
    cout<<decoder(p);*/
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        cout<<decoder(temp);
    }
    return 0;
}
