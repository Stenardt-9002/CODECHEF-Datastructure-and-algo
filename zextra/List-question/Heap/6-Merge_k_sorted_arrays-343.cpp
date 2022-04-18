
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




// vector<int> mergeKArrays(vector<vector<int>> arr, int K)
// {
//     //code here
//     vector<int>ans1 ;
//     for (int i1 = 0; i1 < K; i1++)
//         for (int j1 = 0; j1 < K; j1++)
//             ans1.push_back(arr[i1][j1]) ;

//     sort(ans1.begin(),ans1.end());
//     return ans1 ;
// }




vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> heap1 ;//data,array indexes , array position


    vector<int>ans1 ;
    for (int i1 = 0; i1 < K; i1++)
        heap1.push(make_tuple(arr[i1][0],i1,0));

    while (ans1.size()<K*K)
    {
        tuple<int,int,int> temp1 = heap1.top() ;
        heap1.pop();
        int data = get<0>(temp1);
        int arr_indx = get<1>(temp1);
        int index_within_arr = get<2>(temp1);
        ans1.push_back(data);
        if(index_within_arr<K-1)
            heap1.push(make_tuple(arr[arr_indx][index_within_arr+1],arr_indx,index_within_arr+1 ));

        else 
            heap1.push(make_tuple(INT_MAX,arr_indx,index_within_arr+1 ));
    }

    // sort(ans1.begin(),ans1.end());
    return ans1 ;
}




