function verify(val) 
{
    let atleast_zero = 0;
    let powe = 5 
    while(Math.floor(val/powe)!=0)
    {
        atleast_zero+=Math.floor(val/powe);
        powe*=5;
    }
    return atleast_zero ;
}

findNum(N)
{
    //code here
    if(N==0)
        return 0;
    if(N==1)
        return 5 ;
    
    let low = 5 ;
    let hugh = N*5;
    let ans1 = N*5;
    while (low<=hugh) 
    {
        let mid = (low+hugh)>>1 ;

        if(verify(mid)>=N)
        {
            ans1 = mid ;
            hugh = mid-1;
        }
        else
            low = mid+1 ;
    }
    return ans1 ;
}

