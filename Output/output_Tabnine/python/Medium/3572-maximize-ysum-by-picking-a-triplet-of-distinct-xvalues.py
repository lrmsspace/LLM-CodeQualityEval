# You are given two integer arrays x and y, each of length n. You must choose three distinct indices i, j, and k such that:
# x[i] != x[j]
# x[j] != x[k]
# x[k] != x[i]
# Your goal is to maximize the value of y[i] + y[j] + y[k] under these conditions. Return the maximum possible sum that can be obtained by choosing such a triplet of indices.
# If no such triplet exists, return -1.
# Example 1:
# Input: x = [1,2,1,3,2], y = [5,3,4,6,2]
# Output: 14
# Explanation:
# Choose i = 0 (x[i] = 1, y[i] = 5), j = 1 (x[j] = 2, y[j] = 3), k = 3 (x[k] = 3, y[k] = 6).
# All three values chosen from x are distinct. 5 + 3 + 6 = 14 is the maximum we can obtain. Hence, the output is 14.
# Example 2:
# Input: x = [1,2,1,2], y = [4,5,6,7]
# Output: -1
# Explanation:
# There are only two distinct values in x. Hence, the output is -1.
# Constraints:
# n == x.length == y.length
# 3 <= n <= 105
# 1 <= x[i], y[i] <= 106

class Solution(object):
    def maxSumDistinctTriplet(self, x, y):
        """
        :type x: List[int]
        :type y: List[int]
        :rtype: int
        """
        n = len(x)
        x.sort()
        y.sort()
        i, j, k = 0, 0, n - 1
        max_sum = -1
        
        while i < n - 2 and j < n - 1 and k > 0:
            if x[i]!= x[j] and x[j]!= x[k] and x[k]!= x[i]:
                max_sum = max(max_sum, y[i] + y[j] + y[k])
            if x[i] <= x[j] <= x[k]:
                k -= 1
            elif x[i] <= x[k] <= x[j]:
                j += 1
            else:
                i += 1
        
        return max_sum
        