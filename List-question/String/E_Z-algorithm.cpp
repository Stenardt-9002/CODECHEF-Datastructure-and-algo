

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


vector<int> getZarray(string);




void search(string text1 , string pattern1)
{
    string concat = pattern1+"$"+text1 ;//separator "$"
    int size_n = concat.size();
    vector<int>z_array = getZarray(concat);
    for (int i1 = 0; i1 < size_n; i1++)
        if(z_array[i1]==pattern1.size())//when size equal to z_array value match
            cout<<"\nPattern found at "<<i1-pattern1.length()-1;

}


vector<int> getZarray(string str)
{

    int n = str.length();
    int left=0 , right=0 ,cur ;
    vector<int>z_array(n,0);
    for (int i1 = 1; i1 < n; i1++)
    {
        if(i1>right)
        {
            left = right = i1 ;
            while (right<n && str[right-left]==str[right])
                right++ ;
            z_array[i1] = right-left ;
            right-- ;
        }
        else 
        {
            //inside box 
            cur = i1-left ;
            if(z_array[cur]<right-i1+1)
                z_array[i1] = z_array[cur];
                //copy
            
            
            //if z-value+index is more than right bndry ten calcaulate again 
            else 
            {
            left = i1 ;
            while (right<n && str[right-left]==str[right])
                right++ ;
                z_array[i1] = right-left ;
                right-- ;
            }
        }
    }
    return z_array ;
}


int main(int argc, char const *argv[])
{
 
    return 0;
}








