# https://practice.geeksforgeeks.org/problems/missing-number-in-matrix5316/1
class Solution:
	def MissingNo(self, matrix):
		# Code here
		n = len(matrix)
		if n==1:
		    return 1 
		posi = -1
		posj = -1
		for i in range(n):
		    for j in range(n):
		        if matrix[i][j] == 0 :
		            posi = i 
		            posj = j 
		
		row_dp = [0]*n 
		col_dp = [0]*n 
		for i in range(n):
		    sum_row = 0
		    sum_col = 0
		    for j in range(n):
		        sum_row+=matrix[i][j]
		        sum_col+=matrix[j][i]
		    row_dp[i] = sum_row
		    col_dp[i] = sum_col
		
		row_sum = -1
		if posi!=0:
		    row_sum = row_dp[0]
		else:
		    row_sum = row_dp[1]
		for i in range(n):
		    if i!=posi and row_sum!=row_dp[i]:
		        return -1
# 		print(row_sum)

		col_sum = -1
		if posj!=0:
		    col_sum = col_dp[0]
		else:
		    col_sum = col_dp[1]
# 		print(col_sum)
		for i in range(n):
		    if i!=posj and col_sum!=col_dp[i]:
		        return -1
		
		if(row_sum!=col_sum):
		    return -1 
		

		diff = row_sum-row_dp[posi]
		if(diff+col_dp[posj]!=row_sum):
		    return -1 

	    diagonal = 0
        for i in range(n):
            diagonal+=matrix[i][i]
	    diagonal_cross = 0 
        for i in range(n):
            diagonal_cross+=matrix[i][n-1-i]
        if posi+posj==n-1 and posi==posj:
            if not(diagonal_cross+diff==row_sum and row_sum==diagonal+diff):
                return -1
            pass
        else:
            if (posi+posj==n-1 and not(diagonal_cross+diff==row_sum and row_sum==diagonal)):
                return -1
            if (posi==posj  and not(diagonal+diff==row_sum and row_sum==diagonal_cross)):
                return -1
#         print(posi)
#         print(posj)
# 		print(row_sum)
# 		print(diagonal)
# 		print(diagonal_cross)
		if diff<=0:
		    return -1
		return diff
		