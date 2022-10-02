#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


string longestPalindrome(string S)
{

    int n = S.length();
    int start_indx=0,length_max=1;
    vector<vector<bool>>dp1(n,vector<bool>(n,false));
    for (int i1 = 0; i1 < n; i1++)
        dp1[i1][i1]=true;
    for (int i1 = 0; i1 < n-1; i1++)
        if(S[i1]==S[i1+1])
        {
            dp1[i1][i1+1]=true;
            if(length_max<2 )
            {
            start_indx = i1 ;
            length_max = 2 ;
            }
        }

    for (int len = 2; len < n; len++)
    {
        for (int star = 0; star < n-len; star++)
        {
            int j1 = star+len;
            if(dp1[star+1][j1-1]&&(S[star]==S[j1]))
            {
                dp1[star][j1]=true ;
                if(len+1>length_max)
                {
                    length_max = len+1;
                    start_indx = star;
                }
            }
        }
    }
    if(start_indx==INT_MAX)
        return S.substr(0,1);

    return S.substr(start_indx,length_max);
    // code here 
}




int main(int argc, char const *argv[])
{
    string str = "qrqdwfca";
    cout << "\nLength is: "<<longestPalindrome(str);
    return 0;
}



