// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day6/video/NjM5Mw%3D%3D





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


string add_two_String(string a , string b)
{
    int n = a.length() ;
    int m = b.length();
    if(n<m)
        return add_two_String(b,a);
    string ans1 = "";

    for (int i1 = 0; i1 < n-m; i1++)
        b = "0"+b ;
    int i = n-1 ;
    int carry = 0 ;
    while (i>=0)
    {
        int val = (a[i]-'0')+(b[i]-'0')+carry ;
        carry = val/10 ;
        char curval = (val%10)+'0' ;
        ans1 = (curval)+ans1 ;
        i-- ;
    }
    if(carry!=0)
        ans1="1"+ans1 ;
    return ans1 ;
}
string mutilply_char(string a , char b1)
{
    int n = a.length() ;

    string ans1 = "";
    int b = b1-'0';
    int i =0 ;
    int carry = 0 ;
    reverse(a.begin(),a.end());
    while (i<n)
    {
        int val = ((a[i]-'0')*b) +carry ;
        // cout<<"\n DEUG1 "<<val<<" "<<(a[i]-'0')<<" "<<b<<endl ;
        carry = val/10 ;
        val%=10 ;
        char curval = val+'0' ;
        ans1 = (curval)+ans1 ;
        i++ ;
    }
    while(carry!=0)
    {
        int val = carry%10 ;
        char curval = val+'0';
        ans1=curval+ans1 ;
        carry/=10 ;
    }
    return ans1 ;
}

string multiplyStrings(string s1, string s2) 
{
    //Your code here
    int n = s1.length();
    int m = s2.length() ; 
    if(n<m)
        return multiplyStrings(s2,s1);
    
    bool pos = true ;

    if(s1[0]=='-')
    {
        s1 = s1.substr(1 , s1.size()-1);
        pos = !pos ;
    }
    // cout<<"\nDEUG1 = "<<s1<<" "<<pos <<" ";

    if(s2[0]=='-')
    {
        s2 = s2.substr(1 , s2.size()-1);
        pos = !pos ;
    }

    // cout<<"\nDEUG1 = "<<s2<<" "<<pos <<" ";
    n = s1.length();
    m = s2.length() ; 
    int i = m-1; ;
    string ans1 = "0";
    int powerof10 = 0 ;
    while (i>=0) 
    {
        char multiply = s2[i] ;
        string reality_mul = mutilply_char(s1 , multiply);
        for (int i1 = 0; i1 < powerof10; i1++)
            reality_mul +="0";
        
        ans1 = add_two_String(ans1 , reality_mul);
        i-- ;
        powerof10++ ;
    }
    int i1 =0 , ans1size = ans1.size();
    while(i1<ans1size && ans1[i1]=='0')
        i1++  ;    
    if(i1==ans1size)
        return "0" ;
    ans1 = ans1.substr(i1 , ans1size-i1) ;
    // cout<<ans1<<endl  ;    
    if(!pos)
        ans1 = "-"+ans1 ;
    return ans1 ;

}


int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    int testcase ;
    int n;
    cin>>testcase ;
    int intup, intcol ;

    while (testcase--)
    {
        string a , b ;
        cin>>a>>b ; 

        cout<< multiplyStrings(a,b)       ;
        cout<<endl;

    }
    return 0 ;
}


