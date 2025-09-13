#https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
#Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
# 
#Example 1:
#Input: s = "1001"
#Output: false
#Explanation: The ones do not form a contiguous segment.
#Example 2:
#Input: s = "110"
#Output: true
# 
#Constraints:
#	1 <= s.length <= 100
#	s[i]​​​​ is either '0' or '1'.
#	s[0] is '1'.
class Solution(object):
    def checkOnesSegment(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # 统计字符串中1的个数
        count = 0
        # 遍历字符串，遇到1就加1，遇到0就跳过
        for i in range(len(s)):
            if s[i] == '1':
                count += 1
            else:
                # 如果已经遇到过1，就返回False
                if count > 0:
                    return False
        # 如果没有遇到过1，或者只遇到过一次1，就返回True
        return True if count <= 1 else False        