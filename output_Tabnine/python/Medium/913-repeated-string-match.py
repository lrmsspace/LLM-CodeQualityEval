#https://leetcode.com/problems/repeated-string-match/
#Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
#Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
# 
#Example 1:
#Input: a = "abcd", b = "cdabcdab"
#Output: 3
#Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
#Example 2:
#Input: a = "a", b = "aa"
#Output: 2
# 
#Constraints:
#	1 <= a.length, b.length <= 104
#	a and b consist of lowercase English letters.
class Solution(object):
    def repeatedStringMatch(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        # If b is a substring of a, return 1
        if b in a:
            return 1
        
        # If b is not a substring of a, calculate the minimum number of times a needs to be repeated
        # to make it a substring of b
        n, m = len(a), len(b)
        repeat = (m + n - 1) // n
        
        # Check if a repeated n times is a substring of b
        if (repeat + 1) * n <= m:
            return repeat + 1
        
        # If not, check if a repeated (repeat + 2) times is a substring of b
        if (repeat + 2) * n <= m:
            return repeat + 2
        
        return -1
        