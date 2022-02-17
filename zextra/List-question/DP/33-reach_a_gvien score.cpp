

#include "bits/stdc++.h"

using namespace std;

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	vector<int>steps1 = {3,5,10} ; //sorted
	
	for (auto cstep:steps1)
	{
	 for(int i1 = 1;i1<=n;++i1)   
	    {
	        if(i1>=cstep)
	        {
	            table[i1]+=table[i1-cstep];
	        }
	    }
	}
	
	return table[n];
}