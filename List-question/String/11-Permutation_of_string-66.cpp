// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;

void permute1(string s1 , int l , int r , set<string> &sety1)
{
    if (l==r)
        sety1.insert(s1)     ;

    for (int i1 = l; i1 <=r; i1++)
    {
        swap(s1[l],s1[i1]) ;
        permute1(s1,l+1,r,sety1);
        swap(s1[l],s1[i1]) ;
    }
}

vector<string>find_permutation(string S)
{
    // Code here there
    int n = S.length();
    vector<string> ans1 ;
    set<string> s1 ;
    permute1(S,0,n-1,s1) ;
    for (auto  x:s1)
        ans1.push_back(x);

    return ans1 ;
}

int main(int argc, char const *argv[])
{
    string s1 = "ABC" ;
    vector<string> se1 = find_permutation(s1);
    cout<<endl;
    for (auto x : se1)
    {
        cout<<" "<<x ;
    }
    
    return 0;
}






