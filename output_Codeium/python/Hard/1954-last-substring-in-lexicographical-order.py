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
        max_substring = ""
        for i in range(len(s)):
            for j in range(i+1, len(s)+1):
                if s[i:j] > max_substring:
                    max_substring = s[i:j]
        return max_substring
