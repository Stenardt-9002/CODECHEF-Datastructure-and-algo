#include "bits/stdc++.h"



using namespace std;


// O(n^3)
// all possible iteration sum them 


//O(n^2)

// use contiguous sum array (cumulative sum )
// 1 ,4 ,5 ,-1 ,7 ,-9 === 1 ,5 ,10 ,9 ,16 ,7


//O(n)





    int maxSubArray(vector<int>& nums)
    {
        int n1 = nums.size();
        int curr_max = nums[0];
        int max_yet = nums[0];
        for(int i1 = 1 ;i1<n1;i1++)    
        {
            curr_max = max(nums[i1],curr_max+nums[i1]) ;
            max_yet = max(max_yet , curr_max) ;
        }
        return max_yet ;
    }




int main(int argc, char const *argv[])
{

    vector<int> a1;
    int n1,temp1  ; 
    cin>>n1 ;
    for (int i1 = 0; i1 < n1; i1++)
    {
        cin>>temp1 ;
        a1.push_back(temp1);
    }
    int start1 = 0;
    int end1 = n1-1;
    int sum_curr = a1[0] ;
    int tol_max = a1[0] ;

    for (int i1 = 1; i1 < n1; i1++)
    {
        
        if (a1[i1]<sum_curr+a1[i1])
        {
            sum_curr = sum_curr+a1[i1] ;
        }
        else
        {
            sum_curr = a1[i1] ;
            start1 = i1 ;
        }
        
        if (tol_max<sum_curr)
        {
            tol_max = sum_curr ;
            end1 = i1 ;
        }
        

    }
    
    cout<<"\nAns "<<tol_max ;
    cout<<"Start "<<start1 <<" "<<end1 ;


    return 0;
}



