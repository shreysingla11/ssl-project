#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool getsign(vector<int> v1, vector<int> v2 , vector<int> v){
    int x1,x2,x3,y1,y2,y3;
    bool b=false;
    x1=v1[0];y1=v1[1];
    x2=v2[0];y2=v2[1];
    x3=v[0];y3=v[1];
    if(((y3-y1)*(x2-x1))-((x3-x1)*(y2-y1))<0) {b=true;}
    return b;
}

vector<vector<int> > divlr(vector<vector<int> > red,vector<vector<int> > blue){
        int sr=red.size();
        int sb=blue.size();
        vector<vector<int> > answer;
        vector<vector<int> > lred;
        vector<vector<int> > lblue;
        vector<vector<int> > gred;
        vector<vector<int> > gblue;
        vector<int> randb(2);
        if(sr==1){
            randb[0]=red[0][2];
            randb[1]=blue[0][2];
            answer.push_back(randb);
            return answer;
        }
        else{
            vector<int> fred(3);
            vector<int> fblue(3);
            fred[0]=red[0][0];fred[1]=red[0][1];fred[2]=red[0][2];
            int i=0,bless=0,rless=0,bmore=0,rmore=0;
            while(i<sb){
                fblue[0]=blue[i][0];fblue[1]=blue[i][1];fblue[2]=blue[i][2];
                int j=1,k=0;
                for(j=1;j<sr;j++){
                    if(getsign(fred,fblue,red[j])) {
                        rless++;
                        lred.push_back(red[j]); }
                    else{
                        gred.push_back(red[j]);
                        rmore++;
                    }
                }
                for(k=0;k<sb;k++){
                    if(k==i) continue;
                    if(getsign(fred,fblue,blue[k])) {
                        bless++;
                        lblue.push_back(blue[k]); }
                    else{
                        gblue.push_back(blue[k]);
                        bmore++;
                    }
                }
                if(rless!=bless){
                    rless=0;bless=0;
                    lblue.clear();
                    lred.clear();
                    gblue.clear();
                    gred.clear();
                    i++;
                }
                else{
                    vector<vector<int> > tanswer;
                    randb[0]=fred[2];
                    randb[1]=fblue[2];
                    answer.push_back(randb);
                    if(bless!=0){
                    tanswer=divlr(lred,lblue);
                    answer.insert(answer.end(),tanswer.begin(),tanswer.end());
                    }
                    if(bmore!=0){
                    tanswer=divlr(gred,gblue);
                    answer.insert(answer.end(),tanswer.begin(),tanswer.end());
                    }
                    break;
                }
            }
        }
        return answer;
}


int main(){
    int totaln=0,n=0;
    cin>>totaln;
    n=totaln/2;
    vector<vector<int> > red;
    vector<vector<int> > blue;
    vector<vector<int> > answer;
    vector<int> v(3);
    for(int i=0;i<n;i++){
        scanf("%d %d",&v[0],&v[1]);
        v[2]=i;
        red.push_back(v);
    }
    for(int i=0;i<n;i++){
        scanf("%d %d",&v[0],&v[1]);
        v[2]=i;
        blue.push_back(v);
    }
    answer=divlr(red,blue);
    for(int i=0;i<n;i++){
        printf("%d  %d \n",answer[i][0],answer[i][1]);
    }
return 0;
}
