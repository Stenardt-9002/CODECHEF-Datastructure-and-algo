// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day7/problem/distribute-n-candies


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



vector<long long> distributeCandies(int N, int K) 
{
        // code here
        if(K==1)
            return {N};
        vector<long long> ans1(K,0);

            if((K*(K+1)/2)>N)
            {
                //level 1 
                long long val = 1 ,i1=0;
                long long sumupt_now = 1;
                for (i1 = 0; i1 < K && sumupt_now<=N; i1++)
                {
                    ans1[i1] = val++ ;
                    sumupt_now+=val ;
                }
                sumupt_now-=val ;
                ans1[i1] = N-sumupt_now ;
                return ans1 ;
            }


        long long  minlev = 1 , maxleve = sqrt(N)+1 ;
        long long  anst = minlev ;
        while(minlev<maxleve)
        {
            long long mid = (minlev+maxleve)>>1;
            if(( (K*(K+1)*mid/2) + (mid*(mid-1)*K*K/2) )<=N )
            {
                anst = mid ; 
                minlev = mid+1 ;
            }
            else 
                maxleve = mid ;
        }



        cout<<"\n deug1 "<<anst<<"\n";
        long long  level_sum = K*(anst-1)*anst /2 ;
        long long  new_num = N ;
        int i1 = 0 ;
        for (i1 = 0; i1 < K; i1++)
            ans1[i1] = level_sum+((i1+1)*anst) , new_num-=ans1[i1];
            //now we have level 
        cout<<"\n deug2 "<<new_num<<"\n";



        //assert new_num>=0
        i1=0;
        for (i1 = 0; i1 < K&& new_num-((anst*K)+i1+1)>=0; i1++)
            if(new_num-((anst*K)+i1+1)>=0)
            {
                ans1[i1]+=((anst*K)+i1+1);
                new_num=new_num-((anst*K)+i1+1);
            }

        ans1[i1]+=new_num;
        return ans1 ;
}





int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,k;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n>>k ;
        vector<long long> ans1 = distributeCandies(n,k) ;

        for(int i1 = 0 ;i1 <k ;i1++)
            cout<<ans1[i1]<<" " ; 
        cout<<endl;
    }
    return 0 ;
}








