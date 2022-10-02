
// https://leetcode.com/problems/longest-palindromic-substring/





#include "bits/stdc++.h"

using namespace std;

    string longestPalindrome(string s) 
    {
        // TC = O(n^2) Space = O(n^2)
        // using DP 
        // int curentlength ;
        int n = s.length();
        if(n==1){return s;}
        int length_substring_palindrome =1;
        int tart = 0;
        // string asn1 = "";
        string final_ans = "";
        bool dp1[n][n] ; 
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                dp1[i1][j1] = false ;
            }
        }
        
        for (int i1 = 0; i1 < n; i1++)
        {
            dp1[i1][i1] = true;
            if (i1<n-1&&s[i1]==s[i1+1])
            {
                dp1[i1][i1+1] = true;
                if (length_substring_palindrome!=2)
                {
                    length_substring_palindrome =2 ;
                    tart = i1;
                }
                
            }
            
        }
        int j1 ;
        // i1 start and length of string eachlen
        for (int eachlen = 3; eachlen <=n; eachlen++)
        {
            for (int i1 = 0; i1 < n-eachlen+1; i1++)
            {
                j1 = i1+eachlen-1;
                if(dp1[i1+1][j1-1]&&s[i1]==s[j1])
                {
                    dp1[i1][j1] = true ;
                    if(length_substring_palindrome<eachlen)
                    {
                        length_substring_palindrome = eachlen ; tart = i1 ;
                    }
                }
                

            }
            
        }
        if (length_substring_palindrome ==1)
        {
            tart = 0;
        }
        
        return s.substr(tart,length_substring_palindrome);




        // O(n^2) did not work




        //       int gofurther ,gobeyond,curentlength ;
        // int length_substring_palindrome =1;
        // string asn1 = "";
        // string final_ans = "";
        // int n = s.length();
        // if(n==1){return s;}
        // for (int i1 = 0; i1 < n-1; i1++)
        // {
        //     if (s[i1]==s[i1+1])
        //     {
        //         gofurther = i1+1 ;
        //         gobeyond = i1;
        //         curentlength = 2;
        //         // asn1 = s[i1]+s[i1+1];
        //         asn1 = s.substr(i1,2);
        //         while (++gofurther<n && --gobeyond>=0 &&s[gofurther]==s[gobeyond])
        //         {
        //             curentlength+=2;
        //             asn1 = s.substr(gobeyond,curentlength);
        //         }
        //         if (curentlength>length_substring_palindrome)
        //         {
        //             length_substring_palindrome=curentlength;
        //             final_ans = asn1 ;

        //         }
                
        //     }
        //     if (i1+2<n && s[i1]==s[i1+2])   
        //     {
        //         gofurther = i1+2 ;
        //         gobeyond = i1;
        //         curentlength = 3;
        //         // asn1 = s[i1]+s[i1+1]+s[i1+2];
        //         asn1 = s.substr(i1,3);

        //         while (++gofurther<n && --gobeyond>=0 &&s[gofurther]==s[gobeyond])
        //         {
        //             curentlength+=2;
        //             asn1 = s.substr(gobeyond,curentlength);
        //         }
        //         if (curentlength>length_substring_palindrome)
        //         {
        //             length_substring_palindrome=curentlength;
        //             final_ans = asn1 ;
        //         }
        //     }
        // }
        // // cout<<length_substring_palindrome<<endl;
        // if(length_substring_palindrome==1){final_ans = s[0];}
        // return final_ans;

    }


int main(int argc, char const *argv[])
{
    string s1 ;
    cin>>s1 ;
    cout<<longestPalindrome(s1);
    return 0;
}





