#https://leetcode.com/problems/last-substring-in-lexicographical-order/
#Given a string s, return the last substring of s in lexicographical order.
# 
#Example 1:
#Input: s = "abab"
#Output: "bab"
#Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
#Example 2:
#Input: s = "leetcode"
#Output: "tcode"
# 
#Constraints:
#	1 <= s.length <= 4 * 105
#	s contains only lowercase English letters.
class Solution(object):
    def lastSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        i, j, k = 0, 1, 0
        while j + k < n:
            t = s[i:i+k+1]
            u = s[j:j+k+1]
            if t == u:
                k += 1
            elif t < u:
                i = j
                k = 0
            else:
                j = j + k + 1
                k = 0
        return s[i:]
