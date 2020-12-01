


// Some more test cases are at www.cse.iitb.ac.in/~aad/cs293/Assign3.
#include <iostream>
using namespace std;

int jev=0;

void g()
{
	jev=0;
	// ;
}
//l[i,j] function

// L[n,m] = 1 if a_n == b_m and infinity otherwise.

// L[i,m] = 1 if a_i == b_m otherwise it is 1+L[i+1,m], for 1 <= i < n;

// L[n,j] = infinity for all j < m.

// L[i,j] = 1 + L[i+1,j+1] if a_i == b_j, otherwise it is 1 + L[i+1,j] for
// all 1 <= i < n, 1 <= j < m.

// The final answer is the minimum of L[i,1] for 1 <= i <= n.


int l(int i,int j,int* a,int* b,int len1,int len2,int result)
{
	// int not_found =-1;

	while(i<len1 && j<len2)
	{
	if(len1 == 1 && len2 == 1 && a[i] == b[i]) result=1;
	else if(len2 == 1 && a[i] == b[j]) result = 1;
	else if(len2 == 1 && a[i] != b[j]) 
		{result = 1+l(i+1,j,a,b,len1,len2,result); jev++;}
	else if(len1==1 && j<(len2-1)) result = 0;
	else if(a[i] == b[j]) 
	{
		jev++;
		result=1+l(i+1,j+1,a,b,len1,len2,result);
		
		// cout<<"2 jev"<<jev<<endl;
	}
	else if(a[i] != b[j] && j==0)
	{
		// result=1+l(i+1,j,a,b,len1,len2,result)	;
	}
	else if(a[i] != b[j] && i==len1-1)
	{
		// result=1+l(i+1,j,a,b,len1,len2,result)	;
		// not_found = i;
		// cout<<"reachde"<<endl;

		// cout<<result<<" "<<jev<<endl;
		result -= jev;
		// cout<<result<<" "<<jev<<endl;

		break;
	}
	else if(a[i] != b[j] && j!=0)
	{
		jev++;
		result=1+l(i+1,j,a,b,len1,len2,result);
		
		break;
	}
	break;
	}
	return result;

}

int min(int *a,int l_arr)
{
	int mini = a[0];
	for(int i=0;i<l_arr;i++)
	{
		if(a[i]<mini && a[i] !=0 )
		{
			mini=a[i];
		} 
	}
	return mini;
}


// int len_short(int* c,int* d,int l1,int l2)
// {
// 	int result = -1;
// 	if(len1 == 1 && len2 == 1 && c[0] == d[0])
// 	{
// 		result = 1;
// 	}

// }

int main()
{
	int len1,len2; //lengths
	cin>>len1>>len2;
	int a[len1],b[len2],res[len1]; //sequences
	int len_short,index_in_a,min_index; //result

	for(int i=0;i<len1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<len2;i++)
	{
		cin>>b[i];
	}

	//function for checking the seq b in seq a

	for(int i=0;i<len1;i++)
	{
		// int result=0;
		// cout<<l(i,0,a,b,len1,len2,result)<<endl;
		// jev=0;
		int result=0;
		res[i]=l(i,0,a,b,len1,len2,result);
		jev=0;
	}

	int temp= min(res,len1);
	min_index = -1;
	for(int i=0;i<len1;i++)
	{
		if(res[i] == temp) min_index = i+1;
	}

	cout<<temp<<" "<<min_index<<endl;
	if(min_index == -1)
	{
		cout<<"infinite"<<endl;
	}
	
}
