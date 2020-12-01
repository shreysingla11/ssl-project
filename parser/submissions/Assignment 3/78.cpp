# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
	int N,M;scanf("%d",&N);scanf("%d",&M);
	if(N < M)
	{
		printf("infinity\n");
		return 0;
	}

	int INF = N + 1;
	int * A = new int[N];
	int * B = new int[M];
	int * prevCol = new int[N];
	int * currCol = new int[N];
	int * temp;

	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&A[i]);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d",&B[i]);
	}

	for (int j = M-1; j >= 0; j--)
	{
		for (int i = N-M+j; i >= j ; i--)
		{
			if(j == M-1)
			{
				if(i == N-1)
				{
					if(A[N-1] == B[M-1])
						currCol[N-1] = 1;
					else
						currCol[N-1] = INF;
				}
				else
				{
					if(A[i] == B[M-1])
						currCol[i] = 1;
					else
						currCol[i] = 1 + currCol[i+1];
				}
			}
			else
			{
				if(i == N-1)
				{
					currCol[N-1] = INF;
				}
				else
				{
					if(A[i] == B[j])
						currCol[i] = 1 + prevCol[i+1];
					else
					{
						if(i == N-M+j)
							currCol[i] = INF;
						else
							currCol[i] = 1 + currCol[i+1];
					}
				}

			}
		}

		temp = prevCol;
		prevCol = currCol;
		currCol = temp;
	}

	int min = INF, minIndex;
	for (int i = N-M ; i >= 0; i--)
	{
		if(prevCol[i] <= min)
		{
			min = prevCol[i];
			minIndex = i;
		}
	}

	if(min >= INF)
		printf("infinity\n");
	else
		printf("%d %d\n", min, minIndex + 1);

	return 0;
}
