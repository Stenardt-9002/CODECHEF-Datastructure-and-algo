
#include <bits/stdc++.h>
using namespace std;


    bool palindrome_check(string s,int start,int end)
    {
        while(start<=end)        
        {
            if (s[start++]!=s[end--])
            {
                return false ;
            }

        }
        return true ;
    }

public:
    
    void recur1sive(int ind ,string s,vector<vector<string>>&ans,vector<string>&ds1)
    {
        
        
        if(ind==s.size())
        {
            ans.push_back(ds1);
            return ;
        }
        
        //each len sbstring 
        for(int i=ind;i<s.size();i++)
        if(palindrome_check(s,ind,i)) //previous string partition is palindrome then only
        {
            ds1.push_back(s.substr(ind,i-ind+1)); //substring to be inserted for new partion ind to i length and is already a palindrome
            recur1sive(i+1,s,ans,ds1);
            ds1.pop_back();//if not
        }
    }
    
    
    
    vector<vector<string>> partition(string s) 
    {
        
        vector<vector<string>> ans    ;
        vector<string>ds1 ; // list of palindrome substrings
        recur1sive(0,s,ans,ds1);
        
        
        return ans ;    
    }



