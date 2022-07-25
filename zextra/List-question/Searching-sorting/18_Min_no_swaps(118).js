class Solution
{
    //Function to find the minimum number of swaps required to sort the array.
	minSwaps(nums)
	{
		// code here
        let n = nums.length ;
        let arrcombine = []
        for (let i1 = 0; i1 < n; i1++) 
        arrcombine.push([nums[i1],i1]);

        arrcombine.sort(function(a,b){return a[0]-b[0];});
        let visted = new Array(n);

        for (let i1 = 0; i1 < n; i1++) 
            visted[i1] = false ;


        let ans = 0 ;

        for (let i1 = 0; i1 < n; i1++) {
            
            if(visted[i1]|| arrcombine[i1][1]==i1)
                continue ;
            
            let cycle_size = 0 ;
            let j1 = i1 ;
            while (!visted[j1]) {
                visted[j1] = true ;
                j1 = arrcombine[j1][1];
                cycle_size+=1 ;
            }
            if (cycle_size>1) 
                ans+=(cycle_size-1);
            
        }

        return ans ;
	}
}