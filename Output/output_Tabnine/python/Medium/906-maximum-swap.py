#https://leetcode.com/problems/maximum-swap/
#You are given an integer num. You can swap two digits at most once to get the maximum valued number.
#Return the maximum valued number you can get.
# 
#Example 1:
#Input: num = 2736
#Output: 7236
#Explanation: Swap the number 2 and the number 7.
#Example 2:
#Input: num = 9973
#Output: 9973
#Explanation: No swap.
# 
#Constraints:
#	0 <= num <= 108
class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        num_str = str(num)
        max_idx = len(num_str) - 1
        max_digit = num_str[max_idx]
        
        for i in range(len(num_str) - 2, -1, -1):
            if num_str[i] > max_digit:
                max_idx = i
                max_digit = num_str[max_idx]
        
        num_str = list(num_str)
        num_str[max_idx], num_str[len(num_str) - 1] = num_str[len(num_str) - 1], num_str[max_idx]
        
        return int(''.join(num_str))
        