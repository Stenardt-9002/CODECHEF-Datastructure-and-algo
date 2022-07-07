// https://leetcode.com/problems/search-in-rotated-sorted-array/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;
int search(vector<int>& nums, int target) 
{

    int n = nums.size();
    if(n==1)
    {
        if(nums[0]==target)
            return 0 ;
        return -1 ;
    }

    int low = 0 ;
    int high = n-1 ;
    //find breaking point 
    while(low<high)
    {
        int mid = (low+high)>>1;
        if(nums[mid]>nums[high])
            low = mid+1;
        else
            high = mid ;

    }
    int break_at = low ;
    low = 0 ; high = n-1 ;

    while(low<=high)
    {
        
        int mid = (low+high)>>1;
        int secondmid = (mid+break_at)%n;
        if(nums[secondmid]<target)
            low = mid+1;
        else if(nums[secondmid]>target)
            high = mid-1 ;
        else 
            return secondmid ;
        // cout<<"\nFork "<<low<<" "<<high<<" "<<mid;
    }
    return -1 ;
}

int main(int argc, char const *argv[])
{

    // vector<int> a1 = {5,6,7,0,1,2,4};
    // vector<int> a1 = {-1,2,4,5,6,7,9,10,12};
    // vector<int> a1 = {1,3,9,0};
    vector<int> a1 = {5,1,2,3,4};

    int taret = 0 ;
    cout<<search(a1 , taret);


    return 0;
}
