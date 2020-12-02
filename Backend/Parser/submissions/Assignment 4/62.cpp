class counter{
	vector<int> val;	//counts of pages
	list<list<int> > backbone; //the backbone list
	vector<list<list<int> >::iterator > head; //head pointers of pages
	vector<list<int>::iterator> position; //position pointers of pages
	list<list<int> >::iterator zr; //iterator to zero list, never delete this

	public:
	counter(int n){
		list<int> tmp1;
		for (int i=0; i<n; i++) {
			tmp1.push_back(i);
			val.push_back(0);
		}
		backbone.push_back(tmp1);
		list<int>::iterator it = backbone.front().begin();
		for (int i=0 ; i<n ; i++, it++){
			head.push_back(backbone.begin());
			position.push_back(it);
		}
		zr = backbone.begin();
	}

	void increment(int i){
		if (i<0 || i>=val.size()) {return;}
		val[i]++;

		// if(--head[i]==zr){cout<<"hi";} head[i]++;
		list<list<int> >::iterator tmp = head[i];
		tmp--;
		if (val[i]==0){
			//do nothing, to be inserted to zr list.
		}
		else if (val[i]<0 && tmp==zr){
			list<int> nl;
			backbone.insert(head[i],nl);
		}
		else if (head[i] == backbone.begin()){
			list<int> nl;
			backbone.insert(head[i],nl);
			//append new empty list
		}
		else if ( val[(*(--head[i])).front()] != val[i]){
			list<int> nl;
			backbone.insert(++head[i],nl);
			//insert new empty list
		}
		else{
			head[i]++;
			//nothing
		}
		//return head to the one where you have to delete

		list<list<int> >::iterator it = head[i];
		head[i]--;
		//delete earlier using 'it'
		(*it).erase(position[i]);
		if((*it).empty() && it!=zr){
			backbone.erase(it);
		}

		//also use head[i] later on
		(*head[i]).push_back(i);
		position[i]=((*head[i]).end()); position[i]--;
		return;
	}

	void decrement(int i){
		if (i<0 || i>=val.size()) {return;}
		val[i]--;

		list<list<int> >::iterator nxt=head[i]; nxt++;
		if (val[i]==0){
			nxt = zr;
		}
		else if ( nxt == backbone.end()){
			list<int> nl;
			backbone.push_back(nl);
			nxt=backbone.end();
			nxt--;
			//append new empty list
		}
		else if ( val[(*nxt).front()] != val[i]){
			list<int> nl;
			backbone.insert(nxt,nl);
			nxt=head[i]++;
			//insert new empty list
		}
		else{
			//nothing
		}
		//head contains from which you have to delete, nxt to which you have to add

		(*head[i]).erase(position[i]);
		if((*head[i]).empty() && head[i]!=zr){
			backbone.erase(head[i]);
		}

		head[i]=nxt;
		(*head[i]).push_back(i);
		position[i]=((*head[i]).end()); position[i]--;

		return;
	}

	void reset(int i){
		if (i<0 || i>=val.size()) {return;}
		val[i]=0;

		list<int> t2 = *head[i];
		(*head[i]).erase(position[i]);
		if ((*head[i]).empty() && head[i]!=zr){
			backbone.erase(head[i]);
		}

		list<list<int> >::iterator tmp = zr;
	
		head[i]=tmp;//
		(*tmp).push_back(i);
		position[i] = (*tmp).end();
		position[i]--;
		return;
	}

	int count(int i){
		return val[i];
	}

	int findMax(int i){
		list<list<int> >::iterator it =backbone.begin();
		if ((*it).empty()){it++;}
		return val[backbone.front().front()];
	}

	int numMax(int i){
		list<list<int> >::iterator it =backbone.begin();
		if ((*it).empty()){it++;}
		return backbone.front().size();
	}

	void printMax(){
		list<list<int> >::iterator tmp =backbone.begin();
		if ((*tmp).empty()){tmp++;}
		list<int>::iterator it = (*tmp).begin();
		for ( ; it!=(*tmp).end() ; it++){
		 	cout<<(*it)<<" "<<val[(*it)]<<endl;
		}
		// cout<<val[backbone.front().back()];
	}

	// void print(){
	// 	list<list<int> >::iterator it1=backbone.begin();
	// 	while( it1 != backbone.end() ){

	// 		list<int>::iterator it2 =(*it1).begin();
	// 		while( it2 != (*it1).end() ){
	// 			cout<<(*it2)<<" "<<val[(*it2)]<<endl;
	// 			it2++;
	// 		}
	// 		cout<<endl;
	// 		it1++;
	// 	}
	// 	return;
	// }
};