class boolfunc {

public:

	int n,nov,x;

 boolfunc();

~boolfunc();

boolfunc(boolfunc const &);

void operator+=(boolfunc const &)
{

}

void operator*=(boolfunc const &)
{

}

void operator~()
{

}

bool operator==(boolfunc const &)
{

}

void read()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>nov;
		for(int j=0;j<nov; j++)
		{
			cin>>x;
		}
	}
}

void print()
{

}

private:
	class node
{
    int data;
    struct node *left;
    struct node *right;
};





};