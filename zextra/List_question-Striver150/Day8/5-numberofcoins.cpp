// O(mv)

// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/

// https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8

// https://www.youtube.com/watch?v=Xb4slcp1U38&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=30
// https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35
// https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39

// https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=38
// https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34

// https://www.youtube.com/watch?v=LBVsXSMOIk4&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=33






// https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/
// https://www.geeksforgeeks.org/recursive-program-to-print-all-subsets-with-given-sum/
// https://www.geeksforgeeks.org/gate-cs-notes-gq/
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/?ref=leftbar-rightbar
// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/?ref=lbp
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// https://www.geeksforgeeks.org/min-cost-path-dp-6/?ref=lbp
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/?ref=lbp


// https://www.geeksforgeeks.org/program-nth-catalan-number/
// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/?ref=lbp
// https://en.wikipedia.org/wiki/Catalan_number
// https://en.wikipedia.org/wiki/Bell_number
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/?ref=lbp
// https://www.geeksforgeeks.org/friends-pairing-problem/





https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=56
https://www.geeksforgeeks.org/permutations-of-a-given-string-using-stl/
https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/?ref=lbp
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
https://www.youtube.com/watch?v=b7AYbpM5YrE
https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=55
https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=6
https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/?ref=lbp
https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/?ref=lbp
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
https://www.geeksforgeeks.org/recursive-program-to-print-all-subsets-with-given-sum/?ref=lbp

https://www.geeksforgeeks.org/print-sums-subsets-given-set/










// my appoach





#include "bits/stdc++.h"

using namespace std;

int minCoins(int coins[], int M, int V) 
{ 
	        //min
    int *dp1 = new int[V+1];
    for (int i1 = 0; i1 <= V; i1++)
        dp1[i1] = -1;//init
    
    //all coins 
    for (auto i1 =0 ; i1<M;i1++)
    {
        if (coins[i1]<=V)
        {
            dp1[coins[i1]] = 1;//one coin present 
        }
    }
    //for all values
    int min1 = INT_MAX ;
    for (int i1 = 1; i1 <= V; i1++)
    {
        min1 = INT_MAX ;

        //all coins traersal
        for (int j1 = 0; j1 < M; j1++)
        {
            //all coins 
            if ( (i1-coins[j1])>0&&dp1[i1-coins[j1]]!=-1  &&min1>dp1[i1-coins[j1]]+1   )
            {
                min1 = dp1[i1-coins[j1]]+1;
            }
      
        }
        if (min1!=INT_MAX&&(min1<dp1[i1]||dp1[i1]==-1) )
        {
            dp1[i1] = min1 ;    
        }
        
        
        
    }
    

cout<<endl;
    for (int i1 = 0; i1 < V+1; i1++)
    {
        cout<<" "<<dp1[i1];
    }
    
cout<<endl;



    // delete []dp1;
    return dp1[V];
} 
    

int main(int argc, char const *argv[])
{
    int V ;
    cin>>V;
    int M ; 
    cin>>M;


    int *coints = new int[M];


    for (auto i1 = 0; i1 < M; i1++)
    {
        cin>>coints[i1];
    }
    cout<<minCoins(coints,M,V);




    return 0;
}







