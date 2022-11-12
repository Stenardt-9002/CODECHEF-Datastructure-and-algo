bool allow_prime(int num)
{
    for(int i = 2 ; i*i<=num;i++)
        if(num%i==0)
            return false ;
    return true ;
}



class Solution 
{
public:
    string isSumOfTwo(int N)
    {
        // code here
        for(int i1 = 2 ; i1<=N/2;i1++)
        if(allow_prime(i1)&& allow_prime(N-i1))
            return "Yes" ;
        
        
        return "No";
    }
};