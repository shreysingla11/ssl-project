# include <iostream>
# include <algorithm>
# include <string>
using namespace std;
int minLen, minPos, N, L;
string X;

int findBlockMatch(int blockN);
bool isW(int blockN, int matchStartFrom);

int main()
{	
	cin>>X;
	int matchStartFrom;
	bool found;
	N = X.length();

	int minLenx = N + 1, minPosx = N + 1;
	
	for (L = 1; (4*L-2) <= N; L = L*2)
	{
		// now search for sqaures.len in the range >= 2L -1 && <=4L-2
		// iterate over blocks
		for (int blockN = 0; blockN < (N/L)-1; blockN++)	// iterating over blocks 
		{
			matchStartFrom = findBlockMatch(blockN);
			if(matchStartFrom == -1)
				continue;
			else
			{
				if(isW(blockN, matchStartFrom))		// if it forms the W
				{	
					if(minLen < minLenx)	// store it
					{	
						minLenx = minLen;
						minPosx = minPos;
					}
					found = true;
				}
			}
			if(found)
				break;	
		}
	}
	if(found)
		cout<<minLenx<<" "<<minPosx<<endl;
	else
		cout<<"0 0"<<endl;
	return 0;
}
int findBlockMatch(int blockN)
{
	// returns start pos of matching region, else -1
	// start iterating from next block till 4L-2 away from curr block pos
	int matchCount = 0;
	for (int currIndex = blockN*L+ 2*L -1; currIndex <= (blockN*L + 4*L-2); ++currIndex)
	{
		if(X[(blockN*L) + matchCount] == X[currIndex])
			matchCount++;
		else
			matchCount = 0;

		if(matchCount == L)
			return (currIndex - L + 1);
	}
	return -1;
}
bool isW(int blockN, int matchStartFrom)
{
	int x = 0, y = 0;
	// x is the number of chars matched in back of block
	// y is the number of chars matched in front of block 
	int sumNeeded = matchStartFrom - (blockN*L + L -1) - 1; 
	while(x != sumNeeded)
	{
		if(blockN*L - 1 -x >= 0)	// string exists behind!
		{
			if(X[blockN*L -1 -x] == X[matchStartFrom -1 -x])
				x++;
			else
				break;
		}
		else
			break;
	}

	while(x + y != sumNeeded)
	{
		if(matchStartFrom + L + y < N)	// string exists ahead!
		{
			if(X[blockN*L + L + y] == X[matchStartFrom + L + y])
				y++;
			else
				break;
		}
		else
			break;
	}

	if(x + y == sumNeeded)
	{
		minPos = blockN*L - x;
		minLen = L + sumNeeded;
		return true;
	}
	return false;
}