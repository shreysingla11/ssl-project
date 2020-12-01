#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

string line;
int n;
bool found;
int strLen;
int strInd;

int blockMatch(int ind, int length) {
    int k;
    int minIndex = ind + 2*length -1;
    int maxIndex = ind + 3*length -1;
    if (minIndex >= n) return -1;
    for (int j = minIndex; j <= maxIndex && j + length <= n;) {
        if (line[ind] == line[j]) {
            for (k = 0; k < length; k++) {
                if (line[ind + k] != line[j+k]) {
                    break;
                }
            }
            if (k == length) {return j;}
            j=j+k;
        }
        else j++;
    }
return -1;
}

void stringMatch (int ind1, int ind2, int length) {

    int end1 = ind1 + length;
    int end2 = ind2 + length;

    while( end1 != ind2 ) {

        if( ind1 == 0) return;
        ind1--;
        ind2--;
        if( line[ind1] != line[ind2] ) {
            ind1++;
            ind2++;
            break;
        }
    }

    if( end1 == ind2 ) {

        if (strLen == 0 && end1 - ind1 != 0) {
        cout<<"1"<<endl;
            strLen = end1 - ind1;
            strInd = ind1;
            found = true;
            }
        else if (strLen > end1 - ind1) {
        cout<<"2"<<endl;
            strLen = end1 - ind1;
            strInd = ind1;
            found = true;
        }
        return;
    }

    while( end1 != ind2) {

        if( end2 == n) return;
        if( line[end1] != line[end2] ) {
            break;
        }
        end1++;
        end2++;
    }

    if( end1 == ind2 ) {
        if (strLen == 0 && end1 - ind1 != 0) {
            strLen = end1 - ind1;
            strInd = ind1;
            found = true;
            }
        else if (strLen > end1 - ind1) {
            strLen = end1 - ind1;
            strInd = ind1;
            found = true;
        }
        return;
    }

    return;
}



int main() {

cin>>line;

int l=1;
found = false;
n=line.length();
strLen=0;
strInd=0;

for(l=1;l<=(n+4)/8 + 1;l=l*2) {

    for(int i=0;i<n/l;i++) {
//        cout<<blockMatch(0,1)<<endl;
        if (blockMatch(i*l,l) != -1) {
            for(int d=2*l-1; d<4*l-2 && found == false; d++) {
                stringMatch(i*l,blockMatch(i*l,l),l);
            }
        }
    }
    //cout<<found<<endl;
if (found == true) break;
}

//cout<<blockMatch(2,2)<<endl;
cout<<strLen<<" "<<strInd<<endl;

return 0;
}
