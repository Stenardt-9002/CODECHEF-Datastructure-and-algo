// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




int minimumNumberOfSwaps(string S)
{
    // code here 

    int countL = 0,countR= 0 ;
    int swap1count = 0 ,diference1 = 0 ;
    int n = S.length();
    for (int i1 = 0; i1 < n; i1++)
    {
        if(S[i1]=='[')
        {
            countL++ ;
            if(diference1>0)
            {
                swap1count+=diference1 ;
                diference1--;
            }
        }
        else if(S[i1]==']')
        {
            countR++ ;
            diference1 = (countR-countL) ;
        }
    }
    return swap1count ;
}





int main(int argc, char const *argv[])
{
    
    return 0;
}







