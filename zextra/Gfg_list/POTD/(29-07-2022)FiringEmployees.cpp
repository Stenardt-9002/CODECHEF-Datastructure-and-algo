// https://practice.geeksforgeeks.org/problems/firing-employees5306/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


bool is_prime(int a)
{
    for (int i1 = 2; i1 <=sqrt(a); i1++)
        if(a%i1==0)    
            return false ;
    return true ;
}

int firingEmployees(vector<int> &arr, int n)
{
    // code here          
    int ans1 = 0 ;

    vector<vector<int>>graph1(n) ; 
    //graph directed 
    for (int i1 = 0; i1 < n; i1++)
        if(arr[i1]!=0)
        graph1[arr[i1]-1].push_back(i1);


//only one ggek
    int src ;
    for (int i1 = 0 ;i1<n ;i1++)
        if(arr[i1]==0)
            src = i1 ;
    queue<int> q1 ; 
    // q1.push(src);
    for(auto child : graph1[src])
        q1.push(child);

    int current_parents = 0;
    while (!q1.empty())
    {
        current_parents++ ;
        int qsize = q1.size();
        for (int i1 = 0; i1<qsize ;i1++)
        {
            int top = q1.front();
            q1.pop();
            if(is_prime(top+1+current_parents))
                ans1++ ;

            for(auto child : graph1[top])
                q1.push(child);
        }
    }
    
    return ans1 ;

}


int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tesecase ; cin>>tesecase ;
    while(tesecase--)
    {   
        int n;
        cin>>n ;
        vector<int> input1(n,0) ; 
        for (int i1 = 0; i1 < n; i1++)
            cin>>input1[i1];
        
        cout<<firingEmployees(input1,n)<<endl;
    }
    return 0;
}