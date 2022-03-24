// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;




// vector<long long> printFirstNegativeInteger(long long int A[],
                                            //  long long int N, long long int K) 
// {
    // queue<ll1d>q1 ;
    // vector<ll1d> ans1wr;
    // ll1d i1=0;
    // for ( i1 = 0; i1 <K; i1++)
    //     if (A[i1]<0)
    //         q1.push(i1)        ;

    // for( ; i1<N;i1++)
    // {
    //     if (!q1.empty())
    //         ans1wr.push_back(A[q1.front()]) ;
    //     else
    //         ans1wr.push_back(0)         ;

    //     while (!q1.empty() && (q1.front()<i1-K+1))
    //         q1.pop()         ;

    //     if(A[i1]<0)
    //         q1.push(i1)   ;
    // }
        
    // //last window 

    //  if (!q1.empty())
    //         ans1wr.push_back(A[q1.front()]) ;
    //     else
    //         ans1wr.push_back(0)         ;

    // return ans1wr ;
// }



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
{
    int firstnegativeI = 0;
    vector<long long> ans1 ;

    for (int i1 = K-1; i1 < N; i1++)
    {
        while (firstnegativeI<i1 && (firstnegativeI <=i1-K || A[firstnegativeI]>0 ))
            firstnegativeI++ ; 
        if (A[firstnegativeI]<0)
            ans1.push_back(A[firstnegativeI]) ;
        else
            ans1.push_back(0) ;
    }
    return ans1 ;
}
int main(int argc, char const *argv[])
{
    ll1d n,k ;
    cin>>n;
    
    vector<long long> var ;
    ll1d *A = new ll1d[n];
    for ( ll1d i1 = 0; i1 <n ; i1++)
        cin>>A[i1]     ;

    cin>>k;
    
    cout<<endl;

    var = printFirstNegativeInteger(A,n,k);
    for ( ll1d i1 = 0; i1 <var.size() ; i1++)
        cout<<" "<<var[i1]     ;

    

    return 0;
}


