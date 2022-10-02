// https://practice.geeksforgeeks.org/problems/b6b608d4eb1c45f2b5cace77c4914f302ff0f80d/1/?page=2&curated[]=2&sortBy=submissions



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef  long long ll1d;



long long smallestpositive(vector<long long> array, int n)
{ 
    // code here 
    long long int ans1 = 1;
    sort(array.begin(),array.end());
    for(int i1 = 0 ; i1<n && array[i1]<=ans1;i1++)
        ans1+=array[i1];

    return ans1 ;
} 

int main(int argc, char const *argv[])
{
    vector<long long > a1 = {1,2,3,5};
    cout<<endl <<smallestpositive(a1,3)<<endl;

    return 0;
}

