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
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = [0] * len(envelopes)
        dp[0] = envelopes[0][1]
        for i in range(1, len(envelopes)):
            for j in range(i):
                if envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + envelopes[i][1])
        return max(dp)
        