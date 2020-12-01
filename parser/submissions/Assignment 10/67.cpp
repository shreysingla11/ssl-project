class distinct
{

public:
	vector<int> l, xyz;
	vector< vector<int> > first;
	vector< vector<int> > second;
	int N;

	distinct(vector<int> sequence)
	{
		intmap x;
		int k, g;
		vector<int> mG, mL, count, a1, a2;
		a1.resize(N,0); a2.resize(N,0);
		N = sequence.size();

		// L INIT
		for (int i = 0; i < N; ++i)
		{
			if(x.count(sequence[i]) == 0)
				l.push_back(-1);
			else
				l.push_back(x[sequence[i]]);

			x[sequence[i]] = i;
		}

		g = -1;
		for (int i = 0; i < N; ++i)
		{
			if(l[i] == -1)
				xyz.push_back(g);
			else
			{
				g = i;
				xyz.push_back(g);
			}
		}

		for (int i = 0; i < log2(N); ++i)
		{
			mG.clear();
			mL.clear();
			count.clear();
			mG.resize(pow(2, i), -1);
			mL.resize(pow(2, i), -1);
			count.resize(pow(2, i), 0);

			for (int j = 0; j < N; ++j)
			{
				k = (l[j] * pow(2, i))/(N);

				if(l[j] >= ((k*N)/pow(2, i) + N/pow(2, i+1)))
				{
					count[k]++;
					a2[j] = mL[k];
					mG[k] = j;
				}
				else
				{
					a2[j] = mG[k];
					mL[k] = j;
				}
				a1[j] = count[k];
			}

			first.push_back(a1);
			second.push_back(a2);
		}

		int count = 0;
		for (int j = 0; j < N; ++j)
		{
			if(l[j] >= j)
				a1[j] = 1;
			else
				a1[j] = 0;
		}

		first.push_back(a1);
		a2.clear();
		a2.resize(N, -1);
		second.push_back(a2);

		for (int i = 0; i < log2(N) + 1; ++i)
		{
			cout<<"first: "<<endl;
			for (int j = 0; j < N; ++j)
			{
				cout<<first[i][j]<<" ";
			}
			cout<<endl<<"second: "<<endl;
			for (int j = 0; j < N; ++j)
			{
				cout<<second[i][j]<<" ";
			}
			cout<<endl;

		}
		cout<<endl;
	}

	int num_distinct(int io, int jo)
	{
		int result = 0, max = jo - io +1;
		int mid = N/2;

		if(l[jo] == -1)
			jo == xyz[jo];

		for (int i = 0; i < log2(N) + 1; ++i)
		{
			if(jo == -1)
				break;

			if(io == mid)
			{
				result += first[i][jo];
				break;
			}

			if(io > mid)
			{
				if(l[jo] < mid)
					jo = second[i][jo];
				mid = mid + N/pow(2, i+2);
			}
			else
			{
				result += first[i][jo];

				if(l[jo] >= mid)
				{
					jo = second[i][jo];
				}
				mid = mid - N/pow(2, i+2);
			}
		}

		return max - result;
	}
};