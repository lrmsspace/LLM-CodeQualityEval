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
        # Initialize the result string
        result = ""
        
        # While there are more 'a' or 'b' to add
        while a > 0 or b > 0:
            # If there are more 'a' than 'b', add 'a' to the result
            if a > b:
                result += "a"
                a -= 1
            # If there are more 'b' than 'a', add 'b' to the result
            elif b > a:
                result += "b"
                b -= 1
            # If both 'a' and 'b' are equal, add 'a' to the result and remove one from both
            else:
                result += "a"
                a -= 1
                b -= 1
        
        return result
        