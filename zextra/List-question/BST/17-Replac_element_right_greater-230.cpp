
// https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




vector<int> replace_get_using_Stack(vector<int>arr , int n)
{
    vector<pair<int,int>> temp1 ;
    for (int i1 = 0; i1 < n; i1++)
        temp1.push_back({arr[i1],i1});


    sort(temp1.begin(),temp1.end());
    vector<int> indexes(n,-1) ;//= nexGreaterIndex(temp1);


    stack<int> s1 ;


    for (int i1 = 0; i1 < n; i1++)
    {
        if (s1.empty()||temp1[i1].second<s1.top())
            s1.push(temp1[i1].second);


        else
        {
            while (!s1.empty()&&temp1[i1].second>s1.top())
            {
                indexes[s1.top()] = temp1[i1].second;
                s1.pop();
            }
            s1.push(temp1[i1].second);
        }
    }
    
    vector<int> ans1(n,-1);
    for (int i1 = 0; i1 < n; i1++)
    {
        if (indexes[temp1[i1].second]!=-1)
        {
            ans1[temp1[i1].second] = indexes[temp1[i1].second];
        }
        
    }
    
    return ans1;

}







