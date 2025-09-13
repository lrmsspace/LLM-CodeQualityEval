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
        num_list = list(str(num))
        for i in range(len(num_list)):
            max_digit = max(num_list[i:])
            if num_list[i] != max_digit:
                max_index = num_list.index(max_digit)
                num_list[i], num_list[max_index] = num_list[max_index], num_list[i]
                return int(''.join(num_list))
        return num
