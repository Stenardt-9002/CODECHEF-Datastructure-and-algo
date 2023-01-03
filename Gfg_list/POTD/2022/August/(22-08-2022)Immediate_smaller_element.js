// https://practice.geeksforgeeks.org/problems/immediate-smaller-element1142/1

immediateSmaller(arr,n)
{
   //code here
   let i1 = 0;
   for(i1=0;i1<n-1;i1++)
        if(arr[i1]>arr[i1+1])
            arr[i1] = arr[i1+1];
        else 
            arr[i1] = -1;
    arr[n-1] = -1 ;
}


