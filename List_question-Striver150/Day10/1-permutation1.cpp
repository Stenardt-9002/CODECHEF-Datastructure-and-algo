#include <bits/stdc++.h>
using namespace std;


void recursive1(int l,int r,vector<int> nums,vector<vector<int>>&ans1)
{


    if (l==r)
    {
        ans1.push_back(nums);
    }
    else
    {

        for (int i1 = l; i1 <=r; i1++)
        {
            swap(nums[i1],nums[l]);
            recursive1(l+1,r,nums,ans1);
            swap(nums[i1],nums[l]);


        }
    }   

}
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
       int n = nums.size();
       vector<vector<int>>ans1; 
       recursive1(0,n-1,nums,ans1);
       return ans1;
    }