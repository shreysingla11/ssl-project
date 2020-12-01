#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

int main()
{
    long long int input;
    int n;
    bool a[5];
    unordered_map<long long int,char> A;
    cin>>n;
    long long int p2_9=pow(2,9);
    long long int p2_18=p2_9*p2_9;
    long long int p2_36=p2_18*p2_18;
    long long int p2_27=p2_18*p2_9;


    long long int alphabet;
    for(int i=0; i<2; i++)
    {

        a[4]=i%2;
        a[3]=(i/2)%2;
        a[2]=((i/2)/2)%2;
        a[1]=(((i/2)/2)/2)%2;
        a[0]=((((i/2)/2)/2)/2)%2;
        alphabet=(p2_9-1)*(a[0]*p2_36+a[1]*p2_27+a[2]*p2_18+a[3]*p2_9+a[4]);
        A[alphabet]=97+i;
        long long int p2_j=1;
        long long int p2_k;
        long long int p2_l;
        long long int p2_m;
        int temp;
        long long int alpha_temp1;
        long long int alpha_temp2;
        long long int alpha_temp3;
        for(int j=0; j<45; j++,p2_j=2*p2_j)
        {
            temp=j/9;
            if(a[4-temp]==0)
            {
                A[alphabet+p2_j]=97+i;
                alpha_temp1=alphabet+p2_j;
            }
            else
            {
                A[alphabet-p2_j]=97+i;
                alpha_temp1=alphabet-p2_j;
            }
            p2_k=1;

            for(int k=0; k<j; k++,p2_k=p2_k*2)
            {
                temp=k/9;
                if(a[4-temp]==0)
                {
                    A[alpha_temp1+p2_k]=97+i;
                    alpha_temp2=alpha_temp1+p2_k;
                }
                else
                {
                    A[alpha_temp1-p2_k]=97+i;
                    alpha_temp2=alpha_temp1-p2_k;
                }
                p2_l=1;
                for(int l=0; l<k; l++,p2_l=p2_l*2)
                {
                    temp=l/9;
                    if(a[4-temp]==0)
                    {
                        A[alpha_temp2+p2_l]=97+i;
                        alpha_temp3=alpha_temp2+p2_l;
                    }
                    else
                    {
                        A[alpha_temp2-p2_l]=97+i;
                        alpha_temp3=alpha_temp2-p2_l;
                    }
                    p2_m=1;
                    for(int m=0; m<l; m++,p2_m=p2_m*2)
                    {
                        temp=m/9;
                        if(a[4-temp]==0)
                        {
                            A[alpha_temp3+p2_m]=97+i;
                            //alpha_temp4=alpha_temp3+p2_m;
                        }
                        else
                        {
                            A[alpha_temp3-p2_m]=97+i;
                            //alpha_temp4=alpha_temp3-p2_m;
                        }

                    }
                }
            }
        }
    }

            for(int i=0; i<n; i++)
            {
                scanf("%lld",&input);
                if(A.count(input)==0)
                {
                    printf("?");
                }
                else
                {

                    printf("%c",A[input]);
                }
            }
            return 0;
}
