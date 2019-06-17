def stack_imple_maxarea(lis_t1):
    stack1 = []
    ara = []
    index = 0
    area = 0
    # linear traversal in the list
    while index<len(lis_t1):
        # two cases stack empty or 
        if stack1== [] or lis_t1[index]>=lis_t1[stack1[-1]]:
            stack1.append(index)
            index +=1
        else:
            #keep removing  while top of stack is greater than index (list value)
            popped = stack1.pop()
            if stack1 != []:
                area = lis_t1[popped]*(index-stack1[-1]-1)
            else:
                area = lis_t1[popped]*index
        ara.append(area)
    #empty stack 
    while stack1!=[]:
        popped = stack1.pop()
        if stack1 != []:
            area = lis_t1[popped]*(index-stack1[-1]-1)
        else:
            area = lis_t1[popped]*index
        ara.append(area)
    
    return max(ara)

while True:
    try :
        li_st = list(map(int,input().split()))
    except:
        pass
    if len(li_st) == 1 or len(li_st)==0:
        break
    
    li_st = li_st[1:]

    print("\n"+str(stack_imple_maxarea(li_st)),end = '')