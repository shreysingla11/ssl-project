#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

long long binaryRep(long long );

/*struct func
{

};
*/
long long myfunc(long long i)
	{
        long long bits[5];
        long long p=1000000000,p1=1000000000,p2=1;bool ques=false;

        int errors=0,ones=0,zeros=0;
        bits[0]= i%p;
        bits[1]= (i/p1)%p;p1=p1*p;
        bits[2]= ((i/p1)/p1)%p;
        bits[3]= (((i/p1)/p1)/p1)%p;
        bits[4]= ((((i/p1)/p1)/p1)/p1)%p;

        for (int j=0;j<5;j++){
            for(int k=0;k<9;k++){
                if((bits[j]/p2)%10 == 1){
                    ones++;
                }
                if((bits[j]/p2)%10 == 0){
                    zeros++;
                }
                p2=p2*10;
            }

            errors=errors + (ones>zeros) ? (zeros) : (ones);

            if(errors<5){bits[j]= (ones>zeros) ? 1 : 0 ;}
            else{ques=true ; break;}

            ones=0;zeros=0;
            p2=1;
        }
        if(ques==true){return 11111;}
        else{   int p3=10;
                int result=bits[0];
                result=result+(p3*bits[1]);p3*=10;
                result=result+(p3*bits[2]);p3*=10;
                result=result+(p3*bits[3]);p3*=10;
                result=result+(p3*bits[4]);p3*=10;

                return result;
            }
            return 0;

	}

int main(){
    int n;
    long long dec,bin;
    char res;
    //char c='a';
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    long long resDec;
    unordered_map< long long ,char > M;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>dec;
        bin=binaryRep(dec);
        long long hi = myfunc(bin);
        resDec=decimalRep(hi);
        if (resDec==31){cout << "?";}
        if(resDec<26){cout<<alphabet[resDec];}
        else{cout << "?";}
    }


    for(long long i=0;i<26;i++){
        M.insert(pair<long long,char>(i,alphabet[i]));

    }


return 0;}

long long binaryRep(long long y){
    long long rem,i=1,sum=0;
    do
    {
        rem=y%2;
        sum=sum + (i*rem);
        y=y/2;
        i=i*10;
    }while(y>0);

    return sum;
}

long long decimalRep(long long num){
    long long dec=0,base=1,rem;
    while (num > 0)

    {

        rem = num % 10;

        dec = dec + rem * base;

        base = base * 2;

        num = num / 10;

    }
    return dec;

}

