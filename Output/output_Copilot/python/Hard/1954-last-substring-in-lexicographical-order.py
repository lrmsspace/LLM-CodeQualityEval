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
        max_char = max(s) 
        candidates = [i for i in range(len(s)) if s[i] == max_char]
        result = s[candidates[0]:]
        for i in candidates[1:]:
            if s[i:] > result:
                result = s[i:]
        return result   