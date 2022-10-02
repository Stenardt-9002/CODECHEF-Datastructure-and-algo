
j = 0
while True:
    j+=1

    z = input().rstrip()
    z = list(z)
    # print(z)
    if '-' in z:
        break
    stack1 = []
    countright = 0
    countleft = 0
    print(j,end = '')
    print('.',end = ' ')
    if z == []:
        ans = 0
        print(ans)
        continue
    for i in z:
        if i == '{':
            stack1.append('{')
        else:
            if stack1:
                stack1.pop()
            else:
                countright +=1
    countleft = len(stack1)

    ans = 0
    if countleft%2==0 and countright%2==0:
        countleft/=2
        countright/=2
        ans = (int)(countleft+countright)
    else:
        countleft-=1
        countright-=1
        countleft/=2
        countright/=2
        ans = (int)(countleft+countright)
        ans +=2

    ans = (int)(ans)
    print(ans)
