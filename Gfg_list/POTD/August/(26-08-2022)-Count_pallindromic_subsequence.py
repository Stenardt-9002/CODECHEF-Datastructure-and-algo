

MOD1 = 1000000007

def countPS(string):
    n = len(string)
    dp1 = [[0 for _ in range(n+1)] for _ in range(n+1)]
    for i in range(n):
        dp1[i][i] = 1 
    
    for lenvar in range(2,n+1):
        for star in range(0 , n-lenvar+1):
            if (string[star]==string[star+lenvar-1]):
                dp1[star][star+lenvar-1] = dp1[star][star+lenvar-2] + dp1[star+1][star+lenvar-1]+1

            else :
                dp1[star][star+lenvar-1] = dp1[star][star+lenvar-2] + dp1[star+1][star+lenvar-1] - dp1[star+1][star+lenvar-2]
        pass 

    return dp1[0][n-1]%MOD1



