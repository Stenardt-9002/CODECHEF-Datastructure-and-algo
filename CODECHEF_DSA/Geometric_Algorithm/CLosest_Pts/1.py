x1 = [[1,2],[4,5]]
import math
asnwer =[]
for i in range(len(x1)):
    tem1p = []
    for j in range(len(x1)):
        dit = (float)(math.sqrt((x1[i][0]-x1[j][0])**2+(x1[i][1]-x1[j][1])**2))
        tem1p.append(dit)
    asnwer.append(tem1p)
