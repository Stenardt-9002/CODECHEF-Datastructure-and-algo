

class Heapsort {
    public void sort(int arr[]) {
        int n = arr.length ; 
        for (int i1 = n/2; i1 >=0; i1--) 
        {
            heapify(arr,n,i1)     ;
        }
        for (int i = n-1; i >=0; i--) 
        {
            int temp = arr[0]    ;
            arr[0] = arr[i];
            arr[i] = temp ;
            heapify(arr,i,0);
        }

    }

    public void heapify(int arr[],int n , int i1) 
    {
        int largest = i1 ; int l = 2*i1+1;int r = 2*i1+2 ;
        
        if (l<n&&arr[largest]<arr[l]) 
        {
            largest = l ;
        }

        if (r<n&&arr[largest]<arr[r]) 
        {
            largest = r ;
        }
        int temp1 ;
        if (largest!=i1) {
            temp1 = arr[i1] ;arr[i1] = arr[largest] ; arr[largest] = temp1;
            heapify(arr, n, largest);

        }
        
        
    }
    








public static void main(String[] args) {
    int arr[] = {12,121,13,4,5,6,7,43,112,413} ;

    int n = arr.length ;
    Heapsort obj = new Heapsort() ;
    obj.sort(arr) ;

    for (int i1 = 0; i1 < n; i1++) {
        System.out.println(arr[i1]+ "  ");
    }

}

}





