#include <iostream>
#include <vector>
using namespace std;

class distinct {
//    vector<vector <int> * > *array1_level; /* array that stores for each j, 0 <= j < n, the number
//                            of numbers in l(0) to l(j) that are >= n/2 */
//    vector<vector <int> > **array2_level;
    int **array1_level;
    int **array2_level;
    int *l;      /* l(i) is the largest j such that j < i and a_j = a_i */

public:
    distinct(vector <int> input) {

        int n=input.size();
        int i,t,x;

        for(x=n,t=0; x>1;) {x=x/2;t++;}
        int level = t;                                                                                          cout<<"done"<<endl;

        l = new int[n];
        for(i=0; i<n; i++) {l[i]=-1;}

        array1_level = new int*[level];
        array2_level = new int*[level];
        for(int t = 0; t < level; t++) {
            array1_level[t] = new int[n];
            array2_level[t] = new int[n];
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=i-1; j>=0; j--) {
                if(input[i]==input[j]) {l[i]=j;break;}
            }

        }


        for(int x=n,t=1; t<=level; x=x/2,t++) {
                                                                cout<<"x = "<<x<<" t = "<<t<<endl;

             for(int k=0; k<n/x; k++) {
                int y=0;
                int m1=-1,m2=-1;
                for(int j=k*x; j<k*x+x; j++) {

                    if( l[j] >= (k*x)+(x/2) && l[j] < k*x+x ) {y++;}
                    array1_level[t-1][j] = y;

                    if(j==0) {array2_level[t-1][0] = -1;}
                    else {
                        if( l[j-1] >= k*x && l[j-1] < (k*x)+(x/2) ) {m1=j-1;}
                        if( l[j-1] >= (k*x)+(x/2) && l[j-1] < k*x+x ) {m2=j-1;}

                        if( l[j] >= k*x && l[j] < (k*x)+(x/2) ) {array2_level[t-1][j]=m2;}
                        else if( l[j] >= (k*x)+(x/2) && l[j] < k*x+x ) {array2_level[t-1][j]=m1;}
                        else {array2_level[t-1][j]=-1;}
                    }
                cout<<array1_level[t-1][j]<<array2_level[t-1][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main() {
    vector<int> input;
    input.push_back(1);input.push_back(2);input.push_back(1);input.push_back(3);
    input.push_back(2);input.push_back(1);input.push_back(1);input.push_back(3);
    int n=input.size();
    for(int i=0; i<n; i++) {
            cout<<input.at(i)<<" ";
        }
        cout<<endl;
    distinct x(input);
        cout<<"done"<<endl;
}
