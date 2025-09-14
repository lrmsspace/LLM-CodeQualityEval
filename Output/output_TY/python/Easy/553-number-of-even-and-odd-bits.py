#https://leetcode.com/problems/number-of-even-and-odd-bits/
#You are given a positive integer n.
#Let even denote the number of even indices in the binary representation of n with value 1.
#Let odd denote the number of odd indices in the binary representation of n with value 1.
#Note that bits are indexed from right to left in the binary representation of a number.
#Return the array [even, odd].
# 
#Example 1:
#Input: n = 50
#Output: [1,2]
#Explanation:
#The binary representation of 50 is 110010.
#It contains 1 on indices 1, 4, and 5.
#Example 2:
#Input: n = 2
#Output: [0,1]
#Explanation:
#The binary representation of 2 is 10.
#It contains 1 only on index 1.
# 
#Constraints:
#	1 <= n <= 1000
class Solution(object):
    def evenOddBit(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return [sum(n & (1 << i) for i in range(0, 32, 2)), sum(n & (1 << i) for i in range(1, 32, 2))]