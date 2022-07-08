
// https://practice.geeksforgeeks.org/problems/x-xor-a-is-minimum-and-set-bits-in-x-b/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






int minVal(int a, int b) 
{
    // code here
    // minimisze X xor A 


    int nosetbitsinb = __builtin_popcount(b) ;
    vector<short int> ans1;
    stack<short int> s1 ;  //bin repre of a 

    while (a>0)
    {
        s1.push(a%2);
        a/=2 ;
    }
    //start from msb
    while(!s1.empty())
    {
        if(s1.top()==1 && nosetbitsinb>0)
        {
            ans1.push_back(1);
            nosetbitsinb-- ;
        }
        else 
            ans1.push_back(0);//where not 1 be zero to minimise the msb
        s1.pop();
    }

    for(int i1 = ans1.size()-1;i1>=0&& nosetbitsinb>0;i1--)
        if(ans1[i1]==0)//no set and is least significant
        {
            ans1[i1] = 1;
            nosetbitsinb--;
        }

    int final_ans = 0,power = 0;
    for(int i1=ans1.size()-1;i1>=0;i1--)
    {
        power = 1<<(ans1.size()-1-i1);
        final_ans+=(ans1[i1]*power);
    }

    //if still bits are left add them to msb
    power = ans1.size();
    while(nosetbitsinb>0)
    {
        final_ans+=(1<<power);
        power++ ; nosetbitsinb--;
    }

    return final_ans ;

}