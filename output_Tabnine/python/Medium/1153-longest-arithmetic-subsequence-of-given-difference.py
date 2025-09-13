#https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
#Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
#A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
# 
#Example 1:
#Input: arr = [1,2,3,4], difference = 1
#Output: 4
#Explanation: The longest arithmetic subsequence is [1,2,3,4].
#Example 2:
#Input: arr = [1,3,5,7], difference = 1
#Output: 1
#Explanation: The longest arithmetic subsequence is any single element.
#Example 3:
#Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
#Output: 4
#Explanation: The longest arithmetic subsequence is [7,5,3,1].
# 
#Constraints:
#	1 <= arr.length <= 105
#	-104 <= arr[i], difference <= 104
class Solution(object):
    def longestSubsequence(self, arr, difference):
        """
        :type arr: List[int]
        :type difference: int
        :rtype: int
        """
        # Initialize a dictionary to store the longest subsequence ending at each element
        dp = {num: 1 for num in arr}
        
        # Iterate over the array in reverse order
        for i in range(len(arr) - 2, -1, -1):
            # Find the longest subsequence ending at the current element
            for j in range(i + 1, len(arr)):
                if arr[j] - arr[i] == difference:
                    dp[arr[i]] = max(dp[arr[i]], dp[arr[j]] + 1)
        
        # Return the maximum length of the arithmetic subsequence
        return max(dp.values())
        