#https://leetcode.com/problems/set-mismatch/
#You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
#You are given an integer array nums representing the data status of this set after the error.
#Find the number that occurs twice and the number that is missing and return them in the form of an array.
# 
#Example 1:
#Input: nums = [1,2,2,4]
#Output: [2,3]
#Example 2:
#Input: nums = [1,1]
#Output: [1,2]
# 
#Constraints:
#	2 <= nums.length <= 104
#	1 <= nums[i] <= 104
class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Create a list of size n+1 to store the count of each number
        count = [0] * (len(nums) + 1)
        
        # Iterate through the list and update the count
        for num in nums:
            count[num] += 1
        
        # Find the number that occurs twice
        for i in range(1, len(nums) + 1):
            if count[i] == 2:
                twice_num = i
        
        # Find the number that is missing
        missing_num = 1
        while missing_num <= len(nums):
            if count[missing_num] == 0:
                break
            missing_num += 1
        
        return [twice_num, missing_num]
        