#https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
#You are given an array of strings words. Each element of words consists of two lowercase English letters.
#Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
#Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
#A palindrome is a string that reads the same forward and backward.
# 
#Example 1:
#Input: words = ["lc","cl","gg"]
#Output: 6
#Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
#Note that "clgglc" is another longest palindrome that can be created.
#Example 2:
#Input: words = ["ab","ty","yt","lc","cl","ab"]
#Output: 8
#Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
#Note that "lcyttycl" is another longest palindrome that can be created.
#Example 3:
#Input: words = ["cc","ll","xx"]
#Output: 2
#Explanation: One longest palindrome is "cc", of length 2.
#Note that "ll" is another longest palindrome that can be created, and so is "xx".
# 
#Constraints:
#	1 <= words.length <= 105
#	words[i].length == 2
#	words[i] consists of lowercase English letters.
class Solution(object):
    def longestPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        # Create a dictionary to store the frequency of each character
        freq = {}
        for word in words:
            freq[word[0]] = freq.get(word[0], 0) + 1
            freq[word[1]] = freq.get(word[1], 0) + 1
        
        # Sort the characters in descending order based on their frequency
        sorted_chars = sorted(freq.keys(), key=lambda x: freq[x], reverse=True)
        
        # Initialize the maximum length of the palindrome
        max_length = 0
        
        # Iterate through the sorted characters
        for char in sorted_chars:
            # Check if there is another character with the same frequency
            if freq[char] > 1:
                # Add the length of the palindrome formed by concatenating the two characters
                max_length += 2
                # Decrement the frequency of both characters
                freq[char] -= 2
        
        # Return the maximum length of the palindrome
        return max_length
        