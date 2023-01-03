// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?page=2&difficulty[]=2&status[]=unsolved&sortBy=submissions






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








class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) 
    {
        // code here

        vector<vector<string>>ans ;
        unordered_set<string> hash(wordList.begin(),wordList.end());
        queue<vector<string>>q1 ;
        q1.push({beginWord});
        vector<string> curLevel ;
        int depth = 0 ;
        while (!q1.empty())
        {
            vector<string> front = q1.front();
            q1.pop();
            if(front.size()>depth)
            {
                depth++ ;
                for(auto ths_lvel:curLevel)
                    hash.erase(ths_lvel);
                curLevel.clear();
            }

            string last = front.back();
            //if end
            if(last==endWord)
            {
                if(ans.size()==0)
                    ans.push_back(front);
                else if(ans[0].size()==front.size()) //same size shortesst
                    ans.push_back(front);
            }

            //all next child 
            for (int i = 0; i < last.size(); i++)
            {
                char save = last[i];
                for (char ch = 'a'; ch <='z'; ch++)
                if(ch!=save)
                {
                    last[i] = ch ;
                    if(hash.find(last)!=hash.end())
                    {
                        //found word 
                        front.push_back(last);
                        q1.push(front);
                        front.pop_back();
                        curLevel.push_back(last);
                    }

                }
                last[i] = save ;
            }
        }
        



        return ans ;
    }
};