// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


string findSubString(string str)
{
    // Your code goes here   

    int n = str.length();
    if(n<2)
        return str ;

    int dist_count = 0 ;
    vector<bool> visited(256,false);
    for (int i1 = 0; i1 < n; i1++)
        if(!visited[str[i1]])
        {
            visited[str[i1]] = true ;
            dist_count++ ;
        }
    
    int start = 0,start_index = -1 , min_len = INT_MAX ;
    int count1 = 0 ;

    vector<int>curr_cunt(256,0) ;
    for (int j1 = 0; j1 < n; j1++)
    {
        curr_cunt[str[j1]]++ ;
        if(curr_cunt[str[j1]]==1)
            count1++ ;//found a distinct character 

        if(count1 == dist_count)
        {
            while (curr_cunt[str[start]]>1)
            {
                if(curr_cunt[str[start]]>1)
                    curr_cunt[str[start]]--;
                start++ ;
            }
            int len_windwo = j1-start+1 ;
            if(min_len>len_windwo)
            {
                min_len = len_windwo ;
                start_index = start ;
            }
        }
    }
    return str.substr(start_index,min_len);
}

int main(int argc, char const *argv[])
{
    string str1 = "aabcbcdbca";
    cout<<findSubString(str1);
    return 0;
}




