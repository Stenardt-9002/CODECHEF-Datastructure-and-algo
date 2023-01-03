// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



void rearrange(int arr[], int n) 
{
    // code here
    int i1 ;
    vector<int> positive, negative ;
    for (i1 = 0; i1 < n; i1++)
        if(arr[i1]<0)
            negative.emplace_back(arr[i1]);
        else 
            positive.emplace_back(arr[i1]);


    bool poisitve_turn = true ;
    i1 = 0 ;
    int last_pos = -1 ;
    int pos_itr = 0 ,neg_itr = 0 ;
    while(i1<n)
    {
        if(poisitve_turn)
        {
            if(positive.size()==pos_itr)
            {
                last_pos = i1 ;
                i1 = n ;//break loop
            }
            else 
            {
                arr[i1++] = positive[pos_itr++];
                poisitve_turn =!poisitve_turn ;
            }
        }
        else 
        {
            if(negative.size()==neg_itr)
            {
                last_pos = i1 ;
                i1 = n ;//break loop
            }
            else 
            {
                arr[i1++] = negative[neg_itr++];
                poisitve_turn =!poisitve_turn ;
            }
        }
    }
    while(neg_itr<negative.size())    
        arr[last_pos++] = negative[neg_itr++];

    while(pos_itr<positive.size())    
        arr[last_pos++] = positive[pos_itr++];

        
}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,m;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n ;
        int *ar1 = new int[n]   ;
        for (int i1 = 0; i1 < n; i1++)
            cin>>ar1[i1];
        rearrange(ar1 , n);
        for(int i1 = 0 ;i1 <n ;i1++)
            cout<<ar1[i1]<<" " ; 
        cout<<endl;
    }
    return 0 ;
}





