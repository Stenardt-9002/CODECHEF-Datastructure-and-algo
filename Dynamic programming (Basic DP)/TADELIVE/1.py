# greedy methoid
n,x,y = map(int,input().split())
ar1 = list(map(int,input().split()))
ar2 = list(map(int,input().split()))
diff = [abs(ar1[i]-ar2[i]) for i in range(len(ar1))]

# print(diff)
neware = [x for x,_ in sorted(zip(ar1,diff), key = lambda pr:pr[1])]
# print(neware)
neware2 = [x for x,_ in sorted(zip(ar2,diff), key = lambda pr:pr[1])]
toalmoeyn = 0
one1orders = 0
two2orders =  0
for i in range(len(neware)):
    if(neware[i]>neware2[i]):
        if one1orders<x:
            one1orders+=1
            toalmoeyn+=neware[i]
            pass
        else:
            two2orders+=1
            toalmoeyn+=neware2[i]
    # pass
    else:
        if two2orders<y:
            two2orders+=1
            toalmoeyn+=neware2[i]
            pass
        else:
            one1orders+=1
            toalmoeyn+=neware[i]

print(toalmoeyn)
