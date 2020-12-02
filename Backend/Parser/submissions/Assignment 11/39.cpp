#include<iostream>
#include<string>
#include<stdio.h>
#include<unordered_map>
using namespace std;

int main(){
    char C[26];
    for(int i=0;i<26;i++){
        C[i] = 'a' + i;
    }
    long long A[46];
    long long temp=1;
    for(int i=0;i<46;i++){
        A[i] = temp;
        temp*=2;
    }
    int B[26][5];
    for(int i=0;i<26;i++){
        int temp = i;
        int j=4;
        while(true){
            if(temp==0){B[i][j]=0;break;}
            else{if(temp==1){B[i][j]=1;break;}}
            if(temp%2==0){B[i][j]=0;}
            else{B[i][j]=1;}
            temp = temp/2;
            j--;
        }
        j--;
        while(j>=0){
            B[i][j] = 0;
            j--;
        }
    }







    unordered_map<long long,char> m;
    for(int p=0;p<26;p++){
        temp = 0;
        for(int i=0;i<5;i++){
            int r = i*9;
            int q = B[p][4-i];
            if(q!=0){
                int len = ((i+1)*9);
                while(r<len){
                    temp = temp + A[r];
                    r++;
                }
            }
            else{}//skip this
        }



        m[temp] = C[p];
        for(int i=0;i<45;i++){
            for(int j=i;j<45;j++){
                for(int k=j;k<45;k++){
                    for(int l=k;l<45;l++){
                        long long flip;
                        //flip i
                        flip = temp;
                        if(B[p][(i/9)]==1){flip = flip - A[44-i];}
                        else{flip = flip + A[44-i];}
                       // m[flip] = C[p];
                         //flip j
                      //  flip = temp;
                      if(i!=j){
                        if(B[p][(j/9)]==1){flip = flip - A[44-j];}
                        else{flip = flip + A[44-j];}
                    }
                       // m[flip] = C[p];
                         //flip k
                        //flip = temp;
                        if(j!=k){
                            if(B[p][(k/9)]==1){flip = flip - A[44-k];}
                            else{flip = flip + A[44-k];}
                       } //m[flip] = C[p];
                         //flip l
                       // flip = temp;
                       if(k!=l){
                        if(B[p][(l/9)]==1){flip = flip - A[44-l];}
                        else{flip = flip + A[44-l];}
                    }
                        m[flip] = C[p];

                    }
                }
            }
        }

    }

    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        long long number;
        cin>>number;
        if(m.count(number)>0){printf("%s",&(m[number]));}
        else{printf("?");}
    }

    return 0;
}
