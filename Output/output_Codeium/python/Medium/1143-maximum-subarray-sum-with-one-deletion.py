#https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
#Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
#Note that the subarray needs to be non-empty after deleting one element.
# 
#Example 1:
#Input: arr = [1,-2,0,3]
#Output: 4
#Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
#Example 2:
#Input: arr = [1,-2,-2,3]
#Output: 3
#Explanation: We just choose [3] and it's the maximum sum.
#Example 3:
#Input: arr = [-1,-1,-1,-1]
#Output: -1
#Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
# 
#Constraints:
#	1 <= arr.length <= 105
#	-104 <= arr[i] <= 104
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        if n == 1:
            return arr[0]

        # Initialize arrays for dynamic programming
        dp_no_deletion = [0] * n
        dp_one_deletion = [0] * n

        dp_no_deletion[0] = arr[0]
        dp_one_deletion[0] = 0

        max_sum = arr[0]

        for i in range(1, n):
            dp_no_deletion[i] = max(arr[i], dp_no_deletion[i - 1] + arr[i])
            dp_one_deletion[i] = max(dp_no_deletion[i - 1], dp_one_deletion[i - 1] + arr[i])
            max_sum = max(max_sum, dp_no_deletion[i], dp_one_deletion[i])

        return max_sum

