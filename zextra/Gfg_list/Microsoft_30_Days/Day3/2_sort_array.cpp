// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day3/problem/sort-array-after-converting-elements-to-their-squares










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


bool compare_fun(int a , int b)
{
    return a*a<b*b ;
}


vector<int> sortSquares(int A[], int arr_size)
{
    //Write your code here
    vector<int> ans1 ;
    sort(A, A+arr_size , compare_fun);
    for (int i1 = 0; i1 < arr_size; i1++)
        ans1.push_back(A[i1]);
    return ans1 ;
}