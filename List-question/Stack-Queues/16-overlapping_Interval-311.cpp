// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;

// struct Interval
// {
//     int statr,end ;
// };

bool compares(vector<int> a1 , vector<int> b1)
    {return b1[0]>a1[0] ;}

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
{
    stack<vector<int>> s1 ;
    vector<vector<int>> answer1 ;
    vector<int> temp1,temp2(2) ;
    sort(intervals.begin(),intervals.end(),compares);
    for (auto x : intervals)
    {
        // cout<<x[0]<<" "<<x[1]<<endl ;
        if (s1.empty())
            s1.push(x) ;
        else
        {
            temp1 = s1.top() ;
            s1.pop() ;
            if ( temp1[1]>=x[0])
            {
                temp2[0] = min(temp1[0],x[0]) ;
                temp2[1] = max(temp1[1],x[1]) ;
                s1.push(temp2) ;
            }
            else
            {
                s1.push(temp1) ;
                s1.push(x) ;
            }
        
        }
    }
    while (!s1.empty())
    {
        answer1.push_back(s1.top()) ;
        s1.pop() ;
    }
    reverse(answer1.begin(),answer1.end()) ;
    return answer1 ;
}

int main(int argc, char const *argv[])
{

    int n;
    int temp1,temp2 ;
    cin>>n;
    vector<vector<int>> intervals ;
    vector<int>a(2);
    while (n--)
    {
        cin>>temp1>>temp2 ;
        a[0] = temp1 ;a[1] = temp2 ;
        intervals.push_back(a) ;
    }
    intervals = overlappedInterval(intervals);
    for (auto x : intervals)
        cout<<"\n"<<x[0]<<" "<<x[1] ;



    return 0;
}






