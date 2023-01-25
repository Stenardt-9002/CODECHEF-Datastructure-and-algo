def countsetBits(n):
    count = 0 
    while n:
        count+=(n&1)
        n>>=1 
    return count 

class Solution:
    def minVal(self, a, b):
        #code here
        set_bitsa = countsetBits(a)
        set_bitsb = countsetBits(b)
        if(set_bitsa==set_bitsb):
            return a 
        elif set_bitsa<set_bitsb:
            no_of_extra_bits = set_bitsb-set_bitsa 
            b_copy = a
            ans = 0
            count_1 = 0 
            while b_copy>0 and no_of_extra_bits>0:
                if b_copy&1==0:
                    ans = ans+2**count_1
                    no_of_extra_bits-=1
                b_copy//=2 
                
                count_1+=1
            while no_of_extra_bits>0:
                ans = ans+2**count_1
                count_1+=1
                no_of_extra_bits-=1
            return ans^a
            pass 
        else :
            no_of_extra_bits = set_bitsa-set_bitsb
            b_copy = a
            ans = 0
            count_1 = 0 
            while b_copy>0 and no_of_extra_bits>0:
                if b_copy&1==1:
                    ans = ans+2**count_1
                    no_of_extra_bits-=1
                b_copy//=2 
                
                count_1+=1
            # while no_of_extra_bits>0:
            #     ans = ans+2**count_1
            #     count_1+=1
            #     no_of_extra_bits-=1
            return ans^a
            pass 
            
        # return -1
            
            