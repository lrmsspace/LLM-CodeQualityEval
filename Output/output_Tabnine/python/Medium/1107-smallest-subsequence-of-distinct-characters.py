#https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
#Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
# 
#Example 1:
#Input: s = "bcabc"
#Output: "abc"
#Example 2:
#Input: s = "cbacdcbc"
#Output: "acdb"
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of lowercase English letters.
# 
#Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
class Solution(object):
    def smallestSubsequence(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Create a dictionary to store the last occurrence of each character
        last_occurrence = {c: i for i, c in enumerate(s)}
        
        # Create a stack to store the characters in the subsequence
        stack = []
        
        # Iterate through the string in reverse order
        for i in range(len(s)-1, -1, -1):
            # If the character is not already in the stack and it has a smaller last occurrence
            if s[i] not in stack and last_occurrence[s[i]] > stack[-1:].index(stack[-1]) if stack else -1:
                # Push it onto the stack
                stack.append(s[i])
        
        # Convert the stack to a string and return it
        return ''.join(stack)   
        