#include <bits/stdc++.h> 
using namespace std; 

// Structure for a Pair 
class Pair 
{ 
	public: 
	int a; 
	int b; 
}; 

// This function assumes that arr[] 
// is sorted in increasing order 
// according the first (or smaller) values in Pairs. 
int maxChainLength( Pair arr[], int n) 
{ 
	int i, j, max = 0; 
	int *mcl = new int[sizeof( int ) * n ]; 
	
	/* Initialize MCL (max chain length) 
	values for all indexes */
	for ( i = 0; i < n; i++ ) 
		mcl[i] = 1; 
	
	/* Compute optimized chain length values in bottom up manner */
	for ( i = 1; i < n; i++ ) 
		for ( j = 0; j < i; j++ ) 
			if ( arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1) 
				mcl[i] = mcl[j] + 1; 
	
	// mcl[i] now stores the maximum chain length ending with Pair i 
	
	/* Pick maximum of all MCL values */
	for ( i = 0; i < n; i++ ) 
		if ( max < mcl[i] ) 
			max = mcl[i]; 
	
	/* Free memory to avoid memory leak */
	
	return max; 
} 
	

/* Driver code */
int main() 
{ 
    int n;
    cin>>n ;
    Pair *arr1 = new Pair[n];
    int *dp1 = new int[n];

    int count1=0 ;
    while (count1<n)
    {
        cin>>arr1[count1].a>>arr1[count1].b;
        dp1[count1] = 1;
        count1++;
    }
    cout<<maxChainLength(arr1,n)<<endl;


     delete [] arr1;
    delete []dp1;


	return 0; 
} 

// This code is contributed by rathbhupendra 
