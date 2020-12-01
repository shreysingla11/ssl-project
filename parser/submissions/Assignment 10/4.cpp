#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;


class distinct
{
	public : vector<int> sequence;
	public : vector<int> l;

	public : vector<vector<int> > count;
	vector<vector<int> > second;
	int numLevel;
	public : distinct(vector<int> seq)
	{
		sequence = seq;
		map<int, int> indexMap;
		int n = sequence.size();
		//cout<<n<<"HO"<<endl;
		for(int i=0; i<n; i++)
		{
			if (indexMap.find(sequence[i]) == indexMap.end())
			{
				l.push_back(-1);
			//	cout<<i<<"YO"<<endl;
			}

			else
			{
				l.push_back(indexMap[ sequence[i] ] );
			//	cout<<i<<"Heya"<<endl;
			}

			indexMap[ sequence[i] ] = i;
		}

		numLevel = (int) log2 (n);
		int k, fact;
		vector<int> temp_count;
		vector<int> a;
		vector<int> b;
		a.resize(n);
		b.resize(n);
		vector<int> max_lesser;
		vector<int> max_greater;
		fact = 1;
		for(int i=0; i<numLevel; i++)
		{
			temp_count.clear();
			max_lesser.clear();
			max_greater.clear();
			temp_count.resize(pow(2,i),0);
			max_greater.resize(pow(2,i),-1);
			max_lesser.resize(pow(2,i),-1);
			//count = 0 ;

			for(int j=0; j<n; j++)
			{
			

				k = l[j]*fact/n ;

				if ( l[j]>= k*n/fact + n/(2*fact) )
				{
					temp_count[k]++;
					b[j] = max_lesser[k];
					max_greater[k] = j;
				}
				else
				{	//count[i].push_back(count[i][x-1]);
					b[j] = max_greater[k];
					max_lesser[k] = j;
				}
				a[j] = temp_count[k];

			}
			fact = fact*2;
			count.push_back(a);
			second.push_back(b);
		}

	}

	int num_distinct(int a, int b)
	{
		int init = b-a+1;
		int k;
		int here = l.size()/2;

		if(b==a)
			return 1;

		for (int i=0; i<(int)ceil(log2(l.size())); i++)
		{
			if(a==here)
			{
				k+=count[i][b];
				break;
			}

			else if (a>here)
			{
				if(l[b] < here)
					b = second[i][b];
				if (l[b] == -1)
					break;

				here += (l.size())/pow(2,i+2);
			}

			else
			{
				k += count[i][b];

				if(l[b] >= here)
					b = second[i][b];
				if (l[b] == -1)
					break;

				here -= (l.size())/pow(2,i+2);
			}

		}

		k = init - k;

		return k;
	}
};