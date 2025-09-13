#https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
#Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
#if no such substring exists, return 0.
# 
#Example 1:
#Input: s = "aaabb", k = 3
#Output: 3
#Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
#Example 2:
#Input: s = "ababbc", k = 2
#Output: 5
#Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of only lowercase English letters.
#	1 <= k <= 105
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if len(s) == 0 or len(s) < k:
            return 0
        if k <= 1:
            return len(s)
        # 统计每个字符出现的次数
        count = {}
        for c in s:
            count[c] = count.get(c, 0) + 1
        # 如果当前字符的出现次数小于k，则将其分割
        for c in count:
            if count[c] < k:
                return max(self.longestSubstring(sub, k) for sub in s.split(c))
        return len(s)        