// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day5/video/NjQwNg%3D%3D









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


// string addBinary(string A, string B)
// {
//     // your code here
//     int n = A.size();
//     int m = B.size();
//     string ans1 = "";
//     int carry = 0 ;
//     while (--n && --m)
//     {
//         int sum1 = (A[n]-'0')^(B[m]-'0')^carry;
//         carry = (A[n]-'0')&&(B[m]-'0')|carry&&(B[m]-'0')|(A[n]-'0')&&carry;
//         char an = sum1+'0' ;
//         ans1 = an+ans1 ;
//     }

//     while (--n)
//     {
//         int sum1 = (A[n]-'0')^carry;
//         carry = (A[n]-'0')&&carry;
//         char an = sum1+'0' ;
//         ans1 = an+ans1 ;
//     }
    
    
//     while (--m)
//     {
//         int sum1 = (B[m]-'0')^carry;
//         carry = carry&&(B[m]-'0');
//         char an = sum1+'0' ;
//         ans1 = an+ans1 ;
//     }
//     if(carry==1)
//         ans1 = "1"+ans1 ;

//     return ans1 ;
// }





	string addBinary(string A, string B)
	{
	    // your code here
        int n = A.size()-1;
        int m = B.size()-1;
        string ans1 = "";
        int carry = 0 ;
        while (n>=0 && m>=0)
        {
            char a = A[n];
            char b = B[m];
            int sum1 = (a-'0')^(b-'0')^carry;
            carry = ((a-'0')&&(b-'0'))|(carry&&(b-'0'))|((a-'0')&&carry);
            char an = sum1+'0' ;
            ans1 = an+ans1 ;
            n--; m-- ;
        }
    
        while (n>=0)
        {
            char a = A[n];

            int sum1 = (a-'0')^carry;
            carry = (a-'0')&&carry;
            char an = sum1+'0' ;
            ans1 = an+ans1 ;
            n--;
        }
        
        
        while (m>=0)
        {
            char b = B[m];

            int sum1 = (b-'0')^carry;
            carry = carry&&(b-'0');
            char an = sum1+'0' ;
            ans1 = an+ans1 ;
            m--;
        }
        if(carry==1)
            ans1 = "1"+ans1 ;
        
        int ind = 0 ;
        while(ind<ans1.size()&&ans1[ind]=='0')
            ind++ ;
        if(ind==ans1.size())
            return "0";
        ans1 = ans1.substr(ind,ans1.size()-ind);
        return ans1 ;
	}


//more optimised 
	string addBinary(string A, string B)
	{
	    // your code here
        int n = A.size();
        int m = B.size();
        // A should be greater 
        if(n<m)
            return addBinary(B,A);
        string ans1 = "";
        // padding in B ;
        string padding = "";
        for (int i1 = 0; i1 < n-m; i1++)
            padding+="0";
        B = padding+B ;

        int carry = 0 ;
        n-- ;
        while (n>=0)
        {
            char a = A[n];
            char b = B[n];
            char an  ;
            if(a=='1' && b=='1' )
            {
                if(carry = 1)
                    an = '1' , carry = 1 ;
                else 
                    an = '0' , carry = 1;
            }
            else if(a=='0' && b=='0' )
            {
                if(carry = 1)
                    an = '1' , carry = 0 ;
                else 
                    an = '0' , carry = 0;
            }
            else 
            {
                if(carry==1)
                    an = '0',carry = 1;
                else 
                    an = '1',carry = 0;
            }
            // int sum1 = (a-'0')^(b-'0')^carry;
            // carry = ((a-'0')&&(b-'0'))|(carry&&(b-'0'))|((a-'0')&&carry);
            // char an = sum1+'0' ;
            ans1 = an+ans1 ;
            n--;
        }
    

        if(carry==1)
            ans1 = "1"+ans1 ;
        
        int ind = 0 ;
        while(ind<ans1.size()&&ans1[ind]=='0')
            ind++ ;
        if(ind==ans1.size())
            return "0";
        ans1 = ans1.substr(ind);
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
    ll n ;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        string a , b;
        cin>>a>>b ;
        cout<<addBinary(a,b);
        cout<<endl ;
    }
    return 0 ;
}

