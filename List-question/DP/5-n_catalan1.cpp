
// https://practice.geeksforgeeks.org/problems/geek-and-his-binary-strings1951/1/#
#include "bits/stdc++.h"

using namespace std;
// int prefixStrings(int N)
// { //O(n^2)
// 	    const unsigned int D1 = 1000000007;
// 	        int n = N;
//            unsigned long long int dp1[n+1]    ;//nth number catalan value
//             dp1[0] = dp1[1] = 1;
        
//             // C(n) = (C(i) * C(n-i-1)) i 0 to n-1
//             for (int val1 = 2; val1 < n+1; val1++)// 0 and 1 number catalan value saved
//             {
//                 //sumation
//                 dp1[val1] = 0;
//                 //summation 
//                 for (int i = 0; i < val1; i++)
//                 {
//                     dp1[val1]+=(dp1[i]*dp1[val1-i-1]);
//                     dp1[val1]  =dp1[val1]%D1;
//                 }
               
        
//             }
            
//             return dp1[n];


// }



int prefixStrings(int N)
{
    //O(n)
    const unsigned int D1 = 1000000007;
    if(N==0){return 1;}
    double answer1 = 1 ;
    int n = N; 
    for (int i1 = 0; i1 < n; i1++)
    {
        answer1*=(2*n-i1); 
        answer1/=(i1+1);
        // answer1%=D1;
    }
    long long int val = answer1/(n+1);
    return (val)%D1;

}



int main(int argc, char const *argv[])
{
    int n1 ;
    cin>>n1 ;cout<<prefixStrings(n1);    
    return 0;
}






