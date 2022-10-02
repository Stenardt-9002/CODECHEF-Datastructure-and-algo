#include "bits/stdc++.h"



using namespace std;



    int maxProfit(vector<int>& prices) 
    {
        int min1 = INT_MAX ;
        int len1 = prices.size() ;
        
        int diff = 0;
        int large_diff = 0;
        
        for(int i1 = 0 ;i1<len1 ; i1++)
        {
            if(prices[i1]<min1)
            {
                min1 = prices[i1] ;
            }
            else
            {
                diff = prices[i1]-min1 ;
            }
            
            
            if(diff>large_diff)
            {
                large_diff = diff ;
            }
        }
        
        return large_diff ;
    }


//a same but better solution 

    int maxProfit(vector<int>& prices) 
    {
        int min1 = INT_MAX ;
        int len1 = prices.size() ;
        int diff = 0;
        for(int i1 = 0 ;i1<len1 ; i1++)
        {
            min1 = min(min1 , prices[i1]);
            diff = max(diff,prices[i1]-min1) ;
        }
        return diff ;
    }







