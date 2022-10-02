// https://practice.geeksforgeeks.org/batch-problems/find-all-four-sum-numbers1732/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Newstruc
{
    int i1 , j1, sum ;    
};


bool compardre_fuc(Newstruc a1 , Newstruc b1)
{
    return a1.sum<b1.sum ;
}

bool no_common(Newstruc a1 , Newstruc b1)
{
    if(a1.i1 == b1.i1 || a1.i1 == b1.j1 || a1.j1 == b1.i1 || a1.j1 == b1.j1)
        return false;
    return true;
}

vector<vector<int> > fourSum(vector<int> &arr, int k) 
{
    // Your code goes here
    int n = arr.size();
    vector<vector<int>> ans1 ;
    set<multiset<int>> ans12  ;
    sort(arr.begin(),arr.end());
    for (int i1 = 0; i1 < n-3; i1++)
        for (int j1 = i1+1; j1 < n-2; j1++)
        {
            int firstptr = j1+1 ;
            int secondpt = n-1;
            while(firstptr<secondpt)
            {
                if(arr[firstptr]+arr[secondpt]==k-arr[i1]-arr[j1])
                {
                    multiset<int> var = {arr[i1],arr[j1] ,arr[firstptr],arr[secondpt]};
                    ans12.insert(var);
                    firstptr++ ;
                    secondpt--;
                }
                else if(arr[firstptr]+arr[secondpt]<k-arr[i1]-arr[j1])
                    firstptr++ ;
                else 
                    secondpt--;
            }
        }
    for(auto x : ans12)
        {
            vector<int> temp ;
            for(auto ele: x)
                temp.push_back(ele);
            ans1.push_back(temp);
        }
    return ans1 ;
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
        vector<vector<int>>in = fourSum(array_in,target);
        for(auto vec : in)
        {
            for(auto x:vec)
                cout<<x<<" ";
            cout<<endl ;
        }
        cout<<endl ;
    }
    return 0 ;
}








