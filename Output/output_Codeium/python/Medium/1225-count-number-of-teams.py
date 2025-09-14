#https://leetcode.com/problems/count-number-of-teams/
#There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
#You have to form a team of 3 soldiers amongst them under the following rules:
#	Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
#	A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
#Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
# 
#Example 1:
#Input: rating = [2,5,3,4,1]
#Output: 3
#Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
#Example 2:
#Input: rating = [2,1,3]
#Output: 0
#Explanation: We can't form any team given the conditions.
#Example 3:
#Input: rating = [1,2,3,4]
#Output: 4
# 
#Constraints:
#	n == rating.length
#	3 <= n <= 1000
#	1 <= rating[i] <= 105
#	All the integers in rating are unique.
class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        n = len(rating)
        res = 0
        for i in range(1, n - 1):
            lsmall, llarge = 0, 0
            rsmall, rlarge = 0, 0
            for j in range(i):
                if rating[j] < rating[i]:
                    lsmall += 1
                if rating[j] > rating[i]:
                    llarge += 1
            for j in range(i + 1, n):
                if rating[j] < rating[i]:
                    rsmall += 1
                if rating[j] > rating[i]:
                    rlarge += 1
            res += lsmall * rlarge + llarge * rsmall
        return res
