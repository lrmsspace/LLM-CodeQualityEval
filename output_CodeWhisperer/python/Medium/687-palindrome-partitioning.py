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
        def is_palindrome(s):
            return s == s[::-1]
        
        def backtrack(start, path):
            if start == len(s):
                result.append(path[:])
                return
            for end in range(start, len(s)):
                if is_palindrome(s[start:end+1]):
                    path.append(s[start:end+1])
                    backtrack(end+1, path)
                    path.pop()
        
        result = []
        backtrack(0, [])
        return result

        