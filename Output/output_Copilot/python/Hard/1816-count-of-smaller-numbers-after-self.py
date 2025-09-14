#https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
# 
#Example 1:
#Input: nums = [5,2,6,1]
#Output: [2,1,1,0]
#Explanation:
#To the right of 5 there are 2 smaller elements (2 and 1).
#To the right of 2 there is only 1 smaller element (1).
#To the right of 6 there is 1 smaller element (1).
#To the right of 1 there is 0 smaller element.
#Example 2:
#Input: nums = [-1]
#Output: [0]
#Example 3:
#Input: nums = [-1,-1]
#Output: [0,0]
# 
#Constraints:
#	1 <= nums.length <= 105
#	-104 <= nums[i] <= 104
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 归并排序 + 二分搜索
        def merge_sort(nums, counts, left, right):
            if left >= right:
                return

            mid = (left + right) // 2
            merge_sort(nums, counts, left, mid)
            merge_sort(nums, counts, mid + 1, right)

            # 合并两个有序数组并更新 counts
            i = left
            j = mid + 1
            temp = []
            while i <= mid and j <= right:
                if nums[i] <= nums[j]:
                    temp.append(nums[i])
                    counts[i] += j - (mid + 1)     
                    i += 1
                else:
                    temp.append(nums[j])
                    j += 1
            while i <= mid:
                temp.append(nums[i])
                counts[i] += j - (mid + 1)     
                i += 1
            while j <= right:
                temp.append(nums[j])
                j += 1
            for k in range(len(temp)):
                nums[left + k] = temp[k]

            