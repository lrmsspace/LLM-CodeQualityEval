#https://leetcode.com/problems/string-without-aaa-or-bbb/
#Given two integers a and b, return any string s such that:
#	s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
#	The substring 'aaa' does not occur in s, and
#	The substring 'bbb' does not occur in s.
# 
#Example 1:
#Input: a = 1, b = 2
#Output: "abb"
#Explanation: "abb", "bab" and "bba" are all correct answers.
#Example 2:
#Input: a = 4, b = 1
#Output: "aabaa"
# 
#Constraints:
#	0 <= a, b <= 100
#	It is guaranteed such an s exists for the given a and b.
class Solution(object):
    def strWithout3a3b(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: str
        """
        result = []
        while a > 0 or b > 0:
            if len(result) >= 2 and result[-1] == result[-2]:
                if a >= b:
                    result.append('a')
                    a -= 1
                else:
                    result.append('b')
                    b -= 1
            else:
                if a >= b:
                    result.append('a')
                    a -= 1
                else:
                    result.append('b')
                    b -= 1
        return ''.join(result)
