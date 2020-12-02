#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

class distinct{
public:
        vector<int> sequence_1;
        void num_distinct(int a, int b){
                        int ans=0;
                        vector <int> sequence_2;
                        for (int i=a;i<b+1;i++){
                         sequence_2[i-a]=sequence_1[i];}

                          sort(sequence_2.begin(), sequence_2.end());

                          for( int k=1;k<a-b;k++){
                          if((sequence_2[k]!=sequence_2[k-1])&&(sequence_2[k]!=sequence_2[k+1])){
                           ans=ans+1;}}
                           if (sequence_2[0]!=sequence_2[1]){
                           ans=ans+1;}
                            if (sequence_2[b+1]!=sequence_2[b]){
                           ans=ans+1;}

                           cout<<ans<<endl;


         }


};
