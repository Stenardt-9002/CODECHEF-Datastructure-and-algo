
// https://practice.geeksforgeeks.org/problems/knight-walk4521/1








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int stepsx[] = {-2,-2,-1,-1,1,1,2,2};
int stepsy[] = {1,-1,2,-2,-2,2,-1,1};


bool allow_pos(int srcx , int srcy , int N)
{
    return (srcx<N && srcy<N && srcx>=0 && srcy>=0);
}



int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
{
    queue<pair<int,int>> q1 ; 
    vector<vector<int>> dp1(N,vector<int>(N,-1));
    q1.push({KnightPos[0]-1,KnightPos[1]-1});
    dp1[KnightPos[0]-1][KnightPos[1]-1] =0 ;
    int disatance = 0 ;
    while (!q1.empty())
    {
        int qsize = q1.size();
        while (qsize--)
        {
            pair<int,int> curnode = q1.front();
            q1.pop();
            for (int pos = 0; pos < 8; pos++)
            {
                //try all position 
                if(allow_pos(curnode.first+stepsx[pos],curnode.second+stepsy[pos] , N) && dp1[curnode.first+stepsx[pos]][curnode.second+stepsy[pos]]==-1)
                {
                    dp1[curnode.first+stepsx[pos]][curnode.second+stepsy[pos]] = disatance+1 ;

                    if(curnode.first+stepsx[pos]==TargetPos[0]-1&& curnode.second+stepsy[pos] == TargetPos[1]-1)
                        return dp1[curnode.first+stepsx[pos]][curnode.second+stepsy[pos]];

                    q1.push({curnode.first+stepsx[pos],curnode.second+stepsy[pos]});
                }

            }
            
        }
        disatance++ ;
    }
    

        // cout<<endl<<endl ;
        // for(auto ro : dp1)
        // {
        //     for(auto x:ro)
        //         cout<<x<<" ";
        //     cout<<endl ;
        // }

    return dp1[TargetPos[0]-1][TargetPos[1]-1];
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        vector<int>src(2);
        cin>>src[0]>>src[1];
        vector<int>target(2);
        cin>>target[0]>>target[1];
        cout<<minStepToReachTarget(src,target ,n)<<endl;
    }
    return 0 ;
}
