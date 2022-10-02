// // https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
// #include <bits/stdc++.h>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>


// using namespace std;
// using namespace __gnu_pbds ;
// typedef  long long int ll;



// struct Node_v
// {
//     int data ;
//     int set_bit ;
// };


// bool compare_1(Node_v a1 , Node_v b1)
// {
//     return a1.set_bit>b1.set_bit;
// }

// int fuc_val(int val)
// {
//     int ans1 = 0 ;
//     while (val!=0)
//     {
//         ans1+=(val%2);
//         val/=2 ;
//     }
//     return ans1 ;
// }



// void sortBySetBitCount(int arr[], int n)
// {
//     // Your code goes here

//     vector<Node_v> set_bist;
//     // cout<<endl ;
//     Node_v intup ;
//     for (int i1 = 0; i1 < n; i1++)
//     {
//         intup.data = arr[i1];
//         intup.set_bit = fuc_val(arr[i1]);
//         set_bist.push_back(intup);
//     }
//     sort(set_bist.begin(),set_bist.end() , compare_1);
//     for (int i1 = 0; i1 < n; i1++)
//         arr[i1] = set_bist[i1].data;
// }
// int main(int argc, char const *argv[])
// {
//     // int arr1[] = {1,2,3,4,5,6};
//     int n ;cin>>n ;
//     int *arr1 = new int[n];
//     for (int i1 = 0; i1 < n; i1++)
//         cin>>arr1[i1];
    
//     // int arr1[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
//     // int n = sizeof(arr1)/sizeof(arr1[0]);
//     sortBySetBitCount(arr1,n);
//     cout<<endl ;
//     for (int i1 = 0; i1 < n; i1++)
//         cout<<" "<<arr1[i1];
//     return 0;
// }




// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;


int fuc_val(int val)
{


    int ans1 = 0 ;
    while (val)
    {
        ans1+=(val&1);
        val = val>>1 ;
    }
    return ans1 ;
}

bool compare_1(int a1 , int b1)
{
    int set_bist1 = fuc_val(a1);
    int set_bist2 = fuc_val(b1);
    if(set_bist1<=set_bist2)
        return false ;
    return true ;
}





void sortBySetBitCount(int arr[], int n)
{
    // Your code goes here

    stable_sort(arr,arr+n,compare_1);
}
int main(int argc, char const *argv[])
{
    // int arr1[] = {1,2,3,4,5,6};
    int n ;cin>>n ;
    int *arr1 = new int[n];
    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1];
    
    // int arr1[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    sortBySetBitCount(arr1,n);
    cout<<endl ;
    for (int i1 = 0; i1 < n; i1++)
        cout<<" "<<arr1[i1];
    return 0;
}



