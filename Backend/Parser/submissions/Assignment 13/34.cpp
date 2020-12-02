#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n;
int inf = 1000000000;
struct node{
	//int number;
	int* cost;
	bool* inqueue;
	node(){
		inqueue = new bool[4*n+1];
		cost = new int[4*n+1];
		for(int i=0;i<4*n+1;i++){
			cost[i] = inf;
			inqueue[i] = false;
		}
	}
};
struct pairs{
	int nodenumber;
	int goodness;
};
int main(){
	cin>>n;
	int currcost;
	// queue<int>::iterator it1;
	// queue<int>::iterator it2;
	int** c = new int*[n];
	for(int i = 0; i < n; ++i)
    	c[i] = new int[n];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>c[i][j];
    	}
    }
    // for (int i=0;i<n;i++){
    // 	for(int j=0;j<n;j++){
    // 		cout<<c[i][j]<<endl;
    // 	}
    // }
    vector<node> allnodes(n);
    //cout<<allnodes[0].cost[7]<<"fsdjkf"<<endl;
    queue<int> myqueue1;
    queue<int> myqueue2;
    int min;
    myqueue1.push(0);
    myqueue2.push(2*n);
    allnodes[0].cost[2*n]=0;
    //cout<<"fsd"<<endl;
    //cout<<allnodes.size()<<endl;
    allnodes[0].inqueue[2*n] = true;
    //cout<<"jfhsd"<<endl;
    while(!myqueue1.empty()){
    	int currnum = myqueue1.front();
    	int currgood = myqueue2.front();
    	myqueue1.pop();
     	myqueue2.pop();
     	allnodes[currnum].inqueue[currgood] = false;
    	//cout<<"here"<<endl;
    	for(int i=0;i<n;i++){
    			currcost = c[currnum][i];
    			if(currcost<0){
    				currcost = 0-currcost;
    				//the edge is good
    				if (currgood<=4*n){
    					//cout<<currgood<<"dfsd"<<endl;
    					//cout<<allnodes[i].cost[currgood+1]<<"fsdjkf"<<endl;
    					//cout<<allnodes[currnum].cost[currgood]<<"fsdhfg"<<endl;
    					if(allnodes[i].cost[currgood+1]>currcost+allnodes[currnum].cost[currgood]){
    						//update
    						//cout<<"goodedge"<<currnum<<" "<<i<<" "<<currcost<<" "<<allnodes[i].cost[currgood]<<endl;
    						allnodes[i].cost[currgood+1]=currcost+allnodes[i].cost[currgood];
    						if(allnodes[i].inqueue[currgood+1]){
    							//already in the queue, do nothing
    						}
    						else{
    							myqueue1.push(i);
    							myqueue2.push(currgood+1);
    							allnodes[i].inqueue[currgood+1] = true;
    						}
    					}
    					else{
    						//cout<<"fsd"<<endl;
    					}
    				}
    				
    			}
    			else{
    				//the edge is bad
    				if(currgood>0){
    					if(allnodes[i].cost[currgood-1]>currcost+allnodes[currnum].cost[currgood]){
    						//cout<<"badedge"<<currnum<<" "<<i<<" "<<currcost<<" "<<allnodes[i].cost[currgood]<<endl;
    						allnodes[i].cost[currgood-1] = currcost+allnodes[currnum].cost[currgood];
							
    					if(allnodes[i].inqueue[currgood-1]){
    							//already in the queue, do nothing
    						}
    						else{
    							myqueue1.push(i);
    							myqueue2.push(currgood-1);
    							allnodes[i].inqueue[currgood-1] = true;
    						}
    					}
    					else{
    						//cout<<"fhdgbf"<<endl;
    					}
    				}
    			}
    		
    	}
    // 	 for(it1=myqueue1.begin(),it2=myqueue2.begin();it1!=myqueue1.end();it1++,it2++){
    //  	cout<<(*it1)<<" "<<(*it2)<<endl;
    //  	}
     	
    }
	
    

    for (int k=0;k<n;k++){
    	//calculate minimum from 2n
    	min = inf;
    	for (int l=2*n;l<=4*n-1;l++){
    		//cout<<allnodes[k].cost[l]<<" ";
    		if (min>allnodes[k].cost[l]) min = allnodes[k].cost[l];
    	}
    	cout<<min<<endl;
    	cout<<endl;
    }
	return 0;
}