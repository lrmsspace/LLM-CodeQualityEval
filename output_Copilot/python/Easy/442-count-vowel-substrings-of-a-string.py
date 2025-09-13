#https://leetcode.com/problems/count-vowel-substrings-of-a-string/
#A substring is a contiguous (non-empty) sequence of characters within a string.
#A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
#Given a string word, return the number of vowel substrings in word.
# 
#Example 1:
#Input: word = "aeiouu"
#Output: 2
#Explanation: The vowel substrings of word are as follows (underlined):
#- "aeiouu"
#- "aeiouu"
#Example 2:
#Input: word = "unicornarihan"
#Output: 0
#Explanation: Not all 5 vowels are present, so there are no vowel substrings.
#Example 3:
#Input: word = "cuaieuouac"
#Output: 7
#Explanation: The vowel substrings of word are as follows (underlined):
#- "cuaieuouac"
#- "cuaieuouac"
#- "cuaieuouac"
#- "cuaieuouac"
#- "cuaieuouac"
#- "cuaieuouac"
#- "cuaieuouac"
# 
#Constraints:
#	1 <= word.length <= 100
#	word consists of lowercase English letters only.
class Solution(object):
    def countVowelSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        vowels = set('aeiou')
        count = 0
        n = len(word)
        
        for i in range(n):
            if word[i] in vowels:
                j = i + 1
                while j < n and word[j] in vowels:
                    j += 1
                if j - i >= 5:
                    count += (j - i - 4) * (j - i - 3) // 2
                i = j - 1
        
        return count        