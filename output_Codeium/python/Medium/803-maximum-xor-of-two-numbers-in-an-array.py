#https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
# 
#Example 1:
#Input: nums = [3,10,5,25,2,8]
#Output: 28
#Explanation: The maximum result is 5 XOR 25 = 28.
#Example 2:
#Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
#Output: 127
# 
#Constraints:
#	1 <= nums.length <= 2 * 105
#	0 <= nums[i] <= 231 - 1
class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #create a Trie
        root = {}
        max_xor = 0
        for num in nums:
            node = root
            xor_node = root
            curr_xor = 0
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                if bit not in node:
                    node[bit] = {}
                node = node[bit]
                toggle_bit = 1 - bit
                if toggle_bit in xor_node:
                    curr_xor = (curr_xor << 1) | 1
                    xor_node = xor_node[toggle_bit]
                else:
                    curr_xor = curr_xor << 1
                    xor_node = xor_node[bit]
            max_xor = max(max_xor, curr_xor)
        return max_xor
