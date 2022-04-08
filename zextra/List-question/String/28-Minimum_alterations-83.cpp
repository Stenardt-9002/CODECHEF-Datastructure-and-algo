
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

int minFlips (string S)
{
    // your code here
    // bool zer_o = true ;
    int total_size = S.length() ;
    int itr1 = 1 ;
    string posible1 = "1";
    while (itr1<total_size)
    {
        if(posible1[itr1-1]=='1')
            posible1+='0' ;

        else 
            posible1+='1' ;
        itr1++ ;
    }
    itr1 = 1 ;
    string posible2 = "0";

    while (itr1<total_size)
    {
        if(posible2[itr1-1]=='1')
            posible2+='0' ;

        else 
            posible2+='1' ;
        itr1++ ;
    }
    int count1 = 0;
    for (int i1 = 0; i1 < total_size ; i1++)
        if(S[i1]!=posible1[i1])
            count1++ ;
    
    int count2 = 0;
    for (int i1 = 0; i1 < total_size ; i1++)
        if(S[i1]!=posible2[i1])
            count2++ ;
    return min(count1,count2);
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}




