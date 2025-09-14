#https://leetcode.com/problems/special-binary-string/
#Special binary strings are binary strings with the following two properties:
#	The number of 0's is equal to the number of 1's.
#	Every prefix of the binary string has at least as many 1's as 0's.
#You are given a special binary string s.
#A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
#Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.
# 
#Example 1:
#Input: s = "11011000"
#Output: "11100100"
#Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
#This is the lexicographically largest string possible after some number of swaps.
#Example 2:
#Input: s = "10"
#Output: "10"
# 
#Constraints:
#	1 <= s.length <= 50
#	s[i] is either '0' or '1'.
#	s is a special binary string.
class Solution(object):
    def makeLargestSpecial(self, s):
        """
        :type s: str
        :rtype: str
        """
        def helper(s, i, count):
            while i < len(s) and s[i] == '1':
                i += 1
            if i == len(s):
                return count
            return helper(s, i + 1, count + 1)
        
        def dfs(s, i, j, count):
            if i >= j:
                return s
            max_res = s[:i] + dfs(s, i + 1, j, count)
            if count % 2 == 0:
                max_res = max(max_res, dfs(s, i + 1, j, count + 1) + s[i:j + 1])
            return max_res
        
        count = helper(s, 0, 0)
        return dfs(s, 0, len(s) - 1, count)
        