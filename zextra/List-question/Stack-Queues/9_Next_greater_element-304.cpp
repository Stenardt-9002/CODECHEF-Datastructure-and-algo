


// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/








#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;





vector<long long> nextLargerElement(vector<long long> arr, int n)
{
   stack<long long> s1;
   vector<long long > ans1(n,-1) ;

   s1.push(0)  ;
   for (int i1 = 1; i1 < n; i1++)
   {
        if (s1.empty())
           s1.push(i1);
           
        else
        {

            while (!s1.empty() && arr[s1.top()]<arr[i1] )
            {
                ans1[s1.top()] = arr[i1];
                s1.pop() ;//done
            }
           s1.push(i1);
        }
   }
   
    return ans1;

}










