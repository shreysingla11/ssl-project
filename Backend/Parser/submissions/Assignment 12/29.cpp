#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>


using namespace std;

int main()

{
    long n;// no of persons
    cin>>n;


    vector<long> info;// person info
    vector< vector<long> >  input; // all
    long temp;
    long numFriends;
    for(int i=0;i<n;i++){
        cin>>temp;
        info.push_back(temp);
        cin>>numFriends;
        info.push_back(numFriends);
        for(int j=0;j<numFriends;j++){
        cin>>temp;
        info.push_back(temp);
        }
        input.push_back(info);
    }

    /*
    vector<long> info(n,0);
    vector< vector<long> >  input(n,info ); // all
    long temp;
    long threshhold;
    long friends;
    for(long i=0;i<n;i++){
        cin>>threshhold;
        input[i][0] = threshhold;
        cin>>friends;
        input[i][1] = friends;
        for(long j=0; j<friends;j++){
            cin>>temp;
            input[i][j+2]= temp;
        }
    }
    */
    for(long i=0;i<n;i++){
        for(long j=0;j<n;j++){
            cout << input[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}



