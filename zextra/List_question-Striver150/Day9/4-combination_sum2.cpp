// https://leetcode.com/problems/combination-sum-ii/


//difference is that you can use only once


#include <bits/stdc++.h>
using namespace std;
//TLE error
// void rec1ursive(int ind , int sum1 ,vector<int>& candidates,vector<int>&ds1, vector<vector<int>>&ans1)
// {
//     if (ind==candidates.size())
//     {
//         if (sum1==0)
//         {
//             //got subset of recursion
//             ans1.push_back(ds1);
//         }
//         return ;
        
//     }
    

    
//     if (sum1>=candidates[ind])
//     {
//         ds1.push_back(candidates[ind]);
//         rec1ursive(ind+1,sum1-candidates[ind],candidates,ds1,ans1); //go to next and use it
//         ds1.pop_back();
//     }
//     rec1ursive(ind+1,sum1,candidates,ds1,ans1); //go to next and use it

// }

// vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
// {
//     vector<vector<int>> ans1;
//     vector<int> ds1 ;
//     rec1ursive(0,target,candidates,ds1,ans1);
//     return ans1;
// }






void rec1ursive(int ind , int sum1 ,vector<int>& candidates,vector<int>&ds1, vector<vector<int>>&ans1)
{
    
    // if (candidates[ind]>sum1)
    // {
    //     return ;
    // }
    // covered in for loop


    //base case
        if (sum1==0)
        {
            ans1.push_back(ds1);
        }
        return ;





    
    for (int i1 = ind; i1 < candidates.size(); i1++)
    {
        if (i1>ind && candidates[i1]!=candidates[i1-1])//duplicacy check 
        continue ;
        if (candidates[i1]>sum1)
        break ;            
        

        ds1.push_back(candidates[i1]);
        rec1ursive(i1+1,sum1-candidates[i1],candidates,ds1,ans1);
        ds1.pop_back();
        
    }
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    vector<vector<int>> ans1;
    vector<int> ds1 ;
    sort(candidates.begin(),candidates.end());
    rec1ursive(0,target,candidates,ds1,ans1);
    return ans1;
}




