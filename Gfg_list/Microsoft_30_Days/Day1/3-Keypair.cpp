// https://practice.geeksforgeeks.org/batch-problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






bool hasArrayTwoCandidates(int arr[], int n, int x) 
{
	// code here
	sort(arr,arr+n);
	int i = 0 , j = n-1 ;
	while(i<j)
		if(arr[i]+arr[j]>x)
			j--;
		else if(arr[i]+arr[j]<x)
			i++;
		else 
			return true ;

	return false ;
}