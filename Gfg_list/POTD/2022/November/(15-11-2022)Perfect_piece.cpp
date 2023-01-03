// https://practice.geeksforgeeks.org/problems/close-to-perfection1525/1







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







int longestPerfectPiece(int arr[], int N) {
    // code here
    multiset<int> s1;
    int ans1 = 1 ;
    int ptr1 = 0 , ptr2 = 0 ;
    s1.insert(arr[ptr1]);
    while (ptr2<N)
    {
        if(s1.empty()||(*(--s1.end())-*(s1.begin())<=1))
        {
            
            ans1 = max(ans1,ptr2-ptr1+1);
            ptr2++ ;
            if(ptr2<N)
            s1.insert(arr[ptr2]);
        }
        else 
        {
            s1.erase(arr[ptr1]);
            ptr1++ ;
        }

    }
    
    return ans1;
}









