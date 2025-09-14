#https://leetcode.com/problems/arranging-coins/
#You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
#Given the integer n, return the number of complete rows of the staircase you will build.
# 
#Example 1:
#Input: n = 5
#Output: 2
#Explanation: Because the 3rd row is incomplete, we return 2.
#Example 2:
#Input: n = 8
#Output: 3
#Explanation: Because the 4th row is incomplete, we return 3.
# 
#Constraints:
#	1 <= n <= 231 - 1
class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        #Binary search to find the number of complete rows
        low, high = 0, n
        while low <= high:
            mid = (low + high) // 2
            coins = mid * (mid + 1) // 2
            if coins == n:
                return mid
            elif coins < n:
                low = mid + 1
            else:
                high = mid - 1
        return low
        