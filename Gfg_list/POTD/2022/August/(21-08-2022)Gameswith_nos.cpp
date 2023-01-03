// https://practice.geeksforgeeks.org/problems/game-with-nos3123/1








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int* game_with_number(int arr[], int n)
{
    // Complete the function
    int *ans1 = new int[n];
    for(int i1 = 0 ; i1<n-1 ; i1++)
        ans1[i1] = arr[i1]^arr[i1+1];
    
    ans1[n-1] = arr[n-1];
    return ans1 ;
}