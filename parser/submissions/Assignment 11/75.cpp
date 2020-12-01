#include <iostream>
#include <map>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
    long n;
    cin>>n;

    bitset<45> chbit;
    bitset<5> chbitcorr;
    long long chint;
    int chintcorr;
    char ch;

    int n0, n1;
    int error;

    for(long i=0; i<n; i++)
    {
        cin>>chint;
        bitset<45> b(chint);
        chbit= b;
        bitset<5> b1(0);
        chbitcorr= b1;
        error = 0;
        for (int j = 0; j<5; j++)
        {
            n0 = 0;
            for (int k = j*9; k<((j+1)*9); k++)
            {
                if(chbit[k] == 0)
                {
                    n0++;
                }
            }
            if(n0<=4)
            {
                chbitcorr[j]=1;
                error = error + n0;
            }
            else
            {
                chbitcorr[j]=0;
                error = error + (9 - n0);
            }
        }

        chintcorr = chbitcorr.to_ulong();

        if(error<=4)
        {
            ch = 'a' + chintcorr;
        }
        else
        {
            ch = '?';
        }
        cout<<ch;
    }

    return 0;
}
