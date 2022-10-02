#include <bits/stdc++.h>
using namespace std;

//sum is target 
 void recursive_sum(int ind , int sum , vector<int>&candidate,vector<int>&ds ,vector<vector<int>>&ans1 )
    {
        //end at ind == candidate.size()
        //end at sum == 0

        if(ind==candidate.size())
        {
            if (sum==0)
            {
                ans1.push_back(ds);
            }
            return ;
        }

        //pick
        if(sum>=candidate[ind])
        {
            ds.push_back(candidate[ind]);
            recursive_sum(ind,sum-candidate[ind],candidate,ds,ans1);//taken and again check
            ds.pop_back();
        }

        recursive_sum(ind+1,sum,candidate,ds,ans1);//not taken and moved on 

    }

    

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>>ans1 ; 
    vector<int>srtack1;
    recursive_sum(0,target,candidates,srtack1,ans1);
    return ans1;
}

int main(int argc, char const *argv[])
{

    return 0;
}


