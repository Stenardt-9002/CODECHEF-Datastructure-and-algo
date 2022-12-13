# // https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day15/problem/count-the-reversals0401








# #include <bits/stdc++.h>
# #include<ext/pb_ds/tree_policy.hpp>
# #include<ext/pb_ds/assoc_container.hpp>


# using namespace std;
# using namespace __gnu_pbds ;
# typedef  long long int ll;
# #define DEBUG_var 1
# #define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


# const int mod1 = (1e9+7);
# const int MOD1 = 1000000007;














# int countRev (string s)
# {
#     // your code here
# }





def countRev (s):
    
    # your code here
    n = len(s)
    if(n%2):
        return -1 
        
    stack_1 = []
    for i in s:
        if i=='}' and len(stack_1)>0 and stack_1[-1]=='{':
            stack_1.pop()
        else :
            stack_1.append(i)
        
    n = len(stack_1) 
    left = 0 
    for i in stack_1:
        if i=='{':
            left+=1
    
    return n//2 + left%2







