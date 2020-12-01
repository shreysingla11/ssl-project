#include <iostream>
#include <vector>
using namespace std;

// struct node
// {
// 	int value;
// 	node* left, right;
// };

class boolfunc
{
	int value;
	boolfunc *left, *right;
public:
	boolfunc()
	{
		left = NULL;
		right = NULL;
	}

	boolfunc(int boolvalue)
	{
		value = boolvalue;
		left = NULL;
		right = NULL;
	}

	boolfunc(boolfunc const & f)
	{
		value = f.value;
		delete left;
		delete right;
		left = new boolfunc(*(f.left));
		right = new boolfunc(*(f.right));
	}
	boolfunc& operator=(boolfunc &f)
	{
		value=f.value;
		//destruct left & right
		delete left;
		delete right;
		//if(value == -1 || value == 0)
		left = new boolfunc(*(f.left));
		right = new boolfunc(*(f.right));
	}

	 ~boolfunc()
	 {
	 	delete left;
	 	delete right;
	 }
	void read()
	{
		int n;
		cin>>n;
		vector<int> size;
		vector< vector<int> > input;
		size.resize(n);
		input.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>size[i];
			for(int j=0;j<size[i];j++)
			{
				input[i].resize(size[i]);
				cin>>input[i][j];
			}
		}
		generatetree(input,size,n,1);
	}

	void generatetree(vector< vector<int> > &input, vector<int> &size, int n, int var)
	{
		int leftn, rightn;
		vector<int> leftsizes, rightsizes;
		vector<int>::iterator it;
		vector< vector<int> > leftinput, rightinput;

		bool leftstatus =false, rightstatus = false;
		value = var;
		for(int i=0;i<n;i++)
		{
			
			if(input[i][0]==var)
			{
				if(!rightstatus)
				{
					it = input[i].begin();
					it++;
					if(it==input[i].end())
					{
						right = new boolfunc(-1);
						rightstatus = true;
					}
					vector<int> temp(it, input[i].end());
					rightinput.push_back(temp);
					rightsizes.push_back(size[i]-1);
					rightn++;
				}
			}
			else if(input[i][0]==-var)
			{
				if(!leftstatus)
				{
					it = input[i].begin();
					it++;
					if(it==input[i].end())
					{
						left = new boolfunc(-1);
					}
					vector<int> temp(it, input[i].end());
					leftinput.push_back(temp);					
					leftsizes.push_back(size[i]-1);
					leftn++;
				}
			}
			else
			{
				if(!leftstatus)
				{
					leftinput.push_back(input[i]);
					leftsizes.push_back(size[i]-1);
					leftn++;
				}
				if(!rightstatus)
				{
					rightinput.push_back(input[i]);
					rightsizes.push_back(size[i]-1);
					rightn++;
				}
			}
		}
		if(leftstatus)
		{
			left = new boolfunc(-1);
		}
		else if(leftn==0)
		{
			left = new boolfunc(0);
		}
		else
		{
			left = new boolfunc();
			left->generatetree(leftinput,leftsizes,leftn,value+1);
		}
		if(rightstatus)
		{
			right = new boolfunc(-1);
		}
		else if(rightn==0)
		{
			right = new boolfunc(0);
		}
		else
		{
			right = new boolfunc();
			right->generatetree(rightinput,rightsizes,rightn,value+1);
		}
	}

	void print()
	{
		//assuming first node is not 0 or -1
		//vector<int> leftprint(1,-value),rightprint(1,value);
		// left->print(leftprint,1);
		// right->print(rightprint,1);
		vector<vector<int> > leftseq, rightseq;
		int leftsize=0, rightsize=0, cursize, size;
		bool leftstatus = false, rightstatus= false;

		if(left->value==-1)
		{
			leftstatus=true;
		}
		else if(left->value!=0)
		{
			left->getprintseq(leftseq,leftsize);
		}
		
		if(right->value==-1)
		{
			rightstatus=true;
		}
		else if(right->value!=0)
		{
			right->getprintseq(rightseq,rightsize);
		}

		size = leftsize + rightsize;
		if(leftstatus)
			size++;
		if(rightstatus)
			size++;

		cout<<size<<endl;

		if(leftstatus)
		{
			cout<<1<<endl<<-value<<endl;
		}
		else
		{
			for(int i=0;i<leftsize;i++)
			{
				cursize = leftseq[i].size()+1;
				cout<<cursize<<endl;
				cout<<"-1 ";
				for(int j=0; j<cursize; j++)
				{
					cout<<leftseq[i][j]<<" ";
				}
			}
			cout<<endl;
		}
		if(rightstatus)
		{
			cout<<"1"<<endl<<value<<endl;
		}
		else
		{
			for(int i=0;i<rightsize;i++)
			{
				cursize = rightseq[i].size()+1;
				cout<<cursize<<endl;
				cout<<"1 ";
				for(int j=0; j<cursize; j++)
				{
					cout<<rightseq[i][j]<<" ";
				}
			}
			cout<<endl;
		}
	}

	void getprintseq(vector<vector<int> > &printseq, int &size)
	{
		vector<vector<int> > leftseq, rightseq;
		int leftsize=0, rightsize=0, cursize;
		if(left->value==-1)
		{
			vector<int>temp(1,-value);
			printseq.push_back(temp);
			leftsize=1;
		}
		else if(left->value == 0)
		{
			leftsize = 0;
		}
		else
		{
			left->getprintseq(leftseq,leftsize);
			for(int i=0;i<leftsize;i++)
			{
				vector<int>temp(1,-value);
				temp.insert(temp.end(),leftseq[i].begin(),leftseq[i].end());
				printseq.push_back(temp);
			}
		}

		if(right->value==-1)
		{
			vector<int>temp(1,value);
			printseq.push_back(temp);
			rightsize=1;
		}
		else if(right->value == 0)
		{
			rightsize = 0;
		}
		else
		{
			right->getprintseq(rightseq,rightsize);
			for(int i=0;i<rightsize;i++)
			{
				vector<int>temp(1,value);
				temp.insert(temp.end(),rightseq[i].begin(),rightseq[i].end());
				printseq.push_back(temp);
			}
		}
		size = leftsize + rightsize;
		//printseq.resize(leftsize+rightsize);
	}
	void operator~()
	{
		if(value == -1)
			value=0;
		else if(value == 0)
			value=-1;
		else
		{
			~(*left);
			~(*right);
		}
	}

	bool operator==(boolfunc const & f)
	{
		if( value == f.value && (*left) == (*(f.left)) && (*right) == (*(f.right)) )
			return true;
		else
			return false;
	}

	void operator+=(boolfunc const & f)
	{
		if(f.value==0)
		{
			return;
		}
		else if(f.value==-1)
		{
			value=-1;
			delete left;
			delete right;
			//left = NULL;
			//right = NULL;
			return;
		}

		if(value == 0)
		{
			boolfunc myfunc = f;
			(*this) = myfunc;
		}
		else if(value==-1)
		{
			return;
		}

		if(value == f.value)
		{
			(*left)+= (*(f.left));
			(*right)+= (*(f.right));
			if((*left) == (*right))
			{
				(*this) = *left;
			}
			delete left;
			delete right;
		}
		else if(value<f.value)
		{
			(*left)+= f;
			(*right)+= f;
			if((*left) == (*right))
			{
				(*this) = *left;
			}
			delete left;
			delete right;
		}
		else
		{
			boolfunc myfunc = (*this);
			value = f.value;
			(*left) = myfunc;
			(*right) = myfunc;
			(*left)+= (*(f.left));
			(*right)+= (*(f.right));
			if((*left) == (*right))
			{
				(*this) = *left;
			}
			delete left;
			delete right;

		}
	}

	void operator*=(boolfunc const & f)
	{
		if(f.value==0)
		{
			value = 0;
			delete left;
			delete right;
		}
		else if(f.value==-1)
		{
			return;
		}
		if(value == 0)
		{
			return;
		}
		else if(value==-1)
		{
			boolfunc myfunc = f;
			(*this) = myfunc;
		}

		if(value == f.value)
		{
			(*left)+= (*(f.left));
			(*right)+= (*(f.right));
			if((*left) == (*right))
			{
				(*this) = *left;
			}
			delete left;
			delete right;
		}
		else if(value<f.value)
		{
			(*left)*= f;
			(*right)*= f;
			if((*left) == (*right))
			{
				(*this) = *left;
			}
			delete left;
			delete right;
		}
		else
		{
			boolfunc myfunc = (*this);
			value = f.value;
			(*left) = myfunc;
			(*right) = myfunc;
			(*left)+= (*(f.left));
			(*right)+= (*(f.right));
			if((*left) == (*right))
			{
				(*this) = *left;
			}
			delete left;
			delete right;
		}
	}
};
