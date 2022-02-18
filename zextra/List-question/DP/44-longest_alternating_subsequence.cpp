// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1






#include "bits/stdc++.h"

using namespace std;
int AlternatingaMaxLength(vector<int>&nums)
{
    //TLE on this
    int n1 = nums.size();

    vector<int> dp1(n1),dp2(n1);//dp1 is when last element was larger than second last
                        //dp2 is when last element was smaller than second last
    for (int i1 = 0; i1 < n1; i1++)
    {
        dp1[i1] = dp2[i1] = 1;//all are in sequence 
    }
    
    for (int i1 = 1; i1 < n1; i1++) //till i1 consider 
    {
        for (int j1 = 0; j1 < i1; j1++)
        {
            if (nums[i1]>nums[j1])
            {
                //dp1 comes in role 
                dp1[i1] = max(dp1[i1],dp2[j1]+1);
                //dp2 when last element was smaller from seoncd last 
            }

            else if(nums[j1]>nums[i1])
            {
                //i1 is smaller than j1
                dp2[i1] = max(dp2[i1],dp1[j1]+1);
            }
        }
        
    }
    int max1 =*max_element(dp1.begin(),dp1.end());
    int max2 =*max_element(dp2.begin(),dp2.end());
    max1 = max(max1,max2);
    return max1 ;

}


int main(int argc, char const *argv[])
{
    
    return 0;
}



