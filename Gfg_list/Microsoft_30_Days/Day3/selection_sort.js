class Solution
{
    select(arr,i)
    {
       // code here such that selectionSort() sorts arr[]
       let min_idx = i ,j;
       let n = arr.length;
       for(j=i+1 ; j<n ; j++)
          if(arr[j]<arr[min_idx])
              min_idx = j ;
      
      let swap1 = arr[i] ; 
      arr[i] = arr[min_idx];
      arr[min_idx] = swap1 ;
    }
  
    //Function to sort the array using selection sort algorithm.
    selectionSort(arr,n)
    {
     //code here
     let i = 0 ;
      for(i=0;i<n-1;i++)
          this.select(arr,i);
    }
      
  }