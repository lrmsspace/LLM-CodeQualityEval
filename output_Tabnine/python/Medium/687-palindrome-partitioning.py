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
        def is_palindrome(s, left, right):
            while left < right:
                if s[left]!= s[right]:
                    return False
                left += 1
                right -= 1
            return True
        
        def backtrack(start, path, result):
            if start == len(s):
                result.append(path[:])
                return
            
            for i in range(start, len(s)):
                if is_palindrome(s, start, i):
                    path.append(s[start:i+1])
                    backtrack(i+1, path, result)
                    path.pop()
        
        result = []
        backtrack(0, [], result)
        return result
        