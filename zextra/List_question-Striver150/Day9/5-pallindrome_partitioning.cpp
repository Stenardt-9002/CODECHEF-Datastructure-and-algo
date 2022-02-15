
#include <bits/stdc++.h>
using namespace std;



bool palindrome_check(string s)
{
    int dize= s.length();
    for (int i1 = 0; i1 < dize/2; i1++)
    {
        if (s[i1]!=s[dize-i1])
        {
            return false ;
        }
        
    }
    return true ;
}

    
    
    vector<vector<string>> partition(string s) 
    {
    // #NUMBER OF SUBSTRINGS N(N+1)/2

        vector<vector<string>> ans    ;
        int dize = s.length() ;
        for (int i1 = 0; i1 < dize-1; i1++)
        {
            string tem1p = "";
            for (int k1 = i1; k1 < dize; k1++)
            {
                tem1p+=s[k1];
                if (palindrome_check(tem1p))
                {   
                    vector<string> ds1(tem1p.begin(),tem1p.end()); 
                    ans.push_back(ds1);
                }
            }
        }
        return ans ;
    }





int main(int argc, char const *argv[])
{
    
    return 0;
}



