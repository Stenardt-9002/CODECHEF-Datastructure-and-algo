// https://practice.geeksforgeeks.org/problems/inversion-of-array/0https://practice.geeksforgeeks.org/problems/inversion-of-array/0

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace  std;



class Solution
{
    public:
    long long merge_arr(long long arr[] , vector<long long>&temp , long long first , long long mid, long long last)
    {
        long long i , j, k ;
        long long inv_count = 0 ;
        i = first ; j = mid+1 ; k = first ;
        while((i<=mid)&&(j<=last))
        {
            if(arr[i]<=arr[j])
                temp[k++] = arr[i++];
            else 
            {
                temp[k++] = arr[j++];
                inv_count+=(mid+1-i);
            }
        }
        while(i<=mid)
            temp[k++] = arr[i++];
        while(j<=last)
            temp[k++] = arr[j++];
        for(long long i = first ; i<=last ; ++i)
            arr[i] = temp[i] ;
        return inv_count ; 
        
    }
    
    long long merge_sort(long long arr[] ,vector<long long>&temp , long long first , long long last)
    {
        long long mid , inv_count = 0 ;
        if(last>first)
        {
            mid = (last+first)>>1 ;
            inv_count+=merge_sort(arr , temp , first , mid);
            inv_count+=merge_sort(arr , temp , mid+1 , last);
            inv_count+=merge_arr(arr , temp , first , mid , last);
        }
        return inv_count ;
    }
    
    
    void inversion_count(long long arr[] ,long long N ,long long &ans)
    {
        vector<long long > temp(N,0);
        ans = merge_sort(arr , temp , 0,N-1);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans =0 ;
        inversion_count(arr ,N , ans);
        return ans ;
    }

};

