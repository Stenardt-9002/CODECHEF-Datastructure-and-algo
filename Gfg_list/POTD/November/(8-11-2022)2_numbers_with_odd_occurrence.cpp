
// https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;




    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        set<long long int> s1 ;
        for(auto i1 = 0 ;i1<N;i1++)
            if(s1.find(Arr[i1])==s1.end())
                s1.insert(Arr[i1]);
            else 
                s1.erase(Arr[i1]);
        
        return {*(--s1.end()),*(s1.begin())};
    }









    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        ll xor_bit = 0,part1=0,part2=0 ;
        ll set_bit ,i1=0;

        for (i1 = 0; i1 < N; i1++)
            xor_bit^=Arr[i1];
        

        set_bit = xor_bit&(~(xor_bit-1));

        for (i1 = 0; i1 < N; i1++)
            if(Arr[i1]&set_bit)
                part1^=Arr[i1];
            else 
                part2^=Arr[i1];

        vector<ll> ans1 = {part1,part2}        ;
        if(ans1[0]<ans1[1])
            reverse(ans1.begin(),ans1.end());
        return ans1 ;
    }


