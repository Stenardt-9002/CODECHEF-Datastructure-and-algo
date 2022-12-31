# https://practice.geeksforgeeks.org/problems/hopscotch4857/1





class Solution:
    def hopscotch(self, n, m, mat, ty, i, j):
        # code here
        arr1x = [-1,0,0,1,1,1]
        arr1y = [0,-1,1,-1,0,1]

        arr2x = [-1,-1,-1,0,0,1]
        arr2y = [-1,0,1,-1,1,0]

        arr3x = [-2,-2,-1,0,1,1,2,1,1,0,-1,-2]
        arr3y = [0,1,2,2,2,1,0,-1,-2,-2,-2,-1]

        arr4x = [-2,-1,-1,0,1,2,2,2,1,0,-1,-1]
        arr4y = [0,1,2,2,2,1,0,-1,-2,-2,-2,-1]




        sum1 = 0 

        if ty==0:
            if j%2==1:
                for index in range(len(arr1x)):
                    newx = i+arr1x[index]
                    newy = j+arr1y[index]
                    if(newx>=0 and newy>=0 and newx<n and newy<m):
                        sum1+=(mat[newx][newy])
            else:
                for index in range(len(arr2x)):
                    newx = i+arr2x[index]
                    newy = j+arr2y[index]
                    if(newx>=0 and newy>=0 and newx<n and newy<m):
                        sum1+=(mat[newx][newy])
            
        elif ty==1:
            if j%2==0:
                for index in range(len(arr3x)):
                    newx = i+arr3x[index]
                    newy = j+arr3y[index]
                    if(newx>=0 and newy>=0 and newx<n and newy<m):
                        sum1+=(mat[newx][newy])
            else:
                for index in range(len(arr4x)):
                    newx = i+arr4x[index]
                    newy = j+arr4y[index]
                    if(newx>=0 and newy>=0 and newx<n and newy<m):
                        sum1+=(mat[newx][newy])

        return sum1 
