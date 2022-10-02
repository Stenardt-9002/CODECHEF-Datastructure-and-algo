// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1/?page=2&curated[]=2&sortBy=submissions

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef  long long ll1d;


int majorityElement(int a[], int size)
{
    
    // your code here
    int cunt = 0 , cur_ele=0,i1;
    for(i1=0;i1<size;i1++)
    {
        if(cunt==0)
            cur_ele = a[i1];

        if(a[i1]==cur_ele)
            cunt++ ;
        else
            cunt-- ;
    }
    cunt=0 ;
    for(i1=0;i1<size;i1++)
        if(a[i1]==cur_ele)
            cunt++ ;

    if(cunt>(size/2))
        return cur_ele ;
    return -1 ;
    
}
int main(int argc, char const *argv[])
{

    int a[15] = { 17,19,9,5,3,6,17,7,18,16,18,11,3,15,2};
    cout<<endl<<majorityElement(a,15);

    return 0;
}


