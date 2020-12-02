#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;


class m_node{//main list
public:
    int num_elements;
	int count;
	list< int > sub_nodes;//sublist - contains mainlist iterators
public:
	m_node(){
		count = 0;
		num_elements = 0;
	}
	void print_all(){
		list< int > :: iterator i1 = sub_nodes.begin();
		// cout<<num_elements<<" , "<<sub_nodes.size()<<" num_elements , size ::\t";
		for(;i1!=sub_nodes.end();i1++){
			cout<<*i1<<endl;
		}
	}
};

class counter{
private:

	list< m_node > main_nodes;
	list< m_node > :: iterator zero_node;
	vector < list< int > :: iterator > subnode_iterator;
	vector < list< m_node > :: iterator > m_node_iterator;
	
	// int number_pages;
	list< m_node > :: iterator next(list< m_node > :: iterator it){ return  ++it; }
	list< m_node > :: iterator prev(list< m_node > :: iterator it){	return  --it; }
	list< int > :: iterator next(list< int > :: iterator it){ return  ++it; }
	list< int > :: iterator prev(list< int > :: iterator it){ return  --it;	}
public:
	counter(int n){///Constructor
		// number_pages = n;
		m_node temp;
		for(int i = 0 ; i < n ; i++){
			temp.sub_nodes.push_back(i);
			temp.num_elements++;
		}
		temp.count = 0;
		main_nodes.push_back( temp );
		zero_node = main_nodes.begin();

		list< int > :: iterator i1 = main_nodes.back().sub_nodes.begin();
		for(int i = 0 ; i < n ; i++, i1++){
			subnode_iterator.push_back( i1 );
			m_node_iterator.push_back( prev( main_nodes.end() ) );
			// cout<<(*subnode_iterator[i])<<" "<<i<<" "<<&(*m_node_iterator[i])<<endl;
		}
	}
	//Public-Functions
	void increment(int i);
	void decrement(int i);
	void reset(int i);
	int count(int i);
	int findMax();
	int numMax();
	void printMax();
	
	void printAll();
};

void counter::increment(int n){
	list< m_node > :: iterator parent = m_node_iterator[n];
	list< m_node > :: iterator next_parent = next(parent);
	list< int > :: iterator element = subnode_iterator[n];
	list< int > :: iterator next_element;
	int expected_count = parent -> count + 1;

	if((next_parent == main_nodes.end()) || (next_parent -> count) > expected_count){
		m_node temp;
		temp.count = expected_count;
		next_parent = main_nodes.insert(next(parent) , temp);
	}else if((next_parent -> count) != expected_count){
		cout <<"Whoops!"<<endl; return;
	}

	next_parent -> sub_nodes.push_back(n);
	next_parent -> num_elements++;
	next_element = prev(next_parent -> sub_nodes.end());

	parent -> sub_nodes.erase(element);
	parent -> num_elements--;

	if(parent -> num_elements == 0 && parent!=zero_node){
		main_nodes.erase(parent);
	}

	m_node_iterator[n] = next_parent;
	subnode_iterator[n] = next_element;
}

void counter::printMax(){
	main_nodes.back().print_all();
}

void counter::decrement(int n){
	list< m_node > :: iterator parent = m_node_iterator[n];
	list< m_node > :: iterator next_parent;
	list< int > :: iterator element = subnode_iterator[n];
	list< int > :: iterator next_element;
	int expected_count = parent -> count - 1;
	if( ( parent == main_nodes.begin() ) || ( prev(parent) -> count < expected_count)){
		m_node temp;
		temp.count = expected_count;
		next_parent = main_nodes.insert(parent , temp);
	}
	else if(prev(parent) -> count == expected_count){
		next_parent = prev(parent);
	}else{
		cout<<"Whoops!!"<<endl; return;
	}

	next_parent -> sub_nodes.push_back(n);
	next_parent -> num_elements++;
	next_element = prev(next_parent -> sub_nodes.end());

	parent -> sub_nodes.erase(element);
	parent -> num_elements--;

	if(parent -> num_elements == 0 && parent!=zero_node){
		main_nodes.erase(parent);
	}

	m_node_iterator[n] = next_parent;
	subnode_iterator[n] = next_element;
}

int counter::count(int n){
	list< m_node > :: iterator parent = m_node_iterator[n];
	return parent -> count;
}


int counter::numMax(){
	return main_nodes.back().num_elements;
}

int counter::findMax(){
	return main_nodes.back().count;
}

void counter::reset(int n){
	list< m_node > :: iterator parent = m_node_iterator[n];
	list< m_node > :: iterator next_parent = zero_node;
	list< int > :: iterator element = subnode_iterator[n];
	list< int > :: iterator next_element;
	if(parent -> count == 0){
		return;
	}
	else{
		next_parent -> sub_nodes.push_back(n);
		next_parent -> num_elements++;
		next_element = prev(next_parent -> sub_nodes.end());

		parent -> sub_nodes.erase(element);
		parent -> num_elements--;

		if(parent -> num_elements == 0 && parent!=zero_node){
			main_nodes.erase(parent);
		}

		m_node_iterator[n] = next_parent;
		subnode_iterator[n] = next_element;
	}
}

