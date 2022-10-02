// https://practice.geeksforgeeks.org/problems/max-sum-submatrix2725/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




vector<int> maxSubMatrixSumQueries(vector<int> mat[], int n, int m,
                                vector<pair<int, int>> &queries, int q) 
{
    vector<int> ansn1;
    int icunt = 0;

    int final_sum = INT_MIN ;
    int sum =0 ;

    //preprocess to sum matrix 
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 1; j1 < m; j1++)
            mat[i1][j1]+=mat[i1][j1-1];
    
    // for (int i1 = 0; i1 < n; i1++)
    //     {
    //     for (int j1 = 0; j1 < m; j1++)
    //         cout<<" "<<mat[i1][j1];
    //     cout<<endl;
    //     }   
    

    while(q--)
    {
        sum = 0,final_sum=INT_MIN ;
        int rowd1 = queries[icunt].first ;
        int cold1 = queries[icunt].second ;
        icunt++;
        // for (int currow = 0; currow <rowd1 ; currow++)
        //     sum+=mat[currow][cold1-1];

        // final_sum = max(final_sum,sum);
        for (int allwro = 0; allwro <=n-rowd1 ; allwro++)
        {
            sum = 0;
            for (int currow = allwro; currow <allwro+rowd1 ; currow++)
                sum+=mat[currow][cold1-1];

            final_sum = max(final_sum,sum);
            for (int allcol = 1; allcol <=m-cold1; allcol++)
            {
                sum = 0;
                for (int  row_itr = allwro; row_itr < allwro+rowd1; row_itr++)
                    sum+=(mat[row_itr][allcol+cold1-1]-mat[row_itr][allcol-1]);
                
                final_sum = max(final_sum,sum);
            }
        }

        ansn1.push_back(final_sum);
    }
    return ansn1;
}

// vector<int> maxSubMatrixSumQueries(vector<int> mat[], int n, int m,
//                                 vector<pair<int, int>> &queries, int q) 
// {
//     vector<int> ansn1;
//     int icunt = 0;
//     while(q--)
//     {
//         int rowd1 = queries[icunt].first ;
//         int cold1 = queries[icunt].second ;
//         icunt++ ;
//         int final_sum = INT_MIN ;
//         int sum =0 ;
//         vector<int> temp1 (n,0);
//         final_sum = max(final_sum , sum);
//         for (int top = 0; top <=n-rowd1; top++)
//         {       
//             sum = 0;
//             for (int right = 0; right <cold1; right++)
//                 for (int i1 = top; i1 <top+rowd1; i1++)
//                 sum+=mat[i1][right];
            
//             final_sum = max(final_sum,sum);

//             for (int left = 1; left <=m-cold1; left++)
//             {
//                 for (int curcol = top; curcol <top+rowd1 ; curcol++)
//                 {
//                     sum-=mat[curcol][left-1];
//                     sum+=mat[curcol][left+cold1-1];
//                 }
//                 final_sum = max(final_sum,sum);
//             }
//         }

//         ansn1.push_back(final_sum);
//     }
//     return ansn1;
// }

int main(int argc, char const *argv[])
{
    int n,m ;
    cin>>n>>m ;
    // vector<vector<int>> ar(n,vector<int>(m,0));
    vector<int> *ar = new vector<int>[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        ar[i1].resize(m);
        for (int j1 = 0; j1 < m; j1++)
            cin>>ar[i1][j1];
    }
    int q ; 
    cin>> q;
    
    vector<pair<int,int>> query(q);
    for (int i1 = 0; i1 < q; i1++)
        cin>>query[i1].first>>query[i1].second ;
    cout<<endl;
    for (auto x:maxSubMatrixSumQueries(ar,n,m,query,q))
        cout<<" "<<x;
    return 0;
}




