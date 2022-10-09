// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day11/problem/job-sequencing-problem-1587115620






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
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


bool compartor(Job a , Job b)
{
    return a.profit>b.profit ;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr , arr+n , compartor);
    int deadline_until_now = 0;
    int ans1_profit = 0,job_count = 0 ;

    for (int i1 = 0; i1 < n; i1++)
        deadline_until_now = max(deadline_until_now , arr[i1].dead);

    vector<bool> done(deadline_until_now,false)    ;
    for (int i1 = 0; i1 < n; i1++)
    {
        int dead_line =arr[i1].dead-1 ;
        while(dead_line>=0 && done[dead_line]==true)
            dead_line--;
        if(dead_line>=0&&!done[dead_line])
        {
            ans1_profit+=arr[i1].profit ;
            job_count++ ;
            done[dead_line] = true ;
        }
    }
    return {job_count , ans1_profit};
} 



