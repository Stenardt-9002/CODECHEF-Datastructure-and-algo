



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




int transform (string A, string B)
{
    //code here.


        int m = A.length() ;
        int n = B.length() ;
        if(n!=m) return -1;
        vector<int>char_hash_map(256,0);
        for (int i = 0; i < n; i++)
            char_hash_map[A[i]]++    ;

        for (int i = 0; i < n; i++)
            char_hash_map[B[i]]--    ;

        for (int i = 0; i < 256; i++)
            if(char_hash_map[i]!=0)
                return -1 ;


        int cunt1 = 0;

        for ( int i = n-1,j=n-1; i>=0;)
        {
            while(i>=0 && A[i]!=B[j])
                {i--;cunt1++;}
            if(i>=0 && A[i]==B[j])
                {i--;j--;}

            
        }
        return cunt1 ;

}

int main(int argc, char const *argv[])
{
    string A = "EACDTLKOP";
    string B = "TKLAEDCOP";
    cout<<endl<<transform(A,B);
    
    return 0;
}






