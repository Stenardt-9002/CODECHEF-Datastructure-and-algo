#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    Node * next;
    Node * arb;
    Node (int x)
    {
        data=x;
        next=NULL;
        arb=NULL;
    }
        
};

void swap1(int &a , int &b)
{
    int tmep = a ;
    a = b ;
    b = tmep;
}


int partiont(vector<int> &arr,int l , int h)
{
    int keyx = arr[h];
    int i1 = l ;
    for (int j1 = l; j1 < h; j1++)
        if(arr[j1]<=keyx)    
        {
            swap1(arr[i1],arr[j1]);
            i1++;
        }
    swap1(arr[i1] , arr[h]);
    return i1;
}



int main(int argc, char const *argv[])
{
    int n ; cin>>n;
    vector<int> arr(n,0);
    for(auto &x : arr)
        cin>>x ;

    int pivot = partiont(arr,0,n-1);
    cout<<endl<<pivot<<endl ;
    for(auto x: arr)
        cout<<x<<" ";
    return 0;
}

