
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);



void vsiualise_1(deque<int> Q1)
{
    cout<<endl;
    while (!Q1.empty())
    {
        cout<<" "    <<Q1.front();
        Q1.pop_front();
    }
}




vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
{
    // your code here
    std::deque<int>deq1(k);
    vector<int> asn1;
    int i1 ;
    for ( i1 = 0; i1 < k; i1++)
    {
        while ((!deq1.empty()) && arr[i1]>=arr[deq1.back()])
            deq1.pop_back()        ;

        deq1.push_back(i1);
        // vsiualise_1(deq1);
    }
    for ( ; i1 < n; i1++)
    {
        asn1.push_back(arr[deq1.front()]);
        //remove the external length (not in k subarray)
        while((!deq1.empty()) && deq1.front()<=i1-k )
            deq1.pop_front();

        //remove sammler element
        while((!deq1.empty()) && arr[deq1.back()] <=arr[i1] )
            deq1.pop_back();

        deq1.push_back(i1);
    }
    asn1.push_back(arr[deq1.front()]);
    return asn1;  
}



int main(int argc, char const *argv[])
{
    vector<int> arr1= {12,1,78,90,57,89,56};
    max_of_subarrays(arr1,7,3);

    return 0;
}



