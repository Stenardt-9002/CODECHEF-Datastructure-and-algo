// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

bool compare_d_func(pair<long long int,long long int> a1 , pair<long long int,long long int>b1)
{
    return a1.first<b1.first ;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    int testcase ;
    cin>>testcase ;
    while (testcase--)
    {
        int n , q ;
        cin>>n>>q ;
        vector<pair<long long int,long long int>> intup(n);
        for (int i12 = 0; i12 < n; i12++)
            cin>>intup[i12].first >>intup[i12].second ;


        vector<long long int> qarray(q);

        for (int i1 = 0; i1 < q; i1++)
            cin>>qarray[i1]        ;



        //merge
        //all boundaries 
        sort(intup.begin(),intup.end(),compare_d_func);

        int new_size = 0 ;
        for (int i1 = 1; i1 < n; i1++)
            if (intup[new_size].second>=intup[i1].first)
                intup[new_size].second=max(intup[new_size].second,intup[i1].second);
            else 
                intup[++new_size] = intup[i1];
                    
        for (int q1 = 0; q1 < q; q1++)
        {
            long long int ans1=-1 ;
            for (int i1 = 0; i1 <=new_size; i1++)
            {
                if(intup[i1].second-intup[i1].first+1>=qarray[q1])
                {
                    ans1 = intup[i1].first+qarray[q1]-1 ;
                    break ; 
                }
                else 
                    qarray[q1]=qarray[q1]-(intup[i1].second-intup[i1].first+1);
            }
            cout<<ans1<<endl ;
        }
        

    }
    return 0;
}


