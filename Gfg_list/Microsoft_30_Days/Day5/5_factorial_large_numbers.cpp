// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/problem/factorials-of-large-numbers2508






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




class Solution {
public:


    
    static vector<int> multiple(vector<int>a1 , int b1)
    {
        int carry=0 ,val ;
        int n = a1.size();
        vector<int> ans1 ;
        reverse(a1.begin(),a1.end());
    
    
    
        for (int i1 = 0; i1 < n; i1++)
        {
          val = (a1[i1]*b1)+carry;
          carry = val/10 ;
          val = val%10 ;
          // cout<<endl<<val<<" "<<a1[i1]<<" "<<b1[i1]<<endl;
          ans1.push_back(val);
        }
    
        while(carry!=0)
        {
          ans1.push_back(carry%10);
          carry/=10;
        }
        reverse(ans1.begin(),ans1.end());
        return ans1;
    }



    vector<int> factorial(int N)
    {
        // code here
        if(N==0||N==1)  return {1} ;
        std::vector<int> nthfact = {1};
        for (int i1 = 2; i1 <=N; i1++)
          nthfact = multiple(nthfact,i1);

        return nthfact ;

    }
};