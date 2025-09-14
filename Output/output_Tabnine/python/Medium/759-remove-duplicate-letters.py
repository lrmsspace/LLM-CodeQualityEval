#https://leetcode.com/problems/remove-duplicate-letters/
#Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
# 
#Example 1:
#Input: s = "bcabc"
#Output: "abc"
#Example 2:
#Input: s = "cbacdcbc"
#Output: "acdb"
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of lowercase English letters.
# 
#Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        count = collections.Counter(s)
        visited = set()
        
        for char in s:
            count[char] -= 1
            if char in visited:
                continue
            while stack and stack[-1] > char and count[stack[-1]] > 0:
                visited.remove(stack.pop())
            stack.append(char)
            visited.add(char)
        return ''.join(stack)
        