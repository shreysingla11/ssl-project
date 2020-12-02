#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<math.h>
#include<sstream>
using namespace std;
//here since integers leave out any zeroes in the start of the integer, adding a one before all the key values to reduce anomaly
string correct(long long int key, unordered_map<long long int,char>& hashmap);
int main(){
    long long int key;
    char value;
    stringstream convert;
    unordered_map<long long int,char> hashmap;
    long int key_small;
    string string_key;
    string string_tempkey;
    string ones="111111111";
    int temp;
    key=0;
    key_small=0;
    cout<<hashmap[10];
    //to integer function to be included call stoll
    hashmap[0]='a';
    //clear string_key
    string_key.clear();
    //cout<<string_key.max_size();
    for(int i=97;i<123;i++){
        if(key_small%10==0){
            key_small+=1;
            {
                //string_key+=1;
                temp=key_small/pow(10,4);
                if(temp==1){
                    key+=(stoll(ones)*pow(10,36));
                }
                for(int j=3;j>=0;j--){
                    temp=key_small/pow(10,j);//using the power function
                    temp=temp%10;
                    if(temp==1){
                        key+=(stoll(ones)*pow(10,(9*j)));
                    }
                }
                hashmap[key]=char(i);
                //clear string_key
                string_key.clear();
            }
        }
        else{
            key_small-=1;
            if((key_small/10)%10==0){
                key_small+=10;
                {
                    //string_key+=1;
                    temp=key_small/pow(10,4);
                    if(temp==1){
                        key+=(stoll(ones)*pow(10,36));
                    }
                    for(int j=3;j>=0;j--){
                        temp=key_small/pow(10,j);//using the power function
                        temp=temp%10;
                        if(temp==1){
                            key+=(stoll(ones)*pow(10,(9*j)));
                        }
                    }
                    //key=stoll(string_key);
                    hashmap[key]=char(i);
                    //clear string_key
                    string_key.clear();
                }
            }
            else{
                key_small-=10;
                if((key_small/100)%10==0){
                    key_small+=100;
                    {
                        //string_key+=1;
                        temp=key_small/pow(10,4);
                        if(temp==1){
                            key+=(stoll(ones)*pow(10,36));
                        }
                        for(int j=3;j>=0;j--){
                            temp=key_small/pow(10,j);//using the power function
                            temp=temp%10;
                            if(temp==1){
                                key+=(stoll(ones)*pow(10,(9*j)));
                            }
                        }
                        //key=stoll(string_key);
                        hashmap[key]=char(i);
                        //clear string_key
                        string_key.clear();
                    }
                }
                else{
                    key_small-=100;
                    if((key_small/1000)%10==0){
                        key_small+=1000;
                        {
                            //string_key+=1;
                            temp=key_small/pow(10,4);
                            if(temp==1){
                                key+=(stoll(ones)*pow(10,36));
                            }
                            for(int j=3;j>=0;j--){
                                temp=key_small/pow(10,j);//using the power function
                                temp=temp%10;
                                if(temp==1){
                                    key+=(stoll(ones)*pow(10,(9*j)));
                                }
                            }
                            //key=stoll(string_key);
                            hashmap[key]=char(i);
                            //clear string_key
                            string_key.clear();
                        }
                    }
                    else{
                        key_small-=1000;
                        key_small+=10000;
                        {
                            //string_key+=1;
                            temp=key_small/pow(10,4);
                            if(temp==1){
                                key+=(stoll(ones)*pow(10,36));
                            }
                            for(int j=3;j>=0;j--){
                                temp=key_small/pow(10,j);//using the power function
                                temp=temp%10;
                                if(temp==1){
                                    key+=(stoll(ones)*pow(10,(9*j)));
                                }
                            }
                            //key=stoll(string_key);
                            hashmap[key]=char(i);
                            //clear string_key
                            string_key.clear();
                        }
                    }
                }
            }
        }
        key=0;
    }
    int n;
    string output;
    cout<<"Enter the value of n \n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter key:\n";
        cin>>key;
        //string_key+='1';
        //string_key+=string_tempkey;
        //key=stoll(string_key);
        //cout<<endl;
        output+=correct(key,hashmap);
    }
    cout<<output<<"\n";
    return 1;
}
string correct(long long int key, unordered_map<long long int,char>& hashmap){
    int count0,count1,diff;
    long long int temp;
    string string_key;
    string ones="111111111";
    diff=0;
    for(int i=4;i>0;i--){
        count0=0;count1=0;
        for(int j=(i*9);j<((i*9)+9);j++){
            temp=key/pow(10,j);
            if(i==4 && temp==1){
                count1++;
            }
            else if(i==4){
                count0++;
            }
            else if(temp%10==0){
                count0++;
            }
            else{
                count1++;
            }
            if(count0<count1){
                diff+=count0-count1;
                key+=(stoll(ones)*pow(10,(9*i)));
            }
            else{
                diff+=count1-count0;
            }
        }
        if(diff>4){
            return "a?";
        }
    }
    //key=stoll(string_key);
    string_key=hashmap[key];
    if(string_key!=""){
        return string_key;
    }
    else{
        return "a?";
    }
}


















