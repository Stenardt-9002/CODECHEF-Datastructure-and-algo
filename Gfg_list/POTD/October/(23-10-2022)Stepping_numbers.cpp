
// https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output1813/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

int bfs_func(int n , int m , int digit)
{
    int qfront , lasdigit , stepup ,stepdown,count1 = 0 ;
    queue<int> q1 ;
    q1.push(digit);
    while (!q1.empty())
    {
        qfront = q1.front();
        q1.pop();

        if(qfront<=m && qfront>=n)
            count1++ ;

        if(qfront<=m)
        if(!(digit==0||qfront>m))
        {
            lasdigit = qfront%10 ;
            stepup = qfront*10+lasdigit+1 ;
            stepdown = qfront*10+lasdigit-1 ;

            if(lasdigit==0)
                q1.push(stepup);
            else if(lasdigit==9)
                q1.push(stepdown);
            else 
            {
                q1.push(stepdown);
                q1.push(stepup);
            }
        }
    }
    return count1 ;
}


int steppingNumbers(int n, int m)
{
    // Code Here
    int count1 = 0 ;
    for (int i1 = 0; i1 <=9; i1++)
        count1+=bfs_func(n,m,i1);
    
    return count1 ;
}







