#include<bits/stdc++.h>  



int doUnion(int a[], int n, int b[], int m)  
{
    set<int> s ; 

    for (int i1 = 0; i1 < n; i1++)
    {
        s.insert(a[i1]) ; 
    }
    

    for (int i1 = 0; i1 < m; i1++)
    {
        s.insert(b[i1]) ; 
    }

    int val = s.size() ; 
    return val ;

}









