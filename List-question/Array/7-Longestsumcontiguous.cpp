#include<iostream>
#include<climits>



// int maxSubArraySum(int a[],int size)
// {
//     int max_so_far = -999 , max_ending_till_here=0 ; 

//     for (int i1 = 0; i1 < size; i1++)
//     {
//         max_ending_till_here+=a[i1] ; 

//         if (max_so_far < max_ending_till_here )
//         {
//             max_so_far = max_ending_till_here ; 
//         }

//         if (max_ending_till_here<0)
//         {
//             max_ending_till_here = 0 ; 
//         }
        
        
//     }
    
//     return max_so_far ; 



// }



//also saving store index 

int maxSubArraySum(int a[],int size)
{
    int max_so_far = -999 , max_ending_till_here=0 ; 
    int start =0 ,end = 0 , s = 0 ; 


    for (int i1 = 0; i1 < size; i1++)
    {
        max_ending_till_here+=a[i1] ; 

        if (max_so_far < max_ending_till_here )
        {
            max_so_far = max_ending_till_here ; 
            start = s ;
            end = i1 ;  // update end index till here 

        }

        if (max_ending_till_here<0)
        {
            max_ending_till_here = 0 ; 
            //update start index
            s = i1+1;

        }
        
        
    }
    
    return max_so_far ; 



}




int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}