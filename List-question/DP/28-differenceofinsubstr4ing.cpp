

// #good question 
// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

#include "bits/stdc++.h"

using namespace std;
	int maxSubstring(string S)
	{
        int n = S.length();
        vector<int>dp1(n,0);
        for (int i1 = 0; i1 < n; i1++)
            dp1[i1] = (S[i1]=='0'?1:-1)       ;

        // /same as kadane  
        int curr_max = dp1[0];
        int global_max = dp1[0];

        for (int i1 = 1; i1 < n; i1++)
        {
            curr_max = max(curr_max+dp1[i1],dp1[i1]);
            global_max = max(global_max,curr_max);
        }
        
        return global_max;
	}

int main(int argc, char const *argv[])
{

    return 0;
}


