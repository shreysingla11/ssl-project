#include <iostream>
#include <vector>
using namespace std;



class boolfunc{

	int val;
	boolfunc *left,*right;

	boolfunc(int x){
		val = x;
		left = NULL;
		right = NULL;
	}

void generateTree(std::vector<std::vector<int> >  & values, int count,boolfunc* currnode)
{
	int n = values.size();
	std::vector<std::vector<int> > leftVal, rightVal;

	if(n==0){
		currnode = new boolfunc(0);
		return;
	}

	int countR=0,countL=0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		vector<int> :: iterator it ;
		std::vector<int> v(values[i].begin() + 1, values[i].end());
		if(values[i][0] == count){
			if(v.empty()){
				countR +=1;
			}
			rightVal.push_back(v);
		}
		
		else if(values[i][0] == -1*count)
		{
			if(v.empty()){
				countL +=1;
			}
			leftVal.push_back(v);
		}
		else{

			leftVal.push_back(v);
			std::vector<int> temp(v);
			rightVal.push_back(temp);
		}
	}

	if(leftVal.size() == rightVal.size() == n)
		generateTree(values,count+1,currnode);
	
	else{
		currnode = new boolfunc;
		currnode->val = count;
		if(countL == 0)
			generateTree(leftVal,count+1,currnode->left);
		else{
			currnode->left = new boolfunc(-1);
			//currnode->left = ONE;

		}
		if(countR == 0){
			generateTree(rightVal,count+1,currnode->right);
		}
		else{
			currnode->right = new boolfunc(-1);
			//currnode->right = ONE;
		}
		
	}
}

public:


	boolfunc()
	{

	};

	~boolfunc()
	{
		delete left;
		delete right;
	}

	void read()
	{
		int n,x;
		cin >>n;
		std::vector<std::vector<int> > values;
		values.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >>x;
			values[i].resize(x);
			for (int j = 0; j < x; ++j)
			{
				/* code */
				cin >> values[i][j];
			}
		}
		generateTree(values,1,this);
	}

	void operator~()
	{
		if(val == -1)
			val = 0;
		else if(val ==0)
			val = -1;
		else{
			~(*left);
			~(*right);
		}
	}

	bool operator ==(boolfunc const & f)
	{
		if(val == f.val && (*right) == (*(f.right)) && (*left) == (*f.left))
			return true;
		else
			return false;
	}

	boolfunc operator+=(boolfunc const & f)
	{
		if(f.val == 0){
			return *this;
		}
		else if(f.val == -1)
		{
			left = NULL;
			right = NULL;
			val = -1;
			return *this;
		}

		if(val == -1)
		{}
		else if(val ==0)
		{
			boolfunc func = f;
			*this = func;
		}
		else if(f.val == val)
		{
			*left += *(f.left);
			*right += *(f.right);

		}
		else if(f.val > val)
		{
			*left += f;
			*right += f;
		}
		else{
			boolfunc newfunc = (*this);
			val = f.val;
			(*left) = newfunc;
			(*right) = newfunc;
			(*right) += *(f.right); 
			(*left) += *(f.left);
		}
		return *this;
	}

	boolfunc operator=(boolfunc & func)
	{
		delete left;
		delete right;
		val = func.val;
		left = new boolfunc(*(func.left));
		right = new boolfunc(*(func.right));
		return *this;
	}

	boolfunc(boolfunc const & f)
	{
		delete left;
		delete right;

		val = f.val;
		left = new boolfunc(*(func.left));
		right = new boolfunc(*(func.right));
		return *this;

	}

	/*bool operator*= (boolfunc const & f)
	{
		if(f->val == -1){
			return *this;
		}
		else if(f->val == -1)
		{
			delete left;
			delete right;
			left = NULL;
			right = NULL;
			value = 0;
			return *this;
		}

	}*/

	void print()
	{

	}




	// //~boolfunc(){}
	// //boolfunc( boolfunc const &){

	// };
};

int main()
{
	boolfunc A;
	A.read();

}