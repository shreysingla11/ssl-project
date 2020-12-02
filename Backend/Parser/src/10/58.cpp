class distinct{
	int n;
	vector<int> L;
	vector<vector<int> > A;
	vector<vector<int> > B;
	distinct(vector<int> &A){
		n = A.size();
		L = vector<int>(n,0);
		map<int,int> M;
		for (int i=0; i<n; ++i){
			if (M.find(A[i])==M.end()){
				L[i]=-1;
			}
			else{
				L[i]=M.find(A[i])->second;
			}
			M[A[i]]=i;
		}
		int m=n;

		for (int i=0; m>1; i++,m/=2){
			vector<int> A_temp(n,0);
			vector<int> B_temp(n,-1);
			vector<int> temp(n/m,0);
			vector<int> aux(n/m,-1);
			for (int j=0; j<n; j++){
				int k = L[j]/m ;
				temp[k]++;
				if ((2*L[j])/m == 0){
					if ((2*L[aux[k]])/m == 0){
						B_temp[k] = B[i][aux[k]];
					}
					else{
						B_temp[k] = aux[k];
					}
				}
				else{
					int preindex;
					if ((2*L[aux[k]])/m == 1){
						preindex = aux[i];
					}
					else{
						preindex = B[i][aux[k]];
					}
					A_temp[k] = A_temp[preindex]+1;
					if ((2*L[aux[k]])/m == 1){
						B_temp[k] = B[i][aux[k]];
					}
					else{
						B_temp[k] = aux[k];
					}
				}
				aux[k]=j;
			}
			A.insert(A.end(),A_temp.begin(),A_temp.end());
			B.insert(B.end(),B_temp.begin(),B_temp.end());
		}
	}

	int num_distinct(int i, int j){
		int count = 0, c = 0, d=n;

		for (int x=0,y=0;  ;  ){
			if (j == -1) return 0;

			if (i > (c+d)/2){
				j = (L[j] >= (c+d)/2)? j : B[x][j];
				++x; y = y + y + 1; 
				c = (c+d)/2;
			}
			else if (i == (c+d)/2){
				return A[x][j];
			}
			else{
				count += A[x][j];
				j = (L[j] < (c+d)/2)? j : B[x][j];
				++x; y = y + y ; 
				d = (c+d)/2;
			}
		}
	}

};