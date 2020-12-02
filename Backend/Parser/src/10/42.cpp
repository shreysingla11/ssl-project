#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class distinct{
    private:
        int n,count,up_greater,up_less;
        distinct *left,*right;
        //count is maintaining the number of numbers with l_value greater than n/2
        //up_greater maintains the greatest index which is having l_value greater than n/2
        //up_less is same but less than
    public:
        distinct(vector<int>& s);
        int num_distinct(int i, int j);
};
distinct::distinct(vector<int>& s){
    count=0; up_greater=-1;
    n=s.size();
    if(n>1){
        vector<int> l_value; //vector used to store l(j)
        vector<pair<int,int> >ss; //vector used to sort
        vector<pair<int,int> > r_val; //denotes the second level array
        for(int i=0;i<n;i++){
            ss.push_back(make_pair(s[i],i));
            l_value.push_back(-1);
            r_val.push_back(make_pair(-1,-1));
        }
        sort(ss.begin(),ss.end());
        for(int i=1;i<n;i++){
            if(ss[i-1].first==ss[i].first){
                l_value[ss[i].second]=ss[i-1].second;
            }
        }
        /*
        for(int i=0;i<n;i++){
            cout<<l_value[i]<<" ";
        }
        cout<<"\n";
        */
        //l_value verified
        for(int i=0;i<n;i++){
            if(l_value[i]>=n/2){ //always taking only the floor of the value
                count++;
                up_greater=i;
            }
            else{
                up_less=i;
            }
        }
        //cout<<up_greater<<"\n"<<up_less<<"\n";
        /*
        int prev1, prev2, count1, count2; //prev1 for the last occurred up_greater index, prev2 for last occurred up_less index
        prev1=-1; prev2=-1; count1=0; count2=0;
        for(int i=0;i<n;i++){
            if(l_value[i]>=n/2){
                prev1=i;
                if(l_value[i]>=((3/4)*n)){
                    count1++;
                }
                r_val[i].first=count1;
                r_val[i].second=prev2;
            }
            else{
                prev2=i;
                if(l_value[i]<(n/2) && l_value[i]>(n/4)){
                    count2++;
                }
                r_val[i].first=count2;
                r_val[i].second=prev1;
            }
        }
        */
        vector<int> vleft,vright;
        for(int i=0;i<=((n/2)-1);i++){
            vleft.push_back(s[i]);
        }
        for(int i=n/2;i<n;i++){
            vright.push_back(s[i]);
        }
        left = new distinct(vleft);
        if(up_greater!=-1){
            right = new distinct(vright);
        }
        else{
            right=NULL;
        }
    }
    else{
        left=NULL;
        right=NULL;
    }
}
int distinct::num_distinct(int i,int j){
    //assuming the construction
    int repeat_ex=j-i+1;
    if(n>1){
        if(i<n/2){
            repeat_ex-=count;
            repeat_ex+=left->num_distinct(i,up_less);
        }
        else{
            if(right!=NULL){
                repeat_ex+=right->num_distinct(i-(n/2),up_greater-(n/2));
            }
        }
    }
    //cout<<repeat_ex<<"\n";
    return repeat_ex;
}
/*
int main(){
    vector<int> s;
    cout<<"Enter n\n";
    int n;
    cin>>n;
    cout<<"Enter the sequence\n";
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        s.push_back(temp);
    }
    distinct d(s);
    cout<<"Enter i and j\n";
    int i,j;
    cin>>i>>j;
    cout<<"Yippee :"<<d.num_distinct(i,j)<<"\n";
    return 1;
}
*/
