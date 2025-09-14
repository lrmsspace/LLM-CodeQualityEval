#https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
#The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
#	For example, the beauty of "abaacc" is 3 - 1 = 2.
#Given a string s, return the sum of beauty of all of its substrings.
# 
#Example 1:
#Input: s = "aabcb"
#Output: 5
#Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
#Example 2:
#Input: s = "aabcbaa"
#Output: 17
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of only lowercase English letters.
class Solution(object):
    def beautySum(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, freq = 0, {}
        for i in range(len(s)):
            freq[s[i]] = freq.get(s[i], 0) + 1
            min_freq, max_freq = float('inf'), 0
            for v in freq.values():
                min_freq = min(min_freq, v)
                max_freq = max(max_freq, v)
            res += max_freq - min_freq
        return res
        