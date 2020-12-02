#include <iostream>
#include <unordered_map>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
int main(){
unordered_map<bitset<45>,char> mymap[26];
long long int A[26];
A[0]=0;
A[1]=511;
A[2]=261632;
A[3]=262143;
A[4]=133955584;
A[5]=133956095;
A[6]=134217216;
A[7]=134217727;
A[8]=68585259008;
A[9]=68585259519;
A[10]=68585520640;
A[11]=68585521151;
A[12]=68719214592;
A[13]=68719215103;
A[14]=68719476224;
A[15]=68719476735;
A[16]=35115652612096;
A[17]=35115652612607;
A[18]=35115652873728;
A[19]=35115652874239;
A[20]=35115786567680;
A[21]=35115786568191;
A[22]=35115786829312;
A[23]=35115786829823;
A[24]=35184237871104;
A[25]=35184237871615;
for(int j=0;j<26;j++){
bitset<45> thearray (A[j]);
char thechar=97+j;
bitset<45> temp (A[j]);
mymap[j][temp]=thechar;
for(int j1=0;j1<45;j1++){
temp[j1]=!temp[j1];
mymap[j][temp]=thechar;
temp=thearray;
}
for(int l=0;l<44;l++){
for(int m=l+1;m<45;m++){
temp[l]=!temp[l];
temp[m]=!temp[m];
mymap[j][temp]=thechar;
temp=thearray;
}
}
for(int p=0;p<43;p++){
for(int q=p+1;q<44;q++){
for(int r=q+1;r<45;r++){
temp[p]=!temp[p];
temp[q]=!temp[q];
temp[r]=!temp[r];
mymap[j][temp]=thechar;
temp=thearray;
}
}
}
for(int s=0;s<42;s++){
for(int t=s+1;t<43;t++){
for(int u=t+1;u<44;u++){
for(int v=u+1;v<45;v++){
temp[s]=!temp[s];
temp[t]=!temp[t];
temp[u]=!temp[u];
temp[v]=!temp[v];
mymap[j][temp]=thechar;
temp=thearray;
}
}
}
}

}
int numb;
int we;
string ans="";
cin>>numb;
long long int temper;
vector<bitset<45> > inputs;
for(int counter=0;counter<numb;counter++){
cin>>temper;
bitset<45> tempor (temper);
inputs.push_back(tempor);
}
for(int qw=0;qw<numb;qw++){
for(we=0;we<26;we++){
char charec=97+we;
if((mymap[we].find(inputs[qw]))!=mymap[we].end()){
cout<<charec;break;
}
else{}
}
if(we==26){cout<<"?";}
else{}
}
return 0;
}
