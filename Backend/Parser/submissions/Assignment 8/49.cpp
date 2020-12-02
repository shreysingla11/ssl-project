#include <iostream>
//#include <vector>
#include <map>

using namespace std;

void answer(map<float,int>A, int t1, int t2){
    float valid=0.0, maxi=0.0,pr=t1-1,lt=t2+1;
    int val = 0;
    for (map<float,int>::iterator it=A.begin(); it!=A.end(); ++it){
        val += it->second;
        if(val >= 1){
            if(it->first <= t2 && pr >= t1){valid = it->first - pr;}
            if(it->first <= t2 && pr < t1){valid = it->first - t1;}
            if(it->first > t2 && pr >= t1){valid = t2 - pr;}
            if(it->first > t2 && pr < t1){valid = t2 - t1;}
        }
        if(valid >= maxi){maxi = valid;}
        pr = it->first;
    }
    //cout<<val<<endl;
    if(pr >= t1){valid = t2 - pr;}
    if(pr < t1){valid = t2 - t1;}
    if(valid >= maxi){maxi = valid;}
    cout << maxi << endl;
    //cout << it->first << " => " << it->second << '\n';
};

int main ()
{
    int n, w, u, v, t1, t2, m, l, p;
    int ct = 0,ctp = 0;
    //vector < vector <float> > tmin, tmax;
    map<float,int> all,tall;
    //vector <float> tmn,tmx;
    float t,tl,tf,tn,tmp;
    char c;
    cin >> n >> w >> u >> v >> t1 >> t2;
    tf = w * 1.0 / v;
    for (int i = 0 ; i < n ; i++){
        tn = i * 1.0 * tf;
        cin >> c >> m;
        for (int j = 0 ; j < m ; j++){
            cin >> l >> p;
            tl = l * 1.0 / u;
            if (c == 'E'){t = p * -1.0 / u;}
            if (c == 'W'){t = p * 1.0 / u;}
            //forbidden interval  :  t-tf-tn -> t+tl-tn
            //cout << (t-tf-tn) <<" "<<(t+tl-tn)<<endl;
            //tmn.push_back(t - tf - tn);tmx.push_back(t + tl - tn);
            tmp = t - tf - tn;
            if(all.count(tmp)>0){all [tmp]++;}
            else{all [tmp]=1;}
            tmp = t + tl - tn;
            if(all.count(tmp)>0){all [tmp]--;}
            else{all [tmp]=-1;}
            //tmin.push
        }
        //uniformize all so that only nonintersecting invalid time intervals is stored
      /* ct = 0; ctp = 0;
        for (map<float,int>::iterator itsp=all.begin(); itsp!=all.end(); ++itsp)//{
            /*ct += itsp->second ; *///cout << itsp->first << " => " << itsp->second << " => " << ct << '\n';
            /*if(ct == 0){all [itsp->first]=-1;}//cout<<it->first<<","<<ct<<","<<ctp<<" ";}
            else{
                if(ct > 0 && ctp==0){all [itsp->first]=1;}//cout<<it->first<<","<<ct<<","<<ctp<<" ";}
                else{all.erase(itsp);}
            }
            ctp=ct;
        }*/
        tall = all;
        ct = 0; ctp = 0;
        for (map<float,int>::iterator it=all.begin(); it!=all.end(); ++it){
            ct += it->second;//cout<<ct<<" ";
            if(ct == 0){tall[it->first] = -1;}//cout<<it->first<<","<<ct<<","<<ctp<<" ";}
            else{
                if(ct > 0 && ctp==0){tall[it->first] = 1;}//cout<<it->first<<","<<ct<<","<<ctp<<" ";}
                else{tall.erase(it->first);}
            }
            ctp = ct;
        }
/*
cout<<endl;
        for (map<float,int>::iterator itsp=all.begin(); itsp!=all.end(); ++itsp)
            cout << itsp->first << " => " << itsp->second << '\n';
*/
        answer(tall,t1,t2);

    }
    return 0;
}
