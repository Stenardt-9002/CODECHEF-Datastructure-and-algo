// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day8/problem/the-painters-partition-problem1535


function func_allow(arr,n,k,current_time) 
{
    let current_sum = 0 , i1 =0 , j1=0 ;
    while (i1<n&&j1<k) 
    {
        if(arr[i1]+current_sum<=current_time)    
            current_sum+=arr[i1++];
        else 
        {
            j1++ ;
            current_sum = 0 ;
        }
    }
    if(i1!=n)
        return false ;
    return true ;
}



minTime(arr, n, k)
{
    // code here
    let sum1 = 0;
    let max1 = -9999 ;
    for (let i1 = 0; i1 < n; i1++) 
    {
        sum1+=arr[i1];
        max1 = Math.max(max1 , arr[i1]);
    }
        
    if(k==1)
        return sum1 ;
    if(n==1)
        return arr[0];
    if(n<=k)
        return max1;

    let ans1 = sum1 ;
    while (max1<=sum1) 
    {
        let mid = (max1+sum1)/2;  
        mid = Math.floor(mid);  
        if(func_allow(arr,n,k,mid))
        {
            ans1 = mid ;
            sum1 = mid-1;
        }
        else 
        {
            max1 = mid+1 ;
        }
    }


    return ans1 ;
    

}


