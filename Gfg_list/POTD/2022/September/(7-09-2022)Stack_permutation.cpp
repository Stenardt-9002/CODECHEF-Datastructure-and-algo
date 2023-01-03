// https://practice.geeksforgeeks.org/problems/stack-permutations/1


// https://leetcode.com/problems/validate-stack-sequences/submissions/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//better 
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i1 = 0 ,j1 =0 , N = pushed.size();
        stack<int> s1 ;
        if(pushed.size() != popped.size())
            return false ;
    
        while(i1<N && j1<N)
        {
            int curele = pushed[i1++];
            if(curele == popped[j1])
            {
                j1++ ;
                while(!s1.empty() && j1<N && s1.top()==popped[j1])
                {
                    s1.pop();
                    j1++ ;
                    
                }
                
            }
            
            else 
                s1.push(curele);
        }
        
        return (i1==N)&&s1.empty();
        
    }

int isStackPermutation(int N,vector<int> &A,vector<int> &B)
{
    //check if two 
    int i1 = 0 ,j1=0 ;
    stack<int> s1 ;
    while(i1<N && j1<N)
    {
        int curele = A[i1] ;
        i1++ ;
        if(curele == B[j1])
        {
            j1++ ;
            while(!s1.empty())
            {
                if(s1.top()==B[j1])
                {
                    j1++ ;
                    s1.pop();
                }
                else 
                    break ;
            }
        }
        else 
            s1.push(curele);
    }
    return (i1==N)&&(s1.empty());
}












