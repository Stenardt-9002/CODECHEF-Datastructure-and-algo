try:
    t = int(input())
except EOFError:
    t=0
while t>1:
    corect = True
    try:
        k = int(input())

    except:
        k = 0
        continue
    try:
        str12 = input()
        str12 = list(str12)
    except:
        str12 = []
        continue

    ans = "NO"
    # print(str12)
    lenght = len(str12)
    # print(lenght)
    if k==1 and lenght!=1:
        print(ans)
        continue
    elif lenght==1:
        ans = '0'
        print(ans)
        continue

    if k==2 and lenght%2==1:
        ans = "NO"
        print(ans)
        continue
    for i in range(0,lenght):
        if str12[i]=='?':
            str12[i] = "0"
            # if i==0:
            #     while str12[lenght-1]==str12[i] or str12[i]==str12[(i+1)%lenght]:
            #         val = (int)(str12)
            #         val+=1
            #         str12 = (str)(val)

            # else:
            # print("i = ",(i+1)%lenght)
            while str12[i] == str12[(i+1)%lenght] or str12[i] == str12[i-1]:
                val = (int)(str12[i])
                val += 1
                str12[i] = (str)(val)

        # if i!=0:
        if str12[i]==str12[(i+1)%lenght] or str12[i] == str12[i-1]:
            ans = "NO"
            print(ans)
            corect = False
        # else:
        #     if str12[i] == str12[(i + 1) % lenght] or str12[i] == str12[lenght-1]:
        #         ans = "NO"
        #         print(ans)
        #         corect = False

        if corect == False:
            break




    if corect==True:
        str12 = "".join(str12)
        print(str12)


    t-=1
