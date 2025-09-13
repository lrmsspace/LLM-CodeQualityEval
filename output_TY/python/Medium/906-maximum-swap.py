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
        for i in range(len(num_str)-1):
            max_val = num_str[i]
            max_pos = i
            for j in range(i+1, len(num_str)):
                if num_str[j] >= max_val:
                    max_val = num_str[j]
                    max_pos = j
            if max_val != num_str[i]:
                num_str = num_str[:i] + max_val + num_str[i+1:max_pos] + num_str[i] + num_str[max_pos+1:]
                return int(num_str)
        return num