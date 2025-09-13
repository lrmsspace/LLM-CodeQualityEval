#https://leetcode.com/problems/russian-doll-envelopes/
#You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
#One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
#Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
#Note: You cannot rotate an envelope.
# 
#Example 1:
#Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
#Output: 3
#Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
#Example 2:
#Input: envelopes = [[1,1],[1,1],[1,1]]
#Output: 1
# 
#Constraints:
#	1 <= envelopes.length <= 105
#	envelopes[i].length == 2
#	1 <= wi, hi <= 105
class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if not envelopes:
            return 0

        # Sort envelopes: first by width in ascending order, and then by height in descending order if widths are the same
        envelopes.sort(key=lambda x: (x[0], -x[1]))

        # DP array for the longest increasing subsequence of heights
        dp = []

        # Binary search helper function
        def binary_search(dp, target):
            left, right = 0, len(dp) - 1
            while left <= right:
                mid = (left + right) // 2
                if dp[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return left

        for _, height in envelopes:
            pos = binary_search(dp, height)
            if pos == len(dp):
                dp.append(height)
            else:
                dp[pos] = height

        return len(dp)

