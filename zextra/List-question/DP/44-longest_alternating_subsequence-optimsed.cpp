// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1






#include "bits/stdc++.h"

using namespace std;
int AlternatingaMaxLength(vector<int>&nums)
{
    int n1 = nums.size();

    int lastonewassmall = 1;
    int lastonewaslarge = 1 ;
// both variable contains the data till i1
// consider only i1-1 because lastonewaslarge and lastonewassmall also considered i1-1
    for (int i1 = 1; i1 < n1; i1++)
    {
        if (nums[i1]>nums[i1-1])
        {
            // lastonewaslarge = max(lastonewaslarge ,lastonewassmall+1);
            lastonewaslarge = lastonewassmall+1;
        }
        else if (nums[i1]<nums[i1-1])
        {
            // lastonewassmall = max(lastonewassmall ,lastonewaslarge+1);
            lastonewassmall = lastonewaslarge+1;

        }
    }
    return max(lastonewaslarge,lastonewassmall);
}