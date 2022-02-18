
// https://practice.geeksforgeeks.org/problems/word-break1352/1


#include "bits/stdc++.h"

using namespace std;




bool matchwordfromdick(string word , vector<string> &B)
{
    int size1 = B.size() ;
    for (int i1 = 0; i1 < size1; i1++)
    {
        if(B[i1].compare(word)==0)
        {
            return true ; // match word
        }
    }
    return false ; 
    
}



int wordBreak(string A, vector<string> &B) 
{




            int n = A.size() ;
            if(n==0){return 1;} //all match
    
            for(int i1 = 1; i1 <= n; i1++)
            {
                if(matchwordfromdick(A.substr(0,i1),B) && wordBreak(A.substr(i1,n-i1),B))
                {
                    return true;
                }
            }        
            return false ;
        
        










    // int n = A.size() ;
    // if(n==0){return 1;} //all match
    // int dp1[n+1] ;
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     dp1[i1] = 0;
    // }
    
    // for (int i1 = 1; i1 <=n; i1++) //size of length of words 
    // {
        
    //     if (dp1[i1]==false && matchwordfromdick(A.substr(0,i1),B))
    //     {
    //         dp1[i1] = true ;
    //     }
        
    //     if (dp1[i1])
    //     {
    //         if (i1==n)
    //         {
    //             return 1 ;///if length of n word are matchd in subtring
    //         }

    //         for (int j1 = i1+1; j1 <=n; j1++)
    //         {
    //             if (!dp1[j1] && matchwordfromdick(A.substr(i1,j1-i1),B )) ; //i1 to j1 || 0 to i1
    //             {
    //                 dp1[j1] = true;
    //             }
    //             //done with all strings
    //             if (i1==n&&dp1[i1])
    //             {
    //                 return 1;
    //             }
    //         }
    //     }
    // }
    // return 0 ;
}






