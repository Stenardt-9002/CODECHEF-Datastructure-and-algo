// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-convert-one-string-into-another-with-given-constraints4116/1







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;





int isItPossible(string S, string T, int M, int N) 
{
    // code here
    int countA = 0 , countB = 0;
    for (int i = 0; i < M; i++)
    {
        countA+=(S[i]=='A');
        countB+=(S[i]=='B');
    }    

    for (int i = 0; i < N; i++)
    {
        countA-=(T[i]=='A');
        countB-=(T[i]=='B');
    }    
    if(M!=N)
        return false ;
    if(countA!=0 && countB!=0)
        return false ;
    

// sequence and index maintenence 
    int i , j , k ;//, n = S.size();
    countA = 0 ;
    char ch ;
    vector<pair<char,int>> v1 ,v2 ;
    for ( i = 0; i < M; i++)
    {
        if(S[i]!='#')
            v1.push_back({S[i] , i});
        if(T[i]!='#')
            v1.push_back({T[i] , i});
    }
    for ( i = 0; i < v1.size(); i++)
    {
        if(v1[i].first!=v2[i].first)
            return false ;

        
        else 
        {
            if(v1[i].first =='A' )
            {
                if(v1[i].second<v2[i].second)
                    return false ;
            }
            else 
            {
                if(v1[i].second>v2[i].second)
                    return false ;
            }
        }
    }
    
    
    return true ;






}









