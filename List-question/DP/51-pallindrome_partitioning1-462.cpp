
// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1





#include "bits/stdc++.h"

using namespace std;

//O(n^3)
// int palindromicPartition(string str)
//     {
//         int n1 = str.size() ;


//         int dp1[n1][n1] ;//if dp[i,j] is pallindrome  ::  1 represent is palindrome
//         int cuts[n1][n1] ;

//         for (int i1 = 0; i1 < n1; i1++)
//             for (int j1 = 0; j1 < n1; j1++)
//             {
//                 dp1[i1][j1] = 0 ; cuts[i1][j1] = 1;
//             }


//         for (int i1 = 0; i1 < n1; i1++)
//         {
//             dp1[i1][i1] = 1;
//             cuts[i1][i1] = 0 ;
//             if (i1<n1-1 && str[i1]==str[i1+1])
//             {
//                 cuts[i1][i1+1] = 0;
//                 dp1[i1][i1+1] = 1;
//             }
            
//         }
//         int j1 ;
//         // for each length 

//         for (int len1 = 3; len1 <=n1; len1++)
//         {
//             for (int i1 = 0; i1 < n1-len1+1; i1++) //start from i1
//             {
//                 j1 = i1+len1-1 ;
//                 if (dp1[i1+1][j1-1]&& str[i1]==str[j1])
//                 {
//                     dp1[i1][j1] = 1;
//                     cuts[i1][j1] = 0;
//                 }
//                 else
//                 {
//                     //for each length 
//                     int min_val = INT_MAX ;
//                     for (int k1 = i1; k1 <j1 ; k1++)
//                     {
//                         min_val = min(min_val,1+cuts[i1][k1]+cuts[k1+1][j1]  ) ;//1 cut i1 to k1 and k1+1 to j1
//                     }
//                     cuts[i1][j1] = min_val ;
//                 }
//             }
//         }
        


//         return cuts[0][n1-1];


//     }



//O(n^2)
int palindromicPartition(string str)
{

                int n1 = str.size() ;

        
                int dp1[n1][n1] ;//if dp[i,j] is pallindrome  ::  1 represent is palindrome
        
                for (int i1 = 0; i1 < n1; i1++)
                    for (int j1 = 0; j1 < n1; j1++)
                    {
                        dp1[i1][j1] = 0 ; 
                    }
        
        
                for (int i1 = 0; i1 < n1; i1++)
                {
                    dp1[i1][i1] = 1;
                    if (i1<n1-1 && str[i1]==str[i1+1])
                    {
                        dp1[i1][i1+1] = 1;
                    }
                } 
        
                //O(n^2) 
                int j1 ;
                // for each length 
        
                for (int len1 = 3; len1 <=n1; len1++)
                {
                    for (int i1 = 0; i1 < n1-len1+1; i1++) //start from i1
                    {
                        j1 = i1+len1-1 ;
                        if (dp1[i1+1][j1-1]==1 && (str[i1]==str[j1]))
                        {
                            dp1[i1][j1] = 1;
                        }
                    }
                }
                //GOT PALLINDROME SUBSEQUENCE//
        
                int cuts[n1] ; //cuts i represent minimum number of cuts till string[0:i]
                //O(n^2)
                // dp1[i][j] string i to j is pallindrome if dp1[i][j]==1
                for (int i1 = 0; i1 < n1; i1++)
                {
                    if (dp1[0][i1]==1)
                    {
                        cuts[i1] = 0;
                    }
                    else
                    {
                        // now find j to find the cuts[i] where j is between 0 and i 
                        cuts[i1] = INT_MAX ;
                        for (int j1 = 0; j1 < i1; j1++)
                        {
                            if (dp1[j1+1][i1]&& 1+cuts[j1]<cuts[i1]) //string[j1+1:i1] is pallindrome then use cuts[j] and add it 
                            {
                                cuts[i1] = cuts[j1]+1; //minimum number of cuts so j 
                            }
                            
                        }
                        
                    }
                    
                    
                }
                
        
            return cuts[n1-1];


}















