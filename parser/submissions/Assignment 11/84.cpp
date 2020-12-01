#include <iostream>
#include <bitset>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Decoder
{

    public:
    vector<int> temp;

	pair<int,int> Nine_to_1()
{
    pair<int,int> result;
    int Zeros = 0, Ones = 0;
    int n,e;
    for(int i = 0; i < 9;i++)
    {
            if(temp[i]==0){Zeros++;}
            if(temp[i]==1){Ones++;}
    }
    if(Ones>Zeros)
    {
        n = 1;
        e = Zeros;
    }
    else{
    n = 0;
    e = Ones;
    }
    result.first = n;
    result.second = e;
    return result;
}


void get_Digits(int n)
{
    temp.assign(9,0);
    int b = 10;

    for(int i = 0 ; i < 9 ; i++)
    {
        temp[i] = n%b;
        n = n/b;
    }
    return;
}

long long Convert(long long const j)
	{
        int b = 10;
        int i = j;
        b = b*b*b; b = b*b*b;
        int a[5],n[5],e[5];
        pair<int,int> S;
        a[0] = i%b; i = i/b;
        a[1] = i%b; i = i/b;
        a[2] = i%b; i = i/b;
        a[3] = i%b; i = i/b;
        a[4] = i%b; i = i/b;
        for(int k = 0 ; k < 5 ; k++)
        {
            get_Digits(a[k]);
            S = Nine_to_1();
            n[k] = S.first;
            e[k] = S.second;
        }

        int err=0;long long res5 = 0;
        for(int k = 0 ; k < 5 ; k++)
        {
        err = err + e[k];
        }
        int ddd = 1;
        if(err > 4){res5 = 11111;}
        else{
        for(int k = 0 ; k < 5 ; k++)
        {
        res5 = res5 + n[k]*ddd;
        ddd = ddd*10;
        }
        }
        return res5;

}
};

long long decimal_binary(long long n)  /* Function to convert decimal to binary.*/
{
    int rem, i = 1;
    long long binary = 0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

int main()
{
    int n;
    long long K,r;
    Decoder d;
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> K ;
        r = d.Convert(decimal_binary(K));
        if(r == 11111){cout << "?";}
        if(r == 0 ){cout << "a";}
    }
}
