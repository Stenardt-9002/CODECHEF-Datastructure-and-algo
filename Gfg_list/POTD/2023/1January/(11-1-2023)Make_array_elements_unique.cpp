// # https://practice.geeksforgeeks.org/problems/6e63df6d2ebdf6408a9b364128bb1123b5b13450/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        map<int,int>map1 ;
        set<int>used;
        for (int i = 0; i < N; i++)
            if (map1[arr[i]]++==0)
                used.insert(arr[i]);
        long long int large = 0 ,ans = 0;            
        for(auto ke:map1)
        {
            int occur = ke.second ;
            if(occur<=1)
                continue ;
            int value = ke.first ;
            long long int check = max((long long)(value)+1 , large);
            while (occur>1)
            {
                if(used.find(check)==used.end())
                {
                    ans+=(check-value);
                    used.insert(check);
                    occur--;
                    large = check ;
                }
                check++ ;
            }
        }
        return ans ;
    }
};

// import collections

// class Solution:
//     def minIncrements(self, arr, N): 
//         used = []
//         dict_1 = collections.Counter(arr)
//         ans = 0
//         for i in range(100000):
//             if dict_1[i]>=2:
//                 used = used +([i]*(dict_1[i]-1))
//             elif dict_1[i]==0 and used :
//                 ans+=(i-used.pop())
//         return ans 
            
//         # Code here


// # class Solution:
// #     def minIncrements(self, arr, N): 
// #         arr = sorted(arr)
// #         dict_1 = {}
// #         for i in arr:
// #             if i not in dict_1.keys():
// #                 dict_1[i] = 1
// #             else :
// #                 dict_1[i] += 1
// #         ans  = 0
// #         large_n =arr[-1]+1
// #         unused = [] 
// #         for i in range(arr[0],arr[-1],1):
// #             if i not in dict_1.keys():
// #                 unused.append(i)
// #         ptr1 = 0 
// #         for i in arr:
// #             while dict_1[i]>1:
// #                 if ptr1<len(unused):
// #                     ans+=(unused[ptr1]-i)
// #                     ptr1+=1 
// #                 else:
// #                     ans+=(large_n-i)
// #                     large_n+=1
// #                 dict_1[i]-=1
// #         return ans 
            
// #         # Code here





















