

// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





long long int count(long long int n)
{
	long long int i1;
	// memset(table, 0, sizeof(table));
    vector<long long int> table(n+1,0);
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	table[3] = 1;
	table[5] = 1;
	table[10] = 1;

    for (i1 = 4; i1 <=n; i1++)
    {
        if(i1>=3)
            table[i1]+=table[i1-3];
        if(i1>=5)
            table[i1]+=table[i1-5];
        if(i1>=10)
            table[i1]+=table[i1-10];
    }
    

	// Your code here
	
	return table[n];
}