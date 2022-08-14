
// https://practice.geeksforgeeks.org/batch-problems/count-distinct-elements-in-every-window/0/?track=microsoft-29days-day2&batchId=636


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



vector <int> countDistinct (int A[], int n, int k)
{
    unordered_map<int , int > map1 ;
    int idividual_counter = 0 ;
    for (int i1 = 0; i1 < k; i1++)
        if(map1.find(A[i1])==map1.end()||map1[A[i1]]== 0)
        {
            map1[A[i1]]=1 ;
            idividual_counter++ ;
        }
        else 
            map1[A[i1]]++ ;

    vector<int>ans1 ;
    ans1.push_back(idividual_counter);
    for (int i1 = k; i1 < n; i1++)
    {
        //include i1
        if(map1.find(A[i1])==map1.end()|| map1[A[i1]]== 0)
        {
            map1[A[i1]]=1 ;
            idividual_counter++ ;
        }
        else 
            map1[A[i1]]++ ;

        //exclude i1-k
        if(--map1[A[i1-k]]==0)        
            idividual_counter-- ;
        
        ans1.push_back(idividual_counter);
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
    int n , k;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        int *array_in = new int[n];
        cin>>k ;
        for(int i1 = 0 ; i1<n;i1++)
            cin>>array_in[i1] ;
        vector<int>in = countDistinct(array_in,n,k);
        for(auto vec : in)
            cout<<vec<<" ";

        cout<<endl ;
    }
    return 0 ;
}








