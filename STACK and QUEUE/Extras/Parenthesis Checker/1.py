testces = int(input())

while testces>0:
    testces-=1
    s1r = list(input())
    stac_k = []
    for i1 in s1r:
        if i1=='(' or i1=='{' or i1=='[' :
            stac_k.append(i1)
            pass
        elif i1 == ')' :
            if stac_k!=[]:
                if stac_k[-1] == '(':
                    stac_k = stac_k[:-1]
                else:
                    stac_k = ["bro"]
                    break
            else:
                stac_k = ["bro"]
                break
            pass

        elif i1 == ']' :
            if stac_k!=[]:
                if stac_k[-1] == '[':
                    stac_k = stac_k[:-1]
                else:
                    stac_k = ["bro"]
                    break
            else:
                stac_k = ["bro"]
                break
            
        elif i1 == '}' :
            if stac_k!=[]:
                if stac_k[-1] == '{':
                    stac_k = stac_k[:-1]
                else:
                    stac_k = ["bro"]
                    break
            else:
                stac_k = ["bro"]
                break
           
    if stac_k==[]:
        print("balanced")
    else:
        print("not balanced")
        stac_k = []
        pass
    pass


