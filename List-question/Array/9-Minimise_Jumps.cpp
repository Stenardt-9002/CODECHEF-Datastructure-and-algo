


#include<iostream>
#include<climits>
using namespace std ; 

//O(n^2)


// int minJumps(int arr1[],int n)
// {

//     int *jumps = new int[n];

//     // int i,j  ;

//     if (n==0 || arr1[0]==0)
//     {
//         return INT_MAX ; //no where to go
//     }
    
//     jumps[0] = 0  ;

//     //for all index 1 to n check dp varaible before that 
//     for (int i1 = 1; i1 < n; i1++)
//     {
//         jumps[i1] = INT_MAX ; 
//         for (int j1 = 0; j1 < i1; j1++)
//         {
//             if (i1<=arr1[j1]+j1 && jumps[j1]!=INT_MAX )
//             {
//                 jumps[i1] = min(jumps[i1] , jumps[j1]+1) ;
//                 break ;
//             }
//         }

//     }
//     return jumps[n-1];

//     delete[] jumps ; 

// }



// O(n) 


int minJumps(int arr1[],int n)
{



    if (n==0|| arr1[0]==0)
    {
        return -1;
    }
    if (n==1)
    {
        return 0 ;
    }
    int maxJump = arr1[0]+0 ; int eachstep = arr1[0] ; int jump1 = 1;
    
    int i1 = 1;//from second element 

    for (i1 = 1; i1 < n; i1++)
    {   
        if (i1==n-1)
        {
            return jump1 ;
        }

        maxJump = max(maxJump , i1+arr1[i1]) ;

        eachstep-- ; //analyse from i to step 

        if (eachstep==0)
        {
            
            jump1+=1 ;//another group 
            //check if max or not 
            if (i1>=maxJump)
            {
                // if max reach is still here no way end 
                return -1 ; 
            }

            eachstep = maxJump-i1 ;//another group length 


        }
        
        

    }
    
    return -1 ; //not suppose to reach here





}







int main(int argc, char const *argv[])
{
    int *arr1 ,n ;
    cin>>n ;
    arr1 = new int[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1] ; 
    }
    // cout<<endl;
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<arr1[i1]<<" " ; 
    // }
    
    cout<<endl<<minJumps( arr1, n) ;

    delete []arr1 ; 

    return 0;
}













