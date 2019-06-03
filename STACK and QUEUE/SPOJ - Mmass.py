def stac_k(beg,lis_t):
    j = beg
    stac_kans = 0
    j = j+1
    # print("j")
    # print(j)
    # print("list")
    # print(lis_t)
    # skip (
    while(lis_t[j]!=')'):
        if lis_t[j] == '(':
            an_s1,skip = stac_k(j,lis_t)
            stac_kans = stac_kans+an_s1
            j = skip # doubt check again
        else:
            if lis_t[j].isdigit():
                mul1 = (int)(lis_t[j])
                stac_kans = stac_kans + dic_t[lis_t[j-1]]*(mul1-1)
            else:
                stac_kans = stac_kans + dic_t[lis_t[j]]
        
        j+=1
        # print("STACK ANS")
        # print(stac_kans)
    if j+1<len(lis_t):
        if lis_t[j+1].isdigit():
            mul12 = (int)(lis_t[j+1])
            stac_kans = stac_kans* mul12
            return stac_kans,j+1

    return stac_kans,j

    
z1 = input().split()
# for z in z1:
z = z1[0]
input1 = list(z)
i = 0
dic_t = {'H':1,'O':16,'C':12}
ans = 0
while(i<len(input1)):
    if input1[i] != '(' and input1[i].isdigit()==False:
        ans = ans+dic_t[input1[i]]
    elif input1[i].isdigit()==True:
        mul = (int)(input1[i])
        ans = ans+((mul-1)*(dic_t[input1[i-1]]))
    else:
        
        lit,end = stac_k(i,input1)
        i = end
        ans = ans + lit

    i+=1
print(ans)