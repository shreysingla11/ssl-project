#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class per {

    public:

    bool idg;
    bool idng;

    int t;
    int nf;

    vector<int> invfriends;
};

int main() {

    int going = 0;
    int notgoing = 0;

    int n;

    cin>>n;

    vector<per> fac;
    vector<per> fac2;

    fac.resize(n);

    queue<int> dg;
    queue<int> dng;

    int i, j, k, l;

    for(i=0; i<n; i++) {

        cin>>fac[i].t;
        cin>>fac[i].nf;

        for(j=0; j<fac[i].nf; j++) {

            cin>>k;

            fac[k].invfriends.push_back(i);
        }

        if (fac[i].t == 0) {
            fac[i].idg = true;
            going++;
            dg.push(i);
        }

        if (fac[i].t > fac[i].nf) {
            fac[i].idng = true;
            notgoing++;
            dng.push(i);
        }

    }

    fac2 = fac;


    while(!dg.empty()){

        l = dg.front();

        for(i=0; i<fac[l].invfriends.size(); i++) {

            fac[fac[l].invfriends[i]].t--;


            if (fac[fac[l].invfriends[i]].t == 0) {
                if (fac[fac[l].invfriends[i]].idg == false){
                    fac[fac[l].invfriends[i]].idg = true;
                    going++;
                    dg.push(fac[l].invfriends[i]);
                }
            }
        }

        dg.pop();

    }

    while(!dng.empty()){

        l = dng.front();

        for(i=0; i<fac2[l].invfriends.size(); i++) {

            fac2[fac2[l].invfriends[i]].nf--;

            if (fac2[fac2[l].invfriends[i]].t > fac2[fac2[l].invfriends[i]].nf) {
                if (fac2[fac2[l].invfriends[i]].idng == false) {
                    fac2[fac2[l].invfriends[i]].idng = true;
                    notgoing++;
                    dng.push(fac2[l].invfriends[i]);
                }
            }

        }

        dng.pop();

    }

    cout<<going<<" "<<n-notgoing;


    return 0;
}
