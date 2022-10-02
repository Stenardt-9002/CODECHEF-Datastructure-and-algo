
class Solution
{
    merge(arr, l, m, r)
    {
         // Your code here
        let i1=0 , j1 =0 ,k1=0;
        let size1 = m-l+1 ;
        let size2 = r-m ;

        let array1 = new Array(size1);
        let array2 = new Array(size2);

        for(i1=0 ; i1<size1 ; i1++)
            array1[i1] = arr[l+i1] ;
        

        for(i1=0 ; i1<size2 ; i1++)
            array2[i1] = arr[m+1+i1] ;
        i1 = 0;
        j1 = 0;
        k1 = l;
        while (i1<size1 && j1<size2) 
            if(array1[i1]<=array2[j1])
                arr[k1++] = array1[i1++];
            else 
                arr[k1++] = array2[j1++];
        

        while (i1<size1) 
            arr[k1++] = array1[i1++];
        
        while (j1<size2) 
            arr[k1++] = array2[j1++];
    }
    
    mergeSort(arr, l, r)
    {
     //code here
     if(l<r)
     {
        let mid =  l+(r-l)>>1;
        this.mergeSort(arr,l,mid);
        this.mergeSort(arr,mid+1,r);
        this.merge(arr,l,mid,r);
     }
    }
    
}