class Solution:
    def maxInstance(self, s : str) -> int:
        b_c = 0 
        a_c = 0 
        l_c = 0 
        o_c = 0 
        n_c = 0 
        for c in s:
            if c=='b':
                b_c+=1 
            elif c=='a':
                a_c+=1 
            elif c=='l':
                l_c+=1 
            elif c=='o':
                o_c+=1 
            elif c=='n':
                n_c+=1 
        
        l_c = l_c//2 
        o_c = o_c//2 
        return min(b_c , a_c , l_c , o_c , n_c)
        # code here

