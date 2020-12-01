#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;


struct inter {
	double tx,ty;
	bool operator <(const inter& a) const{
		if(ty < a.tx)
			return true;
		else 
			return false;
	}
};

int main()
{
	int n,w,u,v,t1,t2;
	cin >> n >>w>> u>> v >> t1 >> t2;
	int delta_t = (1.0*w)/v;
	std::vector<std::vector<int> > l(n,vector<int>());
	std::vector<std::vector<int> > p(n,std::vector<int>());
	int fac = 1,sz=0;
	char c;
	for (int i = 0; i < n; ++i)
	{
		cin >>c;
		if(c == 'E')
			fac = 1;
		else
			fac = -1;
		cin >>sz;

		l[i].resize(sz);
		p[i].resize(sz);


		if(fac == 1){
			for(int j=0;j<sz;j++)
			{
				scanf("%d%d",&l[i][j],&p[i][j]);
				p[i][j]*=-1;
			}
		}
		else{
			for(int j= sz-1;j>=0;j--)
			{
				scanf("%d%d",&l[i][j],&p[i][j]);
				
			}
		}
	}

	std::vector<std::vector<double> > tx(n,vector<double>());
	std::vector<std::vector<double> > ty(n,vector<double>());

	int a=0;
	for (int i = 0; i < n; ++i)
	{
		/* code */


		int sz = l[i].size();

		tx[i].resize(sz,0);
		ty[i].resize(sz,0);
		for(int j = sz-1; j >= 0 ; j-- )
		{
			tx[i][sz-j-1] = (1.0*p[i][j])/u - delta_t;
			
			//cout << "%" << tx[i][sz-j-1];

			ty[i][sz-j-1] = (1.0*l[i][j])/u  + (1.0*p[i][j])/u ;
			tx[i][sz-j-1] -= delta_t*(i);
			ty[i][sz-j-1] -= delta_t*(i);
			// if(tx[i][sz-j-1] <= 0){
			// 	tx[i][sz-j-1] = 0;
			// }

		}
	}
	inter pain;
	set<inter> intervals;
	set<inter>::iterator it,it1,it2;
	std::pair<std::set<inter>::iterator,bool> ret;
	double max=0,temp=0,start,end;

	for (int i = 0; i < n; ++i)
	{
		/* code */
		//cout << l[i].size();
		for(int j =0 ; j< l[i].size();j++)
		{
			pain.tx = tx[i][j];
			pain.ty = ty[i][j];
			if(pain.tx < t1)
				pain.tx = t1;
			if(pain.ty > t2)
				pain.ty = t2;
			if(pain.tx > pain.ty)
				continue;
			//cout << pain.tx << "," << pain.ty << " ";

			ret = intervals.insert(pain);

			if(ret.second == false){

				it1 = intervals.find(pain);
				it = it1;
				it++;
				while(it!= intervals.end())
				{
					
					it2 = it;it++;
					if(it2->tx <= pain.ty){
						if(it2->ty > pain.ty)
							pain.ty = it2->ty;
						//cout <<"@"<< it2->tx <<"," << it2->ty << " ";
						intervals.erase(it2);
					}
				}
				it = it1;
				while(true)
				{
					it2 = it;
					if(it == intervals.begin()){
						if(it2->ty >= pain.tx){
						if(it2->tx < pain.tx)
							pain.tx = it2->tx;
						//cout << "!" << it2->tx <<"," << it2->ty << " ";
						intervals.erase(it2);
					}
						break;
					}
					it--;
					if(it2->ty >= pain.tx){
						if(it2->tx < pain.tx)
							pain.tx = it2->tx;
						//cout <<"#"<< it2->tx <<"," << it2->ty << " ";
						intervals.erase(it2);
					}
					else break;
				}
				intervals.insert(pain);
			}
			

		}
			start  = t1*1.0;
			for(set<inter>::iterator it3 = intervals.begin();it3 != intervals.end();++it3 )
			{

				end = it3->tx;
				//cout << start <<","<<  end<<" ";
				temp = end -start;
				if(max < temp)
					max  = temp;
				start = it3->ty;
			}
			end  = t2;
			temp = end - start;
			if(max < temp)
				max  = temp;
			cout << max*1.0<<'\n';

			max =0;

	}

	return 0;


}