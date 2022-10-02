// https://practice.geeksforgeeks.org/problems/minimum-swaps/1


// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
bool compare_fuc(pair<int,int> a1 ,pair<int,int> b1)
{
    return a1.first<b1.first ;
}

//Function to find the minimum number of swaps required to sort the array. 
int minSwaps(vector<int>&nums)
{
    // Code here

    int n = nums.size();
    int ans1 = 0 ;
    vector<pair<int,int>> cmbined_array(n);

    for (int i1 = 0; i1 < n; i1++)
        cmbined_array[i1] = {nums[i1],i1};

    sort(cmbined_array.begin(),cmbined_array.end(),compare_fuc);

    vector<bool>vsisted(n,false)    ;

    for (int i1 = 0; i1 < n; i1++)
    {
        if(vsisted[i1] || cmbined_array[i1].second==i1)
            continue ;

        int j1=i1, cycle_sze = 0 ;

        while(!vsisted[j1])
        {
            vsisted[j1] = true ;
            j1 = cmbined_array[j1].second ;
            cycle_sze++ ;
        }
        if(cycle_sze>0)
            ans1+=(cycle_sze-1);
    }
    
    return ans1 ;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int n ;cin>>n ;
    vector<int>arr1(n) ;
    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1];
    
    cout<<minSwaps(arr1);


    return 0;
}

