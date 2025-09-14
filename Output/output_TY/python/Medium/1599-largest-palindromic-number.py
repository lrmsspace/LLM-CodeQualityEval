#https://leetcode.com/problems/largest-palindromic-number/
#You are given a string num consisting of digits only.
#Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
#Notes:
#	You do not need to use all the digits of num, but you must use at least one digit.
#	The digits can be reordered.
# 
#Example 1:
#Input: num = "444947137"
#Output: "7449447"
#Explanation: 
#Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
#It can be shown that "7449447" is the largest palindromic integer that can be formed.
#Example 2:
#Input: num = "00009"
#Output: "9"
#Explanation: 
#It can be shown that "9" is the largest palindromic integer that can be formed.
#Note that the integer returned should not contain leading zeroes.
# 
#Constraints:
#	1 <= num.length <= 105
#	num consists of digits.
class Solution(object):
    def largestPalindromic(self, num):
        """
        :type num: str
        :rtype: str
        """
        d = [0]*10
        for i in num:
            d[int(i)] += 1
        odd = d[9]%2
        d[9] = d[9]//2
        palindrome = ""
        for i in range(9,-1,-1):
            if d[i]%2==0:
                palindrome += str(i)*(d[i]//2)
            else:
                palindrome += str(i)*(d[i]//2)
                odd = True
        palindrome += str(i)
        palindrome += palindrome[::-1]
        return palindrome