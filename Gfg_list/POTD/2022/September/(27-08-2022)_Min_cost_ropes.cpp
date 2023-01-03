// https://practice.geeksforgeeks.org/problems/tom-and-jerry1325/1




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

const long long int mod2 =  1e18 ;



long long minCost(long long arr[], long long n) 
{
    // Your code here
        if(n==1)
            return 0;
        multiset<long long > s1 ;
        for(int i1 = 0 ; i1<n;i1++)
            s1.insert(arr[i1]);
    
        long long ans1 = 0 ;
        while (s1.size()>1)
        {
            long long top1 = *s1.begin();
            s1.erase(s1.begin());
    
            long long top2 = *s1.begin();
            s1.erase(s1.begin());
            ans1+= top1+top2 ;
            s1.insert(top1+top2);
        }
        
        return ans1;//+*s1.begin() ;      

}






int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        long long *arr = new long long[n];
        for(ll i1 =  0 ; i1<n;i1+=1)
            cin>>arr[i1];
        cout<<minCost(arr,n)<<endl;
    }
    return 0 ;
}



















//old code 
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        // Your code here
       vector<long long> heap1 ;
        for (long long i1 = 0; i1 < n; i1++)
            heap1.push_back(arr[i1])    ;
    
    
        make_heap(heap1.begin(),heap1.end(),greater<long long>());
        // cout<<endl ;
        // for (auto x : heap1)
        //     cout<<" "    <<x ;
        // cout<<endl ;
        long long sum1 = 0,first_al=0,second_val = 0;
        while (heap1.size()!=1)
        {
            first_al = heap1.front();
            second_val = 0;
            pop_heap(heap1.begin(),heap1.end(),greater<long long>());
            heap1.pop_back();
            if(!heap1.empty())
            {
                second_val = heap1.front();
                pop_heap(heap1.begin(),heap1.end(),greater<long long>());
                heap1.pop_back();
            }
            // cout<<"BUG DE"<<first_al<<" "<<second_val<<endl;
            first_al = first_al+second_val ;
            sum1+=first_al ;
            heap1.push_back(first_al) ;
            push_heap(heap1.begin(),heap1.end(),greater<long long>());
        }
        return sum1 ;
    }
};


