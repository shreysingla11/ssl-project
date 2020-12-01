#include <iostream>
#include <algorithm>   
#include <vector>   
using namespace std;


class distinct
 {

 	int r=0;
 public:
 	lab10(vector<int> v)
 	{

 	};

 	int num_distinct(int i,int j)
 	{
 		sort (v.begin(), v.end(); 
 		for (int k=i; k<j; k++)
    {
    	r++;
       // Move the index ahead while there are duplicates
       while (k < j-1 && arr[k] == arr[k+1]){
          k++;
       }
 
       // print last occurrence of the current element
       //cout << arr[k] << " ";
       return r;
    }
 	}
 	
 };


 