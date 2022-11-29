# def function(wordlist):
# #storing word in reverse format along with their indices.

# 	hashmap_reverse = {word[::-1]: index for index, word in enumerate(wordlist)}
# 	ans = []
# 	#enumerating over all words and for each character of them
# 	for index, word in enumerate(wordlist):
# 		for i in range(len(word)):
# 		#extracting left and right of them
# 			left, right = word[:i+1], word[i+1:]
# 			#checking if left exists and is palindrome and also right is present in map
# 			#this is to make sure the best edge case described holds.
			
# 			if not len(left) == 0 and left == left[::-1] and right in hashmap_reverse and hashmap_reverse[right] != index:
# 				ans.append([hashmap_reverse[right], index])
			
# 			#normal case.
# 			if right == right[::-1] and left in hashmap_reverse and hashmap_reverse[left] != index:
# 				ans.append([index, hashmap_reverse[left]])
# 	if len(ans)>0:
# 		return True
# 	return False


#storing word in reverse format along with their indices.
def palindromepair(N, arr):

	ans = []
	hash_arr = {word[::-1]: index for index, word in enumerate(arr)}
	for index_i, str1 in enumerate(arr):
		for i in range(len(str1)):
			left_str, right_str = str1[:i+1], str1[i+1:]
			if not len(left_str) == 0 and left_str == left_str[::-1] and right_str in hash_arr and hash_arr[right_str] != index_i:
				ans.append([hash_arr[right_str], index_i])
			
			if right_str == right_str[::-1] and left_str in hash_arr and hash_arr[left_str] != index_i:
				ans.append([index_i, hash_arr[left_str]])
	if len(ans)>0:
		return True
	return False


words = ["geekf", "geeks", "or","keeg", "abc", "bc"]
print(function(words))




words = ["geekf", "geeks", "or","keeg", "abc", "bc"]
print(function(words))
