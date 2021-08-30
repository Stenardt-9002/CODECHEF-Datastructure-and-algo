
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>


using namespace std;







int *findTwoElement(int *arr , int n)
{
                    int *answer1;
                answer1 = new int[2];
            //     cout<<"CEHCK FUNCTION";
            // for (int i1 = 0; i1 < n; i1++)
            // {
            //     cout<< arr[i1]<< " ";
            // }
            
            
                for (int i1 = 0; i1 < n; i1++)
                {
                    if (arr[abs(arr[i1])-1]>0) // not already visisted
                    {
                        arr[abs(arr[i1])-1] = -arr[abs(arr[i1])-1];
                    }
                    else
                    {
                        answer1[0] = abs(arr[i1]); // this position is already marked therefore repeated //arr[i1]-1
                        // cout<<"DEBUG1 "<<answer1[0];
                    }
            
            
                }
            
                // check missing elment 
                for (int i1 = 0; i1 < n; i1++)
                {
                    if (arr[i1]>0)
                    {
                        //if it is positive meant aht index was not chcked 
                        answer1[1] = i1+1;
                    }
                    
            
                }
            
                
                return answer1 ;
        
        
        
}






int main(int argc, char const *argv[])
{
    int n ;
    cin>>n ;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    


    auto ans = findTwoElement(a,n);
    cout<<" "<<ans[0]<<" "<<ans[1];
    return 0;
}





