// https://practice.geeksforgeeks.org/problems/merging-details/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




vector<vector<string>> mergeDetails(vector<vector<string>>& details) 
{
    int n = details.size();
    vector<vector<string>> ans1 ;

    for (int i1 = 0; i1 < n; i1++)
    {
        //name details[i1][0]
        //vector  details[i1][1:n]
        if(details[i1][0]!="-")
        {
            set<string> s1 ;
            vector<string> v ;
            for (int j1 = 1; j1 < details[i1].size(); j1++)
                s1.insert(details[i1][j1]);
            for (int j1 = i1+1; j1 < n; j1++)
                if(details[j1][0]!="-")
                    for (int k1 = 1; k1 < details[j1].size(); k1++)
                        if(s1.find(details[j1][k1])!=s1.end())
                        {
                            details[j1][0] = "-";
                            for (int l1 = 1; l1 < details[j1].size(); l1++)
                                s1.insert(details[j1][l1]);
                            
                        }



            v.push_back(details[i1][0]);
            for(auto emails:s1)
                v.push_back(emails);
            
            ans1.push_back(v);
        }


    }

    sort(ans1.rbegin(),ans1.rend());
    return ans1 ;
    
}


















