#https://leetcode.com/problems/second-largest-digit-in-a-string/
#Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
#An alphanumeric string is a string consisting of lowercase English letters and digits.
# 
#Example 1:
#Input: s = "dfa12321afd"
#Output: 2
#Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
#Example 2:
#Input: s = "abc1111"
#Output: -1
#Explanation: The digits that appear in s are [1]. There is no second largest digit. 
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of only lowercase English letters and digits.
class Solution(object):
    def secondHighest(self, s):
        """
        :type s: str
        :rtype: int
        """
        digits = sorted(set(c for c in s if c.isdigit()), reverse=True)
        return int(digits[1]) if len(digits) > 1 else -1
        