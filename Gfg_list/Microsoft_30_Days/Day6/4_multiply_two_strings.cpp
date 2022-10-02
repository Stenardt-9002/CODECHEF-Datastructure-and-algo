    
    // https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day6/video/NjM5Mw%3D%3D





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





    string multiplyStrings(string s1, string s2) 
    {
       //Your code here
        int n = s1.length();
        int m = s2.length() ; 
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
        // string ans1 = "" ;
        // for(int i1 =0 ;i1< n+m;i1++)
        //     ans1+="0";
        vector<int> ans1(n+m,0);
        int cnt1 = 0 ; 
        int cnt2 = 0 ;
        int i = n-1; ;
        while (i>=0) 
        {
            int n1 = s1[i]-'0';
            int carry = 0;
            cnt2 = 0 ;
            for(int j1=m-1 ; j1>=0;j1-- )
            {
                int n2 = s2[j1]-'0';
                int sum1 = n1*n2 + ans1[cnt1+cnt2] + carry ;
                carry = sum1/10 ;
                ans1[cnt1+cnt2] = sum1%10;
                cnt2++ ;

            }
            if(carry>0)
                ans1[cnt1+cnt2] += carry;

            cnt1++ ;
            i-- ;
        }
        int i1 = ans1.size()-1;

        while(i1>=0 && ans1[i1]==0)
            i1--  ;    
        if(i1==-1)
            return "0" ;
        string ans2 = "";
        while(i1>=0)
            ans2+=to_string(ans1[i1--]);
        // cout<<ans1<<endl  ;    
        if(!pos)
            ans2 = "-"+ans2 ;
        return ans2 ;

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



