#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n,x,y,ans=0;
    stack <long long int> s1;
    cin>>n;
    long long int arr1[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }  
  
  for(int i=0;i<n;i++)
   {
      while(!s1.empty())
       {
          if(s1.top()<arr1[i]) //makes sure second maximum is not equal to maximum
           {
            ans=max(ans,(s1.top() ^ arr1[i]));
            s1.pop();
           }
          else
           {
               ans=max(ans,(s1.top() ^ arr1[i]));
               break;
           }
      
   }
    s1.push(arr1[i]);
   }



cout<<ans;
    return 0;
}
// #bitchass question 
