
// https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    if (beginWord==endWord)
        return 0 ;

    if (find(wordList.begin(),wordList.end(),endWord)==wordList.end())//not found 
        return 0;

    unordered_set<string> dick(wordList.begin(),wordList.end());
    queue<string> q1 ; 
    q1.push(beginWord);
    int ans1 = 0;
    while (!q1.empty())
    {
        int n = q1.size() ;
        for (int i1 = 0; i1 < n; i1++)
        {
            string cur_word = q1.front() ;
            q1.pop() ;
            if(cur_word==endWord)
                return ans1 ;
            
            dick.erase(cur_word);

            //vsit neighbour if exist
            for(int j1=0;j1<cur_word.size();j1++)
            {
                char cur_char = cur_word[j1] ;
                //all possible alphabets 
                for(int k1 = 0 ;k1<26;k1++)
                {
                    cur_word[j1] = 'a'+k1 ;
                    if(dick.find(cur_word)!=dick.end())
                        q1.push(cur_word);
                }
                cur_word[j1] = cur_char ;
            }
        }
        ans1++  ;
    }
    return 0 ;//not found

}




int main(int argc, char const *argv[])
{
    string s1,e1 ;
    vector<string> dick1 ;
    string temp1 ; 
    cin>>s1>>e1 ;
    int v1;cin>>v1;
    for (int i1 = 0; i1 < v1; i1++)
    {
        cin>>temp1 ; dick1.push_back(temp1)    ;
    }
    cout<<(find(dick1.begin(),dick1.end(),e1)==dick1.end())<<endl ;
    cout<<ladderLength(s1,e1,dick1);
    return 0;
}


