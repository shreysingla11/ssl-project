#include <iostream>
#include <string>
using namespace std;
bool findsubstr(string &s, int l, int block, int preindex, int &sqlength, int &sqindex)
{
	int i, j, blback, preback;
	// cout<<"block = "<<block<<" preindex = "<<preindex<<endl;
	i = block-1;
	j = preindex-1;
	sqlength = l;
	while (i >= 0 && j >= block+l)
	{
		// cout << "Hey1" << endl;
		while (s[i] == s[j])
		{
			--i;
			--j;
			++sqlength;
			if (i == -1 || j == block+l-1)
				break;
		}
		break;
	}
	blback = i+1;
	preback = j+1;
	if (block == 0)
		blback = block;
	if (preindex == block+l)
		preback = block+l;
	if (preback == block+l)
	{
		sqindex = blback;
		return true;
	}
	i = block+l;
	j = preindex+l;
	while (i <= preback-1 && j < s.length())
	{
		// cout << "Hey2" << endl;
		while (s[i] == s[j])
		{
			++i;
			++j;
			++sqlength;
			if (i > preback-1 || j == s.length())
			{
				break;
			}
		}
		break;
	}
	if (i == preback)
	{
		sqindex = blback;
		return true;
	}
	return false;
}
int main()
{
	string s;
	int l, i, block, mismatch, preindex, sqlength, sqindex, minlength, minindex;
	bool blockmatch = false, substrmatch = false;
	cin >> s;
	l = 1;
	minlength = s.length() + 1;
	while (l < s.length())
	{
		block = 0;
		// cout<<"l = "<<l<<endl;
		while(block < s.length())
		{	
			i = 0;
			mismatch = block+l+i;
			while (i < l && mismatch <= block+(4*l-2) && mismatch<s.length())
			{
				preindex = mismatch;
				while (s[block+i] == s[mismatch] && i<l && mismatch <= block+(4*l-2) && mismatch<s.length())
				{
					++i;
					++mismatch; 
				}
				if (i == l)
				{
					// cout<<"preindex = "<<preindex<<"\nblock = "<<block<<endl;
					blockmatch = true;
					if (findsubstr(s, l, block, preindex, sqlength, sqindex))
					{
						substrmatch = true;
						if (sqlength < minlength)
						{
							minlength = sqlength;
							minindex = sqindex;
						}
					}
					i = 0;
				}
				else
				{
					if (i == 0)
						++mismatch;
					else
						i = 0;
				}
			}
			block += l;
		}
		l *= 2;
	}
	if (substrmatch)
		cout << minlength << " " << minindex << endl;
	else
		cout << "0 0 " << endl;
	return 0;
}