#https://leetcode.com/problems/rotated-digits/
#An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
#A number is valid if each digit remains a digit after rotation. For example:
#	0, 1, and 8 rotate to themselves,
#	2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
#	6 and 9 rotate to each other, and
#	the rest of the numbers do not rotate to any other number and become invalid.
#Given an integer n, return the number of good integers in the range [1, n].
# 
#Example 1:
#Input: n = 10
#Output: 4
#Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
#Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
#Example 2:
#Input: n = 1
#Output: 0
#Example 3:
#Input: n = 2
#Output: 1
# 
#Constraints:
#	1 <= n <= 104
class Solution(object):
    def rotatedDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 0, 1, 8 remain the same; 2, 5, 6, 9 are valid; 3, 4, 7 are invalid
        # dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6] + dp[i-7] + dp[i-8]
        # dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 4; dp[5] = 5; dp[6] = 6; dp[7] = 7; dp[8] = 8
        # return dp[n]
        count = 0
        for i in range(1, n+1):
            if self.isGood(i):
                count += 1
        return count        