// https://practice.geeksforgeeks.org/problems/satisfy-the-equation5847/1









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


struct newdata 
{
    int i1,j1,data;
};

bool compare_fuc(struct newdata a1 , struct newdata b1)
{
    return a1.data<b1.data;
}

vector<int> satisfyEqn(int A[], int N) 
{
    // code here
    if(N<4)
        return {-1,-1,-1,-1};
    vector<int>ans1 = {-1,-1,-1,-1};
    vector<newdata>newvec ;
    for (int i1 = 0; i1 < N; i1++)
        for (int j1 = i1+1; j1 < N; j1++)
            newvec.push_back({i1,j1,A[i1]+A[j1]});
    

    sort(newvec.begin(),newvec.end(),compare_fuc)    ;
    int n = newvec.size();
    int first_ptr =0 ,second_ptr= 1;
    bool found_ans = false ;
    while (first_ptr<n && second_ptr<n && !found_ans)
    {
        if(newvec[first_ptr].data==newvec[second_ptr].data)
            second_ptr++;
        else 
        {
            for (int i1 = 0; i1 < count; i1++)
            {
                /* code */
            }
            
            first_ptr = second_ptr;

        }
    }
    


    return ans1 ;
}







