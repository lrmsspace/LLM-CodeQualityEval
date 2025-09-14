#https://leetcode.com/problems/unique-substrings-in-wraparound-string/
#We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
#	"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
#Given a string s, return the number of unique non-empty substrings of s are present in base.
# 
#Example 1:
#Input: s = "a"
#Output: 1
#Explanation: Only the substring "a" of s is in base.
#Example 2:
#Input: s = "cac"
#Output: 2
#Explanation: There are two substrings ("a", "c") of s in base.
#Example 3:
#Input: s = "zab"
#Output: 6
#Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of lowercase English letters.
class Solution(object):
    def findSubstringInWraproundString(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        ans = 0
        max_len = 0
        for i in range(n):
            if i > 0 and (s[i] - s[i - 1] + 26) % 26 == 1:
                max_len += 1
            else:
                max_len = 1
            ans += max_len - dp[s[i]]
            dp[s[i]] = max_len
        return ans