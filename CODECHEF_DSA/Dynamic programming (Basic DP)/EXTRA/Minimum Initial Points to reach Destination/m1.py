testcaies = int(input())


while testcaies>0:
    testcaies-=1
    row,col = map(int,input().split())
    # print(row)
    # print(col)

    dat_a1 = []
    dyna_tae = []
    x1 = list(map(int,input().split()))

    for i in range(row):
        dat_a1.append(x1[i*col:(i+1)*col])
        dyna_tae.append([0 for i in range(col)])
        # print(x1[i*col:(i+1)*col])
        # pass 

    # dat_a1 = dat_a1[:-1]
    # print(dat_a1)
    # print(dyna_tae )
    if dat_a1[row-1][col-1]>0:
        dyna_tae[row-1][col-1] = 1
    else:
        dyna_tae[row-1][col-1] = -dat_a1[row-1][col-1]+1

    
    for var1 in range(col-2,-1,-1):
        dyna_tae[row-1][var1] = max(dyna_tae[row-1][var1+1]-dat_a1[row-1][var1],1)

    
    for var1 in range(row-2,-1,-1):
        dyna_tae[var1][col-1] = max(dyna_tae[var1+1][col-1]-dat_a1[var1][col-1],1)


    for var1 in range(row-2,-1,-1):
        for var2 in range(col-2,-1,-1):
            last_pts = min(dyna_tae[var1+1][var2],dyna_tae[var1][var2+1])
            dyna_tae[var1][var2] = max(last_pts-dat_a1[var1][var2],1)
            pass
        pass

    

    print(dyna_tae[0][0])

    pass

