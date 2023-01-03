// https://practice.geeksforgeeks.org/problems/firing-employees5306/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


char firstRep (string s)
{
    //code here.
    vector<int> hash_char(26,0);
    int n = s.size();
    for (int i1 = 0; i1 < n; i1++)
        hash_char[s[i1]-'a']++;

    for (int i1 = 0; i1 < n; i1++)
        if(hash_char[s[i1]-'a']>1)
            return s[i1];

    return '#';
    
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tesecase ; cin>>tesecase ;
    while(tesecase--)
    {   
        int n;
        cin>>n ;
        vector<int> input1(n,0) ; 
        for (int i1 = 0; i1 < n; i1++)
            cin>>input1[i1];
        
        // cout<<firingEmployees(input1,n)<<endl;
    }
    return 0;
}