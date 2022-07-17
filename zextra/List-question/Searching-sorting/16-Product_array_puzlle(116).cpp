// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) 
{
    ll prod = 1 ;
    int count1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        if(nums[i1]==0)
            count1++;
        else
            prod *= nums[i1]        ;
        
        if(count1>1)
        {
            prod = 0;
            break ;
        }
    }
    //code here        
    vector<ll>ans1(n,prod);
    if(count1>1)
        return ans1 ;
    if(count1==1)
        {
            for (int i1 = 0; i1 < n; i1++)
            if(nums[i1]!=0)
                ans1[i1] = 0 ;
        
            return ans1 ;
        }

    for (int i1 = 0; i1 < n; i1++)
        if(nums[i1]!=0)
        ans1[i1] /= nums[i1]        ;
        

    return ans1 ;
}


int main(int argc, char const *argv[])
{
    // vector<ll> input1 = {1,0};
    vector<ll> input1 = {1,9,7,1,3,1,2,0,6,8,7,4,9,2,4,4};
    int n = input1.size();
    vector<ll> ans1 = productExceptSelf(input1,n);
    cout<<"\n";
    for(auto x : ans1)
        cout<<" "<<x;
    return 0;
}

