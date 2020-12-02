#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> def_go;
    vector<int> def_not;
    vector<int>::iterator it1;
    vector<int>::iterator it2;


	int n,l;
	cin>>n;
	int nfdg[n];
    int nfdn[n];
	int T[n];
	int no_frnds[n];
	vector<vector<int> > vs;
	vector<vector<int> > vp(n);
	for(int p=0;p<n;p++)
	{
        nfdg[p]=0;
        nfdn[p]=0;
		cin>>T[p];
		//cout<<T[p];
		if(T[p]==0)
		{
            def_go.push_back(p);
		}
		cin>>no_frnds[p];
		if(T[p]>no_frnds[p])
		{
            def_not.push_back(p);
		}
		vector<int> frnds;
		for(int i=0;i<no_frnds[p];i++)
		{
            cin>>l;
			frnds.push_back(l);
			vp[l].push_back(p);
		}
		vs.push_back(frnds);

	}

    int defgo = def_go.size();
    int defnot = def_not.size();
 //   cout<<defgo;

    while (!def_go.empty()){
//	for(int p=0;p<def_go.size();p++)
//	{
        for(it1=vp[def_go[0]].begin();it1<vp[def_go[0]].end();it1++)
        {
          //  cout<<(*it1);
            nfdg[(*it1)]++;
            if(nfdg[(*it1)]>=T[(*it1)])
            {
                def_go.push_back((*it1));
                defgo++;
             //  cout<<def_not.size();
            }
        }
       def_go.erase(def_go.begin());
      //  cout<<def_not.size();

//	}
  //  cout<<"in";
//	}

//cout<<"out";

    while (!def_not.empty()){
//	for(int p=0;p<def_not.size();p++)
//	{
        for(it1=vp[def_not[0]].begin();it1<vp[def_not[0]].end();it1++)
        {
            nfdn[(*it1)]++;
             if(no_frnds[(*it1)]-nfdn[(*it1)]<T[(*it1)])
            {
                def_not.push_back((*it1));
                defnot++;
            }
        }
        def_not.erase(def_not.begin());
 //   }
    }

   cout<<defgo<<" "<<n-defnot;


	//cout<<v[0][0]<<v[1][0]<<v[1][1];







	return 0;
}
