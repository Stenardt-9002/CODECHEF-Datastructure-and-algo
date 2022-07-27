// https://practice.geeksforgeeks.org/problems/adding-array-element4756/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


int minOperations(int arr[], int n, int k) 
{
    // code here
    priority_queue<int, vector<int>, greater<int>> heap1 ;
    for (int i1 = 0; i1 < n; i1++)
        heap1.push(arr[i1])    ;

    int top1 = heap1.top();
    if(top1>=k)
        return 0 ;
    int ans1 = 1 ;
    heap1.pop();
    int top2 = heap1.top();
    // cout<<"\nDEBUG "<<top1+top2 <<endl;
    heap1.pop();

    heap1.push(top1+top2);
    while(heap1.size()!=1 && !heap1.empty())
    {
        top1 = heap1.top();
        if(top1>=k)
            return ans1 ;
        heap1.pop();
        // top2 = 0 ;
        // if(!heap1.empty())
        top2 = heap1.top() ;
        heap1.pop();

        heap1.push(top1+top2);
        ans1++ ;
    }
    return ans1 ;
}


int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tesecase ; cin>>tesecase ;
    while(tesecase--)
    {   
    int n ,k;
    cin>>n>>k;
    int *arr1 = new int[n];
    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1]    ;

    cout<<" "<<minOperations(arr1,n,k);
    cout<<"\n";
    }
    return 0;
}


