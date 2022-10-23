

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



int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
         vector<int>visited(n,false);
        // int visist_all = n ;
        int celeb_ind = 0 ;
        int col_val = 0 ;
        int original_celeb_ind = 0;
        while(col_val<n)
        {
            if(M[celeb_ind][col_val]==1)
            {
                visited[celeb_ind] = true ;
                // visist_all--;
                original_celeb_ind = celeb_ind;
                celeb_ind=col_val;
                while(visited[(celeb_ind)%n] && original_celeb_ind!=(celeb_ind%n) )
                ++celeb_ind;
                if(original_celeb_ind!=(celeb_ind%n))
                    col_val = n;
                    // celeb_ind = -1;
                
                else 
                    col_val = 0;
                
                celeb_ind = celeb_ind%n ;
            }
            col_val++ ;
        }
        cout<<"BRUG0 "<<celeb_ind<<endl;

        for(int i1 = 0 ; i1<n ;i1++)
            if(i1!=celeb_ind && M[celeb_ind][i1]==1)
                return -1 ;
        cout<<"BRUG1 "<<celeb_ind<<endl;

        for(int i1 = 0 ; i1<n ;i1++)
            if(i1!=celeb_ind && M[i1][celeb_ind]==0)
                return -1;
        cout<<"BRUG2 "<<celeb_ind<<endl;
        return celeb_ind ;
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
    while (testcases--)
    {
        int n ;
        vector<vector<int>> suggest(n,vector<int>(n,0));

        cin>>n ;
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < n; j1++)
                cin>>suggest[i1][j1];
        

        // Print word having highest frequency
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < n; j1++)
                cout<<suggest[i1][j1]<<" \n"[j1==n-1];

        celebrity(suggest,n);
    }


    return 0;
}



