

// https://www.hackerrank.com/challenges/journey-to-the-moon/problem



#include <bits/stdc++.h>
using namespace std;


void dfs(int src ,int n , vector<bool> &visited ,vector<int>graph1[] ,long long int &count)
{
    visited[src] = true ;
    count+=1;
    for (auto des : graph1[src] )
    {
        if (!visited[des])
        dfs(des,n,visited,graph1,count);
    }
}



long long int journeyToMoon(int n, vector<vector<int>> astronaut) 
{
    vector<int> graph1[n];
    for (int i1 = 0; i1 <astronaut.size(); i1++)
    {
        // astronaut[i1][0]
        graph1[astronaut[i1][0]].push_back(astronaut[i1][1]);
        graph1[astronaut[i1][1]].push_back(astronaut[i1][0]);
    }
    

    //count component and its count
    vector<long long int>component_cnt ;
    long long int count1 = 0;
    long long int toatl1 = n;
    vector<bool> visited(n,false);
    for (long long int i1 = 0; i1 < n; i1++)
    {
        if (!visited[i1])
        {
            count1 = 0;
            dfs(i1,n,visited,graph1,count1);
            if (count1>1)
                component_cnt.push_back(count1);
            // toatl1+=count1 ;
        }
    }

    
    toatl1 = (toatl1*(toatl1-1))/2;//maximum pair
    // component pair 


    long long int temp1 ;
    for (auto i : component_cnt )
    {
        temp1 = (i*(i-1))/2;
        toatl1-=temp1;
    }
    
    return toatl1;

}


int main(int argc, char const *argv[])
{
    int n ;cin>>n ;
    int e ; cin>>e  ;
    vector<vector<int>> astronaut ;
    int temp1 ,temp2 ; 
    while (e--)
    {
        cin>>temp1>>temp2 ;
        astronaut.push_back({temp1,temp2});
    }
    cout<<journeyToMoon(n,astronaut);
    return 0;
}
