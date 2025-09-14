#https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
#Given a string s, return the maximum number of unique substrings that the given string can be split into.
#You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "ababccc"
#Output: 5
#Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
#Example 2:
#Input: s = "aba"
#Output: 2
#Explanation: One way to split maximally is ['a', 'ba'].
#Example 3:
#Input: s = "aa"
#Output: 1
#Explanation: It is impossible to split the string any further.
# 
#Constraints:
#	
#	1 <= s.length <= 16
#	
#	
#	s contains only lower case English letters.
#	
class Solution(object):
    def maxUniqueSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        def dfs(start, visited, substrings):
            if start == len(s):
                return 1
            
            if start in visited:
                return 0
            
            visited.add(start)
            count = 0
            for i in range(start + 1, len(s) + 1):
                if s[start:i] not in visited:
                    count += dfs(i, visited, substrings + [s[start:i]])
                    visited.remove(start)
            
            return count
        
        return dfs(0, set(), [])
        