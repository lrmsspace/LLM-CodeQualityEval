#https://leetcode.com/problems/find-the-closest-palindrome/
#Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
#The closest is defined as the absolute difference minimized between two integers.
# 
#Example 1:
#Input: n = "123"
#Output: "121"
#Example 2:
#Input: n = "1"
#Output: "0"
#Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
# 
#Constraints:
#	1 <= n.length <= 18
#	n consists of only digits.
#	n does not have leading zeros.
#	n is representing an integer in the range [1, 1018 - 1].
class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        if int(n) < 10:
            return str(int(n) - 1)
        if int(n) == 10**len(n) - 1:
            return str(int(n) - 1)
        if int(n) == 10**len(n) + 1:
            return str(int(n) + 2)
        if self.isPalindrome(n):
            if len(n) % 2 == 0:
                return str(int(n[:len(n)//2] + n[len(n)//2] + n[:len(n)//2][::-1]) - 1)
            else:
                return str(int(n[:len(n)//2] + n[len(n)//2] + n[:len(n)//2][::-1]) - 2)
        else:
            if len(n) % 2 == 0:
                return str(int(n[:len(n)//2] + n[:len(n)//2][::-1]))
            else:
                return str(int(n[:len(n)//2] + n[len(n)//2] + n[:len(n)//2][::-1]))
        