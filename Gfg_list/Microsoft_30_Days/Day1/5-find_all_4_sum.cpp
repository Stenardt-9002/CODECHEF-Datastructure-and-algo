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
    int size1 = n*(n-1)/2;
    vector<Newstruc> arr_in(size1);
    set<multiset<int>> ans1 ;
    int k1 = 0 ;
    for (int i1 = 0; i1 < n-1; i1++)
        for (int j1 = i1+1; j1 < n; j1++)
            {
                arr_in[k1].sum = arr[i1]+arr[j1];
                arr_in[k1].i1 = i1 ;
                arr_in[k1].j1 = j1 ;
                k1++ ;
            }


    sort(arr_in.begin(),arr_in.end(),compardre_fuc);

    int i1 = 0 , j1 = size1-1;
    while (i1<j1)
    {
        if(arr_in[i1].sum+arr_in[j1].sum>k)
            j1-- ;
        else if(arr_in[i1].sum+arr_in[j1].sum<k)
            i1++ ;
        else     
        {
            if(no_common(arr_in[i1],arr_in[j1]))
            {
                multiset<int> var = {arr[arr_in[i1].i1],arr[arr_in[i1].j1],arr[arr_in[j1].i1] , arr[arr_in[j1].j1] };
                ans1.insert(var);
            }
            // ans1.insert({arr_in[arr_in[i1].i1]});
            do
                i1++;                
            while(i1+1<size1 && arr_in[i1].sum==arr_in[i1+1].sum);
            do
                j1--;                
            while(j1+1<size1 && arr_in[j1].sum==arr_in[j1+1].sum);
        }
    }
    
    vector<vector<int>> ans2 ;
    for(auto x : ans1)
        {
            vector<int> temp ;
            for(auto ele: x)
                temp.push_back(ele);
            ans2.push_back(temp);
        }
    return ans2 ;

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








