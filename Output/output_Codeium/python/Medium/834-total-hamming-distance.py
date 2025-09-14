#https://leetcode.com/problems/total-hamming-distance/
#The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
#Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.
# 
#Example 1:
#Input: nums = [4,14,2]
#Output: 6
#Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
#showing the four bits relevant in this case).
#The answer will be:
#HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
#Example 2:
#Input: nums = [4,14,4]
#Output: 4
# 
#Constraints:
#	1 <= nums.length <= 104
#	0 <= nums[i] <= 109
#	The answer for the given input will fit in a 32-bit integer.
class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                res += self.hammingDistance(nums[i], nums[j])
        return res
    
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        return bin(x ^ y).count('1')
        
