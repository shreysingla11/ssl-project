#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Person {

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

    vector<Person> facebook;
    vector<Person> facebook2;

    facebook.resize(n);

    queue<int> dg;
    queue<int> dng;

    int i, j, k, l;

    for(i=0; i<n; i++) {

        cin>>facebook[i].t;
        cin>>facebook[i].nf;

        for(j=0; j<facebook[i].nf; j++) {

            cin>>k;

            facebook[k].invfriends.push_back(i);
        }

        if (facebook[i].t == 0) {
            facebook[i].idg = true;
            going++;
            dg.push(i);
        }

        if (facebook[i].t > facebook[i].nf) {
            facebook[i].idng = true;
            notgoing++;
            dng.push(i);
        }

    }

    facebook2 = facebook;


    while(!dg.empty()){

        l = dg.front();
        //cout<<l;
        for(i=0; i<facebook[l].invfriends.size(); i++) {

            facebook[facebook[l].invfriends[i]].t--;


            if (facebook[facebook[l].invfriends[i]].t == 0) {
                if (facebook[facebook[l].invfriends[i]].idg == false){
                    facebook[facebook[l].invfriends[i]].idg = true;
                    going++;
                    dg.push(facebook[l].invfriends[i]);
                }
            }
        }

        dg.pop();

    }

    while(!dng.empty()){

        l = dng.front();
        //cout<<l;
        for(i=0; i<facebook2[l].invfriends.size(); i++) {

            facebook2[facebook2[l].invfriends[i]].nf--;

            if (facebook2[facebook2[l].invfriends[i]].t > facebook2[facebook2[l].invfriends[i]].nf) {
                if (facebook2[facebook2[l].invfriends[i]].idng == false) {
                    facebook2[facebook2[l].invfriends[i]].idng = true;
                    notgoing++;
                    dng.push(facebook2[l].invfriends[i]);
                }
            }

        }

        dng.pop();

    }

    cout<<going<<" "<<n-notgoing;

    // input debug blocks -> work fine :D

    /*
    for(i=0; i<definite.size()+1; i++){
        cout<<definite.top().index;
        definite.pop();
    }
    */

    /*
    for(i=0; i<n; i++) {
        cout<<i<<endl;
        for(j=0; j<facebook[i].friends.size(); j++) {
            cout<<facebook[i].friends[j]<<" ";
        }
        cout<<endl;
        for(j=0; j<facebook[i].invfriends.size(); j++) {
            cout<<facebook[i].invfriends[j]<<" ";
        }
        cout<<endl;
    }
    */

    return 0;
}
