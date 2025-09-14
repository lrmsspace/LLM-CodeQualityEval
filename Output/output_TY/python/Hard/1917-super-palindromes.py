#https://leetcode.com/problems/super-palindromes/
#Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
#Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
# 
#Example 1:
#Input: left = "4", right = "1000"
#Output: 4
#Explanation: 4, 9, 121, and 484 are superpalindromes.
#Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
#Example 2:
#Input: left = "1", right = "2"
#Output: 1
# 
#Constraints:
#	1 <= left.length, right.length <= 18
#	left and right consist of only digits.
#	left and right cannot have leading zeros.
#	left and right represent integers in the range [1, 1018 - 1].
#	left is less than or equal to right.
class Solution(object):
    def superpalindromesInRange(self, left, right):
        """
        :type left: str
        :type right: str
        :rtype: int
        """
        left = int(left)
        right = int(right)
        ans = 0
        for i in range(10):
            for j in range(10):
                s = str(i)
                for k in range(10):
                    s += str(k)
                    s += s[::-1]
                    s = s.lstrip('0')
                    if len(s) > 18:
                        break
                    s = int(s)
                    if s > right:
                        break
                    if s >= left and s == s ** 0.5 ** 2:
                        ans += 1
                    s = str(i)
        for i in range(10):
            for j in range(10):
                s = str(i)
                for k in range(10):
                    s += str(k)
                    s += s[::-1]
                    s = s.lstrip('0')
                    if len(s) > 18:
                        break
                    s = int(s)
                    if s > right:
                        break
                    if s >= left and s == s ** 0.5 ** 2:
                        ans += 1
                    s = str(i)
                    s += str(j)
                    s += s[::-1]
                    s = s.lstrip('0')
        return ans
