#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define INFINITY 1e9

int main(){
	int n, m, i, a1, b1, j;
	//FILE* fp = fopen("2in.txt", "r");
	scanf("%d%d", &n, &m);
	vector<int> a;
	vector<int> b;
	for (i=0; i<n; i++){
		scanf("%d", &a1);
		a.push_back(a1);
	}
	for(i=0; i<m; i++){
		scanf("%d", &b1);
		b.push_back(b1);
	}
	vector<int>curr(m);
	vector<int>col(n);
	int k=0;

	for(i=0; i<m-1; i++){
			curr[i] = INFINITY;
	}
	col.push_back(curr[0]);

	if (a[n-1]==b[m-1])
		curr[m-1]=1;
	else curr[m-1] = INFINITY;

	for(i=n-2; i>=0; i--){
		for (j=0; j<m-1; j++){
            if (j<=i && n-i+j >=m-2+k){
			if(a[i] == b[j]){
                if (curr[j+1] == INFINITY)
                    curr[j]= INFINITY;
                else
                    curr[j] =1 + curr[j+1];
            }
			else{
                if(curr[j] == INFINITY)
                    curr[j] = INFINITY;
                else
                    curr[j] = 1 + curr[j];
            }
		 }
		}
		// j here is m-1
		if (a[i]==b[m-1])
			curr[j]=1;
		else if (curr[j] == INFINITY)
                curr[j] = INFINITY;
        else
			curr[j]=1+ curr[j];

        if(curr[m-2+k]==INFINITY)
            k++;

		col.push_back(curr[0]);

	}

	reverse (col.begin(), col.end());

	int min = INFINITY;
	int pos=0;
	for (i=0; i<n; i++){
		//cout<<endl<< i<<"  "<<col[i];
		if (col[i]<min){
			min=abs(col[i]);
			pos=i;
		}
		//cout<<"    "<<min;
	}

    if (min==INFINITY){
        printf("infinity\n");
	}
    else
        printf("%d %d",min, pos+1);
	//cout<<endl<<min<<endl<<pos+1;
}
