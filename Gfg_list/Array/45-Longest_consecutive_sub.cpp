
// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1/?page=3&curated[]=2&sortBy=submissions


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



int findLongestConseqSubseq(int arr[], int N)
{
    //Your code here
          int i1 = 0 ;
      sort(arr,arr+N);
      int length_ansd = 0 ,curlength=1;
      for(i1=0;i1<N-1;i1++)
      {
          if(arr[i1]==arr[i1+1])
                continue ;
          else if(arr[i1]==arr[i1+1]-1)
                curlength++;
    
          else
          {
              length_ansd = max(length_ansd,curlength);
              curlength = 1;
          }
      }
      length_ansd = max(length_ansd,curlength);
      return length_ansd ;
}
// #hashing 
int longestConsecutive(vector<int>& nums) 
{
    int n = nums.size()    ;
    int ans1 = 0; 
    unordered_set<int> s1et ;

    for(int i1 = 0 ; i1<n ; i1++)
        s1et.insert(nums[i1]);

    for(int i1 = 0 ; i1<n ; i1++)
    if(s1et.find(nums[i1]-1)==s1et.end())
    {
        int start = nums[i1] ;
        while(s1et.find(start)!=s1et.end() )
            start++ ;

        ans1 = max(ans1,start-nums[i1]);
    }
    return ans1 ; 
}


// https://www.geeksforgeeks.org/majority-element/
// https://www.geeksforgeeks.org/find-subarray-with-given-sum/
// https://www.google.com/search?q=subarray+with+sum&oq=subarray+with+sum&aqs=chrome..69i64.4012j0j1&client=ubuntu&sourceid=chrome&ie=UTF-8
// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/


// https://www.geeksforgeeks.org/count-possible-ways-to-construct-buildings/

// https://www.youtube.com/watch?v=tyB0ztf0DNY
// https://www.youtube.com/watch?v=fWX9xDmIzRI
// https://www.youtube.com/watch?v=rYkfBRtMJr8
// https://practice.geeksforgeeks.org/events?utm_source=gfg&utm_medium=gfg_header&utm_campaign=gfgpractice_header
// https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/






