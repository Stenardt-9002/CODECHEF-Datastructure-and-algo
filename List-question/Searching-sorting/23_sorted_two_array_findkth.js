// kthElement(A,B,n,m,k)
// { 
//     //code here
//     if(n==1 || m==1)
//     {
//         if(m==1)
//         {   
//             let temp = A ;
//             A = B ;
//             B = temp ;

//             m= n;
//         }
    
//         if(k==1)
//             return min(A[0],B[0]);
//         else if (k==m+1)
//             return max(A[0],B[0]);
//         else 
//         {
//             if(B[k-1]<A[0])
//                 return B[k-1];
//             else 
//                 return max(A[0],B[k-2]);
//         }
//     }
//     var mid1 = n/2 ;
//     var mid2 = m/2;

//     if(mid1+mid2+1<k)
//     {
//         if(A[mid1]<B[mid2])
//             return kthElement(A.slice(mid1+1,n),B,n-mid1-1,m ,k-mid1-1) ;

//         else 
//             return kthElement(A,B.slice(mid2+1,m),n,m-mid2-1,k-mid2-1) ;

//     }
//     else 
//     {
//         if(A[mid1]<B[mid2])
//             return kthElement(A,B.slice(0,mid2+1),n,mid2+1 ,k) ;

//         else 
//             return kthElement(A.slice(0,mid1+1),B,mid1+1,m,k) ;
//     }


// }

// minSwaps(nums)
// {
//     // code here
//     let n = nums.length ;
//     let arrcombine = []
//     for (let i1 = 0; i1 < n; i1++) 
//     arrcombine.push([nums[i1],i1]);

//     arrcombine.sort(function(a,b){return a[0]-b[0];});
//     let visted = new Array(n);

//     for (let i1 = 0; i1 < n; i1++) 
//         visted[i1] = false ;


//     let ans = 0 ;

//     for (let i1 = 0; i1 < n; i1++) {
        
//         if(visted[i1]|| arrcombine[i1][1]==i1)
//             continue ;
        
//         let cycle_size = 0 ;
//         let j1 = i1 ;
//         while (!visted[j1]) {
//             visted[j1] = true ;
//             j1 = arrcombine[j1][1];
//             cycle_size+=1 ;
//         }
//         if (cycle_size>1) 
//             ans+=(cycle_size-1);
        
//     }

//     return ans ;
// }



function kthElement(arr1, m, arr2, n, k)
{
 
    if (k > (m + n) || k < 1){
        return -1;
    }
    if (m > n){
        return kthElement(arr2, n, arr1, m, k);
    }
    if (m == 0){
        return arr2[k - 1];
    }
    if (k == 1){
        return Math.min(arr1[0], arr2[0]);
    }
    let i = Math.min(m, parseInt(k / 2));
    let j = Math.min(n,  parseInt(k / 2));
 
    if (arr1[i - 1] > arr2[j - 1]){
       
        let temp = arr2.slice(j,n)
        return kthElement(arr1, m, temp, n - j, k - j);
        }
    else{
       
        let temp = arr1.slice(i,m)
        return kthElement( temp, m - i, arr2, n, k - i);
        }
}


