


#include<bits/stdc++.h>
using namespace std;
int A[101];
int sum[101];
int main()
 {
	int T,N,K;
	int mini = 10001;
	cin >> T;
	while(T--)
	{
	    cin >> N >> K;
	    for(int i=0;i<N;i++)
	    {    
	        cin >> A[i];
	    }
	    sort(A,A+N);
	    sum[0] = A[0];
	    for(int i=1;i<N;i++)
	    {    
	        sum[i] = sum[i-1] + A[i];
	    }
	    
	    int ans = 100000000;
	    int cost;
	
	    
	    for(int i=0;i<N;i++)
	    {
	        cost = 0;
	        int pos = upper_bound(A+i+1,A+N,A[i]+K) - A;
	       
	        int len = N - pos;
	       
	        if (i > 0) cost += sum[i-1];
	        
	        if (pos < N)
	            cost += ((sum[N-1] - sum[pos-1]) - len * (A[i]+K));

	        ans = min(ans,cost);
	    }
	   
	    cout << ans << "\n";
	}
	return 0;
}





