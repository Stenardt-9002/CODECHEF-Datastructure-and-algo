#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int count_hash(vector<int> hash_total ,vector<int> hash_first)
{
    int uniqueu_chars = 0;
    for (int i = 0; i < 26; i++)
        uniqueu_chars+=(hash_first[i]>0 && (hash_total[i]-hash_first[i]>0));
    
    return  uniqueu_chars ;
}

class Solution
{
	public:
	int splitString(int n,string s)
	{
		//code here
        vector<int>hash_sentence(26,0);
        for(auto c : s)
            hash_sentence[c-'a']++;
        int ans = 0 ;
        vector<int> hash_first_part(26,0);
        hash_first_part[s[0]-'a']++ ;

        for (int i1 = 1; s[i1]; i1++)
        {
            ans = max(ans , count_hash(hash_sentence , hash_first_part))    ;
            hash_first_part[s[i1]-'a']++ ;
        }
        
        return ans ;
	}
};
