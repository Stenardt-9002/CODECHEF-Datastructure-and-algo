
// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


vector<vector<int>> fourSum(vector<int> &arr, int k) 
{
    // Your code goes here
    vector<vector<int>> ans1 ;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    set<vector<int>> s1 ;
    for (int i1 = 0; i1 < n-3; i1++)
    {
        for (int j1 = i1+1; j1 < n-2; j1++)
        {
            // int target = k-arr[i1]-arr[j1];
            // if(target<0)
            //     continue ;

            int onepointer = j1+1 ;
            int secondpointer = n-1 ;

            while(onepointer<secondpointer)
            {
                if(k == arr[i1]+arr[j1]+arr[onepointer]+arr[secondpointer])
                    s1.insert({arr[i1],arr[j1],arr[onepointer],arr[secondpointer]}),onepointer++ , secondpointer-- ;
                    // ans1.push_back({arr[i1],arr[j1],arr[onepointer],arr[secondpointer]}),onepointer++ , secondpointer-- ;
                    
                else if(k > arr[i1]+arr[j1]+arr[onepointer]+arr[secondpointer])
                    onepointer++;
                else 
                    secondpointer--;
            }
        }
        
    }
    for(auto x: s1)
        ans1.push_back(x);

    return ans1 ;
}

