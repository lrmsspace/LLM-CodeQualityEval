#https://leetcode.com/problems/palindrome-partitioning/
#Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
# 
#Example 1:
#Input: s = "aab"
#Output: [["a","a","b"],["aa","b"]]
#Example 2:
#Input: s = "a"
#Output: [["a"]]
# 
#Constraints:
#	1 <= s.length <= 16
#	s contains only lowercase English letters.
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        result = []
        self.dfs(result, [], s, 0)
        return result

    def dfs(self, result, current, s, start):
        if start == len(s):
            result.append(current[:])
            return
        for end in range(start, len(s)):
            if self.is_palindrome(s, start, end):
                current.append(s[start:end+1])
                self.dfs(result, current, s, end+1)
                current.pop()

    def is_palindrome(self, s, start, end):
        while start < end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
