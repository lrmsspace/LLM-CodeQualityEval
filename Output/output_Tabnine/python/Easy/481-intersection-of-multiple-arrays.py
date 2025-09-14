#https://leetcode.com/problems/intersection-of-multiple-arrays/
#Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.
# 
#Example 1:
#Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
#Output: [3,4]
#Explanation: 
#The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
#Example 2:
#Input: nums = [[1,2,3],[4,5,6]]
#Output: []
#Explanation: 
#There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
# 
#Constraints:
#	1 <= nums.length <= 1000
#	1 <= sum(nums[i].length) <= 1000
#	1 <= nums[i][j] <= 1000
#	All the values of nums[i] are unique.
class Solution(object):
    def intersection(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        # Initialize an empty set to store the intersection of all arrays
        intersection_set = set(nums[0])
        
        # Iterate over each array starting from the second one
        for num_set in nums[1:]:
            # Update the intersection set by taking the intersection of the current set and the next one
            intersection_set &= set(num_set)
        
        # Convert the set back to a list and sort it in ascending order
        return sorted(list(intersection_set))
        