#https://leetcode.com/problems/find-the-maximum-achievable-number/
#Given two integers, num and t. A number is achievable if it can become equal to num after applying the following operation:
#	Increase or decrease the number by 1, and simultaneously increase or decrease num by 1.
#Return the maximum achievable number after applying the operation at most t times.
# 
#Example 1:
#Input: num = 4, t = 1
#Output: 6
#Explanation:
#Apply the following operation once to make the maximum achievable number equal to num:
#	Decrease the maximum achievable number by 1, and increase num by 1.
#Example 2:
#Input: num = 3, t = 2
#Output: 7
#Explanation:
#Apply the following operation twice to make the maximum achievable number equal to num:
#	Decrease the maximum achievable number by 1, and increase num by 1.
# 
#Constraints:
#	1 <= num, t <= 50
class Solution(object):
    def theMaximumAchievableX(self, num, t):
        """
        :type num: int
        :type t: int
        :rtype: int
        """
        # If num is already the maximum achievable number, return it directly
        if num == t:
            return num
        
        # If num is less than t, return the maximum achievable number by applying the operation t times
        if num < t:
            return num + t
        
        # Otherwise, apply the operation t times to find the maximum achievable number
        return 2 * (num - t) + t
        