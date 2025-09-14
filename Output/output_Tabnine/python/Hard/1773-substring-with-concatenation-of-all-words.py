#https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#You are given a string s and an array of strings words. All the strings of words are of the same length.
#A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
#	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
#Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
# 
#Example 1:
#Input: s = "barfoothefoobarman", words = ["foo","bar"]
#Output: [0,9]
#Explanation:
#The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
#The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
#Example 2:
#Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
#Output: []
#Explanation:
#There is no concatenated substring.
#Example 3:
#Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
#Output: [6,9,12]
#Explanation:
#The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
#The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
#The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
# 
#Constraints:
#	1 <= s.length <= 104
#	1 <= words.length <= 5000
#	1 <= words[i].length <= 30
#	s and words[i] consist of lowercase English letters.
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        # If the word list is empty, return an empty list
        if not words:
            return []
        
        # Initialize variables
        word_len = len(words[0])
        total_len = len(words) * word_len
        result = []
        
        # Create a dictionary to store the count of each word
        word_count = {}
        for word in words:
            if word in word_count:
                word_count[word] += 1
            else:
                word_count[word] = 1
        
        # Iterate through the string
        for i in range(len(s) - total_len + 1):
            # Create a copy of the word count dictionary
            current_count = word_count.copy()
            
            # Check if the current substring is a valid concatenated string
            for j in range(total_len // word_len):
                # Get the current word
                current_word = s[i + j * word_len : i + (j + 1) * word_len]
                
                # If the current word is not in the word count dictionary, break the loop
                if current_word not in current_count:
                    break
                
                # Decrement the count of the current word
                current_count[current_word] -= 1
                
                # If the count of the current word becomes 0, remove it from the dictionary
                if current_count[current_word] == 0:
                    del current_count[current_word]
        
        # If the current count dictionary is empty, it means we have found a valid concatenated string
        if not current_count:
            result.append(i)
        
        return result
        