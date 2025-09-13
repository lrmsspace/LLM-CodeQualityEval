#https://leetcode.com/problems/find-closest-number-to-zero/
#Given an integer array nums of size n, return the number with the value closest to 0 in nums. If there are multiple answers, return the number with the largest value.
# 
#Example 1:
#Input: nums = [-4,-2,1,4,8]
#Output: 1
#Explanation:
#The distance from -4 to 0 is |-4| = 4.
#The distance from -2 to 0 is |-2| = 2.
#The distance from 1 to 0 is |1| = 1.
#The distance from 4 to 0 is |4| = 4.
#The distance from 8 to 0 is |8| = 8.
#Thus, the closest number to 0 in the array is 1.
#Example 2:
#Input: nums = [2,-1,1]
#Output: 1
#Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.
# 
#Constraints:
#	1 <= n <= 1000
#	-105 <= nums[i] <= 105
class Solution(object):
    def findClosestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize the closest number to the first element in the list
        closest = nums[0]
        
        # Iterate through each number in the list
        for num in nums:
            # Check if the absolute value of the current number is less than the absolute value of the closest number
            if abs(num) < abs(closest):
                closest = num
            # If they are equal, choose the larger one
            elif abs(num) == abs(closest):
                closest = max(closest, num)
        
        return closest        