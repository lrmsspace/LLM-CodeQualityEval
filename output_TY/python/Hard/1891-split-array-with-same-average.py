#https://leetcode.com/problems/split-array-with-same-average/
#You are given an integer array nums.
#You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
#Return true if it is possible to achieve that and false otherwise.
#Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
# 
#Example 1:
#Input: nums = [1,2,3,4,5,6,7,8]
#Output: true
#Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
#Example 2:
#Input: nums = [3,1]
#Output: false
# 
#Constraints:
#	1 <= nums.length <= 30
#	0 <= nums[i] <= 104
class Solution(object):
    def splitArraySameAverage(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        s = sum(nums)
        for i in range(n):
            nums[i] = float(nums[i]) / s
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    for l in range(k+1, n):
                        for m in range(l+1, n):
                            for p in range(m+1, n):
                                for q in range(p+1, n):
                                    for r in range(q+1, n):
                                        for t in range(r+1,n):
                                            if (nums[i] + nums[j] + nums[k] + nums[l] + nums[m] + nums[p] + nums[q] + nums[r] + nums[t]) == 1.0):
                                                return True
        return False