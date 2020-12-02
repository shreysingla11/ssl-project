#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin>>input;
	int minlength = 10000000;
	int index = 0;
	int strLen = input.length();
	int tempL, tempI1, tempI2, w1right, w2left, length;
	for (int l = 1; l <= (strLen + 2)/4 ; l*=2)
	{
		tempL=l;

		for (int i = 0; i <= (strLen - 2l) ; ++i)
		{
			tempI1 = i;
			tempI2 = i;
				
			if (input[i] == input[i+tempL])
			{
				w1right = tempI1;
				w2left = tempI1 + tempL;

				while (tempI1+tempL != i && tempI1 >= 0)
				{
					if (input[tempI1 + tempL] == input[tempI1])
					{
						w2left = tempI1 + tempL;
						tempI1--;
					}
					else 
						break;
				}

				if (tempI1+tempL != i) 
				{
					while (tempI2 != i+tempL && tempI2 + tempL < strLen)
					{
						if (input[tempI2 + tempL] == input[tempI2])
						{
							w1right = tempI2;
							tempI2++;
						}

						else 
							break;
					}
				}

				if (w2left - w1right == 1)
				{
					length= (w1right-i) + (i+tempL-w2left) + 1;
					if (length < minlength)
					{
						minlength=length;
						index= i- (i+tempL-w2left);
					}
				}
			}

			else
			{
				if ( tempL < (i + 4*l -1) && tempL < strLen )
				{
					tempL++;
					i--;
				}
				else
				{
					tempL = l;
					i--;
					i = i+l; 
				}

			}
		}
	}
	if (minlength==10000000)
		cout<<0<<" "<<0<<endl;
	else
		cout<<minlength<<" "<<index<<endl;
	return 0;
}