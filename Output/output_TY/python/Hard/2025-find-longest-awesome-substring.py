#https://leetcode.com/problems/find-longest-awesome-substring/
#You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
#Return the length of the maximum length awesome substring of s.
# 
#Example 1:
#Input: s = "3242415"
#Output: 5
#Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
#Example 2:
#Input: s = "12345678"
#Output: 1
#Example 3:
#Input: s = "213123"
#Output: 6
#Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists only of digits.
class Solution(object):
    def longestAwesome(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        mask = [0] * (n + 1)
        for i in range(n):
            mask[i + 1] = mask[i] ^ (1 << int(s[i]))
        ans = 1
        for i in range(n):
            for j in range(i):
                ans = max(ans, i - j)
                if mask[i + 1] ^ mask[j] == 0:
                    ans = max(ans, i - j + 1)
        return ans