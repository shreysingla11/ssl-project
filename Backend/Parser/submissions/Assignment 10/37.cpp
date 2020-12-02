#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;

class distinct{
public:
	vector<int> l;
	int n;
	int logn;
	vector<vector<int> > first;
	vector<vector<int> > second;
	distinct(vector<int> a){
		n = a.size();
		logn = log2(n);
		l.resize(n);
		map<int,int> indices ;
		map<int,int>::iterator it;
		for (int i=0;i<n;i++){
			it = indices.find(a[i]);
			if (it==indices.end()){
				l[i]=-1;
				indices[a[i]] = i;
			}
			else{
				l[i] = it->second;
				indices[a[i]] =i;
			}
		}
		
		first = constructFirst();
		second = constructSecond();
	}
	vector<vector<int> > constructFirst(){
		int factor,k;
		vector<int> kvector;
		int x,y;
		vector<vector<int> > result(logn) ;
		for (int i=1;i<=logn;i++){
			factor = pow(2,i-1);
			kvector.resize(factor);
			for (int b=0;b<factor;b++){
				kvector[b]=0;
			}
			k = ((l[0])*factor)/n;


			x = (k*n)/factor + n/(factor*2);
			y = ((k+1)*n)/factor;

			if (l[0]>=x&&l[0]<y) {
				//cout<<"here"<<endl;
				result[i-1].push_back(kvector[k]+1);
				kvector[k]+=1;
			}
			else {
				result[i-1].push_back(kvector[k]);
			}
			for (int j=1;j<n;j++){
				k = ((l[j])*factor)/n;
				x = (k*n)/factor + n/(factor*2);
				y = ((k+1)*n)/factor;
				if (l[j]>=x&&l[j]<y){
					result[i-1].push_back(kvector[k]+1);
					kvector[k]+=1;
				}
				else result[i-1].push_back(kvector[k]);
			}
		}
		return result;
	}
	vector<vector<int> > constructSecond(){

		int factor,k;
		vector<int> kvector1,kvector2;//1 is smaller 2 ios larger
		int x,y,z;
		vector<vector<int> > result(logn) ;
		for (int i=1;i<=logn;i++){
			factor = pow(2,i-1);
			kvector1.resize(factor);
			kvector2.resize(factor);
			for (int b=0;b<factor;b++){
				kvector1[b]=-1;
				kvector2[b]=-1;
			}
			k = ((l[0])*factor)/n;
			x = (k*n)/factor;
			y = (k*n)/factor + n/(factor*2);
			z = ((k+1)*n)/factor;
			if (l[0]>=y&&l[0]<z){
				result[i-1].push_back(-1);
				kvector2[0]=0;
			}
			else{
				result[i-1].push_back(-1);
				kvector1[0]=0;
			}

			for (int j=1;j<n;j++){
				k = ((l[j])*factor)/n;
				x = (k*n)/factor;
				y = (k*n)/factor + n/(factor*2);
				z = ((k+1)*n)/factor;
				if (l[j]>=y&&l[j]<z){
					result[i-1].push_back(kvector1[k]);
					kvector2[k]=j;
				}
				else{
					result[i-1].push_back(kvector2[k]);
					kvector1[k]=j;
				}
			}
		}

		return result;
	}
	int num_distinct(int i, int j){
		int j0 = j;
		int result=0;
		int factor,temp;
		temp = -1;
		int length=n;
		int x=0;
		int y = n/2;
		int z = n;
		std::vector<int> v(n);
		for(int c=0;c<n;c++){
			if(l[c]==-1) {v[c]=temp;}
			else {v[c]=c;temp = c;}
		}
		j = v[j];
		
		
		for (int b=1;b<=logn;b++){
						if (j<i||j==-1) break;
			factor = pow(2,b-1);
				if(i>=y&&i<z){
					length/=2;
					x = y;
					y = x+length/2;
					z = x+length;
					if (l[j]>=y){
						
						//nothing
					}
					else{
						
						j = second[b-1][j];
						
					}
				}
				else{
					length/=2;
					z = y;
					y = x+length/2;
					z = x+length; 
					result=result+first[b-1][j];

					if(l[j]>=y){
						
						j = second[b-1][j];
						
					}
					else{
						
						//do nothing
					}
				}
			
		}
		
		return (j0-i+1-result);
	}

};
