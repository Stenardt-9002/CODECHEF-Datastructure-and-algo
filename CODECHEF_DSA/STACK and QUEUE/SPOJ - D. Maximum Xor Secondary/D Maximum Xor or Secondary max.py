n = int(input())
li_t = list(map(int,input().split()))
stk1 =[]
ans = 0
for i in li_t:
    while stk1!=[]:
        if stk1[-1]<i:
            ans = max(ans,(stk1[-1]^i))
            stk1.pop()
        else:
            ans = max(ans,(stk1[-1]^i))
            break
        
    stk1.append(i)

print(ans)