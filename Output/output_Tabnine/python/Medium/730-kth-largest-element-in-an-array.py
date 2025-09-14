#https://leetcode.com/problems/kth-largest-element-in-an-array/
#Given an integer array nums and an integer k, return the kth largest element in the array.
#Note that it is the kth largest element in the sorted order, not the kth distinct element.
#Can you solve it without sorting?
# 
#Example 1:
#Input: nums = [3,2,1,5,6,4], k = 2
#Output: 5
#Example 2:
#Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
#Output: 4
# 
#Constraints:
#	1 <= k <= nums.length <= 105
#	-104 <= nums[i] <= 104
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #Using QuickSelect algorithm
        #Time complexity: O(n)
        #Space complexity: O(log n)
        def partition(nums, low, high):
            pivot = nums[high]
            i = low - 1
            for j in range(low, high):
                if nums[j] > pivot:
                    i += 1
                    nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1], nums[high] = nums[high], nums[i + 1]
            return i + 1
        
        def quickSelect(nums, low, high, k):
            if low == high:
                return nums[low]
            pivot_index = partition(nums, low, high)
            if k == pivot_index:
                return nums[k]
            elif k < pivot_index:
                return quickSelect(nums, low, pivot_index - 1, k)
            else:
                return quickSelect(nums, pivot_index + 1, high, k)
        
        return quickSelect(nums, 0, len(nums) - 1, len(nums) - k)
    
        