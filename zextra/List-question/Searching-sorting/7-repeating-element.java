int[] findTwoElement(int arr[], int n) 
{
    // code here
    
    int []asnwer = new int[2];
    for(int i1 = 0;i1<n;i1++)
    {
        if(arr[Math.abs(arr[i1])-1]>0)
        {
            arr[Math.abs(arr[i1])-1] = -arr[Math.abs(arr[i1])-1] ;    
        }
        else
        {
            asnwer[0] = Math.abs(arr[i1]) ;
        }
        
    }
    for(int i1 = 0;i1<n;i1++)
    {
        if(arr[i1]>0)
        {
            asnwer[1] = i1+1;
        }
    }
    return asnwer;
    
}