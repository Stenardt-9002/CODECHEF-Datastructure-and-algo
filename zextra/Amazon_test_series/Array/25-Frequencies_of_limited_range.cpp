// https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0/?track=amazon-arrays&batchId=192


#include <bits/stdc++.h>
// #include<ext/pbcumu_valds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>


using namespace std;
// using namespace __gnu_pbds ;
typedef  long long ll1d;



void frequencyCount(vector<int>& arr,int N, int P)
{ 
    
    int i1 =0 ;
    for(i1= 0;i1<N;i1++)
    {
        if(arr[i1]<=N)
        {
            cout<<" "<<arr[i1]<<" "<<arr[i1]%(N+1)<<endl;
            arr[arr[i1]%(N+1)-1]+=(N+1) ;
        }
    }
    cout<<endl;
    for(i1= 0;i1<N;i1++)
    {
        cout<<arr[i1]<<" ";
    }
    
    
}



int main(int argc, char const *argv[])
{
    int n = 5 ; 
    vector<int> arr = {2,3,2,3,5};
    frequencyCount(arr,n,5);
    return 0;
}



