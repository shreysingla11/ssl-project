#include<iostream>
#include<unordered_map>
#include<bitset>

using namespace std;

bitset<45> cnvt(bitset<5> c)
{
    bitset<45> code;
    int k=0;
    for(int i=0; i<5; i++)
    {
        for(int j=i*9; j<9+i*9; j++)
        {
            code[j]=c[i];
        }
    }
    return code;
}

int main()
{
    unordered_map<bitset<5> , char> codeword;
    int number=0;
    bitset<5> code;
    bitset<45> c;
    code=11111;
    for(int i=97; i<123; i++,number++)
    {

        codeword.insert( make_pair<bitset<5> , char>(bitset<5> (number) , i) );
    }

    /* for (auto& x: codeword){
     cout<<cnvt(x.first)<<endl;
     }*/

    int n;
    long long int* A=NULL;
    cin>>n;
    if(n==0)
    {
        return 0;
    }
    A= new long long int[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    bitset<45> temp,temp1;
    bool king;
    for(int i=0; i<n; i++)
    {
        bitset<45> b(A[i]);
        king=false;
        for (auto& x: codeword)
        {
            temp1 = (cnvt(x.first));
            temp = bitset<45> (b & ~temp1);
            temp1 = bitset<45> (temp1 & ~b);
            if(temp.count()<=4&&temp1.count()<=4)
            {
                cout<<x.second;
                king=true;
                break;
            }
            else
            {
            }
        }
        if(!king){cout<<"?";}
    }
    cout<<endl;
    delete [] A;
    A= NULL;
    return 0;


}

