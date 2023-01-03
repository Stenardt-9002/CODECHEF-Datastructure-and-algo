// https://practice.geeksforgeeks.org/problems/grouping-of-numbers0015/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;







int maxGroupSize(int arr[], int N, int K) 
{
    // code here
    int ans1_group_size = 0 ;
    int low = 1,high = K-1 ;
    vector<int> remainder_array(K,0);
    for (int i1 = 0; i1 < N; i1++)
        remainder_array[arr[i1]%K]++;
        

    while (low<high)
    {
        ans1_group_size+=(max(remainder_array[low],remainder_array[high]));
        low++ ;
        high--;
    }
    if(low==high && remainder_array[low]>0)//even divisibilty
        ans1_group_size++;


    if(remainder_array[0]>0) //one number allowed to be divisible alone
        ans1_group_size++;


    return ans1_group_size ;    

}





