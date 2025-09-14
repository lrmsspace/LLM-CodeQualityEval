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
        i, j, k = 0, 1, 0
        while j + k < len(s):
            if s[i+k] == s[j+k]:
                k += 1
            elif s[i+k] < s[j+k]:
                i = max(i+k+1, j)
                j = i+1
                k = 0
            else:
                j += k+1
                k = 0
        return s[i:]
        