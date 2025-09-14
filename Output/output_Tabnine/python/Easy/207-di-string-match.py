#https://leetcode.com/problems/di-string-match/
#A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
#	s[i] == 'I' if perm[i] < perm[i + 1], and
#	s[i] == 'D' if perm[i] > perm[i + 1].
#Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.
# 
#Example 1:
#Input: s = "IDID"
#Output: [0,4,1,3,2]
#Example 2:
#Input: s = "III"
#Output: [0,1,2,3]
#Example 3:
#Input: s = "DDI"
#Output: [3,2,0,1]
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is either 'I' or 'D'.
class Solution(object):
    def diStringMatch(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        n = len(s)
        left, right = 0, n
        perm = [0] * (n + 1)
        
        for i, ch in enumerate(s):
            if ch == 'I':
                perm[i] = left
                left += 1
            else:
                perm[i] = right
                right -= 1
        
        perm[n] = left
        
        return perm
        