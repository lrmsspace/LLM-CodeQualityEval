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
        # Find the longest suffix that is also a prefix of s
        max_suffix = ""
        for i in range(len(s) - 1, -1, -1):
            if s[:i] == s[i:]:
                max_suffix = s[i:]
                break
        
        return max_suffix
        