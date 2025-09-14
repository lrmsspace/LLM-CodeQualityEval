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
        stack = []
        seen = set()
        last_occurrence = {c: i for i, c in enumerate(s)}
        
        for i, char in enumerate(s):
            if char not in seen:
                while stack and char < stack[-1] and i < last_occurrence[stack[-1]]:
                    seen.discard(stack.pop())
                seen.add(char)
                stack.append(char)
        
        return ''.join(stack)

