
    
    
    


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;




char* reverse(char *S, int len)
{
    
    stack<char> s1; 
    for (int i1 = 0; i1 < len; i1++)
        s1.push(S[i1]) ;


    for (int i1 = 0; i1 < len; i1++)
    {
        S[i1] = s1.top();
        s1.pop();
    }

    return S ;
}




