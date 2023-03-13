// https://practice.geeksforgeeks.org/problems/9dacc32ad062be6e2ba8f6c41aad0b2b2376397d/1









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





class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        int k = costs[0].size();
        if(n==1 && k==1)
            return costs[0][0];
        if(k==1)
            return -1 ;
        vector<int> prev(k,0) , curr(k,0);
        int min_index = 0 ;
        for(int i = 0 ; i<k ; ++i)
        {
            prev[i] = costs[0][i];
            if(prev[i]<prev[min_index])
                min_index = i ;
        }
        
        for (int i = 1; i < n; i++)
        {
            int second_min = (min_index+1)%k;
            for (int i1 = 0; i1 < k; i1++)
            if(i1!=min_index && prev[i1]<prev[second_min])
                second_min = i1 ;

            for (int i1 = 0; i1 < k; i1++)
                if(i1!=min_index)
                    curr[i1] = prev[min_index]+costs[i][i1];
            
            curr[min_index] = prev[second_min]+costs[i][min_index];


            
            
            for (int i1 = 0; i1 < k; i1++)
                prev[i1] = curr[i1];
                
            for(int i1 = 0 ; i1<k ; ++i1)
                if(prev[i1]<prev[min_index])
                    min_index = i1 ;
            // cout<<prev[min_index]<<endl;
        }
        min_index = 0 ;
        for(int i = 0 ; i<k ; ++i)
        {
            if(prev[i]<prev[min_index])
                min_index = i ;
        }
        
        return prev[min_index];
    }
};






























