#https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
# 
#Example 1:
#Input: nums = [4,3,2,3,5,2,1], k = 4
#Output: true
#Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
#Example 2:
#Input: nums = [1,2,3,4], k = 3
#Output: false
# 
#Constraints:
#	1 <= k <= nums.length <= 16
#	1 <= nums[i] <= 104
#	The frequency of each element is in the range [1, 4].
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        # Sum of the array
        total_sum = sum(nums)
        
        # If the total sum is not divisible by k, return False
        if total_sum % k!= 0:
            return False
        
        # Divide the total sum by k to get the target sum for each subset
        target_sum = total_sum // k
        
        # Sort the array in descending order
        nums.sort(reverse=True)
        
        # Create a helper function to check if it is possible to form k non-empty subsets with equal sums
        def dfs(index, current_sum, subset_count):
            # If all subsets have been formed, return True
            if subset_count == k:
                return True
            
            # If the current index is out of range, return False
            if index == len(nums):
                return False
            
            # Try adding the current number to each subset
            for i in range(subset_count):
                # If the current sum of the subset is greater than the target sum, skip to the next subset
                if current_sum + nums[index] > target_sum:
                    continue
                
                # Add the current number to the subset and try to form the remaining subsets
                if dfs(index + 1, current_sum + nums[index], subset_count + 1):
                    return True
                
                # Backtrack by removing the current number from the subset
                current_sum -= nums[index]
            
        # Start the DFS from the first index and return the result
        return dfs(0, 0, 0)
        