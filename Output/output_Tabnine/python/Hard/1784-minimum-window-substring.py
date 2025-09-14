#https://leetcode.com/problems/minimum-window-substring/
#Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
#The testcases will be generated such that the answer is unique.
# 
#Example 1:
#Input: s = "ADOBECODEBANC", t = "ABC"
#Output: "BANC"
#Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
#Example 2:
#Input: s = "a", t = "a"
#Output: "a"
#Explanation: The entire string s is the minimum window.
#Example 3:
#Input: s = "a", t = "aa"
#Output: ""
#Explanation: Both 'a's from t must be included in the window.
#Since the largest window of s only has one 'a', return empty string.
# 
#Constraints:
#	m == s.length
#	n == t.length
#	1 <= m, n <= 105
#	s and t consist of uppercase and lowercase English letters.
# 
#Follow up: Could you find an algorithm that runs in O(m + n) time?
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # Initialize variables
        min_len = float('inf')
        start = 0
        char_count = {}
        t_count = {}
        
        # Count the frequency of each character in t
        for char in t:
            t_count[char] = t_count.get(char, 0) + 1
        
        # Initialize variables for the sliding window
        left = 0
        right = 0
        match_count = 0
        
        while right < len(s):
            # Add the character to the sliding window
            char = s[right]
            char_count[char] = char_count.get(char, 0) + 1
            
            # If the character is in t and its frequency is less than or equal to its frequency in t
            if char in t_count and char_count[char] <= t_count[char]:
                match_count += 1
            
            # Move the left pointer if the current window is valid
            while match_count == len(t_count) and left <= right:
                # Update the minimum window length
                current_len = right - left + 1
                if current_len < min_len:
                    min_len = current_len
                    start = left
                
                # Remove the character from the sliding window
                char = s[left]
                char_count[char] -= 1
                
                # If the character is in t and its frequency is more than its frequency in t
                if char in t_count and char_count[char] < t_count[char]:
                    match_count -= 1
                
                # Move the left pointer
                left += 1
            right += 1
        
        return "" if min_len == float('inf') else s[start:start+min_len]
        