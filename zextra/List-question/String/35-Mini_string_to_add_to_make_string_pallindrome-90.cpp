#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);



vector<int> get_lps(string str)
{
    int n = str.length();
    vector<int> lps(n,0);
    int len1 = 0;
    int i1 = 1 ;//start from 1 0 is always 0


    while (i1<n)
    {
        if(str[i1]==str[len1])
            lps[i1++] = ++len1;

        else
        {
            if(len1!=0)
                len1 = lps[len1-1];
            else 
                lps[i1++] = 0;
        }
    }
    return lps ;
}


int get_count_ofchar_to_add_inlineartime(string str)
{
    string revser_str  = str ;
    reverse(revser_str.begin(),revser_str.end());
    string todeal_with = str+"$"+revser_str;

    vector<int> lps = get_lps(todeal_with);
    return (str.length()-lps.back());
}


int main(int argc, char const *argv[])
{
    string str ;
    cin>>str;
    cout<<get_count_ofchar_to_add_inlineartime(str);
    
    return 0;
}
