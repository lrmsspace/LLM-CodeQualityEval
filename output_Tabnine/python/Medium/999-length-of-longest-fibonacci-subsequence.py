#https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
#A sequence x1, x2, ..., xn is Fibonacci-like if:
#	n >= 3
#	xi + xi+1 == xi+2 for all i + 2 <= n
#Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
#A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
# 
#Example 1:
#Input: arr = [1,2,3,4,5,6,7,8]
#Output: 5
#Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
#Example 2:
#Input: arr = [1,3,7,11,12,14,18]
#Output: 3
#Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
# 
#Constraints:
#	3 <= arr.length <= 1000
#	1 <= arr[i] < arr[i + 1] <= 109
class Solution(object):
    def lenLongestFibSubseq(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        fib_set = set(arr)
        fib_map = {arr[i]: i for i in range(n)}
        max_len = 0
        for i in range(1, n + 1):
            for j in range(i - 1, 0, -1):
                diff = arr[i] - arr[j]
                if diff in fib_set:
                    dp[j][i] = dp[j + 1][fib_map[diff]] + 1
                    max_len = max(max_len, dp[j][i])
        return max_len
        