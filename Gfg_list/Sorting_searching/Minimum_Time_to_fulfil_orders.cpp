#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

typedef  long long int lld;


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


bool ok_check(vector<int>&A , int count_limit , int time )
{
    int donut_count = 0 ;

    for(auto rank : A)
    {
        int ans = 0 ;
        int low = floor(sqrt(2*time/rank))-1;
        int high =ceil(sqrt(2*time/rank))+1;    
        while (low<=high)
        {
            int mod = low+(high-low)/2;
            int count_time = (rank*(mod+1)*mod)/2;
            if(count_time>time)
                high = mod-1 ;
            else 
            {
                ans = mod ;
                low = mod+1 ;
            }

        }
        donut_count+=ans ;
    }
    return donut_count>=count_limit ;
}


class Solution{
    public:
    int findMinTime(int N, vector<int>&A, int L)
    {
        //write your code here
        int low =1 ,high = 1e9;
        int ans = high ;
        while (low<=high)
        {
            int time = low+(high-low)/2;
            if(ok_check(A , N , time))
            {
                ans = time ; 
                high = time-1;
            }
            else 
                low = time+1 ;

        }
        return ans ;

    }
};





int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        
    }
    

    return 0;
}












