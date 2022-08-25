


// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day4/problem/top-k-frequent-elements-in-array







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void rec_uitl(int ind , string S , set<string> &st1)
{
	if(S.size()==ind)
		st1.insert(S);

	for(int it = ind ; it < S.size() ; it++)
	{
		swap(S[ind] , S[it]);
		rec_uitl(ind+1 , S , st1);
		swap(S[ind] , S[it]);

	}
}
vector<string>find_permutation(string S)
{
	// Code here there
	set<string> ans2  ;

	rec_uitl(0 , S , ans2);
	vector<string> ans1(ans2.begin(),ans2.end())  ;

	return ans1 ;
}