//  https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#   
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

 
    

int maximumSumRectangle(int R, int C, vector<vector<int>> M) 
{
        int final_sum = INT_MIN ;
        int sum , max_sum ;
        vector<int> temp1 (R,0);
        for (int left = 0; left < C; left++)
        {
            std::fill(temp1.begin(),temp1.end(),0);
            for (int right = left; right < C; right++)
            {
                for (int i1 = 0; i1 < R; i1++)
                    temp1[i1]+=M[i1][right];
                
                
                //kadane logic
    
                sum = temp1[0] ; max_sum = temp1[0];
                for (int j1 = 1; j1 < R; j1++)
                {
                    sum = max(temp1[j1],temp1[j1]+sum);
                    max_sum = max(max_sum , sum);
                }
                final_sum = max(final_sum,max_sum);
            }
        }
        return final_sum;
}

// int maximumSumRectangle(int R, int C, vector<vector<int>> M) 
// {
//     int final_sum = INT_MIN ;
//     int left1final,right1final,top1final,bottom1final ;
//     int sum , start,finsih ;
//     int max_sum ;
//     vector<int> temp1 (R,0);
//     for (int left = 0; left < C; left++)
//     {
//         std::fill(temp1.begin(),temp1.end(),0);
//         for (int right = left; right < C; right++)
//         {
//             for (int i1 = 0; i1 < R; i1++)
//                 temp1[i1]+=M[i1][right];
            
            
//             //kadane logic

//             sum = 0 ; max_sum = INT_MIN;
//             finsih = -1;
//             int local_Start = 0 ;
//             for (int j1 = 0; j1 < R; j1++)
//             {
//                 sum+=temp1[j1];
//                 if(sum<0)
//                 {
//                     sum = 0;
//                     local_Start = j1+1;
//                 }
//                 else if(sum>max_sum)
//                 {
//                     max_sum = sum ;
//                     start = local_Start ;
//                     finsih = j1;
//                 }
//             }
            
//             if (finsih==-1)//negative sum ,take largest number
//             {
//                 max_sum = temp1[0];
//                 start = finsih = 0;
//                 for (int i2 = 1; i2 < R; i2++)
//                     if(temp1[i2]>max_sum)
//                     {
//                         max_sum = temp1[i2];
//                         start = finsih = i2 ;
//                     }
//             }

//             if(max_sum>final_sum)
//             {
//                 final_sum= max_sum   ;
//                 left1final = left ;
//                 right1final = right ;
//                 top1final = start ;
//                 bottom1final = finsih ;
//             }
//         }
        
//     }
//     return final_sum;
// }


int main(int argc, char const *argv[])
{
    
    return 0;
}



