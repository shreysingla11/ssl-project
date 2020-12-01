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

    vector<Person> raju;
    vector<Person> game;

    raju.resize(n);

    queue<int> dg;
    queue<int> dng;

    int i, j, k, l;

    for(i=0; i<n; i++) {

        cin>>raju[i].t;
        cin>>raju[i].nf;

        for(j=0; j<raju[i].nf; j++) {

            cin>>k;

            raju[k].invfriends.push_back(i);
        }

        if (raju[i].t == 0) {
            raju[i].idg = true;
            going++;
            dg.push(i);
        }

        if (raju[i].t > raju[i].nf) {
            raju[i].idng = true;
            notgoing++;
            dng.push(i);
        }

    }

    game = raju;


    while(!dg.empty()){

        l = dg.front();
        //cout<<l;
        for(i=0; i<raju[l].invfriends.size(); i++) {

            raju[raju[l].invfriends[i]].t--;


            if (raju[raju[l].invfriends[i]].t == 0) {
                if (raju[raju[l].invfriends[i]].idg == false){
                    raju[raju[l].invfriends[i]].idg = true;
                    going++;
                    dg.push(raju[l].invfriends[i]);
                }
            }
        }

        dg.pop();

    }

    while(!dng.empty()){

        l = dng.front();
        //cout<<l;
        for(i=0; i<game[l].invfriends.size(); i++) {

            game[game[l].invfriends[i]].nf--;

            if (game[game[l].invfriends[i]].t > game[game[l].invfriends[i]].nf) {
                if (game[game[l].invfriends[i]].idng == false) {
                    game[game[l].invfriends[i]].idng = true;
                    notgoing++;
                    dng.push(game[l].invfriends[i]);
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
        for(j=0; j<raju[i].friends.size(); j++) {
            cout<<raju[i].friends[j]<<" ";
        }
        cout<<endl;
        for(j=0; j<raju[i].invfriends.size(); j++) {
            cout<<raju[i].invfriends[j]<<" ";
        }
        cout<<endl;
    }
    */

    return 0;
}
