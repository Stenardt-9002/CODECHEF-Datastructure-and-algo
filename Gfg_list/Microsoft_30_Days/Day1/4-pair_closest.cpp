// https://practice.geeksforgeeks.org/batch-problems/three-sum-closest/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    

int threeSumClosest(vector<int> arr, int target) 
{
    // Your code goes here
        int n = arr.size();
    int diff_ans = INT_MAX ;
    sort(arr.begin(),arr.end());
    for(int i1 = 0 ; i1<n-2 ; i1++)
    {
        int newtarget = target-arr[i1];
        int firstp = i1+1 ;
        int secondp = n-1 ;
        while(firstp<secondp)
        {
            if(abs(arr[i1]+arr[firstp]+arr[secondp]-target)<abs(diff_ans))
                diff_ans = arr[i1]+arr[firstp]+arr[secondp]-target;
            if(arr[i1]+arr[firstp]+arr[secondp]-target==abs(diff_ans) ) //take positive
                diff_ans = arr[i1]+arr[firstp]+arr[secondp]-target;
               

            if(arr[firstp]+arr[secondp]>newtarget)
                secondp-- ;
            else if(arr[firstp]+arr[secondp]<newtarget)
                firstp++ ;
            else 
                return target ;
            
 
        }
    }
    return target+diff_ans ;
    
}





int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n , target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        vector<int> array_in(n,0);
        cin>>target ;
        for(auto &x : array_in)
            cin>>x ;
        cout<<threeSumClosest(array_in,target);
    }
    return 0 ;
}











