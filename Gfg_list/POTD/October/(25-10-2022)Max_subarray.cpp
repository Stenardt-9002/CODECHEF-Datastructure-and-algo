




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






vector <int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    deque<int> q1 ;
    vector<int> ans1 ;

    for (int i1 = 0; i1 < k; i1++)
    {
        while (!q1.empty()&& arr[q1.back()]<=arr[i1])
            q1.pop_back();

        q1.push_back(i1);
    }
    for (int i1 = k; i1 < n; i1++)
    {
        ans1.push_back(arr[q1.front()]);
        //remove the once that are out of range
        while (!q1.empty() && q1.front()<=i1-k)//now not in range 
            q1.pop_front();//remove the once that were first and max ;

        while (!q1.empty()&& arr[q1.back()]<=arr[i1])
            q1.pop_back();

        q1.push_back(i1);
        //now inseret next and add it to queue

    }
    ans1.push_back(arr[q1.front()]);
    return ans1 ;
}







