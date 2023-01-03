
from collections import deque 

class Solution:
	def wordLadderLength(self, startWord, targetWord, wordList):
		#Code here
		if startWord==targetWord:
            return 0
        if targetWord not in wordList:
            return 0
        
        cur_level = 0 
        WordLength = len(startWord)

        Queue_1 = deque()
        Queue_1.append(startWord)
        while len(Queue_1)>0:
            cur_level+=1 
            sizeq = len(Queue_1)
            for i in range(sizeq):
                word = [j for j in Queue_1.popleft()]
                # WordLength = len(word)
                
                for pos in range(WordLength):
                    orig_char = word[pos]
                    for c in range(ord('a') , ord('z')+1):
                        if chr(c)!=orig_char:
                            word[pos] = chr(c) 
                            if("".join(word) == targetWord):
                                return cur_level+1 
                            
                            if("".join(word) not in wordList):
                                continue 
                            wordList.remove("".join(word))
                            Queue_1.append("".join(word))
                    word[pos] = orig_char 
        return 0 





		#Code here