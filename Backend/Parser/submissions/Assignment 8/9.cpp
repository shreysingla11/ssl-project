#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct times{
    double tf;
    bool type;
};

bool compare (times a, times b){
    if (a.tf < b.tf) return true;
    if (a.tf > b.tf) return false;
    else {
        if (a.type > b.type) return true;
        else return false;
    }
}

int main(){
    int n, w, u, v, t1, t2;
    scanf("%d", &n);
    scanf("%d", &w);
    scanf("%d", &u);
    scanf("%d", &v);
    scanf("%d", &t1);
    scanf("%d", &t2);

    char dir;
    int m;
    int l, p, b;
    times temp;
    double t, ta;
    vector<times> aa;
    aa.clear();
    for (int i=0;i<n; i++){
        cin>>dir;
        cin>>m;
        double dur = (double)(i+1)*w/v;
        if (dir == 'E'){
            for (int j=0; j<m; j++){
                cin>>l>>p;
                t = ((double)(-1*p) - (double)dur*u)/u;
                ta = t + (double)l/u + (double)w/v;
                if (ta >= 0){
                    temp.tf = t;
                    if (temp.tf <=t1) temp.tf = t1;
                    temp.type = true;
                    aa.push_back(temp);
                    temp.tf = ta;
                    if (temp.tf >=t2) temp.tf = t2;
                    temp.type = false;
                    aa.push_back(temp);
                }

            }
        }
        else {
            for (int j=0; j<m; j++){
                cin>>l>>p;
                t = ((double)p - (double)dur*u)/u;
                ta = t + (double)l/u +(double)w/v;
                if (ta >= 0){
                    temp.tf = t;
                    if (temp.tf <=t1) temp.tf = t1;
                    temp.type = true;
                    aa.push_back(temp);
                    temp.tf = ta;
                    if (temp.tf >=t2) temp.tf = t2;
                    temp.type = false;
                    aa.push_back(temp);
                }
                //    aa.push_back(temp);
            }
        }
    }
    //cout<<"Sd";
    sort(aa.begin(), aa.end(), compare);

    int count=0;
    double maxi = -INFINITY;
    //for (int i=0; i<aa.size(); i++){
      //  cout<<aa[i].tf<<" "<<aa[i].type<<endl;
    //}
    double prev=0, curr =0;

    if (aa[0].tf >=t1){
        if (aa[0].tf >=t2){
            maxi = t2 - t1;
        }
        else
            maxi = aa[0].tf - t1;
    }
    //cout<<"E"<<endl;
    for (int i=0; i<aa.size(); i++){
        if (aa[i].type == true) count++;
        else count--;

        if (count == 0){
            prev = aa[i].tf;
            if (i != aa.size() -1)
                curr = aa[i+1].tf;
            else
                curr = t2;

            if (prev >=t1 && curr<=t2)
                maxi = max(maxi, curr-prev) ;
   //         else if (prev < t1 && curr <= t2)
     //           maxi = max(maxi, curr-t1);
       //     else if (prev< t1 && curr >t2)
         //       maxi = max(maxi, t2-t1);
           // else
            //    maxi = max(maxi, t2-prev);
        }

    }
    printf("%.8lf\n",maxi);
}
