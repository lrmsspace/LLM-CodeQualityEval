#https://leetcode.com/problems/reverse-pairs/
#Given an integer array nums, return the number of reverse pairs in the array.
#A reverse pair is a pair (i, j) where:
#	0 <= i < j < nums.length and
#	nums[i] > 2 * nums[j].
# 
#Example 1:
#Input: nums = [1,3,2,3,1]
#Output: 2
#Explanation: The reverse pairs are:
#(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
#(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
#Example 2:
#Input: nums = [2,4,3,5,1]
#Output: 3
#Explanation: The reverse pairs are:
#(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
#(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
#(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
# 
#Constraints:
#	1 <= nums.length <= 5 * 104
#	-231 <= nums[i] <= 231 - 1
class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def merge_sort(nums, left, right):
            if left >= right:
                return 0
            
            mid = left + (right - left) // 2
            count = merge_sort(nums, left, mid) + merge_sort(nums, mid + 1, right)
            
            i, j = left, mid + 1
            temp = []
            while i <= mid and j <= right:
                if nums[i] <= 2 * nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    temp.append(nums[j])
                    count += mid - i
                    j += 1
            
            while i <= mid:
                temp.append(nums[i])
                i += 1
            
            while j <= right:
                temp.append(nums[j])
                j += 1
            
            nums[left:right+1] = temp
            
            return count
        
        return merge_sort(nums, 0, len(nums) - 1)
        