// https://practice.geeksforgeeks.org/problems/the-bit-game2313/1




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

const long long int mod2 =  1e18 ;


int swapBitGame(long long N)
{
    // code here 
            long long int temp = N ;
        int count1 = 0;
        while (temp!=0)
        {
            if(temp%2==1)
                count1++;
            temp/=2 ;
        }
        // return count1 ;
        // last count1 position 
        temp = N ;
        int numofswaps_required = 0 ;
        while (count1--)
        {
            if(temp%2==0)
                numofswaps_required+=1 ;
    
            temp/=2 ;
    
        }
        // return numofswaps_required ;
        if(numofswaps_required%2==1)
            return 1;
        else 
            return 2 ;
}


    int swapBitGame(long long N){
        // code here 
        long long int temp = 0 ;
        long long int contsetbit = 0;
        while(N!=0)
        {
            if(N%2!=0)
                contsetbit^=temp;
            if(N%2==0)
                temp++;
            
            N/=2;
        }
        if(contsetbit!=0)
            return 1;
        else 
            return 2 ;
    }









int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        cout<<swapBitGame(n)<<endl;
    }
    return 0 ;
}

