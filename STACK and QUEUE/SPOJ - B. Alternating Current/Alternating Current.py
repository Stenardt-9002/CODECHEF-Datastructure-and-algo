x = input()
stk1 = []
for i in x:
    if stk1 == []:
        stk1.append(i)
    else:
        if stk1[-1] == i:
            stk1.pop()
        else :
            stk1.append(i)
        
if stk1 == []:
    print("Yes")
else:
    print("No")