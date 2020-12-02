#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
    int color;
    int id;
};

vector<int> first, second;

void find_all_pairs(vector<point>&allpts, int N){
    double slope;
    vector<point>temp, mytemp;
    int j;
    if (N<1)
        return;
    if(N==1){
        if (allpts[0].color == 1) {
            first.push_back(allpts[0].id);
            second.push_back(allpts[1].id);
        }
        else {
            first.push_back(allpts[1].id);
            second.push_back(allpts[0].id);
        }
        return;
    }

    for(int i=1; i<2*N; i++){
        temp.clear();
        mytemp.clear();
        int red, blue;
        if(allpts[i].x == allpts[0].x){
            red=0;
            blue=0;
            for(j=1; j<2*N; j++){
              if(j!=i){
               if (allpts[j].x < allpts[0].x && allpts[j].color==1) {
                    red++;
                    temp.push_back(allpts[j]);
                }
               else if (allpts[j].x < allpts[0].x && allpts[j].color==0){
                    blue++;
                    temp.push_back(allpts[j]);
                }
               else if (allpts[j].x > allpts[0].x)
                    mytemp.push_back(allpts[j]);

               else {}
                }
                mytemp.push_back(allpts[i]);
                mytemp.push_back(allpts[0]);
            }
           //cout<<"dg"<<red<<"  "<<blue<<endl;
            if(red==blue & red>0){
                //cout<<"AD"<<temp.size()<<" "<<mytemp.size()<<endl;
                find_all_pairs(temp, red);
                find_all_pairs(mytemp, N-red);
                red=0; blue=0;
                return;
            }
        }
        else {
        red=0;
        blue=0;
        temp.clear();
        mytemp.clear();
        double sign;
        slope = (allpts[0].y - allpts[i].y)/(allpts[0].x-allpts[i].x);
        double c = allpts[0].y - slope*allpts[0].x;


        for (j=1; j<2*N; j++){
            if(j==i) continue;

            if ((allpts[i].x - allpts[0].x)*(allpts[j].y - allpts[0].y) >(allpts[i].y - allpts[0].y)*(allpts[j].x - allpts[0].x)&& allpts[j].color==1){
                red++;
                temp.push_back(allpts[j]);
            }
            else if ((allpts[i].x - allpts[0].x)*(allpts[j].y - allpts[0].y) >(allpts[i].y - allpts[0].y)*(allpts[j].x - allpts[0].x)&& allpts[j].color==0){
                blue++;
                temp.push_back(allpts[j]);
            }
            else if ((allpts[i].x - allpts[0].x)*(allpts[j].y - allpts[0].y) >(allpts[i].y - allpts[0].y)*(allpts[j].x - allpts[0].x)){
                mytemp.push_back(allpts[j]);
            }
            else {}
            mytemp.push_back(allpts[i]);
            mytemp.push_back(allpts[0]);
            }
            //cout<<"dg"<<red<<"  "<<blue<<endl;
            if(red==blue && red>0){
             //  cout<<"ADC "<<temp.size()<<" "<<mytemp.size();
                find_all_pairs(temp, red);
                find_all_pairs(mytemp, N-red);       //check N
                red =0; blue=0;
                return;
            }
        }
        }

}

int main(){
    vector<point> allpts;
    int N;
    scanf("%d", &N);
    N=N/2;
    point temp;
    temp.color = 1;
    temp.id=0;         // 1 for red
    for(int i=0; i<2*N; i++){
        scanf("%d%d", &temp.x, &temp.y);
        allpts.push_back(temp);
        if(i==N) temp.color=0;
        temp.id++;
        temp.id%=N;
    }

    find_all_pairs(allpts, N);

    for(int i=0; i<first.size(); i++)
        cout<<first[i]<<" "<<second[i]<<endl;


}


