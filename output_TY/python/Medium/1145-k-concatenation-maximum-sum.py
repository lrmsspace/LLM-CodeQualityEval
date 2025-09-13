#https://leetcode.com/problems/k-concatenation-maximum-sum/
#Given an integer array arr and an integer k, modify the array by repeating it k times.
#For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
#Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
#As the answer can be very large, return the answer modulo 109 + 7.
# 
#Example 1:
#Input: arr = [1,2], k = 3
#Output: 9
#Example 2:
#Input: arr = [1,-2,1], k = 5
#Output: 2
#Example 3:
#Input: arr = [-1,-2], k = 7
#Output: 0
# 
#Constraints:
#	1 <= arr.length <= 105
#	1 <= k <= 105
#	-104 <= arr[i] <= 104
class Solution(object):
    def kConcatenationMaxSum(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        n = len(arr)
        ans = 0

        for i in range(n):
            ans += arr[i]
            arr[i] = abs(arr[i])
        max_subarray_sum = max_subarray_sum_ending_here = 0
        for i in range(n):
            max_subarray_sum_ending_here = max(arr[i], max_subarray_sum_ending_here + arr[i])
            max_subarray_sum = max(max_subarray_sum, max_subarray_sum_ending_here)
        if max_subarray_sum < 0:
            return 0
        if k == 1:
            return max_subarray_sum
        max_subarray_sum_ending_here = 0
        for i in range(n):
            max_subarray_sum_ending_here += arr[i]
            max_subarray_sum = max(max_subarray_sum, max_subarray_sum_ending_here)
        return max(max_subarray_sum, ans + max_subarray_sum * (k - 2)) % (10 ** 9 + 7)