

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);









class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int length1 = min(A,B);
        int breadth1 = max(A,B);
        
        int length2 = min(C,D);
        int breadth2 = max(C,D);
        
        int steps = 0;
        while(!((length1<=length2)&& (breadth1<=breadth2)))
        {
            if(breadth1>breadth2)
            {
                int length1_temp = length1 ;
                length1 = min(length1 , breadth1/2);
                breadth1 = max(length1_temp , breadth1/2);
                
            }
            else 
                length1/=2 ;

            steps++ ;
        }
        
        
        return steps ;
    }
};