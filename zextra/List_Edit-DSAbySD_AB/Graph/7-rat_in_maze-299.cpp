    // https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



// bool is_safe(int x ,int y, int n)
// {
//     return (x>=0 && y<n && x<n && y>=0);
// }
    
// bool findPath_util(vector<vector<int>> &m,set<string> &ans,string &current , int x,int y, int n) 
// {
//     if(x==n-1 && y==n-1 && m[x][y]==1)
//     {
//         ans.insert(current);
//         return true ;
//     }
//     string tempU = current+"U" ;
//     string tempR = current+"R" ;
//     string tempL = current+"L" ;
//     string tempD = current+"D" ;
//     if(is_safe(x,y,n)&&m[x][y]==1)
//     {
//         if(findPath_util(m,ans,tempU,x,y+1,n))
//             return true;

//         if(findPath_util(m,ans,tempR,x+1,y,n))
//             return true;


//         if(findPath_util(m,ans,tempL,x-1,y,n))
//             return true;


//         if(findPath_util(m,ans,tempD,x,y-1,n))
//             return true;
//     }

//     return false ;
// }

// vector<string> findPath(vector<vector<int>> &m, int n) 
// {
//     set<string>ans ;
//     vector<string>ans1 ;
//     string empty1 = "";
//     findPath_util(m ,ans,empty1,0,0,n);

//     for (auto x : ans)  
//         ans1.push_back(x)    ;
    
//     return ans1 ;
// }



    static bool is_safe(int x ,int y, int n)
    {
        return (x>=0 && y<n && x<n && y>=0);
    }
        
    static void findPath_util(vector<vector<int>> &m,vector<vector<int>> &marked_1,set<string> &ans,string &current , int x,int y, int n) 
    {
        if(x==n-1 && y==n-1 && m[x][y]==1)
        {
            ans.insert(current);
            
            return  ;
        }
        marked_1[x][y] = 1 ;


        if(is_safe(x+1,y,n)&&m[x+1][y]==1&&marked_1[x+1][y]==0)
        {
            current.push_back('D');
            findPath_util(m,marked_1,ans,current,x+1,y,n);
            current.pop_back();
        }

        if(is_safe(x,y+1,n)&&m[x][y+1]==1&&marked_1[x][y+1]==0)
        {
            current.push_back('R');
            findPath_util(m,marked_1,ans,current,x,y+1,n);
            current.pop_back();
        }

        if(is_safe(x-1,y,n)&&m[x-1][y]==1&&marked_1[x-1][y]==0)
        {
            current.push_back('U');
            findPath_util(m,marked_1,ans,current,x-1,y,n);
            current.pop_back();
        }

        if(is_safe(x,y-1,n)&&m[x][y-1]==1&&marked_1[x][y-1]==0)
        {
            current.push_back('L');
            findPath_util(m,marked_1,ans,current,x,y-1,n);
            current.pop_back();
        }

    
        marked_1[x][y]=0;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        set<string>ans ;
        vector<string>ans1 ;
        string empty1 = "";
        vector<vector<int>> marked_1(n,vector<int>(n,0));
        if(m[0][0]==1)
            findPath_util(m,marked_1,ans,empty1,0,0,n);
        if(ans.size()==0)
            return {"-1"};
        for (auto x : ans)  
            ans1.push_back(x)    ;
        
        return ans1 ;
    }