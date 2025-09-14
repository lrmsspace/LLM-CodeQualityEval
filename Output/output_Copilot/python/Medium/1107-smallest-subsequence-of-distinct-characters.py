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

        for i, c in enumerate(s):
            if c not in seen:
                while stack and c < stack[-1] and i < last_occurrence[stack[-1]]:
                    seen.remove(stack.pop())
                stack.append(c)
                seen.add(c)

        return ''.join(stack)        