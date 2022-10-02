

// https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1/





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);
void create_fromIP(vector<vector<bool>>dp1,int r,int c , string s,string ans1 , set<string> &list);


bool verify(string part_String)
{
    if(part_String=="")
        return false;
    int n = part_String.length() ;
    if(n>3|| stoi(part_String)<0||stoi(part_String)>255)
        return false ;
    if(n>1&& stoi(part_String)==0)//multiple zero not allowed
        return false ;

    if(n>1 && stoi(part_String)!=0 && part_String[0]=='0' )//cant start from zero
        return false ;
    return true;
}



bool valid_ip_str(string ip1)
{
    // vector<string> ips ;
    int n = ip1.length();
    string curent = "";
    for (int i1 = 0; i1 < n; i1++)
    {
        if(ip1[i1]=='.')
        {
            if(!verify(curent))
                return false ;
            curent = "";
        }
        else
            curent+=ip1[i1];
    }
    return true;
}


vector<string> genIp(string &s) 
{
    int n = s.length();

    vector<vector<bool>>dp1(4,vector<bool>(n,false)) ;
    if(n<4||n>12)
        return {"-1"} ;

    for (int i1 = 0; i1 < 4; i1++)
    {
        for (int j1 = n-1; j1>=0; j1--)
        {
            if(i1==0)
            {
                string subpart = s.substr(j1);
                if(valid_ip_str(subpart))
                    dp1[i1][j1]=true ;
                else if(j1<n-3)
                    break ;
            }
            else 
            {
                if(j1<=n-i1)
                {
                    for(int k=1;k<=3&&j1+k<=n;k++)
                    {
                        string temp1 = s.substr(j1,k);
                        if(valid_ip_str(temp1))
                            if(j1+k<n&&dp1[i1-1][j1+k]==true)
                                {
                                    dp1[i1][j1] = true ;
                                    break ;
                                }
                    }
                }
            }
        }
    }
    if(dp1[3][0]==false)
        return {"-1"};


    for (int i1 = 0; i1 < 4; i1++)
    {
        for (int j1 = 0; j1 < n; j1++)
            cout<<" "<<dp1[i1][j1];
        cout<<endl ;        
    }
    

    //creating IP 
    set<string> set1 ;
    vector<string> asn1 ;
    create_fromIP(dp1,3,0,s,"",set1);

    // return {};
    for (auto x : set1)
        asn1.push_back(x)    ;
    return asn1 ;
}

void create_fromIP(vector<vector<bool>>dp1,int r,int c , string s,string ans1 , set<string> &list1 )
{
    if(r==0)
    {
        ans1+=s.substr(c);
        list1.insert(ans1);
        return ;
    }
    else
    {
        for (int i1 = 1; i1 <4&&c+i1<s.length() ; i1++)
            if(valid_ip_str(s.substr(c,i1))&& dp1[r-1][c+i1] )        
                create_fromIP(dp1,r-1,c+i1,s,ans1+s.substr(c,i1)+".",list1);
    }
    
}







int main(int argc, char const *argv[])
{
    string str2 = "25525511135";
    vector<string> ans1 = genIp(str2);
    // for (auto x : ans1)
    //     cout<<" "<<x<<endl;
    return 0;
}





