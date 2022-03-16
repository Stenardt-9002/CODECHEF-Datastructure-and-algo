// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/

// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/


//This is an excellent methodolgy 


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;







class Solution{
    int minEle;
    stack<int> s;
    public:
    
       int getMin()
       {
           if (!s.empty())
                return minEle ;
            return -1;           
       }
       
       int pop()
       {
           int ans;
            if (s.empty())
                return -1; //empty stack 

            else if(s.top()<minEle) //mark that min Ele was the element getting popped and now minEle needs to be changed
            {
                ans = minEle ;
                minEle = 2*minEle-s.top();
                s.pop();
                return ans ;
            }
            ans = s.top(); s.pop();
            return ans ;

       }
       
       void push(int x)
       {
           if (s.empty())
           {
               minEle = x ; s.push(x) ;
           }
           else if(x<minEle)
           {
                //new min 
                s.push(2*x-minEle);
                minEle = x ;
           }
           else
                s.push(x)           ;
           
           
       }
};






