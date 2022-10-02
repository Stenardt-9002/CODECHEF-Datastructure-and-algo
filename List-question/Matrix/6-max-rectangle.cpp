#include<iostream>
#include<vector> 
#include<algorithm>
#include<stack>

using namespace std;


int max_histogram(vector<int> a1)
{
    stack<int> s1 ;
    int stp ;
    int max_area =0;
    int area_top = 0 ;
    int itr = 0;
    int n1 = a1.size();
    while (itr<n1)
    {
      if (s1.empty()|| a1[s1.top()]<=a1[itr] )
      {
          s1.push(itr++);
      }
      //itr right most top of stack left 

      else
      {
         stp = s1.top() ;
         s1.pop() ;
         area_top = a1[stp]*itr ;
         if (!s1.empty())
         {
           area_top = a1[stp]*(itr-s1.top()-1);
         }
         
          if (area_top>max_area)
          {
            max_area = area_top ;
          }

      }
      

      
    }
    //empty stacks 
    while (!s1.empty())
    {
        stp = a1[s1.top()] ;//top value
        s1.pop();
        area_top = stp*itr ;
        if (!s1.empty())
        {
          area_top = stp*(itr-s1.top()-1);
        }
        

      if(max_area<area_top)
      {
        max_area = area_top ;
      }


    }

    return max_area ;
    


}






int maxArea(int M[1000][1000], int n, int m) 
{
    vector<vector<int>> arr(n,vector<int>(m));
    for (int i1 = 0; i1 < n; i1++)
    {
      for (int j1 = 0; j1 < m; j1++)
      {
        arr[i1][j1] = M[i1][j1] ;
      }
      
    }
    
   int result1 = max_histogram(arr[0])  ;
    // cout<<result1;
  int max_result1 = 0 ;

  for (int i1 = 1; i1 < n; i1++)
  {
      for (int j1 = 0; j1 < m; j1++)
      {
        // as soon as 0 the histogram breaks 
        if(arr[i1][j1]==1){arr[i1][j1] = arr[i1-1][j1]+arr[i1][j1] ;}
      }
      max_result1 = max_histogram(arr[i1]) ;
      result1 = max(result1,max_result1) ;
      
  }
  

  return result1;
}




int main(int argc, char const *argv[])
{
    
    int n,m;cin>>n>>m;
  int M[1000][1000];
    for (int i1 = 0; i1 < n; i1++)
    {
      for (int j1 = 0; j1 < m; j1++)
      {
          cin>>M[i1][j1];
      }
    }
 int asnwer = maxArea(M,n,m)   ;





    return 0;
}














