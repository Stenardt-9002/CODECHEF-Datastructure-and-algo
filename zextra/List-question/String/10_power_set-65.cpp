// https://www.geeksforgeeks.org/power-set/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;


vector<string> AllPossibleStrings(string s)
{
    // set<string> s1 ;
    vector<string> ans2 ;

    int n = s.length();
    int set_size1 = pow(2,n);
    for ( int counter = 1;  counter<set_size1 ;counter++ )
    {
        string ans1 = "";
        for (int j1 = 0; j1 < n; j1++)
        {
            if (counter & (1<<j1))
                ans1+=s[j1]            ;
        }
        if(ans1!="")
        ans2.push_back(ans1);
    }

    cout<<endl;
    // sort(ans2.begin(),ans2.end());
    for (auto x : ans2)
        cout<<","<<x;
        // ans2.push_back(x);

    return ans2 ;
    // Code here
}

int main(int argc, char const *argv[])
{
    string a1 = "abc";
    AllPossibleStrings(a1) ;

    return 0;
}





