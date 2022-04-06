

// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);



int romanToDecimal(string &str) 
{
    // code here

    map<char,int> ma_1 ;
    ma_1.insert({ 'I', 1 });
    ma_1.insert({ 'V', 5 });
    ma_1.insert({ 'X', 10 });
    ma_1.insert({ 'L', 50 });
    ma_1.insert({ 'C', 100 });
    ma_1.insert({ 'D', 500 });
    ma_1.insert({ 'M', 1000 });

    int sum1 = 0;

    for (int i1 = 0; i1 < str.size(); i1++)
    {
        if(i1+1<str.size()&& ma_1[str[i1]]<ma_1[str[i1+1]] )
        {
            sum1+=(ma_1[str[i1+1]]-ma_1[str[i1]]);
            i1++;
            continue;
        }
        sum1+=ma_1[str[i1]];
    }
    return sum1 ;
}




int main(int argc, char const *argv[])
{
    
    return 0;
}





