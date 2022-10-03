#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

struct Node1
{
    int height ,  pos ;
};

void DEBUG_gun(vector<pair<int,int>> combined_data , int n)
{
    cout<<endl<<"DEBUG  " ;
    for(int i1=0 ; i1<n ; i1++)
        cout<<combined_data[i1].first <<" "<< combined_data[i1].second<<"   ,  ";

}
bool compare_func(pair<int,int> a , pair<int, int> b)
{
    return a.first>b.first ;
}
vector<int> arrange(vector<int> &A, vector<int> &B, int n)
{
    // code here
    // int n = A.size();
    int i1 = 0 ;
    vector<pair<int,int>> combined_data(n) ;
    for(i1 = 0 ;i1 <n ; ++i1)
        combined_data[i1] = {A[i1], B[i1]};

    sort(combined_data.begin(),combined_data.end() ,compare_func);
    bool done = true ;
    while(done)
    {
        for (i1 = 1; i1 < n; i1++)
        {
            int new_pos = combined_data[i1].second ;
            if(new_pos<i1)
            {
                pair<int,int> current = combined_data[i1] ;
                for (int j1 = i1; j1 >new_pos; j1--)
                    combined_data[j1] = combined_data[j1-1];
                
                combined_data[new_pos] = current ;
            }
            // DEBUG_gun(combined_data,n);
        }
        bool ok = true ;
        for (i1 = 1; i1 < n&&ok; i1++)
        {
            int new_pos = combined_data[i1].second ;
            int count = 0 ;
            for(int j1 = 0 ; j1<i1;j1++)
                if(combined_data[i1].first<=combined_data[j1].first)
                    count++ ;

            ok = (count==new_pos);
            // DEBUG_gun(combined_data,n);
        }
        if(ok)
            done = false ;

    }
    vector<int> ans1 ;
    for(auto x : combined_data)
        ans1.push_back(x.first);

    return ans1 ;
}



int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    int n ;

    while (testcases--)
    {
        cin>> n ;
        vector<int> a1(n) ,ba(n);
        for (int i1 = 0; i1 < n; i1++)
            cin>>a1[i1];

        for (int i1 = 0; i1 < n; i1++)
            cin>>ba[i1];


        vector<int> out = arrange(a1, ba, n);
        cout<<endl ;
        for (int i1 = 0; i1 < n; i1++)
            cout<<out[i1]<<" ";
        

    }
    

    return 0;
}


