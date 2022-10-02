from collections import Counter 



def firstRepeatedWord(sentence):
    lis = list(sentence.split(" "))
    frequencey = Counter(lis)
    for i in lis:
        if(frequencey[i]>1):
            return i 



