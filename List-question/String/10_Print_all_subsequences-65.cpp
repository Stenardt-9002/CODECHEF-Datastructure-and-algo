// https://www.geeksforgeeks.org/print-subsequences-string/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;




void printSubsequence(string inpt , string output)
{
    if (inpt.empty())
    {
        cout<<output<<endl ;
        return ;
    }
    //either take or not
    printSubsequence(inpt.substr(1),output+inpt[0]);
    printSubsequence(inpt.substr(1),output);
}


int main(int argc, char const *argv[])
{
    string outpt = "" ;
    string input1 = "ABCDE";
    printSubsequence(input1,outpt);
    return 0;
}















