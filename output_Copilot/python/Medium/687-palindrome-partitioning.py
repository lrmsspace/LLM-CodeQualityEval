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
        def is_palindrome(substring):
            return substring == substring[::-1]

        def backtrack(start, path):
            if start == len(s):
                result.append(path[:])
                return
            for end in range(start + 1, len(s) + 1):
                if is_palindrome(s[start:end]):
                    path.append(s[start:end])
                    backtrack(end, path)
                    path.pop()

        result = []
        backtrack(0, [])
        return result        