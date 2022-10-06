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

//UPPER BOUND ON VECTOR
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap() 
    {
        
    }
    void set(string key, string value, int timestamp) 
    {
        m[key].push_back({ timestamp, value });
    }
    string get(string key, int timestamp) 
    {
        auto it = upper_bound(begin(m[key]), end(m[key]), pair<int, string>(timestamp, ""), [](
        const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });
        return it == m[key].begin() ? "" : prev(it)->second;
    }

};
//UPPER BOUND ON MAP

class TimeMap1 {
public:
    unordered_map<string , map<int,string>>map1 ;
    TimeMap1() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        this->map1[key][timestamp] = value ;
    }
    
    string get(string key, int timestamp) 
    {
        auto it = this->map1[key].upper_bound(timestamp);
        return it==this->map1[key].begin()?"":(--it)->second ;
    }
};

int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        
    }
    

    return 0;
}





