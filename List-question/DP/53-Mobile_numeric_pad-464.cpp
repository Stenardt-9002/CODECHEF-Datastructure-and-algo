#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

bool corect_pos(long long x ,long long y, long long N,long long M)
{
    return (x>=0 &&y>=0 && x<N && y<M);
}

long long getCount(int N)
{
    // Your code goes here
    int n = N;
    long long key_pad[4][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9},
                        {-1,0,-1}
    };
    if(n==0)
        return 0;
    if(n==1)
        return 10;

    long long row[] = {0,0,-1,0,1};
    long long col[] = {0,-1,0,1,0};

    vector<vector<long long>>dp1(10,vector<long long>(n+1,0));
    long long i1=0,j1=0,k1=0,move=0,ro=0,co=0,num=0;
    for (long long i1 = 0; i1 < 10; i1++)
    {
        dp1[i1][0] = 0; //0 length no count 
        dp1[i1][1] = 1;//each digit starting and one length means that count only
    }
    
    for (long long len1 = 2; len1 < n+1; len1++)
        for (long long i1 = 0; i1 < 4; i1++)
            for (long long j1 = 0; j1 < 3; j1++)
                if(key_pad[i1][j1]!=-1)
                {
                    long long cur_num = key_pad[i1][j1] ;
                    for (long long pos_1 = 0; pos_1 < 5; pos_1++)
                    {
                        long long ro1 = i1+row[pos_1] ;
                        long long co1 = j1+col[pos_1];
                        if(corect_pos(ro1,co1,4,3)&& key_pad[ro1][co1]!=-1)
                        {
                            long long next_num = key_pad[ro1][co1] ;
                            dp1[cur_num][len1]+=dp1[next_num][len1-1];
                        }
                    }
                }

    long long total_cunt = 0;
    for (int i1 = 0; i1 < 10; i1++)
        total_cunt+=dp1[i1][n];
    // starting from diferent digits of n length 
    return total_cunt ;
}



int main(int argc, char const *argv[])
{
    
    return 0;
}




