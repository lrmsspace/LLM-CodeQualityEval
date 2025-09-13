#https://leetcode.com/problems/best-sightseeing-pair/
#You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
#The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
#Return the maximum score of a pair of sightseeing spots.
# 
#Example 1:
#Input: values = [8,1,5,2,6]
#Output: 11
#Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
#Example 2:
#Input: values = [1,2]
#Output: 2
# 
#Constraints:
#	2 <= values.length <= 5 * 104
#	1 <= values[i] <= 1000
class Solution(object):
    def maxScoreSightseeingPair(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        max_score = 0
        max_value = values[0] + 0   
        for j in range(1, len(values)):
            max_score = max(max_score, max_value + values[j] - j)
            max_value = max(max_value, values[j] + j)
        return max_score         