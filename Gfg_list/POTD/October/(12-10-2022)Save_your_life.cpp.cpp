// https://practice.geeksforgeeks.org/problems/save-your-life4601/1





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


int access_indx(char a )
{
    if(a>='a'&&a<='z')
        return a-'a';
    else if(a>='A'&&a<='Z')
        return a-'A'+26;
    return -1;
}


// string maxSum(string w,char x[], int b[],int n)
// {
//     // code here        
//               vector<int>hash_val(52,0);
//             for (char ch = 'a'; ch <='z'; ch++)
//                 hash_val[access_indx(ch)] = ch;
        
//             for (char ch = 'A'; ch <='Z'; ch++)
//                 hash_val[access_indx(ch)] = ch;
        
//             for (int i1 = 0; i1 < n; i1++)
//                 hash_val[access_indx(x[i1])] = b[i1];
            
//             int size1 = w.size();
//             vector<int> kadane_algo(size1,0);
//             for (int i1 = 0; i1 < size1; i1++)
//                 kadane_algo[i1] = hash_val[access_indx(w[i1])] ;
        
        
//             int cur_sum1 = 0 ,max_sum1 = 0;
//             int start1 = 0 , end1 = 0 ,s_ptr = 0;
        
//             for (int i1 = 0; i1 < size1; i1++)
//             {
//                 cur_sum1+=kadane_algo[i1] ;
//                 if(max_sum1<cur_sum1)
//                 {
//                     max_sum1 = cur_sum1 ;
//                     start1 = s_ptr ;
//                     end1 = i1 ;
//                 }
//                 if(cur_sum1<0)
//                 {
//                     cur_sum1 = 0;
//                     s_ptr = i1+1 ;
//                 }
//             }
            
//             return w.substr(start1 , end1-start1+1);
// }



string maxSum(string w,char x[], int b[],int n)
{
    // code here        
        vector<int>hash_val(52,0);
    for (char ch = 'a'; ch <='z'; ch++)
        hash_val[access_indx(ch)] = ch;

    for (char ch = 'A'; ch <='Z'; ch++)
        hash_val[access_indx(ch)] = ch;

    for (int i1 = 0; i1 < n; i1++)
        hash_val[access_indx(x[i1])] = b[i1];
    
    int size1 = w.size();
    vector<int> kadane_algo(size1,0);
    for (int i1 = 0; i1 < size1; i1++)
        kadane_algo[i1] = hash_val[access_indx(w[i1])] ;


    int cur_sum1 = 0 ,max_sum1 = 0;
    int start1 = 0 , end1 = 0 ,s_ptr = 0;

    for (int i1 = 0; i1 < size1; i1++)
    {
        cur_sum1+=kadane_algo[i1] ;
        if(cur_sum1<kadane_algo[i1])
        {
            cur_sum1 = kadane_algo[i1];
            s_ptr = i1 ;
        }
        if(max_sum1<cur_sum1)
        {
            max_sum1 = cur_sum1 ;
            start1 = s_ptr ;
            end1 = i1 ;
        }

    }
    
    return w.substr(start1 , end1-start1+1);
}

