#https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
#Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
#if no such substring exists, return 0.
# 
#Example 1:
#Input: s = "aaabb", k = 3
#Output: 3
#Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
#Example 2:
#Input: s = "ababbc", k = 2
#Output: 5
#Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of only lowercase English letters.
#	1 <= k <= 105
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # Initialize the frequency dictionary
        freq_dict = {}
        
        # Initialize the start and end indices of the current substring
        start, end = 0, 0
        
        # Initialize the maximum length of the substring
        max_length = 0
        
        # Iterate through the string
        while end < len(s):
            # If the character is already in the frequency dictionary, increment its count
            if s[end] in freq_dict:
                freq_dict[s[end]] += 1
            # If the character is not in the frequency dictionary or its count is less than k,
            # move the start index to the next character
            else:
                while s[start] not in freq_dict or freq_dict[s[start]] < k:
                    start += 1
                freq_dict[s[start]] -= 1
            
            # Update the maximum length of the substring
            max_length = max(max_length, end - start + 1)
            
            # Move the end index to the next character
            end += 1
        
        return max_length
        