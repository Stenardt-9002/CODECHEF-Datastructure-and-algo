// https://practice.geeksforgeeks.org/problems/find-the-minimum-time0253/1/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int numberofitemintime(int s1, int s2 , int time)
{
    int n = (time/s2)+(time/s1);
    return n ;
}

int minTime(int S1, int S2, int N)
{
    // code here

    int max_one = max(S1,S2);
    int low = 1 ; int high = max_one*N;
    while(low<high)
    {
        int mid = (low+high)>>1;
        int itm = (mid/S1)+(mid/S2);
        // int itm = numberofitemintime(S1,S2,mid);
        if(itm<N)//need more time
            low = mid+1 ;
        else 
            high = mid ;
    }
    return high ;

}


