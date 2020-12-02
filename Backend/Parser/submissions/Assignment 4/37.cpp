#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using namespace std;

class counter
{
private:
	int n;
	vector<int> counts;
	list<list<int> > lists;
	vector<list<list<int> >::iterator > it_list;
	vector<list<int>::iterator > it_object;

public:

counter(int x)	{
	n=x;
	counts.resize(n,0);
	list<int> temp;
	
	for(int p1=0;p1<n;p1++)
	{
		temp.push_back(p1);
	}
	
	lists.push_back(temp);
	
	for(int p2=0;p2<n;p2++)
	{
		it_list.push_back(lists.begin());
	}
	list<int>::iterator temp_it = (*(lists.begin())).begin();
	for(int p=0;p<n;p++)
	{
		it_object.push_back(temp_it);
		temp_it++;
	}
}

void increment(int i){
	
	counts[i]++;
	list<list<int> >::iterator ending = lists.end();
	ending--;
	
	if(it_list[i] != ending)
	{
		it_list[i]++;
		if(counts[i] == counts[*((*it_list[i]).begin())])
		{
			(*it_list[i]).push_back(i);
			it_list[i]--;
			(*it_list[i]).erase(it_object[i]);  
			it_list[i]++;
			list<int>::iterator temporary1 = (*it_list[i]).end();
			temporary1--;
			it_object[i] = temporary1;
			
			list<list<int> >::iterator del_list1 = it_list[i]--;
			it_list[i]++;
			if((*del_list1).empty())
			{
				lists.erase(del_list1);
			}
			


		}
		else 
		{
			list<int> added_list;
			added_list.push_back(i);
			lists.insert(it_list[i],added_list);
			it_list[i]--;
			it_list[i]--;
			(*it_list[i]).erase(it_object[i]); 
			it_list[i]++;
			it_object[i] = (*it_list[i]).begin();
			
			list<list<int> >::iterator del_list2 = it_list[i]--;
			it_list[i]++;
			if((*del_list2).empty())
			{
				lists.erase(del_list2);
			}
			

		}
	}
	else
	{
		list<int> end_list;
		end_list.push_back(i);
		lists.push_back(end_list);
		(*it_list[i]).erase(it_object[i]); 
		it_list[i]++;
		it_object[i] = (*it_list[i]).begin();
		
		list<list<int> >::iterator del_list3 = it_list[i]--;
			it_list[i]++;
			if((*del_list3).empty())
			{
				lists.erase(del_list3);
			} 

		
	}
}


void decrement(int i){
	counts[i]--;
	list<list<int> >::iterator starting = lists.begin();

	if(it_list[i] != starting)
	{	
		it_list[i]--;
		if(counts[i] == counts[*((*it_list[i]).begin())])
		{
			(*it_list[i]).push_back(i);
			it_list[i]++;
			(*it_list[i]).erase(it_object[i]);  
			it_list[i]--;
			list<int>::iterator temporary2 = (*it_list[i]).end();
			temporary2--;
			it_object[i] = temporary2;

			list<list<int> >::iterator del_list11 = it_list[i]++;
			it_list[i]--;
			if((*del_list11).empty())
			{
				lists.erase(del_list11);
			}
			
		}

		else
		{
			list<int> added_list1;
			added_list1.push_back(i);
			it_list[i]++;
			lists.insert(it_list[i],added_list1);
			(*it_list[i]).erase(it_object[i]); 
			it_list[i]--;
			it_object[i] = (*it_list[i]).begin();

			list<list<int> >::iterator del_list21 = it_list[i]++;
			it_list[i]--;
			if((*del_list21).empty())
			{
				lists.erase(del_list21);
			}

		}

	}

	else
	{
		list<int> start_list;
		start_list.push_back(i);
		lists.push_front(start_list);
		(*it_list[i]).erase(it_object[i]); 
		it_list[i]--;
		it_object[i] = (*it_list[i]).begin();
		list<list<int> >::iterator del_list31 = it_list[i]++;
			it_list[i]--;
			if((*del_list31).empty())
			{
				lists.erase(del_list31);
			} 

	}
	

}

void reset(int i){
	counts[i]=0;

	if(counts[*((*it_list[i]).begin())]==0)
	{	
	(*lists.begin()).push_back(i);
	(*it_list[i]).erase(it_object[i]); 
	list<int>::iterator start = (*lists.begin()).end();
	start--;
	it_object[i]=start;
	list<list<int> >::iterator del_list32 = it_list[i];
			if((*del_list32).empty())
			{
				lists.erase(del_list32);
			} 
	it_list[i]=lists.begin();		


	}

	else
	{
		list<int> added_list0;
		added_list0.push_back(i);
		lists.push_front(added_list0);
		(*it_list[i]).erase(it_object[i]); 
		list<list<int> >::iterator del_list33 = it_list[i];
			if((*del_list33).empty())
			{
				lists.erase(del_list33);
			} 
		it_list[i]=lists.begin();		
		list<int>::iterator start1 = (*lists.begin()).end();
		start1--;



	}



	}

int count(int i){
	return counts[i];
}

int findMax()
{
	list<list<int> >::iterator last=lists.end();
	last--;
	int a=counts[(*((*last).begin()))];
	return a;
}

int numMax()
{	
	list<list<int> >::iterator lastt=lists.end();
	lastt--;
	return (*lastt).size();
}

void printMax()
{
	list<list<int> >::iterator last1=lists.end();
	last1--;
	list<int>::iterator sup;
	for(sup=(*last1).begin();sup!=(*last1).end();sup++)
	{
		cout<<*sup<<endl;
	}
}


};

