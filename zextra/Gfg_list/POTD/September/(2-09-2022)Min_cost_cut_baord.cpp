// https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        int ans1 = 0 ;

        sort(X.begin() , X.end()  , greater<int>());
        sort(Y.begin() , Y.end()  , greater<int>());


        int cnth = 1 , cntv = 1 ;
        int i1 = 0 , j1=0 ;
        while(i1< M-1 && j1<N-1)
        {
            if(X[i1]<=Y[j1])
            {
                ans1+=(Y[j1]*cnth );
                cntv++ ;
                j1++ ;

            }
            else 
            {
                ans1+=(X[i1] * cntv);
                cnth++ ;
                i1++ ;
            }
        }
        int comp1 = 0 ;
        while(i1<M-1)
            comp1+=X[i1++];
        ans1+=(comp1*cntv);

        comp1 = 0 ;
        while(j1<N-1)
            comp1+=Y[j1++];
        ans1+=(comp1*cnth);


        return ans1 ;

    }



