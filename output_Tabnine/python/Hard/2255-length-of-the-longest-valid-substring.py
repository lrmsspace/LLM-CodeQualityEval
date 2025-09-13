#https://leetcode.com/problems/length-of-the-longest-valid-substring/
#You are given a string word and an array of strings forbidden.
#A string is called valid if none of its substrings are present in forbidden.
#Return the length of the longest valid substring of the string word.
#A substring is a contiguous sequence of characters in a string, possibly empty.
# 
#Example 1:
#Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
#Output: 4
#Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" and "aabc". The length of the longest valid substring is 4. 
#It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 
#Example 2:
#Input: word = "leetcode", forbidden = ["de","le","e"]
#Output: 4
#Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
#It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
# 
#Constraints:
#	1 <= word.length <= 105
#	word consists only of lowercase English letters.
#	1 <= forbidden.length <= 105
#	1 <= forbidden[i].length <= 10
#	forbidden[i] consists only of lowercase English letters.
class Solution(object):
    def longestValidSubstring(self, word, forbidden):
        """
        :type word: str
        :type forbidden: List[str]
        :rtype: int
        """
        # Initialize variables
        n = len(word)
        max_length = 0
        
        # Create a hash map to store the indices of forbidden substrings
        forbidden_indices = {}
        for forbidden_word in forbidden:
            for i in range(n - len(forbidden_word) + 1):
                if word[i:i+len(forbidden_word)] == forbidden_word:
                    forbidden_indices[forbidden_word] = i
        
        # Initialize variables to track the start and end indices of the current valid substring
        start = 0
        end = 0
        
        # Iterate through the word
        while end < n:
            # If the current substring is valid, update the max length
            if word[end] not in forbidden_indices or forbidden_indices[word[end]] > end:
                max_length = max(max_length, end - start + 1)
                end += 1
            else:
                # If the current substring is not valid, reset the start index to the next valid index
                start = forbidden_indices[word[end]] + 1
                end = start
        
        return max_length
        