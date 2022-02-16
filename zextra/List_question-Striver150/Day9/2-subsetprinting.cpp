    // https://leetcode.com/problems/subsets-ii/submissions/
#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n1 = nums.size()    ;
        int totla = 1<<n1;
        vector<vector<int>>ans1 ;
        for(int i1 = 0;i1<totla;i1++)
        {
            vector<int> temp1 ;
            for(int j1 = 0;j1<n1;j1++)
            {
                if(i1&(1<<j1))
                {temp1.push_back(nums[j1]); }
            }
            sort(temp1.begin(),temp1.end());
            if(find (ans1.begin(), ans1.end(), temp1)==ans1.end())//element not found
            {
                ans1.push_back(temp1);
            }
        }
        
        return ans1;
    }