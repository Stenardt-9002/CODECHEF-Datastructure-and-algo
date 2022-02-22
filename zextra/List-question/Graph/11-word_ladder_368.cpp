
// https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>
using namespace std;



int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    if (beginWord==endWord)
    {
        return 0 ;
    }
    if (find(wordList.begin(),wordList.end(),endWord)==wordList.end())//not found 
    {
        return -1;
    }

    queue<string> Q ;
    Q.push(beginWord);
    string queuword ;
    int asnwer1 = 0;
    char cureentchar ;
    while (!Q.empty())
    {
        asnwer1++;
        for (int i1 = 0; i1 < Q.size(); i1++)
        {
            queuword = Q.front() ;
            Q.pop() ;
            for (int pos = 0; pos < queuword.length(); pos++)
            {
                cureentchar = queuword[pos];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    queuword[pos] = c;
                    if (queuword==endWord)
                    {
                        return asnwer1+1;
                    }
                    std::vector<string> :: iterator it = find(wordList.begin(),wordList.end(),queuword);
                    if (it==wordList.end())
                    {
                        continue;
                    }
                    //find remove from vector 
                    wordList.erase(it);
                    Q.push(queuword);
                }
                queuword[pos] = cureentchar ;
            }
            
        }
        

    }
    cout<<"EREACHED HERE ";
    return 0;

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


