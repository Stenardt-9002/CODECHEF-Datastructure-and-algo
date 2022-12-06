


# def format_string 


def rearrange(S, N):
    hash_map = [0]*26 
    for i in S:
        hash_map[ord(i)-97]+=1 
    index = ['a','e' ,'i' , 'o' , 'u']
    index = [ord(i)-97 for i in index]
    indices = [i for i in range(26)]
    indices = list(set(indices)-set(index) )
    vowel_count = 0 
    consonant_count = 0

    for i in index:
        vowel_count+=hash_map[i]
    consonant_count = len(S) -vowel_count
    diff = abs(vowel_count-consonant_count)
    if (not(diff==0 or diff==1)):
        return "-1"
    diff = vowel_count-consonant_count
    ans1 = ""
    if diff == 0 :
        start = 0
        for i in range(26):
            if(hash_map[i]>0):
                start = i 
                break 
        i = start
        currentvowel = i in index  
        while len(ans1)!=len(S):
            ans1+=(chr(i+97))
            hash_map[i]-=1
            currentvowel = not currentvowel
            if currentvowel:
                for j in index:
                    if(hash_map[j]>0):
                        i = j 
                        break 
            else :
                for j in indices:
                    if(hash_map[j]>0):
                        i = j 
                        break


            
    elif diff==1 :
        #start with vowel 
        start = 0
        for i in index:
            if(hash_map[i]>0):
                start = i 
                break 
        i = start
        currentvowel = i in index  
        while len(ans1)!=len(S):
            ans1+=(chr(i+97))
            hash_map[i]-=1
            currentvowel = not currentvowel
            if currentvowel:
                for j in index:
                    if(hash_map[j]>0):
                        i = j 
                        break 
            else :
                for j in indices:
                    if(hash_map[j]>0):
                        i = j 
                        break

    else :
        # start with consonant 
        start = 0
        for i in indices:
            if(hash_map[i]>0):
                start = i 
                break 
        i = start
        currentvowel = i in index  
        while len(ans1)!=len(S):
            ans1+=(chr(i+97))
            hash_map[i]-=1
            currentvowel = not currentvowel
            if currentvowel:
                for j in index:
                    if(hash_map[j]>0):
                        i = j 
                        break 
            else :
                for j in indices:
                    if(hash_map[j]>0):
                        i = j 
                        break


    return ans1

    # code here
    
str = input()
print(rearrange(str,len(str)))