#include <iostream>
#include <vector>
#include <list>


using namespace std;

struct Node{

	int count;
	int index;
	int list_number;
};

class Webpages{

private:

	int N;

	//vector to sotre the itr values	
	vector<list<Node>::iterator > index;
	vector<int> list_info;

	list<list<Node> > web_list;

public:

	Webpages(int n){
		
		//initializing N;
		N=n;

		list<Node> list_0;
		for(int i=0; i<N; i++){
			
			Node n;
			n.count=0;
			n.index=i;
			n.list_number=0;

			list_0.push_back(n);
		}

		web_list.push_back(list_0);


		list<Node>::iterator  itr=list_0.begin();
		

		for(int i=0; i<N; i++){

			index.push_back(itr);
			// cout<<itr->index<<endl;
			itr++;
		}

		for(int i=0; i<N; i++){
			list_info.push_back(0);
		}


		// for(int i=0; i<index.size(); i++){
		// 	cout<<index[i]->index<<endl;
		// }

		// for(int i=0; i<index.size(); i++){
		// 	cout<<index[i]->index<<" "<<index[i]->count<<endl;
		// }

	}



	void increment(int in){

		list<Node>::iterator itr;
		itr=index[in];

		itr->count++;
		int LN=itr->list_number;

		cout<<itr->count<<endl;
		cout<<itr->index<<endl;

		list<list<Node> >::iterator itr2=web_list.begin();



		// for(int i=0; i<LN; i++){
		// 	itr2++;
		// }

		//itr2 will point to the list containing the element

		// cout<<LN<<endl;

		// list<Node> a=(*itr2);   //if this is used, i dont know how iterator values get reversed;

		// cout<<(*itr2).size()<<endl;

		for(list<Node>::iterator b=(*itr2).begin(); b!=(*itr2).end(); b++){
			cout<<b->index<<" "<<b->count<<endl;
		}
		cout<<endl;
		

		cout<<itr->index<<" "<<itr->count<<endl;
		(*itr2).erase(itr);


		// for(list<Node>::iterator b=(*itr2).begin(); b!=(*itr2).end(); b++){
		// 	cout<<b->index<<" "<<b->count<<endl;
		// }
		// cout<<endl;
		



	return ;		

	}


	void decrement(int i){

		list<Node>::iterator itr;
		itr=index[i];

		itr->count--;

	}


	void reset(int i){

		list<Node>::iterator itr;
		itr=index[i];

		itr->count=0;
	}

	// Return the current count of ith object.
	int count(int i){

		list<Node>::iterator itr;
		itr=index[i];
		
		return itr->count;
	}


	//Return the maximum count of the objects.
	int findMax(){
		return 0;
	}

	//Return the number of objects having maximum count.
	int numMax(){

	}

	//Print the list of objects with maximum count, in the order in which they achieved that count value.
	void printMax(){

	}





		void print(){

			list<Node>::iterator  itr;
			list<int>::iterator  itr2;

			// list<Node> new_list=web_list.front();

			// cout<<new_list.size()<<endl;
			
			// for(itr=new_list.begin(); itr!=new_list.end(); itr++){

			// 	cout<<itr->index<<" "<<itr->count<<endl;

			// };


			for(int i=0; i<index.size(); i++){
				cout<<index[i]->index<<" "<<index[i]->count<<endl;
			}
		}



};


int main(){


	Webpages W(10);

	

	W.increment(2);

	W.increment(2);
	
	W.increment(2);
	
	W.increment(3);

	W.increment(4);

	W.decrement(2);
	

	W.reset(3);
	

	W.print();


	return 0;
}