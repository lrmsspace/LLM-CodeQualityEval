#https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
#A string is considered beautiful if it satisfies the following conditions:
#	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
#	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
#For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
#Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
#A substring is a contiguous sequence of characters in a string.
# 
#Example 1:
#Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
#Output: 13
#Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
#Example 2:
#Input: word = "aeeeiiiioooauuuaeiou"
#Output: 5
#Explanation: The longest beautiful substring in word is "aeiou" of length 5.
#Example 3:
#Input: word = "a"
#Output: 0
#Explanation: There is no beautiful substring, so return 0.
# 
#Constraints:
#	1 <= word.length <= 5 * 105
#	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
class Solution(object):
    def longestBeautifulSubstring(self, word):
        """
        :type word: str
        :rtype: int
        """
        vowels = ['a', 'e', 'i', 'o', 'u']
        vowel_index = {}
        for i in range(len(vowels)):
            vowel_index[vowels[i]] = i
        max_length = 0
        start = 0
        end = 0
        while end < len(word):
            if word[end] not in vowels:
                start = end + 1
                end = start
                continue
            if word[end] == 'a':
                if end - start >= 5:
                    max_length = max(max_length, end - start)
            elif vowel_index[word[end]] == vowel_index[word[end - 1]] + 1:
                if end - start >= 5:
                    max_length = max(max_length, end - start)
            else:
                start = end
            end += 1
            if end - start >= 5:
                max_length = max(max_length, end - start)
        return max_length
