class Solution
{
  insert(arr,i)
  {
     // code here such that insertionSort() sorts arr[]
     let key = arr[i];
     let  j = i-1 ;
     while(j>=0 && arr[j]>key)
     {
         arr[j+1] = arr[j] ; 
         j-- ;
     }
     arr[j+1] = key ;
  }

   //Function to sort the array using insertion sort algorithm.
  insertionSort(arr,n)
  {
   //code here
   let i ;
   for(i=1;i<n;i++)
   {
       this.insert(arr,i);
   }
  }
    
}